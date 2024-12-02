// main.cpp
#include <iostream>
#include "InputValidation.h"
#include "UIManager.h"
#include "UserManager.h"
#include "ItemListing.h"
#include "RentalManagement.h"
#include "PaymentSimulation.h"
#include "welcome.h"
#include "LendMeCredits.h"

using namespace std;

int main() {
    displayWelcome();

    UIManager ui;
    UserManager userMgr;
    ItemListing itemListing;
    RentalManagement rentalMgmt;
    PaymentSimulation payment;
    LendMeCredits creditsMenu;

    int choice;
    bool loggedIn = false;  // Track login status

    while (true) {
        ui.showMainMenu();
        cout << "Enter your choice: ";

        // Get a validated choice from the user
        choice = getValidChoice();

        switch (choice) {
            case 1: { // Login
                string username, password;
                ui.showLoginMenu();
                cout << "Enter username (or type 'b' to go back): \n";
                cin.ignore();
                getline(cin, username);

                if (username == "b" || username == "B") {
                    ui.showMessage("Returning to the User Manager Menu...");
                    break;
                }

                cout << "Enter password: \n";
                getline(cin, password);

                if (userMgr.validateLogin(username, password)) {
                    ui.showMessage("Login successful!");
                    loggedIn = true;

                    int userChoice;
                    do {
                        ui.showUserDashboard(username);
                        cout << "Enter your choice: ";
                        userChoice = getValidChoice();

                        switch (userChoice) {
                            case 1:
                                // Show Item Listing Menu
                                int itemChoice;
                                do {
                                    cout << "\n=== Item Menu ===\n";
                                    cout << "1. Display Items\n";
                                    cout << "2. Add Item\n";
                                    cout << "3. Remove Item\n";
                                    cout << "4. Borrow Item\n";
                                    cout << "5. Search Items\n";
                                    cout << "6. Back\n";
                                    cout << "Enter your choice: ";
                                    itemChoice = getValidChoice();  // Use getValidChoice()

                                    switch (itemChoice) {
                                        case 1: itemListing.displayItems(); break;
                                        case 2: itemListing.addItem(); break;
                                        case 3: itemListing.removeItem(); break;
                                        case 4: itemListing.borrowItem(payment); break;
                                        case 5: itemListing.searchItems(); break;
                                        case 6: break;
                                        default: ui.showMessage("Invalid choice.");
                                    }
                                } while (itemChoice != 6);
                                break;

                            case 2:
                                // Show Rental Management Menu
                                int rentalChoice;
                                do {
                                    ui.showRentalManagementMenu();
                                    cout << "Enter your choice: ";
                                    rentalChoice = getValidChoice();  // Use getValidChoice()

                                    switch (rentalChoice) {
                                        case 1:
                                            rentalMgmt.displayRentalAgreements();
                                            break;
                                        case 2:
                                            rentalMgmt.checkExpiredRentals();
                                            break;
                                        case 3:
                                            rentalMgmt.displayRentalHistory();
                                            break;
                                        case 4:
                                            cout << "Returning...\n";
                                            break;
                                        default:
                                            ui.showMessage("Invalid choice.");
                                    }
                                } while (rentalChoice != 4);
                                break;

                            case 3:
                                creditsMenu.showMenu();
                                break;

                            case 4: { // Logging out
                                cout << "Logging out...\n";
                                loggedIn = false;
                                break;
                            }

                            default:
                                ui.showMessage("Invalid choice.");
                        }
                    } while (loggedIn);
                } else {
                    ui.showMessage("Login failed!");
                }
                break;
            }
            case 2: { // Register
                string username, password;
                ui.showRegistrationMenu();
                cout << "Enter username (or type 'b' to go back): \n";
                cin.ignore();
                getline(cin, username);

                if (username == "b" || username == "B") {
                    ui.showMessage("Returning to the User Manager Menu...");
                    break;
                }

                cout << "Enter password: \n";
                getline(cin, password);

                if (userMgr.registerUser(username, password)) {
                    ui.showMessage("Registration successful!");
                } else {
                    ui.showMessage("Registration failed. Please try again.");
                }
                break;
            }
            case 3: { // Forgot Password
                string username;
                string password;
                ui.showForgotPasswordMenu();
                cout << "Enter username (or type 'b' to go back): \n";
                cin.ignore();
                getline(cin, username);

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
