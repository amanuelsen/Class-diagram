#pragma once
#include <string>
#include <iostream>
#include "player.h"
#include "Footballplayer.h"

class Team {
private:
    std::string name;
    FootballPlayer* players[MAX_PLAYERS_PER_TEAM];
    int numOfPlayers;

public:
    Team(const std::string& teamName);
    ~Team();

    void addPlayer(FootballPlayer* player);
    void showallplayers();
    std::string returnallpayer();
    std::string getname();
};
