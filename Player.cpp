//
// Player.cpp

#include <iostream>
#include "Player.h"
using namespace std;

Player::Player(int startRow, int startCol, int len) : length(len), direction('D'){
    // initialize the snake body at startRow, and startCol
    for (int i = 0; i < length; ++i) {
        body.push_back({startRow, startCol}); // if len is 3 we make 3 copies in the vector of this pos
    }
}

void Player::setDir(char dir) {
    if ((direction == 'W' && dir == 'S') || (direction == 'S' && dir == 'W')) {
        return; // If we try and switch to an opposite direction, return
    } 
    if ((direction == 'A' && dir == 'D') || (direction == 'D' && dir == 'A')) {
        return; // If we try and switch to an opposite direction, return
    }

    // Otherwise we just set to new direction
    direction = dir;
}

void Player::move() {
    // Gets the x & y of the player head
    int newPosx = body.front().first; //Gets the first element, x of the body vector, at the head
    int newPosy = body.front().second; //Gets the second element, y of the body vector, at the head

    // Move head based on current direction
    switch (direction) {
        case 'W': newPosx -= 1; break;
        case 'S': newPosx += 1; break;
        case 'A': newPosy -= 1; break;
        case 'D': newPosy += 1; break;
    }

    // Insert new pos into the player body
    body.insert(body.begin(), {newPosx, newPosy});

    // Get rid of the tail
    body.pop_back();
}

void Player::grow() {
    // Append to the vector
    body.push_back(body.back());
    length++;
}