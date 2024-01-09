#include "Referees.h"




Referees::~Referees() {};

string Referees::displayInfo() const
{
    return SportsPerson::displayInfo()+" "+to_string(yearsExperience)+ " "+to_string(highestDivision);
}





Referees::Referees()
{
    this->highestDivision = 0;
    this->yearsExperience = 0;
}

Referees::Referees(int age, string personnummer, int yearsExperience, int highestDivision, string name):SportsPerson(name, age, personnummer)
{
    this->yearsExperience = yearsExperience;
    this->highestDivision = highestDivision;
}

// Getter for 'yearsExperience'
int Referees::getYearsExperience() const {
    return yearsExperience;
}

// Setter for 'yearsExperience'
void Referees::setYearsExperience(int experience) {
    yearsExperience = experience;
}

// Getter for 'highestDivision'
int Referees::getHighestDivision() const {
    return highestDivision;
}

// Setter for 'highestDivision'
void Referees::setHighestDivision(int division) {
    highestDivision = division;
}


