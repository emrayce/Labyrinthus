#include <iostream>
#include "game.h"

using namespace std;

int main() {
    Game game("Map/test.map");

    game.gameLoop();

    return 0;

}
