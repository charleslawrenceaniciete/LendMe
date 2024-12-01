// PaymentSimulation.h
#ifndef PAYMENTSIMULATION_H
#define PAYMENTSIMULATION_H

#include <vector>
#include <string>

class PaymentSimulation {
private:
    double balance; // User's balance
    std::vector<std::string> transactions; // Transaction history

public:
    // Constructor to initialize the balance to zero
    PaymentSimulation();

    // Method to top up balance
    void topUpBalance(double amount);

    // Method to view current balance
    void viewBalance() const;

    // Method to use balance for borrowing an item
    bool useBalance(double amount);

    // Accessor to get the current balance
    double getBalance() const;

    // Method to view transaction history
    void viewTransactionHistory() const;
};

#endif // PAYMENTSIMULATION_H
