#include "UIManager.h"
#include "UserManager.h"
#include "welcome.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    displayWelcome();

    UIManager ui;
    UserManager userMgr;
    int choice;

    while (true) {
        ui.showMainMenu(); 
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            ui.showMessage("Invalid input. Please enter a number.");
            continue;
        }

        switch (choice) {
            case 1: { // Login
                string username, password;
                ui.showLoginMenu();
                cout << "Enter username (or type 'b' to go back): \n";
                cin.ignore(); // To clear the input buffer from previous input
                getline(cin, username); // Using getline to allow spaces

                // Check for "b" to go back
                if (username == "b" || username == "B") {
                    ui.showMessage("Returning to the User Manager Menu...");
                    break;
                }

                cout << "Enter password: \n";
                getline(cin, password); // Using getline to allow spaces

                if (userMgr.validateLogin(username, password)) {
                    ui.showMessage("Login successful!");
                } else {
                    ui.showMessage("Login failed!");
                }
                break;
            }
            case 2: { // Register
                string username, password;
                ui.showRegistrationMenu();
                cout << "Enter username (or type 'b' to go back): \n";
                cin.ignore(); // To clear the input buffer
                getline(cin, username); // Using getline to allow spaces

                // Check for "b" to go back
                if (username == "b" || username == "B") {
                    ui.showMessage("Returning to the User Manager Menu...");
                    break;
                }

                cout << "Enter password: \n";
                getline(cin, password); // Using getline to allow spaces

                // Proceed with registration if the username and password are valid
                if (userMgr.registerUser(username, password)) {
                    ui.showMessage("Registration successful!");
                } else {
                    // Here we need to handle specific errors from registerUser
                    ui.showMessage("Registration failed. Please try again.");
                }
                break;
            }
            case 3: { // Forgot Password
                string username;
                string password;
                ui.showForgotPasswordMenu();
                cout << "Enter username (or type 'b' to go back): \n";
                cin.ignore(); // To clear the input buffer
                getline(cin, username); // Using getline to allow spaces

                // Check for "b" to go back
                if (username == "b" || username == "B") {
                    ui.showMessage("Returning to the User Manager Menu...");
                    break;
                }

                if (userMgr.forgotPassword(username, password)) {
                    ui.showMessage("Your password is: " + password);
                } else {
                    ui.showMessage("Username not found.");
                }
                break;
            }
            case 4: // Exit
                return 0;
            default:
                ui.showMessage("Invalid choice.");
        }
    }
}
