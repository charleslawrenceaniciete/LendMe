#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <string>

using namespace std;

class UserManager {
public:
    // Constructor & Destructor
    UserManager() = default;
    ~UserManager() = default;

    // Method to validate if the username is valid
    bool isValidUsername(const string& username);

    // Method to validate if the password is valid (checks length, digits, uppercase, etc.)
    bool isValidPassword(const string& password);

    // Method to validate login credentials
    bool validateLogin(const string& username, const string& password);

    // Method to register a new user
    bool registerUser(const string& username, const string& password);

    // Method to handle forgotten password (retrieves password if username exists)
    bool forgotPassword(const string& username, string& password);
};

#endif // USERMANAGER_H
