#ifndef Player_h
#define Player_h
#include <vector>
using namespace std;

class Player {
private:
    int length;
    char direction;
    vector<pair<int, int>> body;
    // "W" "A" "S" "D"
public:
    // Sets pos to (startx, starty) length = (len), and dir = ("D")
    Player(int startx, int starty, int len);

    int getLen();

    char getDir();
    
    vector<pair<int, int>> getPos();
    // Gets the body at index's x
    int getX(int index);
    // Gets the body at index's y 
    int getY(int index);
    // Change the direction
    void setDir(char ); //will be new dir for the char
    // Move the player's position
    void move();
    // Add's to the end of the vector
    void grow();
};

#endif