#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <iostream>
#include <sstream>
#include <ctime>

#include "AuxiliaryFunctions.h"

using namespace std;

class DateManager
{
    int dateInteger = 0, year = 0, month = 0, day = 0;
    string dateString = "", yearString = "", monthString = "", dayString = "";

public:
    int getDateInteger();
    string getDateString();
    int changeDateToIntNumber(string dateString);
    string changeDateToString(int dateInteger);
    string createDate();
    string getTodaysDateFromSystem();
    void enterDateOfOperation();
    bool ifLeapYear(int year);
    bool ifDateHaveCorrectBeginning();
    bool ifDateCorrect();
};

#endif
