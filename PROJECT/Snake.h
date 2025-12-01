#pragma once
#include <Arduino.h>
#include "BoardClass.h"
#include "Point.h"

enum StateCode { 
  EMPTY = 0,
  BODY_UP = 1, 
  BODY_RIGHT = 2, 
  BODY_DOWN = 3,
  BODY_LEFT = 4,  
};

class Snake {
public:
  Snake();
  void init(int x, int y, int len, uint8_t grid[26][24]);

  void move(int dirX, int dirY, uint8_t grid[26][24]);
  void grow(int amount = 1);

  Point getHead() const { return head; }
  Point getNewHead() const { return newHead; }
  Point getTail() const { return tail; }
  Point getPrevTail() const { return prevTail; }
  int getLength() const { return length; }
  Point getNeck(uint8_t grid[26][24]) const;
  
  void setNewHead(Point newVal) { newHead = newVal; }

private:
  Point newHead;
  Point head;
  Point prevTail;
  Point tail;

  int length;
  int growCount;
  int color;

  void updateTail(uint8_t grid[26][24]);
  uint8_t encodeDirection(int dx, int dy);
};