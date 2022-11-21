#pragma once
#include "Institution.h"
#include <vector>
//ok for now

class Bakery : public Institution
{
public:
	struct MenuItem {
		std::string name;
		int price;
	};
	struct Capacity {
		const int sugar = 2000, egg = 2000, flour = 3000, butter = 1500, chocolate = 4000, apple = 6000;
		const int goodsCapacity = 5000;
	}c;
	struct ingredientAmount {
		int sugar = 100, egg = 0, flour = 0, butter = 0, chocolate = 0, apple = 0;
	}ia;
	struct goodsAmount {
		int amountCookies = 0;
		int amountApplePie = 0;
	}am;
private:
	std::vector<MenuItem> items;
public:
	Bakery() = default;
	Bakery(std::string name, std::string location, std::string number, unsigned short int rating)
		: Institution(name, location, number, rating) {}
	Bakery(std::string name, std::string location, std::string number, unsigned short int rating, std::vector<MenuItem> items)
		:Institution(name, location, number, rating), items(items) {}
	MenuItem& operator[](int index)
	{
		if (index > items.size())
		{
			throw "Index out of bounds of array.";
		}
		return items[index];
	}
	void addItem(std::string name, int price)
	{
		items.push_back(MenuItem{ name, price });
	}
	void removeLastItem()
	{
		items.pop_back();
	}
	int getAmountCookie() const
	{
		return am.amountCookies;
	}
	void addCookie()
	{
		am.amountCookies++;
	}
	int getAmountApplePie() const
	{
		return am.amountApplePie;
	}
	void addApplePie()
	{
		am.amountApplePie++;
	}
};
