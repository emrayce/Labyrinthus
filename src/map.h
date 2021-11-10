#ifndef MAP_H
#define MAP_H

#include <cstddef>
#include <utility>

using namespace std;
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
        {'#','#','#','#','#','P','#','#','#','#'}
    };

        pair<size_t, size_t> start = make_pair(9, 5);
        pair<size_t, size_t> end = make_pair(0, 1);
        pair<size_t, size_t> playerPosition = make_pair(9, 5);


    public:
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
