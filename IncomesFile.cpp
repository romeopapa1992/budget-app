#include "IncomesFile.h"

int IncomesFile::getLastIncomeId()
{
   return lastIncomeId;
}

void IncomesFile::displayIncome(Income income)
{
   cout << "Income ID:  " << income.getIncomeId() << endl;
   cout << "User ID:    " << income.getUserId() << endl;
   cout << "Date:       " << dateManager.changeDateToString(income.getDate()) << endl;
   cout << "Category:   " << income.getCategory() << endl;
   cout << "Amount:     " << income.getOperationValue() << " PLN" << endl;
}

void IncomesFile::addIncomeToXmlFile(Income income, DateManager dateManager)
{
   CMarkup xml;
   bool ifFileExist = xml.Load(getFilename());
   if(!ifFileExist)
   {
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
   xml.AddElem("Amount", AuxiliaryFunctions::convertDoubleToString(income.getOperationValue()));
   lastIncomeId += 1;
   xml.Save(getFilename());
}

vector<Income> IncomesFile::readIncomesOfLoggedUserFromXmlFile(int CURRENT_USER_ID)
{
   Income income;
   vector <Income> incomes;
   CMarkup xml;

   if (ifFileExist(xml))
   {
       xml.FindElem();
       xml.IntoElem();
       while(xml.FindElem("Income"))
       {
           xml.IntoElem();
           xml.FindElem("IncomeId");
           income.setIncomeId(AuxiliaryFunctions::convertStringToInt((xml.GetData())));
           xml.FindElem("UserId");
           income.setUserId(AuxiliaryFunctions::convertStringToInt((xml.GetData())));
           xml.FindElem("Date");
           income.setDate(dateManager.changeDateToIntNumber(xml.GetElemContent()));
           xml.FindElem("Category");
           income.setCategory(xml.GetElemContent());
           xml.FindElem("Amount");
           income.setOperationValue(AuxiliaryFunctions::convertStringToDouble(xml.GetElemContent()));
           xml.OutOfElem();
           if(income.getUserId() == CURRENT_USER_ID)
               incomes.push_back(income);
       }
       lastIncomeId = income.getIncomeId();
   }
    return incomes;
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
