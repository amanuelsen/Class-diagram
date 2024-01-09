#pragma once
#include <iostream>
#include <string> 
using namespace std;
const int MAX_PLAYERS_PER_TEAM = 11;
const int MAX_TEAMS = 2;

class SportsPerson {
private:
	string name;
	int age;
	string personnummer;

public:
	SportsPerson();
	SportsPerson(string name, int age, string personnummer);
	virtual string displayInfo()const = 0;
	std::string getName() const;
	void setName(const std::string& newName);
	int getAge() const;
	void setAge(int newAge);
	std::string getPersonnummer() const;
	void setPersonnummer(const std::string& newPersonnummer);
	virtual ~SportsPerson();
};