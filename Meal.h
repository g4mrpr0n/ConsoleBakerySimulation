#pragma once
#include <string>
#include "Universe.h"

class Meal : public Universe
{
	enum types {
		Snacks, 
		Desserts, 
		Pastry, 
		Pies, 
		Stew, 
		Steaks, 
		Baked,
	};
	struct nutrients {
		double protein, fat, carbs;
	};
	double calories;
public:
	Meal() = default;
	Meal(types mealtype) {
		//basic apple pie
		if (mealtype == Pies)
		{
			nutrients nr;
			nr.protein = 2;
			nr.fat = 15;
			nr.carbs = 47;
			calories = 320;
		}
	}
};