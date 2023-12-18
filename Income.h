#ifndef INCOME_H
#define INCOME_H

#include <iostream>

#include "Operation.h"

using namespace std;

class Income : public Operation
{
    int incomeId;

public:
    void setIncomeId(int newIncomeId);
    int getIncomeId();
};

#endif
