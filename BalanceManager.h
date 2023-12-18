#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include <vector>

#include "IncomesFile.h"
#include "ExpensesFile.h"
#include "DataManager.h"

using namespace std;

class BalanceManager
{
    const int CURRENT_USER_ID;
    vector<Income> incomes;
    vector<Expense> expenses;

    IncomesFile incomesFile;
    ExpensesFile expensesFile;
    DataManager dataManager;

    Income enterNewIncomeData();
    Expense enterNewExpenseData();

    void sortIncomesByDate();
    void sortExpensesByDate();
    void displaySortedIncomes(int fromDate, int toDate);
    void displaySortedExpenses(int fromDate, int toDate);
    void calculateTotalIncome(Income income);
    void calculateTotalExpense(Expense expense);
    float totalIncome;
    float totalExpense;

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

