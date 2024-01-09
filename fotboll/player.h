#pragma once
#include "SportsPerson.h"
#include <iostream>
using namespace std;




class Player: public SportsPerson {
    private:

        int position;
        int jerseyNr;
        int goalsScored;
        

public:
    Player(string name, int age, string personnummer, int position, int jerseyNr, int goalsScored);
    //abtract functkion
    string displayInfo() const  override;
    virtual ~Player() {}

    int getPosition();
    int getJerseyNr();
    int getGoalsScored();

    void setPosition(int position);
    void setJerseyNr(int jerseyNr);
    void setGoalsScored(int goalsScored);
};

//class FootballPlayer : public Player {
//private:
//    string name;
//    int jerseyNumber;
//
//public:
//    FootballPlayer(const string& playerName, int playerJersey) : name(playerName), jerseyNumber(playerJersey) {}
//
//    void displayInfo() const override {
//        cout <<  " Name: " << name << ", Jersey Number: " << jerseyNumber << endl;
//    }
//    string getanameandnum() {
//        string temp = " Name: " + name + ", Jersey Number: " + to_string(jerseyNumber);
//        return temp;
//         
//    }
//};
//
//class Team {
//private:
//    string name;
//    FootballPlayer* players[MAX_PLAYERS_PER_TEAM];
//    int numOfPlayers;
//
//public:
//    Team(const string& teamName) : name(teamName), numOfPlayers(0) {
//        for (int i = 0; i < MAX_PLAYERS_PER_TEAM; ++i) {
//            players[i] = nullptr; // Initialize all pointers to nullptr
//        }
//    }
//    ~Team() {
//        // destructorna
//        for (int i = 0; i < numOfPlayers; i++) {
//            delete players[i];
//        }
//    }
//    void addPlayer(FootballPlayer* player) {
//        if (numOfPlayers < MAX_PLAYERS_PER_TEAM) {
//            players[numOfPlayers++] = new FootballPlayer(*player);
//        }
//        else {
//            cout << "Team is full" << endl;
//        }
//    }
//    void showallplayers() {
//        for (int i = 0; i < numOfPlayers; i++) {
//            cout << "Player " << i + 1; players[i]->displayInfo();
//        }
//    }
//    string returnallpayer() {
//        string temp;
//        if (numOfPlayers == 0) {
//            return "Inga spelare angivna;";
//        }
//        else {
//            temp = "";
//            for (int i = 0; i < numOfPlayers; i++) {
//                temp += "Player " + to_string(i + 1) + players[i]->getanameandnum() + "\n";
//            }
//            return temp;
//        }
//        
//    }
//    string getname() {
//        return name;
//    }
//
// 
//};
//
//class Match {
//public:
//    //abstract function
//    virtual void displayMatchInfo() const = 0;
//    virtual ~Match() {}
//};
//
//class FootballMatch : public Match {
//private:
//    Team* teams[MAX_TEAMS];
//    string date;
//    string stadium;
//    string score;
//    int numOfTeams;
//
//public:
//    FootballMatch(const string& matchDate, const string& matchStadium, const string& matchScore)
//        : date(matchDate), stadium(matchStadium), score(matchScore), numOfTeams(0) {
//        for (int i = 0; i < MAX_TEAMS; ++i) {
//            teams[i] = nullptr;
//        }
//    }
//    ~FootballMatch() {
//        for (int i = 0; i < MAX_TEAMS; i++) {
//            delete teams[i];
//        }
//    }
//
//    void addTeam(Team* team) {
//        if (numOfTeams < MAX_TEAMS) {
//            teams[numOfTeams++] = new Team(*team);
//        }
//        else
//        {
//            cout << "Cannot add more teams" << endl;
//        }
//    }
//    string homevsaway() {
//        return teams[0]->getname() + " vs "+ teams[1]->getname();
//    }
//    string getdate() {
//        return date;
//    }
//    string getscore() {
//        return score;
//
//    }
//    string getstadium() {
//        return stadium;
//    }
//    string gethometemaplayers() {
//        return teams[0]->returnallpayer();
//    }
//    string getawaytemaplayers() {
//        return teams[1]->returnallpayer();
//    }
//    
//    void displayMatchInfo() const override {
//        if (numOfTeams == MAX_TEAMS) {
//            cout << teams[0]->getname() << " vs " << teams[1]->getname() << endl;
//            cout << "Date: " << date << ", Stadium: " << stadium << ", Score: " << score << endl;
//       
//            teams[0]->showallplayers();
//            cout << endl;
//            teams[1]->showallplayers();
//        }
//        else {
//            cout << "Match is not fully set" << endl;
//        }
//    }
//};
//
//class Referees {
//private:
//    string name;
//
//public:
// 
//    Referees(string name="anonym") : name(name) {}
//    virtual ~Referees() {} // Adding a virtual destructor for polymorphic behavior
//
//    string getRefName() {
//        return name;
//    }
//
//    void setRefName(string refName) {
//        this->name = refName;
//    }
//
//    virtual string toString() { // Enables dynamic binding
//        return name;
//    }
//
//};
//
//class MatchRefere : public Referees {
//private:
//    string matchReferee;
//
//public:
//    MatchRefere(string matchReferee) : matchReferee(matchReferee) {}
//
//    string toString() override {
//        return matchReferee;
//    }
//};
