#pragma once
#include "Human.h"
//it's ok for now

class Customer : public Human
{
	int budget;
	Customer(const Human& h, int budget) :budget(budget), Human(h.getName(), h.getSurname(), h.getAge(), h.getGender())
	{
	}
	int getBudget() const
	{
		return budget;
	}
	void setBudget(int number)
	{
		budget = number;
	}
};
