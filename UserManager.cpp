#include "UserManager.h"

void UserManager::signUp()
{
    User user = enterNewUserData();

    users.push_back(user);
    usersFile.addUserToXmlFile(user);

    cout << endl << "Your account has been created." << endl;
    system("pause");
}

User UserManager::enterNewUserData()
{
    User user;
    user.setUserId(getNewUserId());

    string login;
    do
    {
        system("cls");
        cout << "    >>> SIGN UP <<<" << endl;
        cout << endl <<"Enter username: ";
        login = AuxiliaryFunctions::readLine();
        user.setLogin(login);
    }
    while (ifLoginExist(user.getLogin()) == false);

    string password;
    cout << "Enter password: ";
    password = AuxiliaryFunctions::readLine();
    user.setPassword(password);

    string name;
    cout << "Enter name: ";
    cin.sync();
    name = AuxiliaryFunctions::readLine();
    user.setName(AuxiliaryFunctions::convertFirstLetterToUppercaseRestLower(name));

    string surname;
    cout << "Enter surname: ";
    cin.sync();
    surname = AuxiliaryFunctions::readLine();
    user.setSurname(AuxiliaryFunctions::convertFirstLetterToUppercaseRestLower(surname));

    return user;
}

int UserManager::getNewUserId()
{
    int newUserId = users.empty() ? 1 : users.back().getUserId() + 1;
    return newUserId;
}

bool UserManager::ifLoginExist(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Username already exists. Please enter a different username." << endl << endl;
            system("pause");
            return false;
        }
    }
    return true;
}

void UserManager::signIn()
{
    User user;
    system("cls");
    cout << "    >>> SIGN IN <<<" << endl;
    int numberOfAttempts =3;
    string login, password;
    cout << endl << "Enter username: ";
    login = AuxiliaryFunctions::readLine();

    for (vector <User> :: size_type i =0; i < users.size(); i++)
        {
        if (users[i].getLogin() == login)
        {
            while (numberOfAttempts > 0)
            {
                cout << "Enter password. Attempts left: " << numberOfAttempts << ": ";
                password = AuxiliaryFunctions::readLine();

                if (users[i].getPassword() == password)
                {
                    cout << endl << "You have been signed in. "<< endl << endl;
                    loggedUserId = users[i].getUserId();
                    system("pause");
                    return;
                }
                numberOfAttempts--;
            }
            cout << "3 unsuccessful login attempts." << endl;
            system("pause");
            loggedUserId = 0;
            return;
        }
    }
    cout << "User does not exist." << endl << endl;
    system("pause");
}

bool UserManager::isUserLogged()
{
  return loggedUserId > 0;
}


void UserManager::logout()
{
    loggedUserId = 0;
}

int UserManager::getLoggedUserId()
{
    return loggedUserId;
}

void UserManager::changeLoggedUserPassword()
{
    {
    system("cls");
    string newPassword;
    cout << "Enter new password: ";
    newPassword = AuxiliaryFunctions::readLine();
    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getUserId() == loggedUserId)
        {
            while(itr -> getPassword() == newPassword)
            {
                cout << "The new password must be different from the old. Please enter your new password again: ";
                newPassword = AuxiliaryFunctions::readLine();
            }
            itr -> setPassword(newPassword);
            cout << endl << "Your password has been changed." << endl << endl;
            system("pause");
        }
    }
    usersFile.changeUserPassword(loggedUserId, newPassword);
    }
}
