#include "BalanceManager.h"

void BalanceManager::addIncome()
{
    Income income;
    income = enterNewIncomeData();
    bool isIncomeAdded = false;

    incomes.push_back(income);
    isIncomeAdded = incomesFile.addIncomeToXmlFile(income,dataManager);

    if(isIncomeAdded)
        cout << endl << "The income has been added." << endl;

    system ("pause");
}

void BalanceManager::addExpense()
{
    Expense expense;
    expense = enterNewExpenseData();
    bool isExpenseAdded = false;

    expenses.push_back(expense);
    isExpenseAdded = expensesFile.addExpenseToXmlFile(expense,dataManager);

    if(isExpenseAdded)
        cout << endl << "The expense has been added." << endl;

    system ("pause");
}

void BalanceManager::calculateTotalIncome(Income income)
{
  totalIncome += income.getOperationValue();
}

void BalanceManager::calculateTotalExpense(Expense expense)
{
  totalExpense += expense.getOperationValue();
}

void BalanceManager::displayCurrentMonthBalance()
{
    int currentDate = dataManager.changeDateToIntNumber(dataManager.getTodaysDateFromSystem());
    int minDate = (currentDate/100)*100 + 1;
    int toDate = (currentDate/100 + 1)*100;
    system("cls");

    sortIncomesByDate();
    cout << ">>> INCOMES IN CURRENT MONTH <<<" << endl << endl;
    displaySortedIncomes(minDate, toDate);

    sortExpensesByDate();
    cout << ">>> EXPENSES IN CURRENT MONTH <<<" << endl << endl;
    displaySortedExpenses(minDate, toDate);

    cout << ">>> CURRENT MONTH SUMMARY <<<" << endl << endl;
    cout << "Total income:     " << totalIncome << endl;
    cout << "Total expense:    " << totalExpense << endl;
    cout << "Monthly balance:    " << showpos << totalIncome - totalExpense << endl << endl;

    totalIncome = 0;
    totalExpense = 0;

    system("pause");
}

void BalanceManager::displayPreviousMonthBalance()
{
    int currentDate = dataManager.changeDateToIntNumber(dataManager.getTodaysDateFromSystem());
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
    cout << "Total income:     " << totalIncome << endl;
    cout << "Total expense:    " << totalExpense << endl;
    cout << "Monthly balance:    " << showpos << totalIncome - totalExpense << endl << endl;

    totalIncome = 0;
    totalExpense = 0;

    system("pause");
}

void BalanceManager::displaySelectedPeriodOfTimeBalance()
{
    system("cls");

    int date1 = 0, date2 = 0, fromDate = 0, toDate = 0;
    cout << "Enter a start date of period that you want to review: " << endl;
    dataManager.enterDateOfOperation();
    date1 = dataManager.getDateInteger();
    cout << "Enter an end date of period that you want to review: " << endl;
    dataManager.enterDateOfOperation();
    date2 = dataManager.getDateInteger();

    if (date1 < date2)
    {
        fromDate = date1;
        toDate = date2;
    }
    else
    {
        fromDate = date2;
        toDate = date1;
    }

    system("cls");

    sortIncomesByDate();
    cout << ">>> INCOMES IN THE SELECTED PERIOD <<<"<< endl << endl;
    displaySortedIncomes(fromDate, toDate);

    sortExpensesByDate();
    cout << ">>> EXPENSES IN THE SELECTED PERIOD <<<" << endl << endl;
    displaySortedExpenses(fromDate, toDate);

    cout << ">>> SELECTED PERIOD SUMMARY <<<" << endl << endl;
    cout << "Total income:     " << totalIncome << endl;
    cout << "Total expense:    " << totalExpense << endl;
    cout << "Monthly balance:    " << showpos << totalIncome - totalExpense << endl << endl;

    totalIncome = 0;
    totalExpense = 0;

    system("pause");
}

Income BalanceManager::enterNewIncomeData()
{
    string category = "";
    float operationValue = 0;
    char choice;

    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    dataManager.enterDateOfOperation();
    cout << "Enter category: ";
    category = AuxiliaryFunctions::readLine();
    cout << "Enter amount: ";
    operationValue = AuxiliaryFunctions::getFloatNumber();

    income.setIncomeId(incomesFile.getLastIncomeId() + 1);
    income.setUserId(CURRENT_USER_ID);
    income.setDate(dataManager.getDateInteger());
    income.setCategory(category);
    income.setOperationValue(operationValue);

    return income;
}

Expense BalanceManager::enterNewExpenseData()
{
    string category = "";
    float operationValue = 0;
    char choice;

    Expense expense;

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    dataManager.enterDateOfOperation();
    cout << "Enter category: ";
    category = AuxiliaryFunctions::readLine();
    cout << "Enter amount: ";
    operationValue = AuxiliaryFunctions::getFloatNumber();

    expense.setExpenseId(expensesFile.getLastExpenseId() + 1);
    expense.setUserId(CURRENT_USER_ID);
    expense.setDate(dataManager.getDateInteger());
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
    bool incomeExist = false;
    for (Income income : incomes)
    {
        if (income.getDate() >= fromDate && income.getDate() <= toDate)
        {
            incomeExist = true;
            calculateTotalIncome(income);
            incomesFile.displayIncome(income);
            cout << endl;
        }
    }

    if (!incomeExist)
    {
        cout << "There is no income." << endl << endl;
    }
}

void BalanceManager::displaySortedExpenses(int fromDate, int toDate)
{
    bool expenseExist = false;
    for (Expense expense : expenses)
    {
        if (expense.getDate() >= fromDate && expense.getDate() <= toDate)
        {
            expenseExist = true;
            calculateTotalExpense(expense);
            expensesFile.displayExpense(expense);
            cout << endl;
        }
    }

    if (!expenseExist)
    {
        cout << "There is no expense." << endl << endl;
    }
}
