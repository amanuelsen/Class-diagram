#include "SportsPerson.h"

SportsPerson::SportsPerson()
{
    name = "";
    age = 0;
    personnummer = "";
}

SportsPerson::SportsPerson(string name, int age, string personnummer)
{
    this->name = name;
    this->age = age;
    this->personnummer = personnummer;
}

string SportsPerson::displayInfo() const
{
	return this->name + " " + to_string(this->age) + " " + this->personnummer;
}

SportsPerson::~SportsPerson()
{
}
std::string SportsPerson::getName() const {
    return name;
}

void SportsPerson::setName(const std::string& newName) {
    name = newName;
}

int SportsPerson::getAge() const {
    return age;
}

void SportsPerson::setAge(int newAge) {
    age = newAge;
}

std::string SportsPerson::getPersonnummer() const {
    return personnummer;
}

void SportsPerson::setPersonnummer(const std::string& newPersonnummer) {
    personnummer = newPersonnummer;
}