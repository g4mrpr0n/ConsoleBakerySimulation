#pragma once
#include <string>
#include "Human.h"
#include "Cookie.h"
#include "Pie.h"

#include "Bakery.h"

class Employee : public Human, public Cookie, public Pie, public Bakery
{
	double salary, yearsExperience;
	std::string position;
	Employee(const Human& h, double salary, double years, std::string position)
		: Human(h.getName(), h.getSurname(), h.getAge(), h.getGender()), salary(salary), yearsExperience(years), position(position)
	{ }

	void createCookie()
	{
		int upperbound = 10;
		double midrange = upperbound / 2 + yearsExperience * 0.5;
		double rangeValue = rand()%10 + 1;
		Cookie cookies;
		int flour = cookies.getFlour();
		int butter = cookies.getButter();
		int sugar = cookies.getSugar();
		int egg = cookies.getEgg();
		int chocolate = cookies.getChocolate();
		if (rangeValue > midrange)
		{
			if ((flour <= ia.flour) && (butter <= ia.butter) && (sugar <= ia.sugar) && (egg <= ia.egg) && (chocolate <= ia.chocolate))
			{
				cookies.setCookieAmount();
			}
		}
		ia.flour -= flour;
		ia.butter -= butter;
		ia.sugar -= sugar;
		ia.egg -= egg;
		ia.chocolate -= chocolate;
	}
	void createPie()
	{
	}

};
