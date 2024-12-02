#include "PaymentSimulation.h"
#include <iostream>
#include <iomanip> // For currency formatting
#include <vector>  // For transaction history

using namespace std;

// Constructor to initialize the balance to zero
PaymentSimulation::PaymentSimulation() : balance(0.0) {}

// Method to top up balance
void PaymentSimulation::topUpBalance(double amount) {
    if (amount > 0) {
        balance += amount;
        // Add transaction to history
        transactions.push_back("Topped up: " + to_string(amount));
        cout << "Successfully topped up PHP " << fixed << setprecision(2) << amount << " to your account.\n";
    } else {
        cout << "Invalid amount! Top-up must be greater than zero.\n";
    }
}

// Method to view current balance
void PaymentSimulation::viewBalance() const {
    cout << "Your current balance is: PHP " << fixed << setprecision(2) << balance << "\n";
}

// Method to use balance for borrowing an item
bool PaymentSimulation::useBalance(double amount) {
    if (amount <= 0) {
        cout << "Invalid amount! Borrowing amount must be greater than zero.\n";
        return false;
    }

    if (balance >= amount) {
        balance -= amount;
        // Add transaction to history
        transactions.push_back("Borrowed: " + to_string(amount));
        cout << "Successfully borrowed the item. " << fixed << setprecision(2) << amount << " has been deducted from your balance.\n";
        return true;
    } else {
        cout << "Insufficient balance to borrow this item.\n";
        return false;
    }
}

// Accessor to get the current balance
double PaymentSimulation::getBalance() const {
    return balance;
}

// Method to view transaction history
void PaymentSimulation::viewTransactionHistory() const {
    if (transactions.empty()) {
        cout << "No transactions yet.\n";
    } else {
        cout << "Transaction History:\n";
        for (const auto& transaction : transactions) {
            cout << "- " << transaction << "\n";
        }
    }
}

