//
// Board.cpp

#include<iostream>
#include "Board.h"
using namespace std;

void Board::setBoardVal(int r, int c, char val) {
    if (r >= 0 && r < row && c >= 0 && c < col)
        grid[r][c] = val;
}

void Board::printBoard() const {
    // Print each col
    char letterVal = 'A';
    cout << "   ";
    for (int c = 0; c < col; ++c) {
        cout << letterVal << "  ";
        letterVal += 1;
    }
    cout << endl;

    // Print each row
    for (int r = 0; r < row; ++r) {
        cout << r + 1 << ' ';
        for (int c = 0; c < col; ++c) {
            cout << "[" << grid[r][c] << "]";
        }
        cout << endl;
    }
}