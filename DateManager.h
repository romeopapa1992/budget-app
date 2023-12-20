#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <iostream>
#include <sstream>
//#include <windows.h>
#include <ctime>

#include "AuxiliaryFunctions.h"

using namespace std;

class DateManager
{
    //int ;
    int dateInteger = 0, year = 0, month = 0, day = 0;
    //string dateString = "";
    string dateString = "", yearString = "", monthString = "", dayString = "";

public:
    /*Date(int dateInteger = 0, int year = 0, int month = 0, int day = 0, string dateString = "", string yearString = "", string monthString = "", string dayString = "")
    {
        this->dateInteger = dateInteger;
        this->year = year;
        this->month = month;
        this->day = day;
        this->dateString = dateString;
        this->yearString = yearString;
        this->monthString = monthString;
        this->dayString = dayString;
    };*/
    int getDateInteger();
    string getDateString();
    int changeDateToIntNumber(string sdate);
    string changeDateToString(int date);
    string getTodaysDateFromSystem();
    void enterDateOfOperation();
    string createDate();
    bool ifLeapYear(int year);
    bool ifDateHaveCorrectBeginning();
    bool ifDateCorrect();
};

#endif
