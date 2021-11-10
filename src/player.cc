#include "player.h"
#include <cstddef>
#include <iostream>

using namespace std;

Player::Player(size_t x, size_t y) {
    position = make_pair(x, y);
}

void Player::display() {
    cout << "Player: pos_x: " << position.first << ", pos_y: " << position.second << endl;
}

void Player::move(size_t x, size_t y) {
    position.first = x;
    position.second = y;
}
