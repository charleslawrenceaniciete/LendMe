#include "UserManager.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <regex>

using namespace std;

// Helper function to check if input contains spaces
bool containsSpace(const string& input) {
    return input.find(' ') != string::npos;
}

bool UserManager::isValidUsername(const string& username) {
    if (username.length() < 3) {
        cout << "Username must be at least 3 characters long." << endl;
        return false;
    }
    return true;
}

bool UserManager::isValidPassword(const string& password) {
    if (password.length() < 8) {
        cout << "Password must be at least 8 characters long." << endl;
        return false; // Return false immediately if the password is too short
    }

    // Check for at least one digit, one uppercase letter, and one lowercase letter
    bool hasDigit = false, hasUpper = false, hasLower = false;
    for (char ch : password) {
        if (isdigit(ch)) hasDigit = true;
        if (isupper(ch)) hasUpper = true;
        if (islower(ch)) hasLower = true;
    }

    if (!hasDigit || !hasUpper || !hasLower) {
        cout << "Password must contain at least one uppercase letter, one lowercase letter, and one digit." << endl;
        return false;
    }

    return true; // Return true if the password meets all criteria
}

bool UserManager::validateLogin(const string& username, const string& password) {
    cout << "Debug: Starting validateLogin()" << endl;

    // Check for spaces in the username or password before any other checks
    if (containsSpace(username)) {
        cout << "Debug: Username contains space!" << endl;
        cout << "Username must not contain spaces." << endl;
        return false;
    }

    if (containsSpace(password)) {
        cout << "Debug: Password contains space!" << endl;
        cout << "Password must not contain spaces." << endl;
        return false;
    }

    if (!isValidUsername(username)) return false; // Validate username

    ifstream input("credentials.txt");
    if (!input.is_open()) {
        cout << "Error opening file." << endl;
        return false;
    }

    string user, pass;
    while (input >> user >> pass) {
        if (user == username && pass == password) {
            return true; // Successful login
        }
    }
    return false; // Failed login
}

bool UserManager::registerUser(const string& username, const string& password) {
    if (username == "b" || username == "B") return false; // Go back if "b" or "B" is entered

    // Validate username for spaces and length first
    if (username.find(' ') != string::npos) {  // Check for spaces
        cout << "Username must not contain spaces." << endl;
        return false;
    }

    if (username.length() < 3) {  // Ensure username length is >= 3 characters
        cout << "Username must be at least 3 characters long." << endl;
        return false;
    }

    if (!isValidPassword(password)) {  // Validate password
        return false;
    }

    // Open the file and check for an existing username
    ifstream check("credentials.txt");
    if (!check.is_open()) {
        cout << "Error opening file for checking." << endl;
        return false;
    }

    bool usernameTaken = false;
    string user, pass;
    
    // Read the file and check for an existing username
    while (check >> user >> pass) {
        if (user == username) {
            usernameTaken = true;
            break; // Exit the loop if username is found
        }
    }

    if (usernameTaken) {
        cout << "Username already taken." << endl;
        return false; // Username is already taken
    }

    // Now, write the new username and password to the file
    ofstream reg("credentials.txt", ios::app);
    if (!reg.is_open()) {
        cout << "Error opening file for writing." << endl;
        return false;
    }

    reg << username << ' ' << password << endl;
    return true; // Registration successful
}

bool UserManager::forgotPassword(const string& username, string& password) {
    if (!isValidUsername(username)) return false; // Validate username

    ifstream search("credentials.txt");
    if (!search.is_open()) {
        cout << "Error opening file." << endl;
        return false;
    }

    string user, pass;
    while (search >> user >> pass) {
        if (user == username) {
            password = pass;
            return true; // Found password
        }
    }
    return false; // Username not found
}
