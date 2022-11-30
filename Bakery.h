#pragma once
#include "Institution.h"
#include <vector>
//ok for now

class Bakery : public Institution
{
public:
	int employeecounter = 0, vendorCounter = 0, bakerCounter = 0, vendor[70], baker[70];
	struct Cookie{
		int flour = 3, butter = 1, sugar = 2, egg = 2, chocolate = 2;
	}cookies;
	struct Capacity {
		const int sugar = 2000, egg = 2000, flour = 3000, butter = 1500, chocolate = 4000;
		const int goodsCapacity = 5000;
	}c;
	struct ingredientAmount {
		int sugar = 200, egg = 200, flour = 300, butter = 150, chocolate = 400;
	}ia;
	struct goodsAmount {
		int amountCookies = 0;
	}am;

	Bakery() = default;
	Bakery(const char *name, const char *location, const char *number, unsigned short int rating)
		: Institution(name, location, number, rating) {}
	
	void addCookie()
	{
		am.amountCookies++;
	}
};
