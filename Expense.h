#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

#include "Operation.h"

using namespace std;

class Expense : public Operation
{
    int expenseId;

public:
    void setExpenseId(int newExpenseId);
    int getExpenseId();
};

#endif
