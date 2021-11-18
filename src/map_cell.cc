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
    cout << path << endl;
    createMap(path);
}

void MapCell::display() {
    //clear screen and set cursor to row1 col1
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

bool MapCell::isPositionValid(size_t line, size_t col) {
    if (line >= WIDTH || col >= LENGTH) {
        return false;
    }
    if (map[line][col] == '#') {
        return false;
    }
    
    return true;
}

// return false if an error occured
// true otherwise
bool MapCell::createMap(string path) {
    ifstream cell(path);

    size_t row = 0;

    while (cell.good() && row < 22) {
        string line = "";

        getline(cell, line);

        if (row == 0 || row == 1) {
            row++;
            continue;
        }

        if (line.size() != 55)
        {
            cout << "file: " << path <<  " | row: " << row << " | line size: " << line.size() << endl;
            return false;
        }

        fillRow(line, row);
        row++;
    }

    return row == 21;
}

void MapCell::fillRow(string line, size_t row) {
    for (size_t i = 0; i < line.size(); i++) {
       map[row][i] = line[i];
    }
}

void MapCell::setChar(size_t row, size_t col, char c) {
    if (row >= 0 && row < WIDTH && col >= 0 && col <= LENGTH) {
        map[row][col] = c;
    }
}

char MapCell::getChar(size_t row, size_t col) {
    if (row >= 0 && row < WIDTH && col >= 0 && col <= LENGTH) {
        return map[row][col];
    }

    return 'E';

}
