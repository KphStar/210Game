#pragma once
#include "Challenge.h"
#include <utility>

class WormholeChallenge : public Challenge {
    std::pair<int,int> exitCoord;
public:
    WormholeChallenge(int exitX, int exitY)
      : exitCoord{exitX, exitY} {}

    void activate(Player& player) override;
};
