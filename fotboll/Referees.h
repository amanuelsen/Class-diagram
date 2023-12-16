#pragma once
#include<iostream>
#include <string>
#include "Footballmatch.h"
#include "Match.h"
#include "player.h"
#include "Match.h"
using namespace std;
#pragma once
#include <iostream>
#include <string>

class Referees {
private:
    std::string name;

public:
    Referees(std::string name = "anonym");
    virtual ~Referees();

    std::string getRefName();
    void setRefName(std::string refName);
    virtual std::string toString();
};
