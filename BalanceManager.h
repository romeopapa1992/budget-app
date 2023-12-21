#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include <vector>

#include "IncomesFile.h"
#include "ExpensesFile.h"
#include "DateManager.h"

using namespace std;

class BalanceManager
{
    const int CURRENT_USER_ID;
    vector<Income> incomes;
    vector<Expense> expenses;

    IncomesFile incomesFile;
    ExpensesFile expensesFile;
    DateManager dateManager;

    double totalIncome = 0;
    double totalExpense = 0;

    Income enterNewIncomeData();
    Expense enterNewExpenseData();

    void sortIncomesByDate();
    void sortExpensesByDate();
    void displaySortedIncomes(int fromDate, int toDate);
    void displaySortedExpenses(int fromDate, int toDate);

public:
    BalanceManager(int currentUserId, string incomesFilename, string expensesFilename)
    : CURRENT_USER_ID(currentUserId), incomesFile(incomesFilename), expensesFile(expensesFilename)
    {
        incomes = incomesFile.readIncomesOfLoggedUserFromXmlFile(CURRENT_USER_ID);
        expenses = expensesFile.readExpensesOfLoggedUserFromXmlFile(CURRENT_USER_ID);
    };
    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySelectedPeriodOfTimeBalance();
};

#endif

