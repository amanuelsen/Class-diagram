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
    std::string name;

public:
    Referees(std::string name = "anonym");
    virtual ~Referees();
    string displayInfo()const override;
    std::string getRefName();
    void setRefName(std::string refName);
};
