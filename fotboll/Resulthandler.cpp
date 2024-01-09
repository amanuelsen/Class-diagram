#include "Resulthandler.h"

Resulthandler::Resulthandler(int numofmatch):numOfMatches(0)
{
	maxmatches = numofmatch;
	match = new Match *[maxmatches] {nullptr};
}

Resulthandler::~Resulthandler()
{
	for (int i = 0; i < numOfMatches; i++) {
		delete match[i];
	}
	delete []match;
}

int Resulthandler::getnumOfMatches()
{
	return this->numOfMatches;

}

void Resulthandler::addMatch(Match matchplayed){
	if (numOfMatches < maxmatches) {
		match[numOfMatches] = new Match(matchplayed);
		numOfMatches++;
	}
	else
	{
		cout << "You have addad enough matches";
	}

}



