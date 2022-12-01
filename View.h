#pragma once
#include <iostream>
#include <Windows.h>
#include "Bakery.h"

class View : public Bakery
{
public:
    void Draw(Bakery bakery)
    {
        Sleep(5);
        system("cls");
        printf("%s at %s with nr %s and rating %d\n\n", bakery.getName(), bakery.getLocation(), bakery.getNumber(), bakery.getRating());
        printf("Time elapsed: %f, Day: %d\n", bakery.elapsedTime, bakery.day);
        printf("Money: %f, Profit: %f, Loss: %f\n\n", bakery.money, bakery.profit, bakery.loss);
        printf("Employees: %d, Vendors: %d, Bakers: %d\n\n", bakery.employeecounter, bakery.vendorCounter, bakery.bakerCounter);
        printf("Current Amount of Cookies: %d\n", bakery.amountCookies);
        printf("Cookies Made: %d\n", bakery.cookiesMade);
        printf("Cookies Sold: %d\n\n", bakery.cookiesSold);
        printf("Customers Satisifed: %d, Refunds: %d\n\n", bakery.customerSatisfied, bakery.refunds);
        printf("Current Amount of Ingredients: \nflour - %d\nsugar - %d\negg - %d\nbutter - %d\nchocolate - %d", bakery.ia.flour, bakery.ia.sugar, bakery.ia.egg, bakery.ia.butter, bakery.ia.chocolate);
    }
};
