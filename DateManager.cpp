#include "DateManager.h"

string DateManager::getDateString()
{
    return dateString;
}

int DateManager::getDateInteger()
{
    return dateInteger;
}

int DateManager::changeDateToIntNumber(string dateString)
{
    string date;
    stringstream ss(dateString);

    getline(ss, yearString, '-');
    getline(ss, monthString, '-');
    getline(ss, dayString);

    date = yearString + monthString + dayString;

    return AuxiliaryFunctions::convertStringToInt(date);
}

string DateManager::changeDateToString(int date)
{
    string dateString = AuxiliaryFunctions::convertIntToString(date);

    dateString.insert(4,"-").insert(7, "-");

    return dateString;
}

string DateManager::getTodaysDateFromSystem()
{
    string dateString;
    time_t t = time(0);
    tm* now = localtime(&t);
    year = now->tm_year + 1900;
    month = now->tm_mon + 1;
    day = now->tm_mday;

    dateString = createDate();

    return dateString;
}

void DateManager::enterDateOfOperation()
{
    char choice;
    cout << "Do you want to use today's date? (Y/N)" << endl;
    while (true)
    {
        choice = AuxiliaryFunctions::readChar();
        if (choice == 'y' || choice == 'n')
        {
            break;
        }
        else
        {
            cout << "Invalid input. Please enter Y or N." << endl;
        }
    }

    if (choice == 'y')
    {
        dateString = getTodaysDateFromSystem();
        dateInteger = changeDateToIntNumber(dateString);
    }
    else
    {
        cout << "Enter date (yyyy-mm-dd): ";
        dateString = AuxiliaryFunctions::readLine();
        dateInteger = changeDateToIntNumber(dateString);
        if (!ifDateCorrect())
        {
            cout << "Invalid date. Please enter the date again." << endl;
            enterDateOfOperation();
        }
    }
}

string DateManager::createDate()
{
    string dateString;

    yearString = AuxiliaryFunctions::convertIntToString(year);
    monthString = AuxiliaryFunctions::convertIntToString(month);
    dayString = AuxiliaryFunctions::convertIntToString(day);

    monthString = (month > 0 && month < 10) ? "0" + monthString : monthString;
    dayString = (day > 0 && day < 10) ? "0" + dayString : dayString;

    dateString = yearString + "-" + monthString + "-" + dayString;

    return dateString;
}

bool DateManager::ifLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool DateManager::ifDateHaveCorrectBeginning()
{
    int minDate = 20000101;
    int maxDate = (changeDateToIntNumber(getTodaysDateFromSystem())/100 + 1) * 100;

    return dateInteger >= minDate && dateInteger < maxDate;
}

bool DateManager::ifDateCorrect()
{
    int year = AuxiliaryFunctions::convertStringToInt(yearString);
    int month = AuxiliaryFunctions::convertStringToInt(monthString);
    int day = AuxiliaryFunctions::convertStringToInt(dayString);

    bool isDateValid = ifDateHaveCorrectBeginning();

    isDateValid &= month >= 1 && month <= 12;
    isDateValid &= day >= 1 && day <= 31;

    if (month == 2)
    {
        isDateValid &= ifLeapYear(year) ? day <= 29 : day <= 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        isDateValid &= day <= 30;
    }

    return isDateValid;
}
