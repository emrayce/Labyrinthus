#ifndef MAP_H
#define MAP_H
#include "map_cell.h"

#include <cstddef>
#include <string>

using namespace std;

// A Map that contains severa MapCell;
class Map {
    private:
        static const size_t LENGTH = 2;
        static const size_t WIDTH = 2;

        array<MapCell, LENGTH * WIDTH> map;                     // The entire map of the game

        pair<size_t,size_t> getIndexFromFile(string path);      // Get the index of a cell from its file

    public:
        Map();
        Map(string path);

        MapCell getCell(size_t row, size_t col) { return map.at(row * LENGTH + col); }
};

#endif
