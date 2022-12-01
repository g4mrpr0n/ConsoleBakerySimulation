#pragma once

class Economy
{
public:
	double money, profit, loss;
	const double sugarPrice = 1, eggPrice = 1, flourPrice = 1.5, butterPrice = 0.5, chocolatePrice = 2;
	const double cookiePrice = 50;
	Economy() :money(50000), profit(0), loss(0) {
	}
};