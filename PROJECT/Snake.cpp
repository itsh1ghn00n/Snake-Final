#pragma once
#include "Snake.h"

Snake::Snake() : length(3), growCount(0), color(0) {}

void Snake::init(int x, int y, int len, uint8_t grid[26][24])
{
  head = {x, y};
  tail = {(x - (len - 1)), y};
  prevTail = tail;
  length = len;
  growCount = 0;
  color = 0;

  for(int iy = 0; iy < 24; iy++)
        for(int ix = 0; ix < 26; ix++)
            grid[ix][iy] = EMPTY;

  for (int i = 0; i < len; i++)
        grid[x - i][y] = BODY_RIGHT;
}

void Snake::move(int dx, int dy, uint8_t grid[26][24])
{
  uint8_t code = encodeDirection(dx, dy);

  grid[head.x][head.y] = code;

  head.x += dx;
  head.y += dy;

  grid[head.x][head.y] = code;

  // if not growing, remove old tail
  if (growCount > 0) {
    growCount--;
  }
  else {
    prevTail = tail;
    updateTail(grid);
    grid[prevTail.x][prevTail.y] = EMPTY;
  }

  // Flip color
  color ^= 1;
}

void Snake::grow(int amount)
{
    length += amount;
    growCount += amount;
}

uint8_t Snake::encodeDirection(int dx, int dy) { // 0, 1, 2, 3
  if (dx == 1)  return BODY_RIGHT;
  if (dx == -1) return BODY_LEFT;
  if (dy == 1)  return BODY_DOWN;
  return BODY_UP ; // dy = -1
}

void Snake::updateTail(uint8_t grid[26][24])
{
    uint8_t code = grid[tail.x][tail.y];
    // Following from the tail and decoding
    switch(code) {
        case BODY_RIGHT: tail.x++; break;
        case BODY_LEFT:  tail.x--; break;
        case BODY_DOWN:  tail.y++; break;
        case BODY_UP:    tail.y--; break;
    }
}

Point Snake::getNeck(uint8_t grid[26][24]) const {
    uint8_t code = grid[head.x][head.y];
    switch (code) {
      case BODY_RIGHT: return { head.x - 1, head.y };
      case BODY_LEFT:  return { head.x + 1, head.y };
      case BODY_DOWN:  return { head.x, head.y - 1 };
      case BODY_UP:    return { head.x, head.y + 1 };
    }
    return head; // fallback
}

