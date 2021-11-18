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

        MapCell map[WIDTH][LENGTH];

        pair<size_t,size_t> getIndexFromFile(string path);

    public:
        Map(string path);

        MapCell getCell(size_t row, size_t col) { return map[row][col]; }
};

#endif
