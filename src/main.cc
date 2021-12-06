#include <iostream>
#include "game.h"

using namespace std;

int main() {
    //Iinitialization
    Game game("MapTest/");

    // Run
    game.gameLoop();
    //
   //game.display();

    return 0;
}
