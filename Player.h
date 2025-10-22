using namespace std;
#include <vector>
#ifndef Player_h
#define Player_h

class Player {
private:
    int x;
    int y;
    int length;
    char direction;
    vector<pair<int, int>> body;
    // "W" "A" "S" "D"
public:
    Player() : x(0), y(0), length(3), direction('D') { body.push_back({x,y}); }

    Player(int startx, int starty, int len) {}

    int getLen() { return length; }

    char getDir() { return direction; }
    
    vector<pair<int, int>> getPos() { return body; }
    // Change the direction
    void setDir(char newDir) {}
    // Move the player's position
    void move() {}
    // Add's to the end of the vector
    void grow(int r, int c) {}

};

#endif