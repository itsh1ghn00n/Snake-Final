//
// Created by andrew on 10/22/2025.
//
#ifndef BOARDCLASS_H
#define BOARDCLASS_H
#include <string>
#include <sstream>
#include "Player.h"

class board{
  private:
  int col;
  int row;
  int currentAppleRow;
  int currentAppleCol;
  public:
    board();
    board(int col, int row);
    board(int col, int row, int currentAppleRow, int currentAppleCol);
    int getCol(); //getter for col
    int getRow(); //getter for row
    int getCurrentAppleRow();
    int getCurrentAppleCol();
    void setCol(int); //setter for col
    void setRow(int); //setter for row
    void setCurrentAppleRow(int);
    void setCurrentAppleCol(int);
    int getSpace(); //returns current positon
    void setSpace(int, int); //sets the current position
    bool getAppleVal(int, int); //returns true if apple is at curent position false if not
  };


#endif //BOARDCLASS_H
