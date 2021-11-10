#ifndef PLAYER_H
#define PLAYER_H

#include <cstddef>

class Player {
    private:
        size_t posX;
        size_t posY;

    public:
        Player(size_t x, size_t y);

        void display();

        void move(size_t x, size_t y);

        size_t getPosX() { return posX; }
        size_t getPosY() { return posY; }

};
#endif
