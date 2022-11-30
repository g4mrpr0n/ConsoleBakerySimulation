#pragma once
#include <random>
#include "Human.h"
#include "Bakery.h"
#include "Economy.h"

class Employee :  public Human, public Bakery, public Economy
{
	double salary;
	std::string position;
	
public:
	Employee() = default;

	void assign(std::string name, std::string surname, unsigned short int age, unsigned short int years, bool gender, double salary, std::string theposition)
	{
		this->familyname = name;
        this->surname = surname;
        this->age = age;
        this->yearsExperience = years;
        this->gender = gender;
		this->salary = salary;
		this->position = theposition;
	}

	bool employeeHiringRNG()
	{
		std::random_device rd;	
		std::mt19937 gen(rd());	
		std::uniform_real_distribution<> dist(0, 9.999);
		int upperbound = 10;
		double midrange = upperbound / 2 - employeecounter * 0.05;
		double rangeValue = dist(gen);
		if (rangeValue < midrange)
		return true;
		else return false;
	}

	bool cookieCreationRNG()
	{
		std::random_device rd;	
		std::mt19937 gen(rd());	
		std::uniform_real_distribution<> dist(0, 10);
		int upperbound = 10;
		double midrange = upperbound / 2 + getYearsExperience() * 0.5;
		double rangeValue = dist(gen);
		if (rangeValue < midrange) return true;
		else return false;
	}

	void restockIngredients(std::string pos)
	{
		if (pos == "Vendor")
		{
			if (ia.sugar <= c.sugar - 500)
			{
				ia.sugar += 500;
				money = money - 500 * sugarPrice;
			}
			if (ia.flour <= c.flour - 500)
			{
				ia.flour += 500;
				money = money - 500 * flourPrice;
			}
			if (ia.egg <= c.egg - 500)
			{
				ia.egg += 500;
				money = money - 500 * eggPrice;
			}
			if (ia.butter <= c.butter - 500)
			{
				ia.butter += 500;
				money = money - 500 * butterPrice;
			}
			if (ia.chocolate <= c.chocolate - 500)
			{
				ia.chocolate += 500;
				money = money - 500 * chocolatePrice;
			}
		}
	}

	void createCookie(Bakery bakery)
	{

		int flour = bakery.cookies.flour;
		int butter = bakery.cookies.butter;
		int sugar = bakery.cookies.sugar;
		int egg = bakery.cookies.egg;
		int chocolate = bakery.cookies.chocolate;
		if (cookieCreationRNG)
		{
			if ((flour <= ia.flour) && (butter <= ia.butter) && (sugar <= ia.sugar) && (egg <= ia.egg) && (chocolate <= ia.chocolate))
			{
				bakery.addCookie();
			}
		}
		ia.flour -= flour;
		ia.butter -= butter;
		ia.sugar -= sugar;
		ia.egg -= egg;
		ia.chocolate -= chocolate;
	}
	double getSalary()
	{
		return salary;
	}
	std::string getPosition()
	{
		return position;
	}
};
