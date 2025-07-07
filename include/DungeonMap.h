#pragma once
#include <vector>
#include "Cell.h"

class DungeonMap {
    int width, height;
    std::vector<std::vector<Cell>> grid;
    void generateMaze();  // e.g., DFS or Prim’s
public:
    DungeonMap(int w, int h);
    Cell& getCell(int x, int y);
    void placeChallenges();

    int getWidth() const  { return width; }
    int getHeight() const { return height; }

};
