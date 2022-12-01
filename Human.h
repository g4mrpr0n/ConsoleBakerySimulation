#pragma once
#include <string>
#include "Universe.h"
//do not touch anything here, it is done and ready for usage

class Human: public Universe
{
protected:
	std::string familyname, surname;
	unsigned short int age, yearsExperience;
	bool gender;
public:
	Human(): familyname("None"), surname("None"), age(0), gender(0)
	{
	}
	Human(std::string name, std::string surname, unsigned short int age, unsigned short int yearsExperience, bool gender)
		: age(age), familyname(name), surname(surname), yearsExperience(yearsExperience), gender(gender)
	{
	}
	std::string getFamilyName() const
	{
		return familyname;
	}
	std::string getSurname() const
	{
		return surname;
	}
	unsigned short int getAge() const
	{
		return age;
	}
	unsigned short int getYearsExperience() const
	{
		return yearsExperience;
	}
	bool getGender() const
	{
		return gender;
	}
};