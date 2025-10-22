//
// Created by andre on 10/22/2025.
//

#include "BoardClass.h"

board::board(){
  }
board::board(int col, int row) {
    this->col = col;
    this->row = row; //setting both vals to a passed int which will be defined in main program
};
int board::getCol(){//getter for col
  return col;
}
int board::getRow(){//getter for row
  return row;
}
void board::setCol(int newCol){//setter for col same as row
  col = newCol;
}

void board::setRow(int newRow){//setter for row this should only be used in the inital setup to scale the baord correctly
  row = newRow;
}
int board::getSpace(){//returns current positon
  int currentRow = getRow();
  int currentCol = getCol();
  return currentRow * currentCol;
}
void board::setSpace(int aRow, int aCol){//sets the current position

}
bool board::getAppleVal(int aRow, int aCol){//returns true if apple is at curent position false if not

}
