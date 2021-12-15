#include "map_cell.h"

#include <iostream>
#include <cstddef>
#include <utility>
#include <fstream>

using namespace std;

MapCell::MapCell() {
}

MapCell::MapCell(string path) {
    createMap(path);
}

bool MapCell::isPositionValid(size_t row, size_t col) {
    if (row >= WIDTH || col >= LENGTH) {
        return false;
    }
    if (map.at(row * LENGTH + col) != ' ') {
        return false;
    }

    return true;
}


// return false if an error occured
// true otherwise
void MapCell::createMap(string path) {
    ifstream cell(path);

    size_t row = 0;

    string line = "";

    // Map file starts with their index on the Great Map of the game
    // so we first need to discard these lines before accesing the map
    getline(cell, line);
    getline(cell, line);

    while (cell.good() && row < WIDTH) {
        getline(cell, line);

        if (line.size() != LENGTH)
        {
            cerr << "ERROR while parsing: " << path << endl <<  "row: " << row
                 << " | line size: " << line.size() << endl;
        }

        fillRow(line, row);
        row++;
    }
}


void MapCell::fillRow(string line, size_t row) {
    for (size_t i = 0; i < line.size(); i++) {
       map.at(row * LENGTH + i) = line[i];
    }
}


void MapCell::setChar(size_t row, size_t col, char c) {
    if (row < WIDTH && col <= LENGTH) {
        map.at(row * LENGTH + col) = c;
    }
}


char MapCell::getChar(size_t row, size_t col) {
    return map.at(row * LENGTH + col);
}
