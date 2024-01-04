#include "Operation.h"

int Operation::getUserId()
{
    return userId;
}

int Operation::getDate()
{
    return date;
}

string Operation::getCategory()
{
    return category;
}

float Operation::getOperationValue()
{
    return operationValue;
}

void Operation::setUserId(int newUserId)
{
    userId = newUserId;
}

void Operation::setDate(int newDate)
{
    date = newDate;
}

void Operation::setCategory(string newCategory)
{
    category = newCategory;
}

void Operation::setOperationValue(float newOperationValue)
{
    operationValue = newOperationValue;
}

bool Operation::operator() (Operation a, Operation b)
{
    return a.getDate() < b.getDate();
}
