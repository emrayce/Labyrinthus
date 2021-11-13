#include "game.h"

#include <cstddef>
#include <utility>
#include <iostream>

using namespace std;

Game::Game(string path) {
    map = new Map(path);
}

void Game::movePlayer(int x, int y) {
#include "player.h"
    size_t newPosX = map->getPlayerPosition().first + x;
    size_t newPosY = map->getPlayerPosition().second + y;

    if (map->isPositionValid(newPosX, newPosY)) {
        map->movePlayer(newPosX, newPosY);
    }
}

// the game loop where input are taken and game is played
void Game::gameLoop() {
    map->display();
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

        
        if (map->getPlayerPosition() == map->getEndPosition()) {
            win = true;
            break;
        }

        map->display();
    }

}
