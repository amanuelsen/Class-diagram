#include "Referees.h"

Referees::Referees(std::string name) : name(name) {}

Referees::~Referees() {}

string Referees::displayInfo() const
{
    return name;
}

std::string Referees::getRefName() {
    return name;
}

void Referees::setRefName(std::string refName) {
    this->name = refName;
}


