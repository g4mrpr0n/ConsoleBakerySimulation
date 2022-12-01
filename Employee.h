#pragma once
#include <random>
#include "Human.h"
#include "Bakery.h"

class Employee : public Human, public Bakery
{
	double salary;
	std::string position;
	int id;

public:
	Employee() = default;

	void assign(int id, std::string name, std::string surname, unsigned short int age, unsigned short int years, bool gender, double salary, std::string theposition)
	{
		this->id = id;
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
		srand(time(NULL));
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

	bool employeeActionRNG()
	{
		srand(time(NULL));
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dist(0, 10);
		int upperbound = 10;
		double midrange = upperbound / 2 + getYearsExperience() * 0.5;
		double rangeValue = dist(gen);
		if (rangeValue < midrange) return true;
		else return false;
	}

	bool refundRNG()
	{
		srand(time(NULL));
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dist(0, 10);
		double midrange = 2 - getYearsExperience() * 0.15;
		double rangeValue = dist(gen);
		if (rangeValue < midrange) return true;
		else return false;
	}

	void restockIngredients(Bakery &b)
	{
		if (b.ia.sugar <= b.c.sugar - 200)
		{
			b.ia.sugar += 200;
			b.money = b.money - 200 * sugarPrice;
			b.loss += 200 * sugarPrice;
		}
		if (b.ia.flour <= b.c.flour - 200)
		{
			b.ia.flour += 200;
			b.money = b.money - 200 * flourPrice;
			b.loss += 200 * flourPrice;
		}
		if (b.ia.egg <= b.c.egg - 200)
		{
			b.ia.egg += 200;
			b.money = b.money - 200 * eggPrice;
			b.loss += 200 * eggPrice;
		}
		if (b.ia.butter <= b.c.butter - 200)
		{
			b.ia.butter += 200;
			b.money = b.money - 200 * butterPrice;
			b.loss += 200 * butterPrice;
		}
		if (b.ia.chocolate <= b.c.chocolate - 200)
		{
			b.ia.chocolate += 200;
			b.money = b.money - 200 * chocolatePrice;
			b.loss += 200 * chocolatePrice;
		}
	}

	bool createCookie(Bakery &bakery)
	{

		int flour = bakery.cookies.flour;
		int butter = bakery.cookies.butter;
		int sugar = bakery.cookies.sugar;
		int egg = bakery.cookies.egg;
		int chocolate = bakery.cookies.chocolate;
		if (employeeActionRNG())
		{
			if ((flour <= bakery.ia.flour) && (butter <= bakery.ia.butter) && (sugar <= bakery.ia.sugar) && (egg <= bakery.ia.egg) && (chocolate <= bakery.ia.chocolate))
			{
				bakery.amountCookies++;
				bakery.cookiesMade++;
			}
		}
		if ((flour <= bakery.ia.flour) && (butter <= bakery.ia.butter) && (sugar <= bakery.ia.sugar) && (egg <= bakery.ia.egg) && (chocolate <= bakery.ia.chocolate))
		{
			bakery.ia.flour -= flour;
			bakery.ia.butter -= butter;
			bakery.ia.sugar -= sugar;
			bakery.ia.egg -= egg;
			bakery.ia.chocolate -= chocolate;
			return true;
		}
		else return false;
	}

	void sellCookie(Bakery &b)
	{
		bool sold = 0;
		if (employeeActionRNG()) {
			b.amountCookies--;
			b.money += cookiePrice + getYearsExperience() * 10;
			b.cookiesSold++;
			sold = 1;
		}
		//refund
		if (refundRNG() && sold == 1)
		{
			b.money -= cookiePrice;
			b.loss += cookiePrice;
			b.refunds++;
		}
	}

	int getID()
	{
		return id;
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
