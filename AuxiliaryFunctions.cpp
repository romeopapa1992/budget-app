#include "AuxiliaryFunctions.h"

char AuxiliaryFunctions::readChar()
{
    string choice = "";
    char character ={0};

    while (true)
    {
        choice = AuxiliaryFunctions::readLine();
        if (choice.length() == 1)
        {
            character = choice[0];
            break;
        }
        cout << "This is not a single character. Please try again." << endl;
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
    while (true)
    {
        string input = AuxiliaryFunctions::readLine();

        if (input.empty())
        {
            cout << "Input empty. Please try again." << endl;
            continue;
        }
        replace(input.begin(), input.end(), ',', '.');

        bool validInput = true;
        for (size_t i = 0; i < input.length(); ++i)
        {
            if (input[i] == '.')
            {
                continue;
            }

            if (!isdigit(input[i]))
            {
                validInput = false;
                break;
            }
        }

        if (validInput)
        {
            return convertStringToFloat(input);
        }
        else
        {
            cout << "Incorrect input. Try again." << endl;
        }
    }
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
