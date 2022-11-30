#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <string.h>
#include "Bakery.h"
#include "Customer.h"
#include "Universe.h"
#include "Economy.h"
#include "Employee.h"
#include "Human.h"
#include "Institution.h"
using namespace std;


void Draw(Bakery bakery);
void Logic(Bakery bakery, bool &simover, int seconds, Employee employees[]);
ifstream names("lastname.txt");
ifstream surnames("firstname.txt");
string name[20],surname[20];
bool gender[20];


int main()
{
    char ch;
    bool simover = 0, runonce=1;
    int lastupdate, seconds;
    initscr();			
	printw("Hello and welcome to this stupid Bakery sim that ate my sanity!\n\nPress 1 to Start it, and 2 to exit.\n\n1. Start\n2. Exit\n\n");
	refresh();			
    ch = getch();		
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
    endwin();
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
    clear();
    const char *bakeryName=bakery.getName(), *bakeryLocation=bakery.getLocation(),*bakeryNumber=bakery.getNumber();
    unsigned short int bakeryRating=bakery.getRating();
    printw("%s at %s with nr %s and rating %d\n", bakeryName, bakeryLocation, bakeryNumber, bakeryRating);
    printw("Time elapsed: %f, Day: %d\n", bakery.elapsedTime, bakery.day);
    printw("Employees: %d, Vendors: %d, Bakers: %d", bakery.employeecounter, bakery.vendorCounter, bakery.bakerCounter);

    refresh();
    
}

void Logic(Bakery bakery, bool &simover, int seconds, Employee employees[])
{
    int employeeSeconds, cookieSeconds;
    bool createEmployee=0;
    if (seconds % 10 == 0 && seconds != 0 && seconds != employeeSeconds)
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
                bakery.vendor[bakery.vendorCounter] = bakery.vendorCounter;
                bakery.vendorCounter++;
            }
            else {pos = "Baker";
                bakery.bakerCounter++;}
            employees[bakery.employeecounter].assign(name[namerng], surname[surnamerng], rand()%20+20, rand()%10+1, gender[surnamerng], rand() % 1000+1000, pos);
            bakery.employeecounter++;
        }
    }
    if (bakery.bakerCounter > 0 && seconds % 2 == 0 && seconds != 0 && seconds != cookieSeconds)
    {
        
    }
}
