//
//  Board.h

#include <iostream>
using namespace std;
#include <vector>
#ifndef Board_h
#define Board_h

class Board {
private:   
    int row;
    int col;
    vector<vector<char>> grid;
public:
    // Default Contructor
    Board() : row(5), col(5), grid(row, vector<char>(col, '0')) {}

    // Parametered Constructor
    Board(int r, int c) : row(r), col(c), grid(row, vector<char>(col, '0')) {}

    char getBoardVal(int r, int c) const { 
        if (r >= 0 && r < row && c >= 0 && c < col)
            return grid[r][c];
        return '?'; // Error val
    }

    void setBoardVal(int row, int col, char val);

    void printBoard() const; 
};

#endif