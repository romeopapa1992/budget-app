#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <vector>

#include "CMarkup.h"
#include "AuxiliaryFunctions.h"
#include "DataManager.h"

using namespace std;

class XmlFile
{
    const string FILENAME;

public:
    DataManager dataManager;
    XmlFile(string filename) : FILENAME(filename){}
    bool ifFileExist(CMarkup xml);
    string getFilename();
};

#endif
