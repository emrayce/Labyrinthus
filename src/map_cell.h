#ifndef MAP_CELL_H
#define MAP_CELL_H

#include <cstddef>
#include <utility>
#include <string>
#include <array>

using namespace std;
class MapCell {
    private:
        static const size_t LENGTH = 55;
        static const size_t WIDTH = 20;
        array<char, WIDTH * LENGTH> map;                // A cell of the great map

        void createMap(string path);            // Create the cell from file
        void fillRow(string line, size_t row);          // Fill a row of the cell with line


    public:
        MapCell();
        MapCell(string path);

        // check if the given position is valid
        // valid position are:
        //      cells inside SIZE range
        //      empty cell
        bool isPositionValid(size_t row, size_t col);

        void setChar(size_t row, size_t col, char c);       // Set the char at index [row][col]
        char getChar(size_t row, size_t col);               // Get the char at index [row][col]

};
#endif
