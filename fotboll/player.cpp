#include "player.h"

Player::Player(string name, int age, string personnummer, int position, int jerseyNr, int goalsScored):SportsPerson(name, age, personnummer)
{

	this->position = position;
	this->jerseyNr = jerseyNr;
	this->goalsScored = goalsScored;

}

string Player::displayInfo() const
{
	return SportsPerson::displayInfo() + " " + to_string(position) + " " + to_string(jerseyNr) + " " + to_string(goalsScored);
}

int Player::getPosition()
{
	return position;
}

int Player::getJerseyNr()
{
	return jerseyNr;
}

int Player::getGoalsScored()
{
	return goalsScored;
}

void Player::setPosition(int position)
{
	this->position = position;
}

void Player::setJerseyNr(int jerseyNr)
{
	this->jerseyNr = jerseyNr;
}

void Player::setGoalsScored(int goalsScored)
{
	this->goalsScored = goalsScored;
}
