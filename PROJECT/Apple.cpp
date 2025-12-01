#include "Apple.h"
#include <Arduino.h>

Apple::Apple() : isGolden(false) {}

void Apple::spawn(int gridW, int gridH, int xOffset, int yOffset, uint8_t snakeGrid[25][24]) {
  do {
    pos.x = random(xOffset, gridW + xOffset);
    pos.y = random(yOffset, gridH + yOffset);
  } while (snakeGrid[pos.x][pos.y] != EMPTY);

  isGolden = (random(10) == 0);
}