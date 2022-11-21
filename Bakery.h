#pragma once
#include "Institution.h"
#include <vector>

class Bakery : public Institution 
{
public:
	struct MenuItem {
		std::string name;
		int price;
	};
    struct ingredientAmount {
		int sugar=0, egg=0, flour=0, butter=0, chocolate=0, milk=0, apple=0, pumpkin=0, cherry=0;
	}ia;
private:
	std::vector<MenuItem> items;
public:
	Bakery() = default;
	Bakery(std::string name, std::string location, std::string number, unsigned short rating)
		: Institution(name, location, number, rating){}
	Bakery(std::string name, std::string location, std::string number, unsigned short rating, std::vector<MenuItem> items)
		:Institution(name,location,number,rating), items(items){}
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
};
