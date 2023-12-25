#pragma once
#include <iostream>
using namespace std;
class SportsPerson {
public:
	virtual string displayInfo()const = 0;
	virtual ~SportsPerson();
};