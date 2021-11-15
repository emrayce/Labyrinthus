#ifndef MAP_CELL_H
#define MAP_CELL_H

#include <cstddef>
#include <utility>
#include <string>

using namespace std;
class MapCell {
    private:
        static const size_t LENGTH = 55;
        static const size_t WIDTH = 20;
        char map[WIDTH][LENGTH];

        pair<size_t, size_t> start;
        pair<size_t, size_t> end;
        pair<size_t, size_t> playerPosition;

        bool createMap(string path);
        void fillRow(string line, size_t row);


    public:
        MapCell(string path);

        void display();

        // check if the given position is valid
        // valid position are:
        //      cells inside SIZE range
        //      empty cell
        bool isPositionValid(size_t line, size_t col);

        pair<size_t, size_t> getStartPosition() { return start; };
        pair<size_t, size_t> getEndPosition() { return end; }
        pair<size_t, size_t> getPlayerPosition() {return playerPosition; }

        void movePlayer(size_t line, size_t col);
};


#endif
