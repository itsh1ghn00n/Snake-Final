//
// Created by andrew on 10/22/2025.
//
#ifndef BOARDCLASS_H
#define BOARDCLASS_H
#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include "Player.h"

class board{
  private:
  int col; //col ammount
  int row; //row ammount
  int currentAppleRow; //current apple row position
  int currentAppleCol; //current apple col position
  vector<vector<char>> grid; //main grid for the game
  public:
    board();
    board(int col, int row);
    board(int col, int row, int currentAppleRow, int currentAppleCol);
    int getCol(); //getter for col
    int getRow(); //getter for row
    int getCurrentAppleRow();
    int getCurrentAppleCol();
    int getSpace(); //returns current positon
    bool getAppleVal(int, int, Player); //returns true if apple is at curent position false if not
    void setCol(int); //setter for col
    void setRow(int); //setter for row
    void setCurrentAppleRow(int);
    void setCurrentAppleCol(int);
    void setSpace(int, int); //sets the current position
    void setBoardVal(int, int, char);
    void fillBoard(vector<vector<char>>);
    void printBoard(vector<vector<char>>);
  };


#endif //BOARDCLASS_H
