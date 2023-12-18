#include "DataManager.h"

string DataManager::getDateString()
{
    return dateString;
}

int DataManager::getDateInteger()
{
    return dateInteger;
}

int DataManager::changeDateToIntNumber(string sdate)
{
    string date;
    stringstream ss(sdate);

    getline(ss, syear, '-');
    getline(ss, smonth, '-');
    getline(ss, sday);

    date = syear + smonth + sday;

    return AuxiliaryFunctions::convertStringToInt(date);
}

string DataManager::changeDateToString(int date)
{
    string sdate = AuxiliaryFunctions::convertIntToString(date);

    sdate.insert(4,"-");
    sdate.insert(7, "-");

    return sdate;
}

string DataManager::getTodaysDateFromSystem()
{
    string sdate;
    time_t t = time(0);
    tm* now = localtime(&t);
    year = now->tm_year + 1900;
    month = now->tm_mon + 1;
    day = now->tm_mday;

    sdate = createDate();

    return sdate;
}

void DataManager::enterDateOfOperation()
{
    char choice;
    cout << "Do you want to use today's date? (Y/N)" << endl;
    while(true)
    {
        choice = AuxiliaryFunctions::readChar();
        if (isalpha(choice))
        {
            if (tolower(choice)=='y')
            {
                dateString = getTodaysDateFromSystem();
                dateInteger = changeDateToIntNumber(dateString);
                break;
            }
            else if (tolower(choice)=='n')
            {
                cout << "Enter date (yyyy-mm-dd): ";

                while (true)
                {
                    dateString = AuxiliaryFunctions::readLine();
                    dateInteger = changeDateToIntNumber(dateString);
                    if(ifDateCorrect())
                    {
                        break;
                    }
                    else
                        cout << "Date is not valid. Enter the date again." << endl;
                }
                break;
            }
            else
            {
                cout << "There is no such option. Try again.";
                Sleep(1500);
            }
        }
        else
        {
            cout << "It is not a letter. Try again.";
            Sleep(1500);
        }
    }
}

string DataManager::createDate()
{
    string sdate = "";

    syear = AuxiliaryFunctions::convertIntToString(year);
    smonth = AuxiliaryFunctions::convertIntToString(month);
    sday = AuxiliaryFunctions::convertIntToString(day);

    if (month > 0 && month < 10)
        smonth = "0" + smonth;
    if (day > 0 && day < 10)
        sday = "0" + sday;

    sdate = syear + "-" + smonth + "-" + sday;

    return sdate;
}

bool DataManager::ifLeapYear(int year)
{
    if ((year%4==0 && year%100!=0) || year%400==0)
        return true;
    else
        return false;
}

bool DataManager::ifDateHaveCorrectBeginning()
{
    int minDate = 20000101;
    int maxDate = (changeDateToIntNumber(getTodaysDateFromSystem())/100 + 1) * 100;

    if (dateInteger >= minDate && dateInteger < maxDate)
        return true;
    return false;
}

bool DataManager::ifDateCorrect()
{
    int year = AuxiliaryFunctions::convertStringToInt(syear);
    int month = AuxiliaryFunctions::convertStringToInt(smonth);
    int day = AuxiliaryFunctions::convertStringToInt(sday);

    if(ifDateHaveCorrectBeginning())
    {
        if(month < 1 || month > 12)
            return false;

        if(day < 1 || day > 31)
            return false;

        if(month == 2)
        {
            if (ifLeapYear(year))
                return day <= 29;
            else
                return day <= 28;
        }
        if(month == 4 || month == 6 || month == 9 || month == 11)
            return day <= 30;
        return true;
    }
    return false;
}

