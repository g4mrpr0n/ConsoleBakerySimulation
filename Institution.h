#pragma once
#include <string>
#include "Universe.h"
//do not touch anything here, it is done and ready for usage

class Institution : public Universe
{
	const char* name, *location, *number;
	unsigned short int rating;
protected:
	void setName(const char name[])
	{
		this->name = name;
	}
	void setLocation(const char location[])
	{
		this->location = location;
	}
	void setNumber(const char number[])
	{
		this->number = number;
	}
	void setRating(unsigned short int rating)
	{
		this->rating = rating;
	}
public:
	Institution() = default;

	Institution(const char name[], const char location[], const char number[], unsigned short int rating)
		: name(name), location(location), number(number), rating(rating)
	{
	}
	const char *getName() const
	{
		return name;
	}
	const char *getLocation() const
	{
		return location;
	}
	const char *getNumber() const
	{
		return number;
	}
	unsigned short getRating() const
	{
		return rating;
	}
};
