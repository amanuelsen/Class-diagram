#include "Referees.h"

Referees::Referees(std::string name) : name(name) {}

Referees::~Referees() {}

std::string Referees::getRefName() {
    return name;
}

void Referees::setRefName(std::string refName) {
    this->name = refName;
}

std::string Referees::toString() {
    return name;
}
