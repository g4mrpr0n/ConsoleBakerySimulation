#pragma once
#include "Human.h"
//it's ok for now

class Customer : public Human
{
	int budget;
	Customer(std::string name, std::string surname, unsigned short int age, bool gender, int budget) 
	:budget(budget), Human(name,surname,age,gender)
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
