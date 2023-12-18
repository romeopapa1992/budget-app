#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include "XmlFile.h"
#include "Income.h"
#include "Expense.h"

using namespace std;

class ExpensesFile : public XmlFile
{
    int lastExpenseId;

    int getLastExpenseIdFromFile();
public:
    ExpensesFile(string expensesFilename) : XmlFile(expensesFilename)
    {
        lastExpenseId = getLastExpenseIdFromFile();
    };
    vector<Expense> readExpensesOfLoggedUserFromXmlFile(int CURRENT_USER_ID);
    void displayExpense(Expense expense);
    //void displayExpense(vector <Expense>::iterator itr);
    bool addExpenseToXmlFile(Expense expense, DataManager dataManager);
    int getLastExpenseId();
};

#endif // EXPENSESFILE
