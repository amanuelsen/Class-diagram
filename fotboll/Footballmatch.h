#pragma once

#include "Footballmatch.h"
#include "Match.h"
#include <string>
#include<iostream>




class FootballMatch : public Match {
private:
    Team* teams[MAX_TEAMS];
    std::string date;
    std::string stadium;
    std::string score;
    int numOfTeams;

public:
    FootballMatch(const std::string& matchDate, const std::string& matchStadium, const std::string& matchScore);
    ~FootballMatch();

    void addTeam(Team* team);
    std::string homevsaway();
    std::string getdate();
    std::string getscore();
    std::string getstadium();
    std::string gethometemaplayers();
    std::string getawaytemaplayers();

    void displayMatchInfo() const override;
};

