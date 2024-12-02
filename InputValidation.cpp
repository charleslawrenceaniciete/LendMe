// input_validation.cpp
#include "InputValidation.h"
#include <limits>

using namespace std;

int getValidChoice() {
    int choice;
    while (true) {
        cin >> choice;
        
        // Check if input failed (non-integer input)
        if (cin.fail()) {
            // Clear the error flag and ignore remaining input in the buffer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid number: ";
        } else {
            return choice;  // Valid input, exit the loop
        }
    }
}
