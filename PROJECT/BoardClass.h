//
// Created by andrew on 10/22/2025.
//
#ifndef BOARDCLASS_H
#define BOARDCLASS_H

#include <Arduino.h>

class board{
  private:

  int col;
  int row;
  
  static const int MAX_BITS = 24 * 26;
  static const int MAX_BYTES = (MAX_BITS + 7) / 8;
  uint8_t gridBitArray[MAX_BYTES];

  int index(int c, int r) const { return r * col + c; }

  public:
    board(int col, int row);

    void clear();
    bool getBoardVal(int c, int r) const;
    void setBoardVal(int c, int r, bool value);

    int getCol() const { return col; }
    int getRow() const { return row; }
  };


#endif //BOARDCLASS_H