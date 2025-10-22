//
// Player.cpp
#include <iostream>
#include "Player.h"

using namespace std;


int Player::getLen() const { return length; }

char Player::getDir() const { return direction; }

std::pair<int, int> Player::getPos(int index) { return body.at(index); }
// Gets the body at index's x
int Player::getX(int index) {return body.at(index).first; }
// Gets the body at index's y 
int Player::getY(int index) {return body.at(index).second; }

void Player::setLength(int val) { length = val; }

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
        case 'W': newPosy -= 1; break;
        case 'S': newPosy += 1; break;
        case 'A': newPosx -= 1; break;
        case 'D': newPosx += 1; break;
    }

    // Insert new pos into the player body
    body.insert(body.begin(), {newPosx, newPosy});

    // Get rid of the tail
    body.pop_back();
}

void Player::grow() {
    // Append to the vector
    body.push_back(body.back());
    length = length + 1;
}

// TODO ANDREW COMMENT [maybe consider making the check for the apple in the next col in here reason being that I can use
// TODO the func to then check with the boards apple checker to see if the next pos is a apple]