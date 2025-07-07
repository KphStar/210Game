#include "GameController.h"
#include "Logger.h"

Logger gameLogger("game.log");   // ← defines the global

int main() {
    const int width = 10, height = 10;
    GameController game(width, height);
    game.start();
    return 0;
}
// The main function initializes the game controller with a specified width and height for the dungeon map.