#include "BudgetingApplication.h"


char BudgetingApplication::chooseOptionFromMainMenu()
{
    char choice;
    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Sign up" << endl;
    cout << "2. Sign in" << endl;
    cout << "3. Exit" << endl;
    cout << "---------------------------" << endl;
    choice = AuxiliaryFunctions::readChar();

    return choice;
}

char BudgetingApplication::chooseOptionFromUserMenu()
{
    char choice;
    system("cls");
    cout << "            >>> USER MENU <<<" << endl;
    cout << "----------------------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. View current month's balance" << endl;
    cout << "4. View last month's balance" << endl;
    cout << "5. View balance of the selected period" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Sign out" << endl;
    cout << "----------------------------------------" << endl;
    choice = AuxiliaryFunctions::readChar();

    return choice;
}

void BudgetingApplication::signUp()
{
    userManager.signUp();
}

void BudgetingApplication::signIn()
{
    userManager.signIn();
    if (userManager.isUserLogged())
    {
        balanceManager = new BalanceManager(userManager.getLoggedUserId(), INCOMES_FILE, EXPENSES_FILE);
    }
}

void BudgetingApplication::addIncome()
{
    balanceManager -> addIncome();
}

void BudgetingApplication::addExpense()
{
    balanceManager -> addExpense();
}

void BudgetingApplication::displayCurrentMonthBalance()
{
    balanceManager -> displayCurrentMonthBalance();
}

void BudgetingApplication::displayPreviousMonthBalance()
{
    balanceManager -> displayPreviousMonthBalance();
}

void BudgetingApplication::displaySelectedPeriodOfTimeBalance()
{
    balanceManager -> displaySelectedPeriodOfTimeBalance();
}

void BudgetingApplication::changeLoggedUserPassword()
{
    userManager.changeLoggedUserPassword();
}

bool BudgetingApplication::isUserLogged()
{
    userManager.isUserLogged();
}

void BudgetingApplication::logout()
{
    userManager.logout();
    delete balanceManager;
    balanceManager = NULL;
}
