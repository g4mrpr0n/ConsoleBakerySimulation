#pragma once
#include "Meal.h"
//do not touch anything here, it is done and ready for usage

class Pie : public Meal
{
	int flour, butter, sugar, egg, apples;
public:
	Pie():apples(6),butter(2),flour(1),sugar(1),egg(1)
	{}
	int getFlour() const 
	{
		return flour;
	}
	int getButter() const
	{
		return butter;
	}
	int getSugar() const
	{
		return sugar;
	}
	int getEgg() const
	{
		return egg;
	}
	int getApples() const
	{
		return apples;
	}
};

