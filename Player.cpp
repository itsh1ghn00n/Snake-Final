//
// Player.cpp

#include <iostream>
#include "Player.h"
using namespace std;

Player::Player(int startRow, int startCol, int len) : length(len), direction('D'){
    // initialize the snake body to the right
    for (int i = 0; i < length; ++i) {
        body.push_back({startRow, startCol - i});
    }
}

void Player::setDir(char dir) {
    if ((direction == 'W' && dir == 'S') || (direction == 'S' && dir == 'W')) {
        return; // If we try and imediately switch directions, Don't
    } 
    if ((direction == 'A' && dir == 'D') || (direction == 'D' && dir == 'A')) {
        return; // If we try and imediately switch directions, Don't
    }

    direction = dir;
}

void Player::move() {
    
}

void Player::grow(int r, int c) {
    // Append to the vector
    body.push_back({r,c});
    length++;
}