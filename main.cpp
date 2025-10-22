#include <iostream>
#include "Board.h"
#include "Player.h" // includes the vector class
#include <chrono> // Temp until we port to arduino
#include <thread> // ^
using namespace std;
//this will be the main runner for the game

void updateBoard(Player player, Board gameBoard) {
    for (int i = 0;i < player.getLen() ; i++) {
        gameBoard.setBoardVal(player.getX(i), player.getY(i), '1');
    }
}

int main() {
    int row = 5;
    int col = 5;
    Board gameBoard(row, col);
    Player player(3, 3, 3);

    bool winCond = false;
    gameBoard.printBoard();
    //gameBoard.setBoardVal(2, 3, '1');

    // Check for apple at pos (2, 3)
    if (gameBoard.getBoardVal(2, 3) == '*');
    // do something

    while (winCond == false) {
        // clear the screen
        gameBoard.printBoard(); // then update
        updateBoard(player, gameBoard);
        // Game Runs
        //player.setDir('D'); Need to add a way to grab input and we should be solid
        player.move();
        if (row * col == player.getLen()) {
            // Player Wins
            winCond = true;
            cout << "You win!" << endl;
            return 0;
        }
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}
