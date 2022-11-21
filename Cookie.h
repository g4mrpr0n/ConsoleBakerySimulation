#pragma once
#include "Meal.h"
//do not touch anything here, it is done and ready for usage

class Cookie : public Meal
{
	int flour, butter, sugar, egg, chocolate;
public:
	Cookie():flour(3),butter(1),sugar(2),egg(2),chocolate(2)
	{
	}
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
	int getEgg() const {
		return egg;
	}
	int getChocolate() const
	{
		return chocolate;
	}
};
