//
// Created by andre on 10/22/2025.
//
#include "BoardClass.h"

board::board(){
  }
board::board(int col, int row) { //initializer with only  col and row dimensions
    this->col = col;
    this->row = row; //setting both vals to a passed int which will be defined in main program
  char**  dynamicArray = new char*[row];
  for (int i = 0; i < row; ++i) {
    dynamicArray[i] = new char[col];
    for (int j = 0; j < col; ++j) {
      dynamicArray[i][j] = i + j;
    }
  }
};
board::board(int col, int row, int currentAppleRow, int currentAppleCol) {
  this->col = col;
  this->row = row;
  this->currentAppleRow = currentAppleRow;
  this->currentAppleCol = currentAppleCol;
}

int board::getCol(){//getter for col
  return col;
}
int board::getRow(){//getter for row
  return row;
}
int board::getCurrentAppleRow(){
  return currentAppleRow;
}
int board::getCurrentAppleCol(){
  return currentAppleCol;
}
void board::setCol(int newCol){//setter for col same as row
  this->col = newCol;
}
void board::setRow(int newRow){//setter for row this should only be used in the inital setup to scale the baord correctly
  this->row = newRow;
}
void board::setCurrentAppleRow(int newRow){
  this->currentAppleRow = newRow;
}
void board::setCurrentAppleCol(int newCol){
  this->currentAppleCol = newCol;
}
int board::getSpace(){//returns current positon
  int currentRow = getRow();
  int currentCol = getCol();
  return currentRow * currentCol;
}
void board::setSpace(int aRow, int aCol){//sets the given position

}
bool board::getAppleVal(int aCurrentAppleRow, int aCurrentAppleCol){//returns true if apple is at curent position false if not
 //get players next pos after taking the input from the user.
 //make check with the current apple row and col to then return true or false (true apple is in users path or false it is not)
}
