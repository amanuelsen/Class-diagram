#pragma once
#include <string>
#include <iostream>
#include "player.h"
#include "Footballplayer.h"


class Team {
private:
    const int MAX_PLAYERS_PER_TEAM = 11;

        

    string name;
    Player* players[MAX_PLAYERS_PER_TEAM];
    int numOfPlayers;

public:
    
    Team();
    Team(const std::string& teamName);
    virtual~Team();

    void addPlayer(Player* player);
    void showallplayers();
    std::string returnallpayer();
    std::string getTeamname();
};
