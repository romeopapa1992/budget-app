#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include "XmlFile.h"
#include "Income.h"
#include "Expense.h"

using namespace std;

class ExpensesFile : public XmlFile
{
    int lastExpenseId;

public:
    ExpensesFile(string expensesFilename) : XmlFile(expensesFilename)
    {
        lastExpenseId = 0;
    };
    vector<Expense> readExpensesOfLoggedUserFromXmlFile(int CURRENT_USER_ID);
    void displayExpense(Expense expense);
    //void displayExpense(vector <Expense>::iterator itr);
    //bool addExpenseToXmlFile(Expense expense, DataManager dataManager);
    void addExpenseToXmlFile(Expense expense, DateManager dateManager);
    int getLastExpenseId();
    int getLastExpenseIdFromFile();
};

#endif // EXPENSESFILE
