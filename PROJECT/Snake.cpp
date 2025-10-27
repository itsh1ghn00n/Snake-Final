#include "Snake.h"

Snake::Snake() : length(3) {}

void Snake::init(int len) {
  length = len;
  for (int i = 0; i < length; ++i) {
    body[i] = {5 - i, 5};
  }
}

void Snake::move(int dirX, int dirY) {
  //prevTail = body[length - 1];
  for (int i = length - 1; i > 0; i--) {
    body[i] = body[i - 1];
  }
  body[0].x += dirX;
  body[0].y += dirY;
}

void Snake::grow() {
  if (length < MAX_SIZE) {
    body[length] = body[length - 1];
    length++;
  }
}

bool Snake::isOnBody(int x, int y) const {
  for (int i = 1; i < length; i++) {
    if (body[i].x == x && body[i].y == y)
      return true;
  }
  return false;
}