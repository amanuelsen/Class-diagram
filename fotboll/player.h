#pragma once
#include <iostream>
using namespace std;

const int MAX_PLAYERS_PER_TEAM = 11;
const int MAX_TEAMS = 2;

class Player {
public:
    //abtract functkion
    virtual void displayInfo() const = 0;
    virtual ~Player() {}
};

class FootballPlayer : public Player {
private:
    string name;
    int jerseyNumber;

public:
    FootballPlayer(const string& playerName, int playerJersey) : name(playerName), jerseyNumber(playerJersey) {}

    void displayInfo() const override {
        cout <<  " Name: " << name << ", Jersey Number: " << jerseyNumber << endl;
    }
};

class Team {
private:
    string name;
    FootballPlayer* players[MAX_PLAYERS_PER_TEAM];
    int numOfPlayers;

public:
    Team(const string& teamName) : name(teamName), numOfPlayers(0) {
        for (int i = 0; i < MAX_PLAYERS_PER_TEAM; ++i) {
            players[i] = nullptr; // Initialize all pointers to nullptr
        }
    }
    ~Team() {
        // destructorna
        for (int i = 0; i < numOfPlayers; i++) {
            delete players[i];
        }
    }
    void addPlayer(FootballPlayer* player) {
        if (numOfPlayers < MAX_PLAYERS_PER_TEAM) {
            players[numOfPlayers++] = player;
        }
        else {
            cout << "Team is full" << endl;
        }
    }
    void showallplayers() {
        for (int i = 0; i < numOfPlayers; i++) {
            cout << "Player " << i + 1; players[i]->displayInfo();
        }
    }
    string getname() {
        return name;
    }

 
};

class Match {
public:
    //abstract function
    virtual void displayMatchInfo() const = 0;
    virtual ~Match() {}
};

class FootballMatch : public Match {
private:
    Team* teams[MAX_TEAMS];
    string date;
    string stadium;
    string score;
    int numOfTeams;

public:
    FootballMatch(const string& matchDate, const string& matchStadium, const string& matchScore)
        : date(matchDate), stadium(matchStadium), score(matchScore), numOfTeams(0) {
        for (int i = 0; i < MAX_TEAMS; ++i) {
            teams[i] = nullptr;
        }
    }
    ~FootballMatch() {
        for (int i = 0; i < MAX_TEAMS; i++) {
            delete teams[i];
        }
    }

    void addTeam(Team* team) {
        if (numOfTeams < MAX_TEAMS) {
            teams[numOfTeams++] = team;
        }
    }

    void displayMatchInfo() const override {
        if (numOfTeams == MAX_TEAMS) {
            cout << teams[0]->getname() << " vs " << teams[1]->getname() << endl;
            cout << "Date: " << date << ", Stadium: " << stadium << ", Score: " << score << endl;
       
            teams[0]->showallplayers();
            cout << endl;
            teams[1]->showallplayers();
        }
        else {
            cout << "Match is not fully set" << endl;
        }
    }
};

class Referees {
private:
    string name;

public:
    Referees() {
        this->name = "anonym";
    }
    Referees(string name) : name(name) {}
    virtual ~Referees() {} // Adding a virtual destructor for polymorphic behavior

    string getRefName() {
        return name;
    }

    void setRefName(string refName) {
        this->name = refName;
    }

    virtual string toString() { // Enables dynamic binding
        return name;
    }

};

class MatchRefere : public Referees {
private:
    string matchReferee;

public:
    MatchRefere();
    MatchRefere(string matchReferee) : matchReferee(matchReferee) {}

    string toString() override {
        return matchReferee;
    }
};
