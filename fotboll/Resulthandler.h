#pragma once
#include "Match.h"

class Resulthandler {
private:
	Match** match;
	int numOfMatches;
	int maxmatches;
public:
	Resulthandler(int numofmatch);
	int gettotalgoals();
	virtual~Resulthandler();
	int getnumOfMatches();
	void addMatch(Match matchplayed);

};
//alla personer , på 