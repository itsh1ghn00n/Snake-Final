//
// Created by andre on 10/22/2025.
//

#ifndef BOARDCLASS_H
#define BOARDCLASS_H
#include <string>

class board{
  private:
  int col;
  int row;
  public:
    board();
    board(int col, int row);
    int getCol(); //getter for col
    int getRow(); //getter for row
    void setCol(int); //setter for col
    void setRow(int); //setter for row
    int getSpace(); //returns current positon
    void setSpace(int, int); //sets the current position
    bool getAppleVal(int, int); //returns true if apple is at curent position false if not
  };


#endif //BOARDCLASS_H
