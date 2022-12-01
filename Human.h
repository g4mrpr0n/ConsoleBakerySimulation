#pragma once
#include <string>
#include "Universe.h"

class Human : public Universe
{
protected:
	std::string familyname, surname;
	unsigned short int age, yearsExperience;
	bool gender;
public:
	Human() = default;
	Human(std::string name, std::string surname, unsigned short int age, unsigned short int yearsExperience, bool gender)
		: age(age), familyname(name), surname(surname), yearsExperience(yearsExperience), gender(gender)
	{
	}
};