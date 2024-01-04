#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>

using namespace std;

class Operation
{
    int userId;
    int date;
    string category;
    float operationValue;

public:
    int getUserId();
    int getDate();
    string getCategory();
    float getOperationValue();
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setCategory(string newCategory);
    void setOperationValue(float newOperationValue);
    bool operator () (Operation a, Operation b);
};

#endif
