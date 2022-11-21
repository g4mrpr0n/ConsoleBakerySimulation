#pragma once
#include "Universe.h"

class Economy : public Universe 
{
public:
	int gdp, profit;
	Economy() :gdp(0), profit(0) {

	}
};