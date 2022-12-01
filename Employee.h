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

	void employ(int id, std::string name, std::string surname, unsigned short int age, unsigned short int years, bool gender, double salary, std::string theposition)
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

	bool scaledRNG(int lowerbound, int upperbound, int midvalue, int scaledvalue, int scale)
	{
		srand(time(NULL));
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dist(lowerbound, upperbound);
		double midrange = midvalue + scaledvalue * scale;
		double rangeValue = dist(gen);
		if (rangeValue < midrange)
			return true;
		else return false;
	}

	void Restock(Bakery &b, int amount, int capacity, int price)
	{
		if (amount <= capacity - 200)
		{
			amount += 200;
			b.money -= 200 * price;
			b.loss += 200 * price;
		}
	}

	void restockIngredients(Bakery &b)
	{
		Restock(b, b.ia.sugar, b.c.sugar, b.sugarPrice);
		Restock(b, b.ia.flour, b.c.flour, b.flourPrice);
		Restock(b, b.ia.egg, b.c.egg, b.eggPrice);
		Restock(b, b.ia.butter, b.c.butter, b.butterPrice);
		Restock(b, b.ia.chocolate, b.c.chocolate, b.chocolatePrice);
	}

	bool createCookie(Bakery &bakery)
	{
		int flour = bakery.cookies.flour;
		int butter = bakery.cookies.butter;
		int sugar = bakery.cookies.sugar;
		int egg = bakery.cookies.egg;
		int chocolate = bakery.cookies.chocolate;
		if (scaledRNG(0,10,5,yearsExperience,0.5))
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
		if (scaledRNG(0, 10, 5, yearsExperience, 0.5)) {
			b.amountCookies--;
			b.money += b.cookiePrice + yearsExperience * 10;
			b.cookiesSold++;
			sold = 1;
		}
		//refund
		if (scaledRNG(0,10,2,yearsExperience*(-1),0.15) && sold == 1)
		{
			b.money -= b.cookiePrice;
			b.loss += b.cookiePrice;
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
