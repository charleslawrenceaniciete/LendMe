#include "RentalManagement.h"

RentalManagement::RentalManagement() : DATA_FILE("RentalAgreements.txt") { // Initializes the system and loads rental agreements from a file.//
    loadRentalAgreementsFromFile(); 
}

void RentalManagement::loadRentalAgreementsFromFile() { //Reads the rental agreements from a file and stores them in memory.//
    ifstream file(DATA_FILE);
    if (file.is_open()) {
        string itemName, rentedBy;
        time_t rentDate;
        int duration;

        while (getline(file, itemName)) {
            getline(file, rentedBy);
            file >> rentDate >> duration;
            file.ignore();  // To ignore the newline character after the duration

            RentalAgreement agreement = { itemName, rentedBy, rentDate, duration };
            rentalAgreements.push_back(agreement);
        }
        file.close();
    }
}

void RentalManagement::saveRentalAgreementsToFile() { // Saves the current rental agreements back to the file.//
    ofstream file(DATA_FILE);
    if (file.is_open()) {
        for (const auto& agreement : rentalAgreements) {
            file << agreement.itemName << endl;
            file << agreement.rentedBy << endl;
            file << agreement.rentDate << endl;
            file << agreement.duration << endl;
        }
        file.close();
    }
}

time_t RentalManagement::getCurrentDate(){ //Returns the current date (as a timestamp).
    return time(0);  // Get the current system time
}

string RentalManagement::formatDate(time_t date) { //Converts a timestamp into a readable date format.
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", localtime(&date));
    return string(buffer);
}

void RentalManagement::displayRentalAgreements() { //Shows all the rental agreements with details like the item, who rented it, when it was rented, and how long the rental lasts.
    if (rentalAgreements.empty()) {
        cout << "No rental agreements found.\n";
        return;
    }

    cout << "\nRental Agreements:\n";
    for (size_t i = 0; i < rentalAgreements.size(); ++i) {
        cout << i + 1 << ". Item: " << rentalAgreements[i].itemName
             << " | Rented by: " << rentalAgreements[i].rentedBy
             << " | Rent Date: " << formatDate(rentalAgreements[i].rentDate)
             << " | Duration: " << rentalAgreements[i].duration << " days"
             << " | Rental Ends: " << formatDate(rentalAgreements[i].rentDate + rentalAgreements[i].duration * 86400)
             << "\n";
    }
}

void RentalManagement::checkExpiredRentals() {

    time_t now = getCurrentDate();  // Get the current system time
    bool expiredFound = false;      // Flag to track if any expired rentals are found

    cout << "\nExpired Rentals:\n";

    for (const auto& agreement : rentalAgreements) {
        time_t rentalEndDate = agreement.rentDate + agreement.duration * 86400; // Calculate rental end date
        string expirationDate = formatDate(rentalEndDate);

        if (now >= rentalEndDate) {
            expiredFound = true;  // Set the flag to true if an expired rental is found

            // Display the expired rental in the specified format
            cout << "You borrowed " << agreement.itemName 
                 << " from " << agreement.rentedBy 
                 << ". It has expired. (" << expirationDate << ")\n";

            cout << "You lended " << agreement.itemName 
                 << " to " << agreement.rentedBy 
                 << ". It has expired. (" << expirationDate << ")\n\n";
        }
    }

    if (!expiredFound) {  // If no expired rentals were found, display a message
        cout << "No expired rentals found.\n";
    }
}



void RentalManagement::displayRentalHistory() {
    ifstream file(DATA_FILE);
    if (file.is_open()) {
        cout << "\nRental History:\n";

        string itemName, rentedBy;
        time_t rentDate;
        int duration;

        while (getline(file, itemName)) {
            getline(file, rentedBy);
            file >> rentDate >> duration;
            file.ignore();  // Ignore the newline character after the duration

            string formattedRentDate = formatDate(rentDate);
            string formattedEndDate = formatDate(rentDate + duration * 86400);

            cout << "You borrowed " << itemName << " from " << rentedBy
                 << ". It was returned on " << formattedEndDate << ".\n";
            cout << "You lended " << itemName << " to " << rentedBy
                 << ". It has been returned on " << formattedEndDate << ".\n\n";
        }
        file.close();
    } else {
        cout << "No rental history available.\n";
    }
}

#include "RentalManagement.h"

