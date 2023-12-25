#pragma once
#include "player.h"
#include <string>
#include <iostream>

class FootballPlayer : public Player {
private:
    std::string name;
    int jerseyNumber;

public:
    FootballPlayer(const std::string& playerName, int playerJersey);

    string displayInfo() const override;
};
