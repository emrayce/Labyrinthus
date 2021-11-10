#include "map.h"

#include <iostream>
#include <cstddef>
#include <utility>

using namespace std;

void Map::display() {
    //clear screen and set curso to row1 col1
    cout << "\033[2J\033[1;1H";

    string displayed = "";
    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE; j++) {
            displayed+= map[i][j];
        }
        displayed += '\n';
    }

    cout << displayed << endl;
}

bool Map::isPositionValid(size_t line, size_t col) {
    if (line >= SIZE || col >= SIZE) {
        return false;
    }
    if (map[line][col] == '#') {
        return false;
    }
    
    return true;
}

void Map::movePlayer(size_t line, size_t col) {
    map[playerPosition.first][playerPosition.second] = ' ';
    playerPosition.first = line;
    playerPosition.second = col;
    map[playerPosition.first][playerPosition.second] = 'P';
}
