#include <iostream>
#include <vector>
#include "BoardClass.h"
#include "Player.h"
#include <chrono> // Temp until we port to arduino
#include <thread> // ^

using namespace std;
//this will be the main runner for the game

void updateBoard(Player& player, board& gameBoard) {
    for (int i = 0;i < player.getLen() ; i++) {
        cout << "Section at: (" << player.getX(i) << "," << player.getY(i) << ")" << endl;
        gameBoard.setBoardVal(player.getX(i), player.getY(i), '1');
    }
}

int main() {
    int row = 7;
    int col = 7;
    board gameBoard(row, col);
    Player player(3, 3, 3);

    bool winCon = false;
    int winLength = row * col;

    cout << "Length: " << player.getLen() << endl;

    updateBoard(player, gameBoard);
    gameBoard.printBoard();

    player.move();
    player.grow();
    cout << "Length: " << player.getLen() << endl;

    updateBoard(player, gameBoard);
    gameBoard.printBoard();

    // Check for apple at pos (2, 3)
    //if (gameBoard.getBoardVal(2, 3) == '*');
    // do something

    //player.setDir('W'); //Need to add a way to grab input and we should be solid
    while (!winCon) {
        //updateBoard(player, gameBoard);
        //gameBoard.printBoard();
        //player.move();
        // Game Runs
        winCon = true;
        if (row * col == player.getLen()) {
            // Player Wins
            winCon = true;
            cout << "You win!" << endl;
            return 0;
        }
        this_thread::sleep_for(chrono::milliseconds(1000)); // 1 frame per second
    }
    return 0;
}
