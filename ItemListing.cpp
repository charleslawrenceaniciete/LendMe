#include "ItemListing.h"

ItemListing::ItemListing() : DATA_FILE("ItemListing.txt") {  
    loadItemsFromFile();  
}

void ItemListing::loadItemsFromFile() {
    ifstream file(DATA_FILE);
    if (file.is_open()) {
        string name, description;
        double rentalPrice;
        bool available;

        while (getline(file, name)) {
            getline(file, description);
            file >> rentalPrice >> available;
            file.ignore();  

            Item item = { name, description, rentalPrice, available };
            items.push_back(item);
        }
        file.close();
    }
}

void ItemListing::saveItemsToFile() {
    ofstream file(DATA_FILE);
    if (file.is_open()) {
        for (size_t i = 0; i < items.size(); ++i) {
            const Item& item = items[i];
            file << item.name << endl;
            file << item.description << endl;
            file << item.rentalPrice << endl;
            file << item.available << endl;
        }
        file.close();
    }
}

void ItemListing::displayItems() {
    if (items.empty()) {
        cout << "\nNo items available.\n";
        return;
    }

    cout << "\nAvailable Items:\n";
    cout << "-------------------------------------------------------------\n";
    for (size_t i = 0; i < items.size(); ++i) {
        const Item& item = items[i];
        cout << "Item #" << i + 1 << ":\n";
        cout << "-------------------------------------------------------------\n";
        cout << "Name        : " << item.name << "\n";
        cout << "Description : " << item.description << "\n";
        cout << "Rental Price: PHP " << item.rentalPrice << "\n";
        cout << "Availability: " << (item.available ? "Available" : "Not Available") << "\n";
        cout << "-------------------------------------------------------------\n";
    }
}

void ItemListing::addItem() {
    Item item;
    cout << "\nEnter item details to add:\n";
    cout << "-------------------------------\n";
    cout << "Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, item.name);

    cout << "Description: ";
    getline(cin, item.description);

    cout << "Rental Price: PHP ";
    while (!(cin >> item.rentalPrice) || item.rentalPrice < 0) {
        cout << "Invalid input. Please enter a valid rental price: ";
        cin.clear();  
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
    }

    cout << "Is the item available? (1 for Yes, 0 for No): ";
    int availabilityInput;
    while (!(cin >> availabilityInput) || (availabilityInput != 0 && availabilityInput != 1)) {
        cout << "Invalid input. Please enter 1 for Yes or 0 for No: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    item.available = static_cast<bool>(availabilityInput);

    items.push_back(item);
    saveItemsToFile();
    cout << "\nItem added successfully!\n";
}

void ItemListing::removeItem() {
    if (items.empty()) {
        cout << "\nNo items available to remove.\n";
        return;
    }

    int index;
    displayItems();
    cout << "\nEnter the number of the item to remove: ";
    while (!(cin >> index) || index <= 0 || index > static_cast<int>(items.size())) {
        cout << "Invalid input. Please enter a valid item number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    items.erase(items.begin() + index - 1);
    saveItemsToFile();
    cout << "\nItem removed successfully!\n";
}

#include "PaymentSimulation.h"  // Include the header for PaymentSimulation

void ItemListing::borrowItem(PaymentSimulation &payment) {
    if (items.empty()) {
        cout << "\nNo items available to borrow.\n";
        return;
    }

    int index;
    double itemCost = 10.0; // Example cost of borrowing an item, adjust as necessary
    cout << "\nBorrow Item:\n";
    displayItems();
    cout << "\nEnter the number of the item you want to borrow: ";
    while (!(cin >> index) || index <= 0 || index > static_cast<int>(items.size())) {
        cout << "Invalid input. Please enter a valid item number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Check if the user has enough balance to borrow the item
    if (payment.useBalance(itemCost)) {  // If balance is sufficient
        if (items[index - 1].available) {
            items[index - 1].available = false;
            saveItemsToFile();
            cout << "\nItem borrowed successfully!\n";
        } else {
            cout << "\nSorry, the item is already borrowed.\n";
        }
    } else {
        cout << "\nThank you for supporting LendMe!\n";
    }
}


void ItemListing::searchItems() {
    string searchQuery;
    cout << "\nEnter the item name to search: ";
    cin.ignore();
    getline(cin, searchQuery);

    bool found = false;
    cout << "\nSearch Results:\n";
    cout << "-------------------------------------------------------------\n";
    for (size_t i = 0; i < items.size(); ++i) {
        const Item& item = items[i];
        if (item.name.find(searchQuery) != string::npos) {
            cout << "Name        : " << item.name << "\n";
            cout << "Description : " << item.description << "\n";
            cout << "Rental Price: PHP " << item.rentalPrice << "\n";
            cout << "Availability: " << (item.available ? "Available" : "Not Available") << "\n";
            cout << "-------------------------------------------------------------\n";
            found = true;
        }
    }

    if (!found) {
        cout << "\nNo items found matching your search.\n";
    }
}