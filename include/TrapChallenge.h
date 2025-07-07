#pragma once
#include "Challenge.h"

class TrapChallenge : public Challenge {
    int damage;
public:
    // damage: how many health points to remove
    TrapChallenge(int dmg) : damage(dmg) {}

    void activate(Player& player) override;
};
