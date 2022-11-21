#pragma once
#include <string>
#include "Universe.h"
//do not touch anything here, it is done and ready for usage

class Meal : public Universe 
{
	enum types {
		Pastry,
		Pies
	}mealtype;
	struct nutrients {
		int protein, fat, carbs;
	}nutr;
	int calories;
public:
	Meal() = default;
	Meal(types mealtype) {
		if (mealtype == Pies)
		{
			nutrients nr;
			nr.protein = 2;
			nr.fat = 15;
			nr.carbs = 47;
			calories = 320;
		}
		else {
			nutrients nr;
			nr.fat = 12;
			nr.protein = 3;
			nr.carbs = 23;
			calories = 194;
		}
	}
	int getProtein() const
	{
		return nutr.protein;
	}
	int getCarbs() const
	{
		return nutr.carbs;
	}
	int getFat() const
	{
		return nutr.fat;
	}
	int getCalories() const
	{
		return calories;
	}
	types getType() const
	{
		return mealtype;
	}
};
