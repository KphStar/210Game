#include "DungeonMap.h"
#include <random>
#include <stack>
#include <utility>
#include <algorithm>
#include <iostream>
#include "WormholeChallenge.h"
#include "TrapChallenge.h"

DungeonMap::DungeonMap(int w, int h)
  : width(w), height(h), grid(h, std::vector<Cell>(w, Cell(0,0,CellType::Wall)))
{
    // initialize cells with coordinates
    for(int y=0; y<height; ++y)
        for(int x=0; x<width; ++x)
            grid[y][x] = Cell(x, y, CellType::Wall);

    generateMaze();
    placeChallenges();
}

void DungeonMap::generateMaze() {
    // Simple randomized DFS maze carving
    std::mt19937 rng(std::random_device{}());
    auto inBounds = [&](int x, int y){
        return x>0 && x<width-1 && y>0 && y<height-1;
    };

    // start at (1,1)
    std::stack<std::pair<int,int>> stk;
    stk.push({1,1});
    grid[1][1].type = CellType::Empty;

    while(!stk.empty()) {
        auto [cx,cy] = stk.top();
        // collect unvisited neighbors two steps away
        std::vector<std::pair<int,int>> neighbors;
        const int dx[4]{2,-2,0,0}, dy[4]{0,0,2,-2};
        for(int i=0;i<4;++i){
            int nx = cx + dx[i], ny = cy + dy[i];
            if(inBounds(nx,ny) && grid[ny][nx].type == CellType::Wall)
                neighbors.emplace_back(nx,ny);
        }

        if(!neighbors.empty()) {
            std::uniform_int_distribution<>dist(0, neighbors.size()-1);
            auto [nx,ny] = neighbors[dist(rng)];
            // knock down wall between
            int wx = (cx+nx)/2, wy = (cy+ny)/2;
            grid[wy][wx].type = CellType::Empty;
            grid[ny][nx].type = CellType::Empty;
            stk.push({nx,ny});
        } else {
            stk.pop();
        }
    }

    std::cout << "Maze generated (" << width << "x" << height << ")\n";

    
}
// return a reference into our grid
Cell& DungeonMap::getCell(int x, int y) {
    return grid[y][x];
}

// placeholder for now — you must fill this in
void DungeonMap::placeChallenges() {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> xDist(1, width - 2);
    std::uniform_int_distribution<int> yDist(1, height - 2);

    const int numWormholes = (width * height) / 30;  // adjust density as you like
    const int numTraps      = (width * height) / 20;

    // Place wormholes
    for (int i = 0; i < numWormholes; ++i) {
        // find a random empty cell for entry
        int ex, ey;
        do {
            ex = xDist(rng);
            ey = yDist(rng);
        } while (grid[ey][ex].type != CellType::Empty);

        // find a random empty cell for exit
        int tx, ty;
        do {
            tx = xDist(rng);
            ty = yDist(rng);
        } while ((tx == ex && ty == ey) || grid[ty][tx].type != CellType::Empty);

        grid[ey][ex].type = CellType::Wormhole;
        grid[ey][ex].challenge = new WormholeChallenge(tx, ty);
    }

    // Place traps
    for (int i = 0; i < numTraps; ++i) {
        int tx, ty;
        do {
            tx = xDist(rng);
            ty = yDist(rng);
        } while (grid[ty][tx].type != CellType::Empty);

        grid[ty][tx].type = CellType::Trap;
        // e.g. each trap does 10 damage
        grid[ty][tx].challenge = new TrapChallenge(10);
    }

    std::cout << "Placed " << numWormholes
              << " wormholes and " << numTraps << " traps.\n";
}