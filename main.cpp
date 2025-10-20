#include <iostream>
using namespace std;
//this will be the main runner for the game

constexpr int row = 7; //n-1 so this creates a game board of 5 but to access last slot it will be n-1
constexpr int col = 10;
char board[row][col] = {};

void fillBoard(char board[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            board[i][j] = '0';
        }
    }
}

void printBoard(char board[row][col]) {
    // Column Lettering = #Col
    char letterVal = 'A';
    cout << " "; //This sets the spacing to the correct size
    for (int i = 0; i < col; i++) {
        cout << '[' << letterVal << ']';
        letterVal += 1;
    }
    // Row Numbering = #Row
    for (int i = 0; i < row; i++) {
        cout << '\n' << i + 1;
        for (int j = 0; j < col; j++) {
            cout << '[' << board[i][j] << ']';
        }   // This loop is responsible for printing the value that is currently inside of the boards.
    }   // This loop is used to indent the values
}
<<<<<<< Updated upstream

bool checkApple(int row, int col) {
    if (board[row][col] == '*') {
        return true;
        // Apple here
    } else {
        return false;
        // No Apple
=======
bool checkApple(int row, int col) {
    if (board[row][col] == '*') {
        return true; //which means apple is currently at position
>>>>>>> Stashed changes
    }
}

int main() {
<<<<<<< Updated upstream
    char gameBoard[row][col];
    fillBoard(gameBoard);
    printBoard(gameBoard);
    bool winCon = false;
=======
    fillBoard(board);
    printBoard(board);
    bool winCond = false;
>>>>>>> Stashed changes
    int playerLen = 1;
    int playerXval = 0, playerYval = 0; //this is setting the Y and X cords for the game board
    char playerLastInput = 'd'; //this will keep track of players previous input starting going right
    int winLength = row * col;

<<<<<<< Updated upstream
    while (winCon == false) {
        // wincon
        if (row * col == playerLen) {
            winCon = true;
=======
    while (winCond == false) {







        if (winLength == playerLen) {
            winCond = true;
>>>>>>> Stashed changes
        }
    }
    return 0;
}
