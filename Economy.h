#pragma once

class Economy
{
public:
	double money, profit, loss, initialBudget=20000;
	const double sugarPrice = 1, eggPrice = 1, flourPrice = 1.5, butterPrice = 0.5, chocolatePrice = 2;
	Economy() :profit(0), loss(0) {
		money = initialBudget;
	}
};