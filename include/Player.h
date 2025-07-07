#pragma once
#include <vector>
#include <string>

class Player {
public:
    int x, y;
    int health;
    int score;
    std::vector<std::string> inventory;

    Player(int startX, int startY);
    void move(int dx, int dy);
};
