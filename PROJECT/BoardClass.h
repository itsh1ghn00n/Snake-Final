//
// Created by andrew on 10/22/2025.
//
#ifndef BOARDCLASS_H
#define BOARDCLASS_H

class board{
  private:
  static const int MAX_ROWS = 24;
  static const int MAX_COLS = 32;
  int col; //col ammount
  int row; //row ammount
  char grid[MAX_COLS][MAX_ROWS]; //main grid for the game
  public:
    board(int col, int row);
    char getBoardVal(int c, int r);
    void setBoardVal(int c, int r, char val);
  };


#endif //BOARDCLASS_H
