#pragma once
#include "Meal.h"

class Pie : public Meal
{
	enum ingredient {
		Apple, Cherry, Pumpkin
	};
	int apples, cherry, pumpkin, butter, flour, sugar, egg;
	struct amount{
		int amountApplePie;
		int amountCherryPie;
		int amountPumpkinPie;
	}a;
public:
	Pie() = default;
	Pie(ingredient ing)
	{
		if (ing == Apple)
		{
			apples = 6;
			butter = 2;
			flour = 1;
			sugar = 1;
			egg = 1;
		}
		else if (ing == Cherry)
		{
			cherry = 4;
			sugar = 1;
			butter = 1;
			egg = 1;
			flour = 1;
		}
		else {
			pumpkin = 1;
			egg = 4;
			sugar = 1;
			butter = 0;
			flour = 3;
		}
	}
	int getApples()
	{
		return apples;
	}
	int getCherry()
	{
		return cherry;
	}
	int getPumpkin()
	{
		return pumpkin;
	}
	int getButter()
	{
		return butter;
	}
	int getFlour()
	{
		return flour;
	}
	int getSugar()
	{
		return sugar;
	}
	int getEgg()
	{
		return egg;
	}
	int getAmountApplePie()
	{
		return a.amountApplePie;
	}
	int getAmountCherryPie()
	{
		return a.amountCherryPie;
	}
	int getAmountPumpkinPie()
	{
		return a.amountPumpkinPie;
	}
	void setAmountApplePie()
	{
		a.amountApplePie++;
	}
	void setAmountCherryPie()
	{
		a.amountCherryPie++;
	}
	void setAmountPumpkinPie()
	{
		a.amountPumpkinPie++;
	}
};

