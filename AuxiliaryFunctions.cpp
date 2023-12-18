#include "AuxiliaryFunctions.h"

char AuxiliaryFunctions::readChar()
{
    string choice = "";
    char character ={0};

    while (true)
    {
        getline(cin, choice);

        if (choice.length() == 1)
        {
            character = choice[0];
            break;
        }
        cout << "This is not a single character. Enter the character again." << endl;
    }
    return character;
}

string AuxiliaryFunctions::readLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

float AuxiliaryFunctions::getFloatNumber()
{
    string input = "";
    float number = 0;

    while (true)
    {
        getline(cin, input);
        if (stof(input))
        {
            input = changeCommaToDot(input);
            break;
        }

        cout << "It is not a number. Enter a number again." << endl;
    }
    number = stof(input);
    return number;
}

string AuxiliaryFunctions::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryFunctions::convertStringToInt(string snumber)
{
    int number;
    istringstream iss(snumber);
    iss >> number;
    return number;
}

string AuxiliaryFunctions::convertFloatToString(float fnumber)
{
    ostringstream ss;
    ss << fnumber;
    string str = ss.str();
    return str;
}

float AuxiliaryFunctions::convertStringToFloat(string snumber)
{
    float number;
    istringstream iss(snumber);
    iss >> number;
    return number;
}

string AuxiliaryFunctions::changeCommaToDot(string input)
{
    size_t foundComma = input.find(",");
    if(foundComma != string::npos)
    {
        input.replace(foundComma, 1, ".");
    }
    return input;
}

string AuxiliaryFunctions::convertFirstLetterToUppercaseRestLower(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}
