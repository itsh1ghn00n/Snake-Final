#ifndef Player_h
#define Player_h
#include <vector>

class Player {
private:
    int length;
    char direction;
    std::vector<std::pair<int, int>> body;
    // "W" "A" "S" "D"
public:
    // Sets pos to (startx, starty) length = (len), and dir = ("D")
    Player(int startx, int starty, int len) {
        length = len;
        direction = 'D';

        for (int i = 0; i < length; ++i) {
            body.push_back({startx, starty}); // if len is 3 we make 3 copies in the vector of this pos
        }
    }

    // Getters
    int getLen() const;
    char getDir() const;
    int getX(int index);
    int getY(int index);
    std::pair<int, int> getPos(int index);

    // Setters / Actions
    void setLength(int val);
    void setDir(char newDir);
    void move();
    void grow();

};

#endif