#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>

#include "UsersFile.h"

using namespace std;

class UserManager
{
    UsersFile usersFile;
    int loggedUserId;
    vector<User> users;

    User enterNewUserData();
    int getNewUserId();
    bool ifLoginExist(string login);

public:
    UserManager(string usersFilename):usersFile(usersFilename)
    {
        users = usersFile.readUsersFromXmlFile();
        loggedUserId = 0;
    };
    int getLoggedUserId();
    void signUp();
    void signIn();
    void changeLoggedUserPassword();
    void logout();
    bool isUserLogged();
};

#endif
