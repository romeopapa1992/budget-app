#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <vector>

#include "CMarkup.h"
#include "AuxiliaryFunctions.h"
#include "DateManager.h"

using namespace std;

class XmlFile
{
    const string FILENAME;

public:
    DateManager dateManager;
    XmlFile(string filename) : FILENAME(filename){}
    bool ifFileExist(CMarkup &xml);
    string getFilename();
};

#endif
