#include "Team.h"

Team::Team(const std::string& teamName) : name(teamName), numOfPlayers(0) {
    for (int i = 0; i < MAX_PLAYERS_PER_TEAM; ++i) {
        players[i] = nullptr; // Initialize all pointers to nullptr
    }
}

Team::~Team() {
    for (int i = 0; i < numOfPlayers; i++) {
        delete players[i];
    }
}

void Team::addPlayer(FootballPlayer* player) {
    if (numOfPlayers < MAX_PLAYERS_PER_TEAM) {
        players[numOfPlayers++] = new FootballPlayer(*player);
    }
    else {
        std::cout << "Team is full" << std::endl;
    }
}

void Team::showallplayers() {
    for (int i = 0; i < numOfPlayers; i++) {
        std::cout << "Player " << i + 1;
        players[i]->displayInfo();
    }
}

std::string Team::returnallpayer() {
    std::string temp;
    if (numOfPlayers == 0) {
        return "Inga spelare angivna;";
    }
    else {
        temp = "";
        for (int i = 0; i < numOfPlayers; i++) {
            temp += "Player " + std::to_string(i + 1) + players[i]->displayInfo() + "\n";
        }
        return temp;
    }
}

std::string Team::getname() {
    return name;
}
