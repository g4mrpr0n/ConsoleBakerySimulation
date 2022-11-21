#pragma once
#include <string>
#include "Universe.h"

class Institution : public Universe
{
	std::string name, location, number;
	unsigned short rating;
public:
	Institution()
	{
		name = number = location = "None";
		rating = 0;
	}
	Institution(std::string name, std::string location, std::string number, unsigned short rating) 
		: name(name), location(location), number(number), rating(rating)
	{
	}	
	std::string getName() const
	{
		return name;
	}
	std::string getLocation() const
	{
		return location;
	}
	std::string getNumber() const
	{
		return number;
	}
	unsigned short getRating() const
	{
		return rating;
	}
    void setName(std::string name)
	{
		this->name = name;
	}
	void setLocation(std::string location)
	{
		this->location = location;
	}
	void setNumber(std::string number)
	{
		this->number = number;
	}
	void setRating(unsigned short rating)
    {
		this->rating = rating;
	}
};
