#include "WormholeChallenge.h"
#include "Player.h"
#include <iostream>

void WormholeChallenge::activate(Player& player) {
    std::cout << "You step into a glowing wormhole...\n";
    player.x = exitCoord.first;
    player.y = exitCoord.second;
    std::cout << "You emerge at (" << player.x << ", " << player.y << ")!\n";
    // TODO: ASCII animation
}
