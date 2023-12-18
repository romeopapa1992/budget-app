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
    static float getFloatNumber();
    static string convertIntToString(int number);
    static int convertStringToInt(string snumber);
    static string convertFloatToString(float fnumber);
    static float convertStringToFloat(string snumber);
    static string changeCommaToDot(string input);
    static string convertFirstLetterToUppercaseRestLower(string text);
};

#endif
