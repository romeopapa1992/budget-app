#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include "Expense.h"
#include "XmlFile.h"
#include "DateManager.h"

using namespace std;

class ExpensesFile : public XmlFile
{
    int lastExpenseId;

public:
    ExpensesFile(string expensesFilename) : XmlFile(expensesFilename)
    {
        lastExpenseId = 0;
    };
    void displayExpense(Expense expense);
    void addExpenseToXmlFile(Expense expense, DateManager dateManager);
    vector<Expense> readExpensesOfLoggedUserFromXmlFile(int CURRENT_USER_ID);
    int getLastExpenseId();
    int getLastExpenseIdFromFile();
};

#endif
