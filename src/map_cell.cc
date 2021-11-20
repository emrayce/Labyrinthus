#include "map_cell.h"

#include <iostream>
#include <cstddef>
#include <utility>
#include <fstream>

using namespace std;

MapCell::MapCell() {
    /*for (size_t i = 0; i < WIDTH; i++) {
        for (size_t j = 0; j < LENGTH; j++) {
            map[i][j] = ' ';
        }
    }*/
}

MapCell::MapCell(string path) {
    createMap(path);
}

void MapCell::display() {
    //clear screen and set cursor to row1 col1
    cout << "\033[2J\033[1;1H";

    string displayed = "";
    for (size_t i = 0; i < WIDTH; i++) {
        for (size_t j = 0; j < LENGTH; j++) {
            displayed += map.at(i * LENGTH + j);
        }
        displayed += '\n';
    }

    cout << displayed << endl;
}

bool MapCell::isPositionValid(size_t row, size_t col) {
    if (row >= WIDTH || col >= LENGTH) {
        return false;
    }
    if (map.at(row * LENGTH + col) == '#') {
        return false;
    }
    
    return true;
}

// return false if an error occured
// true otherwise
bool MapCell::createMap(string path) {
    ifstream cell(path);

    size_t row = 0;

    string line = "";
    getline(cell, line);
    getline(cell, line);
    while (cell.good() && row < WIDTH) {
        getline(cell, line);

        if (line.size() != 55)
        {
            cout << line << endl;
            cout << "file: " << path <<  " | row: " << row
                 << " | line size: " << line.size() << endl;
            return false;
        }

        fillRow(line, row);
        row++;
    }

    return row == WIDTH;
}

void MapCell::fillRow(string line, size_t row) {
    for (size_t i = 0; i < line.size(); i++) {
       map.at(row * LENGTH + i) = line[i];
    }
}

void MapCell::setChar(size_t row, size_t col, char c) {
    if (row >= 0 && row < WIDTH && col >= 0 && col <= LENGTH) {
        map.at(row * LENGTH + col) = c;
    }
}

char MapCell::getChar(size_t row, size_t col) {
    return map.at(row * LENGTH + col);

    return 'E';
}
