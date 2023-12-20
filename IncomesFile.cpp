#include "IncomesFile.h"

int IncomesFile::getLastIncomeId()
{
    return lastIncomeId;
}

void IncomesFile::displayIncome(Income income)
{
    cout << "Income ID:   " << income.getIncomeId() << endl;
    cout << "User ID:     " << income.getUserId() << endl;
    cout << "Date:        " << dateManager.changeDateToString(income.getDate()) << endl;
    cout << "Category:    " << income.getCategory() << endl;
    cout << "Amount:      " << income.getOperationValue() << " PLN" << endl;
}

vector<Income> IncomesFile::readIncomesOfLoggedUserFromXmlFile(int CURRENT_USER_ID)
{
    CMarkup xml;
    vector <Income> incomes;
    int incomeId = 0;

    if (ifFileExist(xml))
    {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Income"))
        {
            Income income;
            xml.IntoElem();
            xml.FindElem("IncomeId");
            incomeId = atoi((xml.GetElemContent()).c_str());
            xml.FindElem("UserId");
            if (atoi((xml.GetElemContent()).c_str()) == CURRENT_USER_ID)
            {
                income.setUserId(CURRENT_USER_ID);
                income.setIncomeId(incomeId);
                xml.FindElem("Date");
                income.setDate(dateManager.changeDateToIntNumber(xml.GetElemContent()));
                xml.FindElem("Category");
                income.setCategory(xml.GetElemContent());
                xml.FindElem("Amount");
                income.setOperationValue(AuxiliaryFunctions::convertStringToFloat(xml.GetElemContent()));
                incomes.push_back(income);
            }
            xml.OutOfElem();
        }
    }
    return incomes;
}

void IncomesFile::addIncomeToXmlFile(Income income, DateManager dateManager)
{
    CMarkup xml;

    if (!ifFileExist(xml))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", income.getIncomeId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", dateManager.getDateString());
    xml.AddElem("Category", income.getCategory());
    xml.AddElem("Amount", AuxiliaryFunctions::convertFloatToString(income.getOperationValue()));
    xml.OutOfElem();
    xml.Save(getFilename());
    lastIncomeId++;
    if (!ifFileExist(xml))
    {
        cout << "Cannot open the " << getFilename() << " file." << endl;
    }
}

int IncomesFile::getLastIncomeIdFromFile()
{
    CMarkup xml;
    int lastIncomeId = 0;

    if (ifFileExist(xml))
    {
        xml.FindElem();
        xml.IntoElem();
        xml.FindElem("Income");
        if (xml.FindChildElem("IncomeId"))
        {
            lastIncomeId = AuxiliaryFunctions::convertStringToInt(xml.GetChildData());
        }
    }

  return lastIncomeId;
}

