#include <iostream>
#include <fstream>
#include <string.h>
#include <Windows.h>
#include "Bakery.h"
#include "Universe.h"
#include "Economy.h"
#include "Employee.h"
#include "Human.h"
#include "Institution.h"
using namespace std;

void Draw(Bakery bakery);
void Logic(Bakery &bakery, bool& simover, int seconds, Employee employees[]);
void Setup();
ifstream names("lastname.txt");
ifstream surnames("firstname.txt");
string name[20], surname[20];
bool gender[20];
int employeeSeconds = 0, cookieSeconds = 0, restockSeconds = 0, sellSeconds = 0, paySeconds = 0;

int main()
{
    char ch;
    bool simover = 0, runonce = 1;
    int lastupdate=0, seconds;
    printf("Hello and welcome to this stupid Bakery sim that ate my sanity!\n\nPress 1 to Start it, and 2 to exit.\n\n1. Start\n2. Exit\n\n");
    cin >> ch;
    if (ch == 49)
    {
        Universe time;
        Bakery mainbakery("Mnemonic Cookie Bakery", "NewBay", "+66624072002", 0);
        Economy economy;
        Employee employees[100];
        while (!simover)
        {
            if (runonce)
            {
                Setup();
            }
            mainbakery.elapsedTime = (double)(clock() - mainbakery.tStart) / CLOCKS_PER_SEC;
            int seconds = (int)trunc(mainbakery.elapsedTime);
            if ((seconds % 60 == 0) && seconds != 0 && seconds != lastupdate)
            {
                lastupdate = seconds;
                mainbakery.day++;
            }
            Draw(mainbakery);
            Logic(mainbakery, simover, seconds, employees);
        }

    }
    return 0;
}

void Setup()
{
    for (int i = 0; i < 20; i++)
    {
        names >> name[i];
        surnames >> gender[i] >> surname[i];
    }
}

void Draw(Bakery bakery)
{
    Sleep(5);
    system("cls");
    const char* bakeryName = bakery.getName(), * bakeryLocation = bakery.getLocation(), * bakeryNumber = bakery.getNumber();
    unsigned short int bakeryRating = bakery.getRating();
    printf("%s at %s with nr %s and rating %d\n\n", bakeryName, bakeryLocation, bakeryNumber, bakeryRating);
    printf("Time elapsed: %f, Day: %d\n", bakery.elapsedTime, bakery.day);
    printf("Money: %f, Profit: %f, Loss: %f\n\n", bakery.money, bakery.profit, bakery.loss);
    printf("Employees: %d, Vendors: %d, Bakers: %d\n\n", bakery.employeecounter, bakery.vendorCounter, bakery.bakerCounter);
    printf("Current Amount of Cookies: %d\n", bakery.amountCookies);
    printf("Cookies Made: %d\n", bakery.cookiesMade);
    printf("Cookies Sold: %d\n\n", bakery.cookiesSold);
    printf("Customers Satisifed: %d, Refunds: %d\n\n", bakery.customerSatisfied, bakery.refunds);
    printf("Current Amount of Ingredients: \nflour - %d\nsugar - %d\negg - %d\nbutter - %d\nchocolate - %d", bakery.ia.flour, bakery.ia.sugar, bakery.ia.egg, bakery.ia.butter, bakery.ia.chocolate);
}

void Logic(Bakery &bakery, bool& simover, int seconds, Employee employees[])
{
    srand(time(NULL));
    bool needRestock=0;
    if (seconds % 5 == 0 && seconds != 0 && seconds != employeeSeconds && bakery.employeecounter <100)
    {
        if (employees[bakery.employeecounter].employeeHiringRNG())
        {
            employeeSeconds = seconds;
            string pos;
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
            employees[bakery.employeecounter].assign(bakery.employeecounter, name[namerng], surname[surnamerng], rand() % 20 + 20, yearsExperience, gender[surnamerng], 50 + yearsExperience * 25, pos);

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
    if (needRestock && bakery.vendorCounter > 0  || (bakery.vendorCounter > 0 && seconds % 180 == 0 && seconds != 0 && seconds != restockSeconds))
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
    if (bakery.employeecounter > 0 && seconds % 180 == 0 && seconds  != 0  && seconds != paySeconds)
    {
        paySeconds = seconds;
        for (int i = 0; i < bakery.employeecounter; i++)
        {
            bakery.money -= employees[i].getSalary();
            bakery.loss += employees[i].getSalary();
        }
    }
    bakery.profit = bakery.money - bakery.loss - 50000;
    bakery.customerSatisfied = bakery.cookiesSold - bakery.refunds;
    if (bakery.money == 0)
    {
        simover = true;
    }
    if (bakery.customerSatisfied% 100==0)
    {
        int currentRating = bakery.getRating();
        bakery.setRating(currentRating++);
    }
}