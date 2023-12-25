#include "FootballPlayer.h"

FootballPlayer::FootballPlayer(const std::string& playerName, int playerJersey) : name(playerName), jerseyNumber(playerJersey) {}

string FootballPlayer::displayInfo() const {
    std::string temp = " Name: " + name + ", Jersey Number: " + std::to_string(jerseyNumber);
    return temp;
}


