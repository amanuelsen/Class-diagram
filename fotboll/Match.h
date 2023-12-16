#pragma once
#include <iostream>
#include <string>
#include "Footballplayer.h"
#include "player.h"
#include "Team.h"


class Match {
public:
    //abstract function
    virtual void displayMatchInfo() const = 0;
    virtual ~Match() {}
};
