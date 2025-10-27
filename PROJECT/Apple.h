#include <Arduino.h>
#include "Snake.h"

class Apple {
public:
  Apple() { pos = {0, 0}; }
  void spawn(int gridW, int gridH, const Snake& snake);
  Point getPos() const { return pos; }

private:
  Point pos;
};