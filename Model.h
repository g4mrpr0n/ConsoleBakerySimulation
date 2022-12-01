#pragma once
#include "Employee.h"
#include "Bakery.h"
#include <random>
#include <string.h>

class Model : public Bakery, public Employee
{
    int employeeSeconds = 0, cookieSeconds = 0, restockSeconds = 0, sellSeconds = 0, paySeconds = 0;
public:
    void Logic(Bakery& bakery, bool& simover, int seconds, Employee employees[], std::string name[], std::string surname[], bool gender[])
    {
        srand(time(NULL));
        bool needRestock = 0;
        if (seconds % 5 == 0 && seconds != 0 && seconds != employeeSeconds && bakery.employeecounter < 50)
        {
            if (employees[bakery.employeecounter].scaledRNG(0,10,5,bakery.employeecounter * (-1), 0.05))
            {
                employeeSeconds = seconds;
                std::string pos;
                int namerng = rand() % 20;
                int surnamerng = rand() % 20;
                int positionrng = rand() % 2;
                if (positionrng == 1)
                {
                    pos = "Vendor";
                    bakery.vendor[bakery.vendorCounter] = bakery.employeecounter;
                    bakery.vendorCounter++;
                }
                else {
                    pos = "Baker";
                    bakery.baker[bakery.bakerCounter] = bakery.employeecounter;
                    bakery.bakerCounter++;
                }
                int yearsExperience = rand() % 10 + 1;
                employees[bakery.employeecounter].employ(bakery.employeecounter, name[namerng], surname[surnamerng], rand() % 20 + 20, yearsExperience, gender[surnamerng], 50 + yearsExperience * 25, pos);

                bakery.employeecounter++;
            }
        }
        if (bakery.bakerCounter > 0 && seconds % 3 == 0 && seconds != 0 && seconds != cookieSeconds)
        {
            cookieSeconds = seconds;
            int employeeRNG = rand() % bakery.bakerCounter;
            if (!employees[bakery.baker[employeeRNG] - 1].createCookie(bakery))
            {
                needRestock = true;
            }
        }
        if (needRestock && bakery.vendorCounter > 0 || (bakery.vendorCounter > 0 && seconds % 180 == 0 && seconds != 0 && seconds != restockSeconds))
        {
            restockSeconds = seconds;
            int employeeRNG = rand() % bakery.vendorCounter;
            employees[bakery.vendor[employeeRNG] - 1].restockIngredients(bakery);
            needRestock = 0;
        }
        if (bakery.vendorCounter > 0 && bakery.amountCookies > 0 && seconds % 4 == 0 && seconds != sellSeconds)
        {
            sellSeconds = seconds;
            int employeeRNG = rand() % bakery.vendorCounter;
            employees[bakery.vendor[employeeRNG] - 1].sellCookie(bakery);
        }
        if (bakery.employeecounter > 0 && seconds % 180 == 0 && seconds != 0 && seconds != paySeconds)
        {
            paySeconds = seconds;
            for (int i = 0; i < bakery.employeecounter; i++)
            {
                bakery.money -= employees[i].getSalary();
                bakery.loss += employees[i].getSalary();
            }
        }
        bakery.profit = bakery.money - bakery.loss - bakery.initialBudget;
        bakery.customerSatisfied = bakery.cookiesSold - bakery.refunds;
        if (bakery.money == 0 && seconds != 0)
        {
            simover = true;
        }
        if (bakery.customerSatisfied % 100 == 0)
        {
            int currentRating = bakery.getRating();
            bakery.setRating(currentRating++);
        }
    }
};
