#include <iostream>
#include <fstream>
#include <string.h>
#include "Bakery.h"
#include "Universe.h"
#include "Economy.h"
#include "Employee.h"
#include "Human.h"
#include "Institution.h"
using namespace std;

void Draw(Bakery bakery);
void Logic(Bakery bakery, bool &simover, int seconds, Employee employees[]);
void Setup();
ifstream names("lastname.txt");
ifstream surnames("firstname.txt");
string name[20],surname[20];
bool gender[20];

int main()
{
    char ch;
    bool simover = 0, runonce=1;
    int lastupdate, seconds;
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
            mainbakery.elapsedTime =(double)(clock() - mainbakery.tStart) / CLOCKS_PER_SEC;
            int seconds = (int)trunc(mainbakery.elapsedTime);
            if ((seconds % 60 == 0) && seconds!=0 && seconds != lastupdate) 
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
        names  >> name[i];
        surnames >> gender[i] >> surname[i];
    }
}


void Draw(Bakery bakery)
{
    const char *bakeryName=bakery.getName(), *bakeryLocation=bakery.getLocation(),*bakeryNumber=bakery.getNumber();
    unsigned short int bakeryRating=bakery.getRating();
    printf("%s at %s with nr %s and rating %d\n", bakeryName, bakeryLocation, bakeryNumber, bakeryRating);
    printf("Time elapsed: %f, Day: %d\n", bakery.elapsedTime, bakery.day);
    printf("Money: %f, Profit: %f, Loss: %f\n", bakery.money, bakery.profit, bakery.loss);
    printf("Employees: %d, Vendors: %d, Bakers: %d\n", bakery.employeecounter, bakery.vendorCounter, bakery.bakerCounter);
    printf("Current Amount of Cookies: %d\n", bakery.amountCookies);
    printf("Cookies Made: %d\n", bakery.cookiesMade);
    printf("Cookies Sold: %d\n", bakery.cookiesSold);
    printf("Customers Satisifed: %d, Refunds: %d\n", bakery.customerSatisfied, bakery.refunds);
    printf("Current Amount of Ingredients: \nflour - %d\nsugar - %d\negg - %d\nbutter - %d\nchocolate - %d", bakery.ia.flour, bakery.ia.sugar, bakery.ia.egg, bakery.ia.butter, bakery.ia.chocolate);
    
}

void Logic(Bakery bakery, bool &simover, int seconds, Employee employees[])
{
    int employeeSeconds, cookieSeconds, restockSeconds, sellSeconds, paySeconds;
    bool needRestock;
    if (seconds % 5 == 0 && seconds != 0 && seconds != employeeSeconds)
    {
        if (employees[bakery.employeecounter].employeeHiringRNG())
        {
            employeeSeconds = seconds;
            string pos;
            int namerng = rand() % 20;
            int surnamerng = rand() % 20;
            int positionrng = rand() % 2;
            if (positionrng==1)
            {
                pos = "Vendor";
                bakery.vendor[bakery.vendorCounter] = bakery.employeecounter;
                bakery.vendorCounter++;
            }
            else {pos = "Baker";
                bakery.baker[bakery.bakerCounter] = bakery.employeecounter;
                bakery.bakerCounter++;}
            employees[bakery.employeecounter].assign(bakery.employeecounter,name[namerng], surname[surnamerng], rand()%20+20, rand()%10+1, gender[surnamerng], rand() % 1000+1000, pos);
            
            bakery.employeecounter++;
        }
    }
    if (bakery.bakerCounter > 0 && seconds % 2 == 0 && seconds != 0 && seconds != cookieSeconds)
    {
        cookieSeconds = seconds;
        int employeeRNG = rand() % bakery.bakerCounter;
        if (!employees[bakery.baker[employeeRNG]-1].createCookie(bakery))
        {
            needRestock=true;
        }
        else {
            bakery.cookiesMade++;
        }
    }
    if (needRestock && bakery.vendorCounter > 0 || (bakery.vendorCounter > 0 && seconds % 11 == 0 && seconds != 0 && seconds != restockSeconds))
    {
        
       int employeeRNG = rand() % bakery.vendorCounter; 
       employees[bakery.vendor[employeeRNG]-1].restockIngredients();
    }
    if (bakery.vendorCounter > 0  && bakery.amountCookies > 0 && seconds % 4 == 0 && seconds != sellSeconds)
    {
        sellSeconds = seconds;
        int employeeRNG = rand() % bakery.vendorCounter; 
        employees[bakery.vendor[employeeRNG]-1].sellCookie();
    }
    if (bakery.employeecounter > 0; seconds %20==0 && seconds != 0 && seconds != paySeconds)
    {
        paySeconds = seconds;
        for (int i = 0; i < bakery.employeecounter; i++)
        {
            bakery.money-=employees[i].getSalary();
            bakery.loss+=employees[i].getSalary();
        }
    }
    bakery.profit = bakery.money - bakery.loss;
    bakery.customerSatisfied = bakery.cookiesSold - bakery.refunds;
}
