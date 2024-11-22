#include "UIManager.h"
#include "UserManager.h"
#include "welcome.h"
#include <iostream>

using namespace std;

int main(){
    
    displayWelcome();

    UIManager ui;
    UserManager userMgr;
    int choice;

    while (true) {
        //ui.clearScreen();
        ui.showMainMenu(); 
        cin >> choice;

        switch (choice) {
            case 1: {
                string username, password;
                ui.showLoginMenu();
                cin >> username >> password;
                if (userMgr.validateLogin(username, password)) {
                    ui.showMessage("Login successful!");
                } else {
                    ui.showMessage("Login failed!");
                }
                break;
            }
            case 2: {
                string username, password;
                ui.showRegistrationMenu();
                cin >> username >> password;
                if (userMgr.registerUser(username, password)) {
                    ui.showMessage("Registration successful!");
                } else {
                    ui.showMessage("Username already taken.");
                }
                break;
            }
            case 3: {
                string username, password;
                ui.showForgotPasswordMenu();
                cin >> username;
                if (userMgr.forgotPassword(username, password)) {
                    ui.showMessage("Your password is: " + password);
                } else {
                    ui.showMessage("Username not found.");
                }
                break;
            }
            case 4:
                return 0;
            default:
                ui.showMessage("Invalid choice.");
        }
    }
}
