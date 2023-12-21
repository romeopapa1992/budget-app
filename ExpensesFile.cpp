#include "ExpensesFile.h"

int ExpensesFile::getLastExpenseId()
{
    return lastExpenseId;
}

void ExpensesFile::displayExpense(Expense expense)
{
    cout << "Expense ID: " << expense.getExpenseId() << endl;
    cout << "User ID:    " << expense.getUserId() << endl;
    cout << "Date:       " << dateManager.changeDateToString(expense.getDate()) << endl;
    cout << "Category:   " << expense.getCategory() << endl;
    cout << "Amount:     " << expense.getOperationValue() << " PLN" << endl;
}

void ExpensesFile::addExpenseToXmlFile(Expense expense, DateManager dateManager)
{
    CMarkup xml;
    bool ifFileExist = xml.Load(getFilename());
    if (!ifFileExist)
    {
        xml.AddElem("Expenses");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getExpenseId());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", dateManager.getDateString());
    xml.AddElem("Category", expense.getCategory());
    xml.AddElem("Amount", AuxiliaryFunctions::convertDoubleToString(expense.getOperationValue()));
    lastExpenseId += 1;
    xml.Save(getFilename());
}

vector<Expense> ExpensesFile::readExpensesOfLoggedUserFromXmlFile(int CURRENT_USER_ID)
{
    Expense expense;
    vector <Expense> expenses;
    CMarkup xml;

    if (ifFileExist(xml))
        {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Expense"))
        {
            xml.IntoElem();
            xml.FindElem("ExpenseId");
            expense.setExpenseId(AuxiliaryFunctions::convertStringToInt((xml.GetData())));
            xml.FindElem("UserId");
            expense.setUserId(AuxiliaryFunctions::convertStringToInt((xml.GetData())));
            xml.FindElem("Date");
            expense.setDate(dateManager.changeDateToIntNumber(xml.GetElemContent()));
            xml.FindElem("Category");
            expense.setCategory(xml.GetElemContent());
            xml.FindElem("Amount");
            expense.setOperationValue(AuxiliaryFunctions::convertStringToDouble(xml.GetElemContent()));
            xml.OutOfElem();
            if (expense.getUserId() == CURRENT_USER_ID)
                expenses.push_back(expense);
        }
        lastExpenseId = expense.getExpenseId();
    }
    return expenses;
}

int ExpensesFile::getLastExpenseIdFromFile()
{
    CMarkup xml;
    int lastExpenseId = 0;

    if (ifFileExist(xml))
    {
        xml.FindElem();
        xml.IntoElem();
        xml.FindElem("Expense");
        if (xml.FindChildElem("ExpenseId"))
        {
            lastExpenseId = AuxiliaryFunctions::convertStringToInt(xml.GetChildData());
        }
    }

  return lastExpenseId;
}
