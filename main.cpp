#include <iostream>

#include "BudgetingApplication.h"

using namespace std;

int main()
{
    BudgetingApplication budgetingApplication("users.xml", "incomes.xml", "expenses.xml");
    char choice;

    while (true)
    {
        if (!budgetingApplication.isUserLogged())
        {
            choice = budgetingApplication.chooseOptionFromMainMenu();

            switch (choice)
            {
            case '1': budgetingApplication.signUp(); break;
            case '2': budgetingApplication.signIn(); break;
            case '3': exit(0); break;
            default:
                cout << endl << "No such option in the main menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = budgetingApplication.chooseOptionFromUserMenu();

            switch (choice)
            {
            case '1': budgetingApplication.addIncome(); break;
            case '2': budgetingApplication.addExpense(); break;
            case '3': budgetingApplication.displayCurrentMonthBalance(); break;
            case '4': budgetingApplication.displayPreviousMonthBalance(); break;
            case '5': budgetingApplication.displaySelectedPeriodOfTimeBalance(); break;
            case '6': budgetingApplication.changeLoggedUserPassword(); break;
            case '7': budgetingApplication.logout(); break;
            }
        }
    }
    return 0;
}
