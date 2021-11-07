#include "player.h"
#include <cstddef>
#include <iostream>

using namespace std;

Player::Player(size_t x, size_t y) {
    pos_x = x;
    pos_y = y;
}

void Player::display() {
    cout << "Player: pos_x: " << pos_x << ", pos_y: " << pos_y << endl;
}
