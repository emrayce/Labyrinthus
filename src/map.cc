#include "map.h"
#include <iostream>
#include <cstddef>
#include <utility>

using namespace std;

void Map::display() {
    string displayed = "";
    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE; j++) {
            displayed+= map[i][j];
        }
        displayed += '\n';
    }

    cout << displayed << endl;
}

bool Map::IsPositionValid(size_t x, size_t y) {
    return map[x][y] != '#';
}
