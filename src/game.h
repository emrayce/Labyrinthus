#ifndef GAME_H
#define GAME_H

#include "map_cell.h"

class Game {
    private:
        MapCell* map;

    public: 
        Game(string path);
        void movePlayer(int line, int col);

        void gameLoop();

};
#endif
