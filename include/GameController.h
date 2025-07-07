#pragma once
#include "DungeonMap.h"
#include "Player.h"

class GameController {
    DungeonMap map;
    Player player;
    bool isRunning;
    void processInput(char input);
    void gameLoop();
public:
    GameController(int w, int h);
    void start();
};
