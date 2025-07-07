#pragma once
#include "Player.h"

class Challenge {
public:
    virtual ~Challenge() = default;
    virtual void activate(Player& player) = 0;
};
// The Challenge class is an abstract base class that defines the interface for all challenges in the game.
// It contains a pure virtual function `activate` that takes a reference to a Player object.
// Derived classes will implement this function to define the specific behavior of each challenge.
