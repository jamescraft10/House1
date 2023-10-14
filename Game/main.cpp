#include <iostream>
#include <vector>
#include <conio.h>

class Player {
    public:
    int x;
    int y;
    void Update(std::vector<std::vector<char>> map) {
        map[x][y];
    }
};

int main() {
    Player player;
    player.x = 0;
    player.y = 0;

    std::vector<std::vector<char>> map = {
        {'#','#','#','#','#'},
        {'#',' ',' ',' ','#'},
        {'#',' ',' ',' ','#'},
        {'#',' ',' ',' ','#'},
        {'#','#','#','#','#'}
    };

    while(true) {
        switch(getch()) {
            case 'W':
                player.y += -1;
                player.Update(map);
                break;
        }
    }
}