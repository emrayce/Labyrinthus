#include <iostream>
#include "map.h"
#include "player.h"
using namespace std;

int main() {
    Map map;
    map.display();

    Player player(5, 9);
    player.display();

    return 0;

}
