#pragma once
#include <string>
#include "Universe.h"
//do not touch anything here, it is done and ready for usage

class Human: public Universe
{
	std::string name, surname;
	unsigned short int age;
	bool gender;
public:
	Human(): name("None"), surname("None"), age(0), gender(0)
	{
	}
	Human(std::string name, std::string surname, unsigned short int age, bool gender)
		: age(age), name(name), surname(surname), gender(gender)
	{
	}
	std::string getName() const
	{
		return name;
	}
	std::string getSurname() const
	{
		return surname;
	}
	unsigned short int getAge() const
	{
		return age;
	}
	bool getGender() const
	{
		return gender;
	}
};