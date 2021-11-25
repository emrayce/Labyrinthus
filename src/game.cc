#include "game.h"

#include <cstddef>
#include <utility>
#include <iostream>

using namespace std;

Game::Game(string path) {
    playerMapCell = make_pair(0, 0);
    playerPosition = make_pair(19, 22);

    gameMap = Map(path);

    unitMap = MapCell("Map/unit.map");
    unitMap.setChar(playerPosition.first, playerPosition.second, 'P');
}

bool Game::cellChangeNeeded(size_t row, size_t line) {
    return row >= WIDTH || line >= LENGTH;
}


void Game::movePlayer(int row, int col) {
    size_t newPosX = playerPosition.first + row;
    size_t newPosY = playerPosition.second + col;

    MapCell cell = gameMap.getCell(playerMapCell.first, playerMapCell.second);

    if (cellChangeNeeded(newPosX, newPosY)) {
        unitMap.setChar(playerPosition.first, playerPosition.second, ' ');
        changeMap();
        setIndexPlayerOnNewCell();
    }

    else if (cell.isPositionValid(newPosX, newPosY)) {
        unitMap.setChar(playerPosition.first, playerPosition.second, ' ');

        playerPosition.first = newPosX;
        playerPosition.second = newPosY;

        unitMap.setChar(playerPosition.first, playerPosition.second, 'P');
    }

    unitMap.setChar(playerPosition.first, playerPosition.second, 'P');
}

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
