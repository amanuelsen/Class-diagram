#pragma once
#include <iostream>
#include <string>
#include "Footballplayer.h"
#include "player.h"
#include "Team.h"
#include "Referees.h"

class Match {
private:

    Team teams[MAX_TEAMS];
    string name;
    int division;
    string date;
    string stadium;
    string score;
    
    //Referees referee;
    
    int numOfTeams;
public:
    Match();
    Match(string matchName, int matchDivision,
        string matchDate, string matchStadium, string matchScore);
    //abstract function
    string displayInfo() const;  
    virtual ~Match() {}
    void addTeam(Team team);
    int totalgoalforteam();
   
    string getName();
    int getDivision();
   // void addReferee( int age, string personnummer, int yearsExperience, int highestDivision , string name);
	string getDate();
	string getStadium();
	string getScore();
    string getTeams();
    void setName(string name);
    void setDivision(int division);
	void setDate(string date);
	void setStadium(string score);
	void setScore(int numOfTeams);
};
