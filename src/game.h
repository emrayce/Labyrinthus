#ifndef GAME_H
#define GAME_H

#include "map_cell.h"
#include "map.h"

#include <utility>

using namespace std;

class Game {
    private:
        static const size_t LENGTH = 55;
        static const size_t WIDTH = 20;

        Map gameMap;               // Entire map of the game

        // Map where player and pnj move
        MapCell unitMap;

        // Get The player position on unitMap
        pair<size_t, size_t> playerPosition;
        // Get the cell index on the GameMap
        pair<size_t, size_t> playerMapCell;

        void changeMap(size_t row, size_t line);
        void setIndexPlayerOnNewCell();
        bool cellChangeNeeded(size_t x, size_t y);

    public: 
        Game(string path);
        // move the player in his MapCell
        void movePlayer(int line, int col);

        void gameLoop();

        // Display the map and the units
        void display();

};
#endif
