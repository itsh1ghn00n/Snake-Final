using namespace std;
#include <vector>
#ifndef Player_h
#define Player_h

class Player {
private:
    int x;
    int y;
    vector<vector<int>> playerPos;
    char playerVal = '1';
public:
    void addLen(int r, int c) {}
};

#endif