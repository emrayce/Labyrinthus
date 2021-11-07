#ifndef PLAYER_H
#define PLAYER_H

#include <cstddef>

class Player {
    private:
        size_t pos_x;
        size_t pos_y;

    public:
        Player(size_t x, size_t y);

        void display();

};
#endif
