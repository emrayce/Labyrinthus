#ifndef GAME_H
#define GAME_H

#include "map.h"

class Game {
    private:
        Map* map;

    public: 
        Game();
        void movePlayer(int line, int col);

        void gameLoop();

};
#endif
