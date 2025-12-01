#pragma once
#include <Arduino.h>
#include "Point.h" 
#include "Snake.h"

class Snake;

class Apple {
public:
  Apple();

  void spawn(int gridW, int gridH, int xOffset, int yOffset, uint8_t snakeGrid[25][24]);
  
  Point getPos() const { return pos; }
  bool getIsGolden() const { return isGolden; }

private:
  Point pos;
  bool isGolden;
};