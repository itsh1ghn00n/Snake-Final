#pragma once
#include <Arduino.h>
#include "Snake.h"
#include "Apple.h"
#include "BoardClass.h"

class Game {
public:
  Game(int gridW, int gridH, int xoffset, int yoffset);
  void start();
  void reset();
  void update(int inputDirX, int inputDirY);

  const board& getBoard() const { return gameBoard; }
  uint8_t (*getSnakeGrid())[24] { return snakeGrid; }

  const Snake& getSnake() const { return snake; }
  const Apple& getApple() const { return apple; }

  bool isRunning() const { return running; }
  int getScore() const { return snake.getLength(); }

  int getXOffset() const { return xOffset; }
  int getYOffset() const { return yOffset; }

private:
  int gridW, gridH;
  int xOffset, yOffset;

  board gameBoard;
  uint8_t snakeGrid[26][24];

  Snake snake;
  Apple apple;

  int dirX, dirY;
  int inputDirX, inputDirY;
  bool running;
};