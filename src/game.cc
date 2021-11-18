#include "game.h"

#include <cstddef>
#include <utility>
#include <iostream>

using namespace std;

Game::Game(string path) {
    playerMapCell = make_pair(0, 0);
    playerPosition = make_pair(15, 15);
    MapCell cell("MapTest/test00.map");
    gameMap = new Map(path);
    cout << "prout" << endl;
    unitMap = new MapCell("Map/unit.map");
    cout << "fcs" << endl;
    unitMap->setChar(15, 15, 'P');
}

void Game::movePlayer(int x, int y) {
#include "player.h"
    size_t newPosX = playerPosition.first + x;
    size_t newPosY = playerPosition.second + y;

    MapCell cell = gameMap->getCell(playerMapCell.first, playerMapCell.second);

    if (cell.isPositionValid(newPosX, newPosY)) {
        playerPosition.first = newPosX;
        playerPosition.second = newPosY;
    }
}

// the game loop where input are taken and game is played
void Game::gameLoop() {
    display();
    bool win = false;
    while (!win) {
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

        display();
    }
}

void Game::display() {
    MapCell cell = gameMap->getCell(playerMapCell.first, playerMapCell.second);
    string displayed = "";

    for (size_t i = 0; i < 20; i++) {
        for (size_t j = 0; j < 55; j++) {
            if (unitMap->getChar(i, j) != ' ') {
                displayed += unitMap->getChar(i,j);
            }
            else {
                displayed += cell.getChar(i, j);
            }
        }
        displayed += '\n';
    }
}
