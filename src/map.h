#ifndef MAP_H
#define MAP_H

#include <cstddef>
#include <utility>

class Map {
    private:
        static const size_t SIZE = 10;
        char map[SIZE][SIZE] = {
        {'#','E','#','#','#','#','#','#','#','#'},
        {'#',' ',' ',' ','#','#',' ',' ',' ','#'},
        {'#','#','#',' ','#',' ',' ','#',' ','#'},
        {'#','#','#',' ',' ',' ','#','#',' ','#'},
        {'#','#',' ',' ','#','#','#','#',' ','#'},
        {'#','#','#','#','#','#','#',' ',' ','#'},
        {'#','#','#','#','#','#','#',' ','#','#'},
        {'#','#','#','#','#',' ',' ',' ','#','#'},
        {'#','#','#',' ',' ',' ','#','#','#','#'},
        {'#','#','#','#','#','S','#','#','#','#'}
    };

        std::pair<size_t, size_t> start = std::make_pair(5, 9);


    public:
        void display();

        // check if the given position is valid
        // valid position are:
        // empty cell
        bool IsPositionValid(size_t x, size_t y);

        std::pair<size_t, size_t> getStartPosition() { return start; };

};


#endif
