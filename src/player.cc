#include "player.h"
#include <cstddef>
#include <iostream>

using namespace std;

Player::Player(size_t x, size_t y) {
    posX = x;
    posY = y;
}

void Player::display() {
    cout << "Player: pos_x: " << posX << ", pos_y: " << posY << endl;
}

void Player::move(size_t x, size_t y) {
    posX = x;
    posY = y;
}
