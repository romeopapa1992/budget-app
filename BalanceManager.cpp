#include "BalanceManager.h"

void BalanceManager::addIncome()
{
    Income income;
    income = enterNewIncomeData();

    incomes.push_back(income);
    incomesFile.addIncomeToXmlFile(income,dateManager);

    cout << endl << "The income has been added." << endl;

    system ("pause");
}

void BalanceManager::addExpense()
{
    Expense expense;
    expense = enterNewExpenseData();

    expenses.push_back(expense);
    expensesFile.addExpenseToXmlFile(expense,dateManager);
    cout << endl << "The expense has been added." << endl;

    system ("pause");
}

void BalanceManager::displayCurrentMonthBalance()
{
    int currentDate = dateManager.changeDateToIntNumber(dateManager.getTodaysDateFromSystem());
    int fromDate = (currentDate/100)*100 + 1;
    int toDate = (currentDate/100 + 1)*100;
    system("cls");

    sortIncomesByDate();
    cout << ">>> INCOMES IN CURRENT MONTH <<<" << endl << endl;
    displaySortedIncomes(fromDate, toDate);

    sortExpensesByDate();
    cout << ">>> EXPENSES IN CURRENT MONTH <<<" << endl << endl;
    displaySortedExpenses(fromDate, toDate);

    cout << ">>> CURRENT MONTH SUMMARY <<<" << endl << endl;
    cout << "Total income:     " << totalIncome << " PLN" << endl;
    cout << "Total expense:    " << totalExpense << " PLN" << endl;
    cout << "Monthly balance:  " << totalIncome - totalExpense << " PLN" << endl << endl;

    totalIncome = 0;
    totalExpense = 0;

    system("pause");
}

void BalanceManager::displayPreviousMonthBalance()
{
    int currentDate = dateManager.changeDateToIntNumber(dateManager.getTodaysDateFromSystem());
    int fromDate = (currentDate/100 - 1)*100 + 1;
    int toDate = (currentDate/100)*100;

    system("cls");

    sortIncomesByDate();
    cout << ">>> INCOMES IN LAST MONTH <<<" << endl << endl;
    displaySortedIncomes(fromDate, toDate);

    sortExpensesByDate();
    cout << ">>> EXPENSES IN LAST MONTH <<<" << endl << endl;
    displaySortedExpenses(fromDate, toDate);

    cout << ">>>   LAST MONTH SUMMARY   <<<" << endl << endl;
    cout << "Total income:     " << totalIncome << " PLN" << endl;
    cout << "Total expense:    " << totalExpense << " PLN" << endl;
    cout << "Monthly balance:  " << totalIncome - totalExpense << " PLN" << endl << endl;

    totalIncome = 0;
    totalExpense = 0;

    system("pause");
}

void BalanceManager::displaySelectedPeriodOfTimeBalance()
{
    system("cls");

    int date1 = 0, date2 = 0, fromDate = 0, toDate = 0;
    cout << ">>> SELECTED PERIOD BALANCE <<<" << endl << endl;
    cout << "Enter a start date: " << endl;
    dateManager.enterDateOfOperation();
    date1 = dateManager.getDateInteger();
    cout << "Enter an end date: " << endl;
    dateManager.enterDateOfOperation();
    date2 = dateManager.getDateInteger();

    fromDate = (date1 < date2) ? date1 : date2;
    toDate = (date1 < date2) ? date2 : date1;

    system("cls");

    sortIncomesByDate();
    cout << ">>> INCOMES IN THE SELECTED PERIOD <<<"<< endl << endl;
    displaySortedIncomes(fromDate, toDate);

    sortExpensesByDate();
    cout << ">>> EXPENSES IN THE SELECTED PERIOD <<<" << endl << endl;
    displaySortedExpenses(fromDate, toDate);

    cout << ">>> SELECTED PERIOD SUMMARY <<<" << endl << endl;
    cout << "Total income:     " << totalIncome << " PLN" << endl;
    cout << "Total expense:    " << totalExpense << " PLN" << endl;
    cout << "Monthly balance:  " << totalIncome - totalExpense << " PLN" << endl << endl;

    totalIncome = 0;
    totalExpense = 0;

    system("pause");
}

Income BalanceManager::enterNewIncomeData()
{
    string category = "";
    double operationValue = 0;

    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    dateManager.enterDateOfOperation();
    cout << "Enter category: ";
    category = AuxiliaryFunctions::readLine();
    cout << "Enter amount: ";
    operationValue = AuxiliaryFunctions::getDoubleNumber();

    income.setIncomeId(incomesFile.getLastIncomeId()+ 1);
    income.setUserId(CURRENT_USER_ID);
    income.setDate(dateManager.getDateInteger());
    income.setCategory(category);
    income.setOperationValue(operationValue);

    return income;
}

Expense BalanceManager::enterNewExpenseData()
{
    string category = "";
    double operationValue = 0;

    Expense expense;

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    dateManager.enterDateOfOperation();
    cout << "Enter category: ";
    category = AuxiliaryFunctions::readLine();
    cout << "Enter amount: ";
    operationValue = AuxiliaryFunctions::getDoubleNumber();

    expense.setExpenseId(expensesFile.getLastExpenseId() + 1);
    expense.setUserId(CURRENT_USER_ID);
    expense.setDate(dateManager.getDateInteger());
    expense.setCategory(category);
    expense.setOperationValue(operationValue);

    return expense;
}

void BalanceManager::sortIncomesByDate()
{
    sort(incomes.begin(), incomes.end(), Income());
}

void BalanceManager::sortExpensesByDate()
{
    sort(expenses.begin(), expenses.end(), Expense());
}

void BalanceManager::displaySortedIncomes(int fromDate, int toDate)
{
    bool isIncomeExist = false;
    for (Income income : incomes)
    {
        if (income.getDate() >= fromDate && income.getDate() <= toDate)
        {
            isIncomeExist = true;
            totalIncome += income.getOperationValue();
            incomesFile.displayIncome(income);
            cout << endl;
        }
    }

    if (!isIncomeExist)
    {
        cout << "There is no income." << endl << endl;
    }
}

void BalanceManager::displaySortedExpenses(int fromDate, int toDate)
{
    bool isExpenseExist = false;
    for (Expense expense : expenses)
    {
        if (expense.getDate() >= fromDate && expense.getDate() <= toDate)
        {
            isExpenseExist = true;
            totalExpense += expense.getOperationValue();
            expensesFile.displayExpense(expense);
            cout << endl;
        }
    }

    if (!isExpenseExist)
    {
        cout << "There is no expense." << endl << endl;
    }
}
