#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include "Income.h"
#include "XmlFile.h"
#include "DateManager.h"

using namespace std;

class IncomesFile : public XmlFile
{
   int lastIncomeId;

public:
   IncomesFile(string incomesFilename) : XmlFile(incomesFilename)
   {
       lastIncomeId = 0;
   };
   void displayIncome(Income income);
   void addIncomeToXmlFile(Income income, DateManager dateManager);
   vector<Income> readIncomesOfLoggedUserFromXmlFile(int CURRENT_USER_ID);
   int getLastIncomeId();
   int getLastIncomeIdFromFile();
};

#endif
