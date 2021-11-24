#ifndef GAME_H
#define GAME_H

#include "map_cell.h"
#include "map.h"

#include <utility>

using namespace std;

class Game {
    private:
        // Size of a cell
        static const size_t LENGTH = 55;
        static const size_t WIDTH = 20;

        Map gameMap;                                // Entire map of the game
        MapCell unitMap;                            // Map where player and pnj move

        pair<size_t, size_t> playerPosition;        // The player position on unitMap
        pair<size_t, size_t> playerMapCell;         // The index of the cell where the player is


        void changeMap();                           // Change playerMapCell to the cell where the player is heading
        void setIndexPlayerOnNewCell();             // Place the player correctly on the new cell
        bool cellChangeNeeded(size_t row, size_t col);  // Check row and col to know if we need to change cell

    public: 
        Game(string path);
        void movePlayer(int line, int col);         // move the player in his MapCell
        void gameLoop();                            // the loop where the decisions are made

        void display();                             // Display the map and the units


};
#endif
