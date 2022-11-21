#pragma once
#include "Human.h"
#include "Cookie.h"
#include "Pie.h"
#include "Bakery.h"
#include "Economy.h"

class Employee :  public Human, public Cookie, public Pie, public Bakery, public Economy
{
	double salary, yearsExperience;
	enum position {
		Vendor, Baker
	};
public:
	Employee(const Human& h, double salary, double years, position theposition)
		: Human(h.getName(), h.getSurname(), h.getAge(), h.getGender()), salary(salary), yearsExperience(years)
	{
		position p;
		p = theposition;
	}

	void restockIngredients(position pos)
	{
		if (pos == Vendor)
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
			if (ia.apple <= c.apple - 500)
			{
				ia.apple += 500;
				money = money - 500 * applePrice;
			}
		}
	}

	void createCookie()
	{
		Bakery bakery;
		Cookie cookies;
		//creation RNG
		int upperbound = 10;
		double midrange = upperbound / 2 + yearsExperience * 0.5;
		double rangeValue = rand() % 10 + 1;
		
		int flour = cookies.getFlour();
		int butter = cookies.getButter();
		int sugar = cookies.getSugar();
		int egg = cookies.getEgg();
		int chocolate = cookies.getChocolate();
		if (rangeValue > midrange)
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

	void createPie()
	{
		Pie pie;
		Bakery bakery;
		
		//creation RNG
		int upperbound = 10;
		double midrange = upperbound / 2 + yearsExperience * 0.5;
		double rangeValue = rand() % 10 + 1;
		
		int flour = pie.getFlour();
		int butter = pie.getButter();
		int sugar = pie.getSugar();
		int egg = pie.getEgg();
		int apple = pie.getApples();
		
		if (rangeValue > midrange)
		{
			if ((flour <= ia.flour) && (butter <= ia.butter) && (sugar <= ia.sugar) && (egg <= ia.egg) && (apple <= ia.apple))
			{
				bakery.addCookie();
			}
		}
		ia.flour -= flour;
		ia.butter -= butter;
		ia.sugar -= sugar;
		ia.egg -= egg;
		ia.apple -= apple;
	}
};
