#ifndef LENDMECREDITS_H
#define LENDMECREDITS_H

#include "PaymentSimulation.h"
#include "ItemListing.h"
#include <iostream>

using namespace std;

class LendMeCredits {
private:
    PaymentSimulation credits;  // This uses PaymentSimulation for actual balance operations

    ItemListing itemListing;
    PaymentSimulation payment;
public:
    // Show the LendMe Credits menu
    void showMenu() {
        int choice;
        while (true) {  // Keep the loop running until "Exit" is chosen
            cout << "\n----- LendMe Credits Menu -----\n";
            cout << "1. Top Up Balance\n";
            cout << "2. View Balance\n";
            cout << "3. Borrow an Item\n";
            cout << "4. View Transaction History\n";
            cout << "5. Back\n";
            cout << "Enter your choice: ";
            cin >> choice;

            // Handle invalid input
            if (cin.fail()) {
                cin.clear();  // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore bad input
                cout << "Invalid input! Please enter a number between 1 and 4.\n";
                continue;
            }

            switch (choice) {
                case 1:
                    topUpMenu();
                    break;
                case 2:
                    credits.viewBalance();
                    break;
                case 3:
                    itemListing.borrowItem(payment); break;
                    break;
                case 4:
                    credits.viewTransactionHistory();
                    break;
                case 5:
                    return;
                default:
                    cout << "Invalid choice! Please try again.\n";
                    break;
            }
        }
    }

private:
    // Top up the balance (input amount)
    void topUpMenu() {
        double amount;
        cout << "Enter the amount to top up: $";
        cin >> amount;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid amount! Please enter a valid number.\n";
        } else {
            credits.topUpBalance(amount);
        }
    }
};

#endif  // LENDMECREDITS_H
