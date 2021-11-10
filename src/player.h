#ifndef PLAYER_H
#define PLAYER_H

#include <cstddef>
#include <utility>

using namespace std;

class Player {
    private:
        pair<size_t, size_t> position;

    public:
        Player(size_t x = 0, size_t y = 0);

        void display();

        void move(size_t x, size_t y);

        pair<size_t, size_t> getPosition() { return position; }

};
#endif
