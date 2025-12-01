//
// Created by Andrew on 10/28/2025.
// Modified by Nico on 10/28/2025
//
#include "BoardClass.h"

board::board(int col, int row) 
    : col(col), row(row)
{ 
  clear();
  
  for (int r = 0; r < row; ++r) {
    for (int c = 0; c < col; ++c) {
        // Checkerboard pattern: alternate bits
        bool bitVal = ((r + c) % 2 == 0); // ex r:0 + c:0 / 2 == 0, r:0 + c:3 / 2 != 0
        setBoardVal(c, r, bitVal);
    }
  }
}

bool board::getBoardVal(int c, int r) const {
  if (c < 0 || c >= col || r < 0 || r >= row)
        return 0;

  int flatindex = index(c, r);
  
  int byteIndex = flatindex / 8; //same as the prior indexing but for printing
  int bitIndex  = flatindex % 8;

  return (gridBitArray[byteIndex] >> bitIndex) & 1; //applies a 1 mask to find if the value is 1. if not will return 0
}

void board::setBoardVal(int c, int r, bool val) {
  if (c < 0 || c >= col || r < 0 || r >= row)
      return;

  int flatindex = index(c, r);
  
  int byteIndex = flatindex / 8; //will be the input for which byte to access
  int bitIndex  = flatindex % 8; //gives the value for which bit to access

  if (val) //value is true to set a bit at the bit index
    gridBitArray[byteIndex] |= (1 << bitIndex); //using or for bit wise operation
  else //value is false which will clear the bits at the bit index
    gridBitArray[byteIndex] &= ~(1 << bitIndex); //using the and for bit wise operation
}

void board::clear() {
    for (int i = 0; i < MAX_BYTES; ++i)
      gridBitArray[i] = 0;
}