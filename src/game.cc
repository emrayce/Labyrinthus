#include "game.h"
#include "renderer.h"

#include <cstddef>
#include <utility>
#include <iostream>

using namespace std;

// Constructor of game class
Game::Game(string path) {
    playerMapCell = make_pair(0, 0);                // Choose the firt MapCell of the game
    playerPosition = make_pair(19, 22);             // Choose the initial position of the player

    gameMap = Map(path);                            // Load the map of the game

    unitMap = MapCell("Map/unit.map");              // Load the unitMap

    // Set the player on unitMap
    unitMap.setChar(playerPosition.first, playerPosition.second, 'P');

    // Retrieve the mapCell for the renderer
    MapCell cell = gameMap.getCell(playerMapCell.first, playerMapCell.second);

    renderer.clearScreen();

    renderer.setScreenFromMapCell(cell);            // Fill the renderer with the current cell

    // Set the player on the screen
    renderer.setPlayer(playerPosition.first, playerPosition.second);
    renderer.insertAllLinesToDisplay();
}


// Check if we need to change of MapCell
bool Game::cellChangeNeeded(size_t row, size_t line) {
    return row >= WIDTH || line >= LENGTH;
}


// Move the player on the unitMap
// Change MapCell if needed
// Actualize the renderer to move player on screen too
void Game::movePlayer(int row, int col) {
    // create the theorical new position
    size_t newPosX = playerPosition.first + row;
    size_t newPosY = playerPosition.second + col;

    // get the cell for renderer
    MapCell cell = gameMap.getCell(playerMapCell.first, playerMapCell.second);

    // If we need to change MapCell
    // Find the index ofthe new cell
    // Then find the position of the player on the new cell
    // Set the player on unitMap with the new position
    // Set the pixels corresponding to the player on the renderer
    if (cellChangeNeeded(newPosX, newPosY)) {
        unitMap.setChar(playerPosition.first, playerPosition.second, ' ');

//TODO use something different than playerPosition when sprite on several pixel will be implemented
        renderer.setPixel(playerPosition.first, playerPosition.second, renderer.createPixel(' '));

        changeMap();
        setIndexPlayerOnNewCell();

        renderer.setScreenFromMapCell(gameMap.getCell(playerMapCell.first, playerMapCell.second));

        unitMap.setChar(playerPosition.first, playerPosition.second, 'P');

        renderer.setPlayer(playerPosition.first, playerPosition.second);
        renderer.insertAllLinesToDisplay();
    }


    // Check if the position is valid
    // If it's the case then remove old player's position from unitMap
    // Set up the new position
    // Set the player on the unitMap with the new position
    // Set the player on unitMap with the new position
    // Set the pixels corresponding to the player on the renderer
    else if (cell.isPositionValid(newPosX, newPosY)) {
        unitMap.setChar(playerPosition.first, playerPosition.second, ' ');

//TODO use something different than playerPosition when sprite on several pixel will be implemented
        renderer.setPixel(playerPosition.first, playerPosition.second, renderer.createPixel(' '));

        renderer.insertLineToDisplay(playerPosition.first);

        playerPosition.first = newPosX;
        playerPosition.second = newPosY;

        unitMap.setChar(playerPosition.first, playerPosition.second, 'P');

        renderer.setPlayer(playerPosition.first, playerPosition.second);
        renderer.insertLineToDisplay(playerPosition.first);
    }
}

// Change mapCell according to the previous position of the player
void Game::changeMap() {
    if (playerPosition.first == 0) {
        playerMapCell.first -= 1;
    }
    if (playerPosition.first >= WIDTH - 1) {
        playerMapCell.first += 1;
    }

    if (playerPosition.second == 0) {
        playerMapCell.second -= 1;
    }
    if (playerPosition.second >= LENGTH - 1) {
        playerMapCell.second += 1;
    }
}

// Put the player on the newMap according to its previous position
void Game::setIndexPlayerOnNewCell() {
    if (playerPosition.first == 0) {
        playerPosition.first = WIDTH - 1;
    }
    else if (playerPosition.first == WIDTH - 1) {
        playerPosition.first = 0;
    }

    if (playerPosition.second == 0) {
        playerPosition.second = LENGTH - 1;
    }
    else if (playerPosition.second == LENGTH - 1) {
        playerPosition.second = 0;
    }
}


// the game loop where input are taken and game is played
void Game::gameLoop() {
    bool win = false;
    while (!win) {
        display();
        char input = ' ';

        cin >> input;

        switch (input) {
            case 'w':
                movePlayer(-1, 0);
                break;
            case 's':
                movePlayer(1, 0);
                break;
            case 'a':
                movePlayer(0, -1);
                break;
            case 'd':
                movePlayer(0, 1);
                break;
        }
    }
}

void Game::display() {
    renderer.display();
}
