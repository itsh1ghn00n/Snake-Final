#include <Arduino.h>
#include "Apple.h"
#include "BoardClass.h"

class Game {
public:
  Game(int gridW, int gridH);
  void start();
  void reset();
  void update(int inputDirX, int inputDirY);
  bool isRunning() const { return running; }
  int getScore() const { return snake.getLength(); }

  const Snake& getSnake() const { return snake; }
  const Apple& getApple() const { return apple; }
  const board& getBoard() const { return gameBoard; }

private:
  int gridW, gridH;
  int dirX, dirY;
  int inputDirX, inputDirY;
  bool running;
  Snake snake;
  Apple apple;
  board gameBoard;

};