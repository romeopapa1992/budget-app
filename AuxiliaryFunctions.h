#ifndef AUXILIARYFUNCTIONS_H
#define AUXILIARYFUNCTIONS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryFunctions
{
public:
    static char readChar();
    static string readLine();
    static double getDoubleNumber();
    static string convertIntToString(int number);
    static int convertStringToInt(string stringNumber);
    static string convertDoubleToString(double doubleNumber);
    static double convertStringToDouble(string stringNumber);
    static string convertFirstLetterToUppercaseRestLower(string text);
    static string changeCommaToDot(string input);
};

#endif
