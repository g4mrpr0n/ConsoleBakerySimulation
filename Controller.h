#pragma once
#include <fstream>
#include <iostream>
#include "Model.h"
#include "View.h"

class Controller : public Model, public View
{
public:
    std::string name[20], surname[20];
    bool gender[20];
    Controller()
    {
        std::ifstream names("lastname.txt");
        std::ifstream surnames("firstname.txt");
        for (int i = 0; i < 20; i++)
        {
            names >> name[i];
            surnames >> gender[i] >> surname[i];
        }
    }
    void InitializeSimulation()
    {
        char ch;
        bool simover = 0;
        int lastupdate = 0, seconds;
        printf("Hello and welcome to this stupid Bakery sim that ate my sanity!\n\nPress 1 to Start it, and 2 to exit.\n\n1. Start\n2. Exit\n\n");
        std::cin >> ch;
        if (ch == 49)
        {
            Bakery mainbakery("Mnemonic Cookie Bakery", "NewBay", "+66624072002", 0);
            Employee employees[50];
            while (!simover)
            {
                mainbakery.elapsedTime = (double)(clock() - mainbakery.tStart) / CLOCKS_PER_SEC;
                int seconds = (int)trunc(mainbakery.elapsedTime);
                if ((seconds % 60 == 0) && seconds != 0 && seconds != lastupdate)
                {
                    lastupdate = seconds;
                    mainbakery.day++;
                }
                Draw(mainbakery);
                Logic(mainbakery, simover, seconds, employees, name, surname, gender);
            }
        }
    }
};
