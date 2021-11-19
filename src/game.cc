#include "game.h"

#include <cstddef>
#include <utility>
#include <iostream>

using namespace std;

Game::Game(string path) {
    playerMapCell = make_pair(0, 0);
    playerPosition = make_pair(15, 15);

    gameMap = Map(path);

    unitMap = MapCell("Map/unit.map");
    unitMap.setChar(15, 15, 'P');
}

void Game::movePlayer(int x, int y) {
    size_t newPosX = playerPosition.first + x;
    size_t newPosY = playerPosition.second + y;

    MapCell cell = gameMap.getCell(playerMapCell.first, playerMapCell.second);

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
                cout << "hi?" << endl;
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
    //clear screen and set cursor to row1 col1
    cout << "\033[2J\033[1;1H";

    MapCell cell = gameMap.getCell(playerMapCell.first, playerMapCell.second);
    string displayed = "";

    for (size_t i = 0; i < 20; i++) {
        for (size_t j = 0; j < 55; j++) {
            if (unitMap.getChar(i, j) != ' ') {
                displayed += unitMap.getChar(i,j);
            }
            else {
                displayed += cell.getChar(i, j);
            }
        }
        displayed += '\n';
    }
    cout << displayed << endl;
}
