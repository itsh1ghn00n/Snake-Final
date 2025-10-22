using namespace std;
#include <vector>
#ifndef Player_h
#define Player_h

class Player {
private:
    int length;
    char direction;
    vector<pair<int, int>> body;
    // "W" "A" "S" "D"
public:
    // Sets pos to (startx, starty) length = (len), and dir = ("D")
    Player(int startx, int starty, int len) {}

    int getLen() { return length; }

    char getDir() { return direction; }
    
    vector<pair<int, int>> getPos() { return body; }
    // Gets the body at index's x
    int getX(int index) {return body.at(index).first; }
    // Gets the body at index's y 
    int getY(int index) {return body.at(index).second; }
    // Change the direction
    void setDir(char newDir) {}
    // Move the player's position
    void move() {}
    // Add's to the end of the vector
    void grow() {}

};

#endif