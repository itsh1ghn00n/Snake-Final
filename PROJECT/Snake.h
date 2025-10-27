#include <Arduino.h>
#include "Point.h"

const int MAX_SIZE = 100;

class Snake {
public:
  Snake();
  void init(int length);
  void move(int dirX, int dirY);
  void grow();

  void setPrevTail(Point pos) { prevTail = pos; }
  bool isOnBody(int x, int y) const;
  Point getHead() const { return body[0]; }
  Point getTail() const { return body[length - 1]; }
  Point getPrevTail() const { return prevTail; }
  int getLength() const { return length; }
  Point getSegment(int i) const { return body[i]; }

private:
  Point prevTail;
  Point body[MAX_SIZE];
  int length;
};