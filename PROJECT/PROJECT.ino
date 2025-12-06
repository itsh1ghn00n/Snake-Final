#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include "Game.h"
#include <EEPROM.h>

#define TFT_CS     10
#define TFT_DC      7
#define TFT_RST     8

Adafruit_ST7789 lcd = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

const int GRID_W = 26; //30 Maybe
const int GRID_H = 24; //22 Maybe
const int CELL_SIZE = 10;
const int joyPin1 = A0;
const int joyPin2 = A1;

Game game(GRID_W, GRID_H, 3, 0);

int highScore = 0;
const int EEPROM_HIGH_SCORE_ADDR = 200;

// Frame Rate
unsigned long frameCount = 0;
unsigned long lastTime = 0;
float fps = 0;
float prevFps = -1;

bool debug = false;

uint16_t bg_c1 = ST77XX_BLACK; // black
uint16_t bg_c2 = lcd.color565(20, 20, 20); // grey
uint16_t ui_c = lcd.color565(0,0,150);

uint16_t snakeColor = lcd.color565(0, 255, 0); 
uint16_t altSnakeColor = lcd.color565(0, 128, 0);

unsigned long lastUpdate = 0;
const int moveDelay = 300;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //
  EEPROM.get(EEPROM_HIGH_SCORE_ADDR, highScore);
  if (highScore > (GRID_W * GRID_H)) { 
    EEPROM.put(EEPROM_HIGH_SCORE_ADDR, 0); }

  lcd.init(240, 320); // width, height
  lcd.setRotation(1);

  randomSeed(analogRead(0)); // so that when we spawn an apple it spawns at random positions every start

  startGame();
}


void loop() {
  unsigned long now = millis();

  int inputX, inputY;
  readJoystick(inputX, inputY);
  if (game.isRunning() && (now - lastUpdate >= moveDelay)) {
    char inChar = Serial.read();
    Serial.println(inChar);
    if (inChar == 'r') { // Reset eeprom highscore.
      EEPROM.put(EEPROM_HIGH_SCORE_ADDR, 0);
    }
    if (inChar == 'd') { // Display debug.
      debug = !debug;
    }
    if (inChar == 'm') { // Set score to max
      const Snake& snakeN = game.getSnake();
      snakeN.grow(576);
    }
    
    game.update(inputX, inputY);
    lastUpdate = now;
  }

  if (game.isRunning()) {
    drawFrame();
    int score = game.getScore();
    if (score == (GRID_W * GRID_H)) {
      winGame();
    }
  } else {
    loseGame();
  }
}

// GAMEPLAY

void startGame() {
  waitForStart();
  game.start();
  lcd.setCursor(100, 80);
  lcd.setTextColor(ST77XX_GREEN, ST77XX_BLACK);
  lcd.setTextSize(6);
  for (int i = 3; i > 0; i--) {
    lcd.fillScreen(ST77XX_BLACK);
    lcd.print(i);
    delay(800);
  }
  lcd.fillScreen(ST77XX_BLACK); // Clears Screen With Black
  lcd.setCursor(110, 80);
  lcd.print("GO!");
  delay(600);
  lcd.fillScreen(ui_c); // Fills the screen with blue
  drawBoard();
  drawSnake();
  drawApple();
  drawUI();
}

void waitForStart() {
  bool visible = true;
  lcd.fillScreen(ST77XX_BLACK);

  while (true) {
    lcd.setTextSize(4);
    lcd.setTextColor(ST77XX_GREEN, ST77XX_BLACK);
    lcd.setCursor(40, 80);
    lcd.print("SNAKE GAME");

    // Blink Start Text
    if (visible) {
      lcd.setTextSize(3);
      lcd.setTextColor(ST77XX_RED, ST77XX_BLACK);
      lcd.setCursor(40, 150);
      lcd.print("MOVE TO START");
    } else {
      lcd.setTextSize(3);
      lcd.setTextColor(ST77XX_BLACK, ST77XX_BLACK); // erase text
      lcd.setCursor(40, 150);
      lcd.print("MOVE TO START");
    }

    visible = !visible;
    delay(500);

    // Read joystick input
    int inputX, inputY;
    readJoystick(inputX, inputY);

    if (inputX != 0 || inputY != 0) {
      break;
    }
  }
}

void loseGame() {
  int score = game.getScore();

  lcd.fillScreen(ST77XX_BLACK);
  lcd.setCursor(30, 80);
  lcd.setTextColor(ST77XX_RED, ST77XX_BLACK);
  lcd.setTextSize(5);
  lcd.print("YOU LOSE!");

  EEPROM.get(EEPROM_HIGH_SCORE_ADDR, highScore);
  if (score > highScore) { 
    EEPROM.put(EEPROM_HIGH_SCORE_ADDR, score); highScore = score; 
    lcd.setTextSize(2);
    lcd.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
    lcd.setCursor(30, 140);
    lcd.print("New Highscore!");
  }
  // Display HighScore 
  lcd.setTextSize(2);
  lcd.setCursor(30, 160); 
  lcd.setTextColor(ST77XX_GREEN, ST77XX_BLACK); 
  lcd.print("High Score: "); 
  lcd.print(highScore);
  
  restartGame();
}

void winGame() {
  int score = game.getScore();
  // win game
  lcd.fillScreen(ST77XX_GREEN);
  lcd.setCursor(30, 80);
  lcd.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
  lcd.setTextSize(5);
  lcd.print("YOU WIN!");

  EEPROM.get(EEPROM_HIGH_SCORE_ADDR, highScore);
  if (score > highScore) { 
    EEPROM.put(EEPROM_HIGH_SCORE_ADDR, score); highScore = score; 
    lcd.setTextSize(2);
    lcd.setTextColor(ST77XX_BLUE, ST77XX_BLACK);
    lcd.setCursor(30, 140);
    lcd.print("New Highscore!");
  }
  lcd.setTextSize(2);
  lcd.setCursor(30, 160); 
  lcd.setTextColor(ST77XX_GREEN, ST77XX_BLACK); 
  lcd.print("High Score: "); 
  lcd.print(highScore);

  restartGame();
}

void restartGame() {
  while (true) {
    int inputX, inputY;
    readJoystick(inputX, inputY);
    if (inputX != 0 || inputY != 0) {
      lcd.fillScreen(ST77XX_BLACK);
      game.reset();
      startGame();
      break;
    }
    delay(100);
  }
}

// Return a color from the board

uint16_t getBoardColor(int x, int y) {
  uint8_t cellVal = game.getBoard().getBoardVal(x,y);
  if (cellVal == 0) return bg_c1;
  if (cellVal == 1) return bg_c2;
  return ST77XX_RED;
}

// DRAW CALLS

void drawFrame() {
  unsigned long start = millis();

  // Do your screen updates here:
  drawSnake();
  drawApple();
  drawUI();

  frameCount++;
  unsigned long now = millis();
  if (now - lastTime >= 1000) {
    fps = frameCount * 1000.0 / (now - lastTime);
    frameCount = 0;
    lastTime = now;
  }
}

void drawBoard() {
  for (int x = 0; x < GRID_W; ++x) {
    for (int y = 0; y < GRID_H; ++y) {
      uint16_t boardColor = getBoardColor(x, y);
      drawCell(x, y, boardColor);
    }
  }
}

void drawSnake() {
  const Snake& s = game.getSnake();
  uint8_t (*snakeGrid)[24] = game.getSnakeGrid();

  Point head = s.getHead();
  Point neck = s.getNeck(snakeGrid);
  Point prevTail = s.getPrevTail();

  // Draw Head
  drawCell(head.x, head.y, ST77XX_YELLOW);

  uint8_t neckDir = snakeGrid[neck.x][neck.y];
  uint16_t bodyColor = (neckDir %2 == 0) ? snakeColor : altSnakeColor;

  drawCell(neck.x, neck.y, bodyColor);

  drawCell(prevTail.x, prevTail.y, getBoardColor(prevTail.x, prevTail.y)); // or background color
}

void drawApple() {
  Point apple = game.getApple().getPos();
  uint16_t color;
  if (game.getApple().getIsGolden()) {
    color = ST77XX_YELLOW;
  } else {
    color = ST77XX_RED;
  }
  drawCell(apple.x, apple.y, color);
}

// DrawCell
// Takes x,y, and the color to draw
// It draws a rectangle of the color from the x, y to x,y * CELL_SIZE.
// Primarily just an expansion on the built in fillRect() func from adafruit library
void drawCell(int x, int y, uint16_t color) {
  int sx = (x + game.getXOffset()) * CELL_SIZE;
  int sy = (y + game.getYOffset()) * CELL_SIZE;

  lcd.fillRect(sx, sy, CELL_SIZE, CELL_SIZE, color);
}

// DrawUI
// Just a void function to compartmentalize UI drawing
// Solely draws ui while game.is_running is true
void drawUI() {
  lcd.setTextColor(ST77XX_GREEN, ui_c); 
  lcd.setTextSize(1);
  lcd.setCursor(290, 0); 
  lcd.print("Score:"); 
  lcd.setTextSize(1.7);
  lcd.setCursor(290, 10); 
  lcd.print(game.getScore());

  // Debug head position
  if (debug) {
    lcd.setCursor(250, 40); 
    lcd.print("HeadP");
    lcd.setCursor(245, 60); 
    Point head = game.getSnake().getHead();
    if (head.x < 10) lcd.print("0");
    lcd.print(head.x);
    lcd.print(", ");
    if (head.y < 10) lcd.print("0");
    lcd.print(head.y);

    //lcd.setCursor(245, 80); 
    //Point tail = game.getSnake().getTail();
    //if (tail.x < 10) lcd.print("0");
    //lcd.print(tail.x);
    //lcd.print(", ");
    //if (tail.y < 10) lcd.print("0");
    //lcd.print(tail.y);
    // Debug fps
    if (abs(fps - prevFps) >= 0.1f) // If the absolute change in fps is greater than 0.01, display
    {
      lcd.setCursor(255, 80);
      lcd.print("FPS:");
      lcd.setCursor(250, 100);
      lcd.print(fps, 1);
      prevFps = fps;
    }
  }
}

// INPUT

void readJoystick(int& inputX, int& inputY) {
  int xVal = analogRead(joyPin1);
  int yVal = analogRead(joyPin2);
  const int deadzone = 50;

  inputX = 0; inputY = 0;

  if (abs(xVal - 512) > abs(yVal - 512)) {
    if (xVal > 512 + deadzone) inputX = -1;
    else if (xVal < 512 - deadzone) inputX = 1;
  } else {
    if (yVal > 512 + deadzone) inputY = -1;
    else if (yVal < 512 - deadzone) inputY = 1;
  }
}
