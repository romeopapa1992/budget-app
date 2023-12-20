#include "ExpensesFile.h"

void ExpensesFile::displayExpense(Expense expense)
{
    cout << "Expense ID: " << expense.getExpenseId() << endl;
    cout << "User ID:    " << expense.getUserId() << endl;
    cout << "Date:       " << dateManager.changeDateToString(expense.getDate()) << endl;
    cout << "Category:   " << expense.getCategory() << endl;
    cout << "Amount:     " << expense.getOperationValue() << " PLN" << endl;
}

vector<Expense> ExpensesFile::readExpensesOfLoggedUserFromXmlFile(int CURRENT_USER_ID)
{
    CMarkup xml;
    vector <Expense> expenses;
    int expenseId = 0;

    if (ifFileExist(xml))
    {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Expense"))
        {
            Expense expense;
            xml.IntoElem();
            xml.FindElem("ExpenseId");
            expenseId = AuxiliaryFunctions::convertStringToInt(xml.GetElemContent());
            xml.FindElem("UserId");
            if(AuxiliaryFunctions::convertStringToInt(xml.GetElemContent()) == CURRENT_USER_ID)
            {
                expense.setUserId(CURRENT_USER_ID);
                expense.setExpenseId(expenseId);
                xml.FindElem("Date");
                expense.setDate(dateManager.changeDateToIntNumber(xml.GetElemContent()));
                xml.FindElem("Category");
                expense.setCategory(xml.GetElemContent());
                xml.FindElem("Amount");
                expense.setOperationValue(AuxiliaryFunctions::convertStringToFloat(xml.GetElemContent()));
                expenses.push_back(expense);
            }
            xml.OutOfElem();
        }
    }
    return expenses;
}

void ExpensesFile::addExpenseToXmlFile(Expense expense, DateManager dateManager)
{
    CMarkup xml;

    if (!ifFileExist(xml))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
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
    xml.AddElem("Amount", AuxiliaryFunctions::convertFloatToString(expense.getOperationValue()));
    xml.OutOfElem();
    xml.Save(getFilename());
    lastExpenseId++;
    if (!ifFileExist(xml))
    {
        cout << "Cannot open the " << getFilename() << " file." << endl;
    }
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

int ExpensesFile::getLastExpenseId()
{
    return lastExpenseId;
}
