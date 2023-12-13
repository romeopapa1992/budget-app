#ifndef BUDGETINGAPPLICATION_H
#define BUDGETINGAPPLICATION_H

#include <iostream>

#include "UserManager.h"
#include "BalanceManager.h"

using namespace std;

class BudgetingApplication
{
    UserManager userManager;
    BalanceManager *balanceManager;
    const string INCOMES_FILE;
    const string EXPENSES_FILE;

public:
    BudgetingApplication(string usersFile, string incomesFile, string expensesFile)
    :userManager(usersFile), INCOMES_FILE(incomesFile), EXPENSES_FILE(expensesFile)
    {
        balanceManager = NULL;
    };
    ~BudgetingApplication()
    {
        delete balanceManager;
        balanceManager = NULL;
    }
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    void signUp();
    void signIn();
    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySelectedPeriodOfTimeBalance();
    void changeLoggedUserPassword();
    bool isUserLogged();
    void logout();
};

#endif
