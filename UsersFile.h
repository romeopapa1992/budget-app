#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>

#include "User.h"
#include "XmlFile.h"

using namespace std;

class UsersFile : public XmlFile
{

public:
    UsersFile(string usersFilename) : XmlFile(usersFilename)
    {};
    vector<User> readUsersFromXmlFile();
    void addUserToXmlFile(User user);
    void changeUserPassword(int loggedUserId, string newPassword);
};

#endif
