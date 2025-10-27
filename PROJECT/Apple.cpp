#include "Apple.h"
#include <Arduino.h>

void Apple::spawn(int gridW, int gridH, const Snake& snake) {
  do {
    pos.x = random(0, gridW);
    pos.y = random(0, gridH);
  } while (snake.isOnBody(pos.x, pos.y));
}