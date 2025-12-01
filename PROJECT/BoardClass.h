//
// Created by andrew on 10/22/2025.
//
#ifndef BOARDCLASS_H
#define BOARDCLASS_H

#include <Arduino.h>

class board{
  private:
  const int MAX_ROWS = 24;
  const int MAX_COLS = 24;
  static const int NUM_BYTES = 72;

  int col;
  int row;

  uint8_t gridBitArray[NUM_BYTES];

  int index(int c, int r) const { return r * col + c; }
  public:
    board(int col, int row);

    uint8_t getBoardVal(int c, int r) const;
    void setBoardVal(int c, int r, bool value);
  };


#endif //BOARDCLASS_H