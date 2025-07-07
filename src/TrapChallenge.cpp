#include <thread>
#include "TrapChallenge.h"
#include "Player.h"
#include "Logger.h"
#include <iostream>
#include <windows.h>  // for Sleep()
#include <chrono>

extern Logger gameLogger; // assume you have a global or passed‐in logger

void TrapChallenge::activate(Player& player) {
    std::cout << R"(
  _______
 /       \
|  TRAP!  |
 \_______/
)" << "\n";
    // simulate a brief pause for effect
   // std::this_thread::sleep_for(std::chrono::milliseconds(500)); use this for mac
   #ifdef _WIN32
    Sleep(500);  // Windows API sleep in milliseconds
#else
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
#endif

    player.health -= damage;
    std::cout << "You triggered a trap! -" << damage 
              << " health (now " << player.health << ")\n";

    // log the event
    gameLogger.log("Player hit a trap at (" 
        + std::to_string(player.x) + "," 
        + std::to_string(player.y) + 
        "), health now " + std::to_string(player.health));
}
