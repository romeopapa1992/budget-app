#include "Operation.h"

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

bool Operation::operator () (Operation a, Operation b)
{
    if (a.getDate() < b.getDate())
        return true;
}
