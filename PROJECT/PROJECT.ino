#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#define TFT_CS     10
#define TFT_DC      7
#define TFT_RST     8
#include "Game.h"

Adafruit_ST7789 lcd = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

const int GRID_W = 24;
const int GRID_H = 24;
const int CELL_SIZE = 10;
//const int MAX_SIZE = 768;
const int joyPin1 = A0;
const int joyPin2 = A1;

Game game(GRID_W, GRID_H);

Point apple;

uint16_t bg_c1 = ST77XX_BLACK; // black
uint16_t bg_c2 = lcd.color565(20, 20, 20); // grey
uint16_t ui_c = lcd.color565(0,0,150);

uint16_t snakeColor, altSnakeColor;

const unsigned long moveDelay = 200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init(240, 320); // width, height
  lcd.setRotation(1);

  randomSeed(analogRead(0));
  snakeColor = lcd.color565(0, 255, 0);
  altSnakeColor = lcd.color565(0, 128, 0);

  lcd.fillScreen(ui_c);
  startGame();
}

void loop() {
  int inputX, inputY;
  readJoystick(inputX, inputY);
  if (game.isRunning()) {
    game.update(inputX, inputY);
    drawSnake();
    drawApple();
  } else if (!game.isRunning()) {
    loseGame();
  }
  delay(moveDelay);
}

// GAMEPLAY

void startGame() {
  lcd.fillScreen(ST77XX_BLACK);
  game.start();
  for (int i = 3; i > 0; i--) {
    lcd.fillScreen(ST77XX_BLACK);
    lcd.setCursor(100, 80);
    lcd.setTextColor(ST77XX_GREEN, ST77XX_BLACK);
    lcd.setTextSize(6);
    lcd.print(i);
    delay(800);
  }
  lcd.fillScreen(ST77XX_BLACK);
  lcd.setCursor(70, 80);
  lcd.setTextColor(ST77XX_GREEN, ST77XX_BLACK);
  lcd.setTextSize(6);
  lcd.print("GO!");
  delay(600);
  lcd.fillScreen(ST77XX_BLACK);
  
  drawBoard();
  drawSnake();
  drawApple();
  //drawUI();
}

void loseGame() {
  lcd.fillScreen(ST77XX_BLACK);
  lcd.setCursor(30, 80);
  lcd.setTextColor(ST77XX_RED, ST77XX_BLACK);
  lcd.setTextSize(5);
  lcd.print("YOU LOSE!");
  delay(5000);
  lcd.fillScreen(ST77XX_BLACK);
  game.reset();
  startGame();
  //game.startMenuActive = true;
}

// Return a color from the board

uint16_t getBoardColor(int x, int y) {
  char cellVal = game.getBoard().getBoardVal(x,y);
  if (cellVal == 3) return bg_c1;
  if (cellVal == 4) return bg_c2;
  return ST77XX_YELLOW;
}

// DRAW CALLS

void drawBoard() {
  for (int x = 0; x < GRID_W; ++x) {
    for (int y = 0; y< GRID_H; ++y) {
      uint16_t boardColor = getBoardColor(x, y);
      drawCell(x, y, boardColor);
    }
  }
}

void drawSnake() {
  const Snake& s = game.getSnake();
  for (int i = 0; i < s.getLength(); i++) {
    uint16_t color = (i == 0)
        ? ST77XX_YELLOW
        : (i % 2 == 0 ? snakeColor : altSnakeColor);
    drawCell(s.getSegment(i).x, s.getSegment(i).y, color);
  }
  Point tail = s.getPrevTail();
  drawCell(tail.x, tail.y, getBoardColor(tail.x, tail.y));
}

void drawApple() {
  Point a = game.getApple().getPos();
  drawCell(a.x, a.y, ST77XX_RED);
}

void drawCell(int x, int y, uint16_t color) {
  lcd.fillRect(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE, color);
}

void drawUI() {
  lcd.setCursor(30, 10);
  lcd.setTextColor(ST77XX_GREEN, ST77XX_BLACK);
  lcd.setTextSize(2);
  lcd.print("Score: ");
  //lcd.print(snakeLength);
}

// INPUT

void readJoystick(int& inputX, int& inputY) {
  int xVal = analogRead(joyPin1);
  int yVal = analogRead(joyPin2);
  const int deadzone = 50;

  inputX = 0; inputY = 0;

  if (abs(xVal - 512) > abs(yVal - 512)) {
    if (xVal > 512 + deadzone) inputX = 1;
    else if (xVal < 512 - deadzone) inputX = -1;
  } else {
    if (yVal > 512 + deadzone) inputY = -1;
    else if (yVal < 512 - deadzone) inputY = 1;
  }
}
