//
// Created by Andrew on 10/22/2025.
//
#include "BoardClass.h"

board::board(int col, int row) : col(col), row(row) {
  for (int y = 0; y < col; ++y) {
    for (int x = 0; x < row; ++x) {
      grid[y][x] = ((x + y) % 2 == 0) ? 3 : 4; // initalizes the board with a checkerboard of 3 on even and 4 on odd.
    }
  }
}

char board::getBoardVal(int c, int r) {
  return grid[c][r];
}
void board::setBoardVal(int c, int r, char val) {
  if (r >= 0 && r < row && c >= 0 && c < col)
    grid[c][r] = val;
}

