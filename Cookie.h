#pragma once
#include "Meal.h"

class Cookie : public Meal
{
	int flour, butter, sugar, egg, chocolate;
	int amountCookies;
public:
	Cookie()
	{
		flour = 3; butter = 1; sugar = 2; egg = 2; chocolate = 2;
		amountCookies = 0;
	}
	int getFlour()
	{
		return flour;
	}
	int getButter()
	{
		return butter;
	}
	int getSugar()
	{
		return sugar;
	}
	int getEgg() {
		return egg;
	}
	int getChocolate()
	{
		return chocolate;
	}
	int getCookieamount()
	{
		return amountCookies;
	}
	void setCookieAmount()
	{
		amountCookies++;
	}
};

