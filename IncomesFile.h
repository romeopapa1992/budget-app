#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include "XmlFile.h"
#include "Income.h"

using namespace std;

class IncomesFile : public XmlFile
{
    int lastIncomeId;

    int getLastIncomeIdFromFile();
public:
    IncomesFile(string incomesFilename) : XmlFile(incomesFilename)
    {
        lastIncomeId = getLastIncomeIdFromFile();
    };
    vector<Income> readIncomesOfLoggedUserFromXmlFile(int CURRENT_USER_ID);
    void displayIncome(Income income);
    bool addIncomeToXmlFile(Income income, DataManager dataManager);
    int getLastIncomeId();
};

#endif
