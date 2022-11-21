#pragma once
#include "Universe.h"
//ok for now

class Economy : public Universe 
{
public:
	double money, profit, loss;
	const double sugarPrice = 1, eggPrice = 1, flourPrice = 1.5, butterPrice = 0.5, chocolatePrice = 2, applePrice = 0.5;
	const double cookiePrice = 50, piePrice = 70;
	Economy() :money(20000), profit(0), loss(0) {
	}
};