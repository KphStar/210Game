#include "Player.h"

Player::Player(int startX, int startY)
  : x(startX), y(startY), health(100), score(0)
{}

void Player::move(int dx, int dy) {
    x += dx;
    y += dy;
    // TODO: add bounds‐checking & collision vs walls
}
