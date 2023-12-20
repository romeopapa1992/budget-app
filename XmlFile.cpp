#include "XmlFile.h"

bool XmlFile::ifFileExist(CMarkup &xml)
{
    return xml.Load(getFilename());
}
string XmlFile::getFilename()
{
    return FILENAME;
}
