#include <iostream>
#include <vector>
#include "Board.h"
using namespace std;
//this will be the main runner for the game

bool checkApple(int row, int col) {
    //if (board[row][col] == '*') {
        //return true;
        // Apple here
    //} else {
        //return false;
        // No Apple
    //}
    return true;
}

int main() {
    int row = 7;
    int col = 7;
    Board gameBoard(row, col);

    bool winCon = false;
    fillBoard(board);
    printBoard(board);
    bool winCond = false;
    int playerLen = 1;
    int playerXval = 0, playerYval = 0; //this is setting the Y and X cords for the game board
    char playerLastInput = 'd'; //this will keep track of players previous input starting going right
    int winLength = row * col;

    gameBoard.printBoard();
    gameBoard.setBoardVal(2, 3, '1');

    // Check for apple at pos (2, 3)
    if (gameBoard.getBoardVal(2, 3) == '*');
    // do something

    while (winCon == false) {
        // wincon
        if (row * col == playerLen) {
            winCon = true;
            while (winCond == false) {







                if (winLength == playerLen) {
                    winCond = true;
                }
            }
            return 0;
        }
    }
}
