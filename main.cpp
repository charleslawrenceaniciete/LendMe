#include "UIManager.h"
#include "UserManager.h"
#include "ItemListing.h"
#include "RentalManagement.h"
#include "PaymentSimulation.h"
#include "welcome.h"
#include "LendMeCredits.h"
#include <iostream>
#include <limits>

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

                    // After login, show a menu with item options
                    int userChoice;
                    do {
                        cout << "\n=== Welcome " << username << " ===\n";
                        cout << "1. Item Menu\n";
                        cout << "2. Rental Management\n";
                        cout << "3. LendMe Credits\n";
                        cout << "4. Logout\n";
                        cout << "Enter your choice: ";
                        cin >> userChoice;

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
                                    cin >> itemChoice;

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
                                // Show Rental Management Menu and handle choices
                                int rentalChoice;
                                do {
                                    ui.showRentalManagementMenu();
                                    cout << "Enter your choice: ";
                                    cin >> rentalChoice;

                                    switch (rentalChoice) {
                                        case 1:
                                            // Implement View Rental Agreements functionality
                                            rentalMgmt.displayRentalAgreements();  // Assuming this method exists
                                            break;
                                        case 2:
                                            // Implement Check Expired Rentals functionality
                                            rentalMgmt.checkExpiredRentals();  // Assuming this method exists
                                            break;
                                        case 3:
                                            // Implement View Rental History functionality
                                            rentalMgmt.displayRentalHistory();  // Assuming this method exists
                                            break;
                                        case 4:
                                            cout << "Returning...\n";
                                            break;
                                        default:
                                            ui.showMessage("Invalid choice.");
                                    }
                                } while (rentalChoice != 4);  // Loop until user logs out or chooses to go back
                                break;

                            case 3:
                                creditsMenu.showMenu();
                                break;

                            case 4:
                                cout << "Logging out...\n";
                                break;

                            default:
                                ui.showMessage("Invalid choice.");
                        }
                    } while (userChoice != 3);  // Loop until user logs out
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