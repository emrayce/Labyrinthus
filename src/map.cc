#include "map.h"

#include <iostream>
#include <cstddef>
#include <utility>
#include <fstream>

using namespace std;

Map::Map(string path) {
    createMap(path);
    playerPosition = make_pair(5, 14);
    map[5][14] = 'P';
}

void Map::display() {
    //clear screen and set curso to row1 col1
    cout << "\033[2J\033[1;1H";

    string displayed = "";
    for (size_t i = 0; i < WIDTH; i++) {
        for (size_t j = 0; j < LENGTH; j++) {
            displayed+= map[i][j];
        }
        displayed += '\n';
    }

    cout << displayed << endl;
}

bool Map::isPositionValid(size_t line, size_t col) {
    if (line >= WIDTH || col >= LENGTH) {
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

// return false if an error occured
// true otherwise
bool Map::createMap(string path) {
    cout << path;
    ifstream cell(path);

    size_t row = 0;

    while (cell.good() && row < 21) {
        string line = "";

        getline(cell, line);

        if (line.size() != 55)
        {
            cout << line.size() << endl;
            return false;
        }

        fillRow(line, row);
        row++;
    }

    return row == 21;
}

void Map::fillRow(string line, size_t row) {
    for (size_t i = 0; i < line.size(); i++) {
        map[row][i] = line[i];
        cout << line[i];
    }
}
