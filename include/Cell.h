#pragma once

enum class CellType { Empty, Wall, Wormhole, Trap, Item };

struct Cell {
    int x, y;
    CellType type;
    bool visited = false;
    // Pointer to a challenge (wormhole or trap)
    class Challenge* challenge = nullptr;

    Cell(int x_, int y_, CellType t)
      : x(x_), y(y_), type(t) {}
};
