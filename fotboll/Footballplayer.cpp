#include "FootballPlayer.h"

FootballPlayer::FootballPlayer(const std::string& playerName, int playerJersey) : name(playerName), jerseyNumber(playerJersey) {}

void FootballPlayer::displayInfo() const {
    std::cout << " Name: " << name << ", Jersey Number: " << jerseyNumber << std::endl;
}

std::string FootballPlayer::getanameandnum() {
    std::string temp = " Name: " + name + ", Jersey Number: " + std::to_string(jerseyNumber);
    return temp;
}
