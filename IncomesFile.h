#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include "XmlFile.h"
#include "Income.h"

using namespace std;

class IncomesFile : public XmlFile
{
    int lastIncomeId;

public:
    IncomesFile(string incomesFilename) : XmlFile(incomesFilename)
    {
        //lastIncomeId = getLastIncomeIdFromFile();
        lastIncomeId = 0;
    };
    vector<Income> readIncomesOfLoggedUserFromXmlFile(int CURRENT_USER_ID);
    void displayIncome(Income income);
    //bool addIncomeToXmlFile(Income income, DataManager dataManager);
    void addIncomeToXmlFile(Income income, DateManager dateManager);
    int getLastIncomeId();
    int getLastIncomeIdFromFile();
};

#endif
