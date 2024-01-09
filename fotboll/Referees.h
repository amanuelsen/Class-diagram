#pragma once
#include<iostream>
#include <string>
#include "Footballmatch.h"
#include "Match.h"
#include "player.h"
#include "Match.h"
#include "SportsPerson.h"
using namespace std;
#pragma once
#include <iostream>
#include <string>

class Referees:public SportsPerson {
private:
    int yearsExperience;
    int highestDivision;



    
public:
    Referees();
    
    Referees(int age, string personnummer, int yearsExperience, int highestDivision, string name = "anonym");
    int getYearsExperience() const;
    void setYearsExperience(int experience);
    int getHighestDivision() const;
    void setHighestDivision(int division);
    virtual ~Referees();
    string displayInfo()const override;
  
};
