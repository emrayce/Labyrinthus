#include <iostream>
#include <utility>
#include "map.h"
#include "player.h"
using namespace std;

int main() {
    Map map;
    map.display();

    auto start = map.getStartPosition();
    Player player(start.first, start.second);
    player.display();

    return 0;

}
