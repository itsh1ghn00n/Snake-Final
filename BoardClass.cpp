//
// Created by Andrew on 10/22/2025.
//
#include "BoardClass.h"

using namespace std;

board::board(int col, int row, int currentAppleRow, int currentAppleCol) : col(col), row(row), grid(col, std::vector<char>(row, '0')) {
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
int board::getSpace(){//returns current positon
  int currentRow = getRow();
  int currentCol = getCol();
  return currentRow * currentCol;
}
bool board::getAppleVal(int aCurrentAppleRow, int aCurrentAppleCol,Player currentPlayer){
  //returns true if apple is at curent position false if not
  //get players next pos after taking the input from the user.
  //make check with the current apple row and col to then return true or false (true apple is in users path or false it is not)
  return false;
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
void board::setBoardVal(int r, int c, char val) {
  if (r >= 0 && r < row && c >= 0 && c < col)
    grid[r][c] = val;
}
void board::setSpace(int aRow, int aCol){//sets the given position

}
void board::printBoard(){
    char letterVal = 'A';
    cout << " "; //This sets the spacing to the correct size
    for (int i = 0; i < row; i++) {
      cout << '[' << letterVal << ']';
      letterVal += 1;
    }
    for (int i = 0; i < row; i++) {
      cout << '\n' << i + 1;
      for (int j = 0; j < col; j++) {
        cout << '[' << grid[i][j] << ']';
      }   // This loop is responsible for printing the value that is currently inside of the boards.
    }   // This loop is used to indent the values
  }

