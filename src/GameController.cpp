#include "GameController.h"
#include "Challenge.h" 
#include <iostream>

GameController::GameController(int w, int h)
  : map(w,h), player(1,1), isRunning(true)
{}

void GameController::start() {
    std::cout << "Welcome to Dungeon Explorer!\n";
    gameLoop();
}

void GameController::processInput(char input) {
    // WASD movement
    int dx=0, dy=0;
    switch(std::tolower(input)) {
        case 'w': dy = -1; break;
        case 's': dy = +1; break;
        case 'a': dx = -1; break;
        case 'd': dx = +1; break;
        case 'q': isRunning = false; return;
        default:
            std::cout << "Invalid command. Use WASD to move, Q to quit.\n";
            return;
    }

    player.move(dx, dy);
    Cell& c = map.getCell(player.x, player.y);
    if(c.challenge) {
        c.challenge->activate(player);
        // optionally remove one‐time traps
        if(c.type == CellType::Trap)
            c.challenge = nullptr;
    }
}

void GameController::gameLoop() {
    while(isRunning && player.health > 0) {
        // render a simple viewport around the player
        for(int y = player.y-2; y <= player.y+2; ++y) {
            for(int x = player.x-2; x <= player.x+2; ++x) {
                if(x==player.x && y==player.y) {
                    std::cout << 'P';
                } else if(x>=0 && x<map.getWidth()
                       && y>=0 && y<map.getHeight()) {
                    auto& cell = map.getCell(x,y);
                    char ch = (cell.type==CellType::Wall ? '#' : '.');
                    std::cout << ch;
                } else {
                    std::cout << ' ';
                }
            }
            std::cout << "\n";
        }

        std::cout << "\nHealth: " << player.health
                  << "  Score: " << player.score << "\n";
        std::cout << "Move (WASD), Q to quit: ";

        char cmd;
        std::cin >> cmd;
        processInput(cmd);
        std::cout << "\n";
    }

    if(player.health <= 0)
        std::cout << "You have perished in the dungeon...\n";
    else
        std::cout << "Goodbye, adventurer.\n";
}
