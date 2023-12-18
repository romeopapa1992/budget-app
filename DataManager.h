#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <iostream>
#include <sstream>
#include <windows.h>
#include <ctime>

#include "AuxiliaryFunctions.h"

using namespace std;

class DataManager
{
    int dateInteger;
    int year, month, day;
    string dateString;
    string syear, smonth, sday;

    string createDate();
    bool ifLeapYear(int year);
    bool ifDateHaveCorrectBeginning();
    bool ifDateCorrect();

public:
    Date(int dateInteger = 0, int year = 0, int month = 0, int day = 0, string dateString = "", string syear = "", string smonth = "", string sday = "")
    {
        this->dateInteger = dateInteger;
        this->year = year;
        this->month = month;
        this->day = day;
        this->dateString = dateString;
        this->syear = syear;
        this->smonth = smonth;
        this->sday = sday;
    }
    int getDateInteger();
    string getDateString();
    int changeDateToIntNumber(string sdate);
    string changeDateToString(int date);
    string getTodaysDateFromSystem();
    void enterDateOfOperation();
};

#endif
