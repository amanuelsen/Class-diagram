#include "Match.h"
#include "Referees.h"


Match::Match(string matchName, int matchDivision,
    string matchDate, string matchStadium, string matchScore)
    : name(matchName), division(matchDivision),
    date(matchDate), stadium(matchStadium), score(matchScore) {
    this->numOfTeams = 0;
    
}
Match::Match() {
    name = "";
    division = 0;
    date = "";
    stadium = "";
    score = "";
    numOfTeams = 0;
}

string Match::displayInfo() const
{
    std::string info = "Match Information:\n";
    info += "Name: " + name + "\n";
    info += "Division: " + std::to_string(division) + "\n";
    info += "Date: " + date + "\n";
    info += "Stadium: " + stadium + "\n";
    info += "Score: " + score + "\n";
    info += "Number of Teams: " + std::to_string(numOfTeams) + "\n";

    // Include team information
   
    

    return info;
}

void Match::addTeam(Team team)
{
    if (numOfTeams < MAX_TEAMS) {
        teams[numOfTeams] =  Team(team);
        numOfTeams++;
    }
    else {
        std::cout << "Cannot add more teams" << std::endl;
    }
}

string Match::getName()
{
    return name;
}

int Match::getDivision()
{
    return division;
}
//
//void Match::addReferee( int age, string personnummer, int yearsExperience, int highestDivision, string name)
//{
//    referee.setName(name);
//    referee.setAge(age);
//    referee.setPersonnummer(personnummer);
//    referee.setYearsExperience(yearsExperience);
//    referee.setHighestDivision(highestDivision);
//}



string Match::getDate()
{
    return date;
}

string Match::getStadium()
{
    return stadium;
}

string Match::getScore()
{
    return score;
}

string Match::getTeams()
{
    return teams[0].getTeamname() + " vs " + teams[1].getTeamname();
}

void Match::setName(string name)
{
    this->name = name;
}

void Match::setDivision(int division)
{
    this->division = division;
}



void Match::setDate(string date)
{
    this->date = date;
}

void Match::setStadium(string score)
{
    this->score = score;
}

void Match::setScore(int numOfTeams)
{
    this->numOfTeams = numOfTeams;
}
