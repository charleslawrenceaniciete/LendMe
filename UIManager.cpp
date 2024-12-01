#include "UIManager.h"
#include "ui.h"  
#include <cstdlib>
#include <iostream>

void UIManager::showMainMenu() {
    const std::string ORANGE_COLOR = "\033[38;5;202m";  
    const std::string RESET_COLOR = "\033[0m";        
    std::cout << ORANGE_COLOR; 
    cout << createLine('=', 53) << endl; 
    cout << centerText("LendMe User Manager Menu", 53) << endl;  
    cout << createLine('=', 53) << endl;
    std::cout << RESET_COLOR; 

    cout << "1. Login\n2. Register\n3. Forgot Password\n4. Exit\n";
}

void UIManager::showLoginMenu() {
    const std::string ORANGE_COLOR = "\033[38;5;202m";  
    const std::string RESET_COLOR = "\033[0m";        
    std::cout << ORANGE_COLOR; 
    cout << createLine('=', 53) << endl;  
    cout << centerText("", 53) << endl;  
    cout << createLine('=', 53) << endl;
    cout << "Please enter your username and password.\n";
    std::cout << RESET_COLOR; 
}
void UIManager::showRentalManagementMenu() {
    const string ORANGE_COLOR = "\033[38;5;202m";  
    const string RESET_COLOR = "\033[0m";        
    cout << ORANGE_COLOR; 
    cout << createLine('=', 53) << endl; 
    cout << centerText("Rental Management Menu", 53) << endl;  
    cout << createLine('=', 53) << endl;
    cout << RESET_COLOR; 

    cout << "1. View Rental Agreements\n2. Check Expired Rentals\n3. View Rental History\n4. Logout\n";
}


void UIManager::showRegistrationMenu() {
    const std::string ORANGE_COLOR = "\033[38;5;202m";  
    const std::string RESET_COLOR = "\033[0m";        
    std::cout << ORANGE_COLOR; 
    cout << createLine('=', 53) << endl;
    cout << centerText("Registration Menu", 53) << endl;
    cout << createLine('=', 53) << endl;
    cout << "Enter your username and password.\n";
    std::cout << RESET_COLOR; 
}

void UIManager::showForgotPasswordMenu() {
    const std::string ORANGE_COLOR = "\033[38;5;202m";  
    const std::string RESET_COLOR = "\033[0m";        
    std::cout << ORANGE_COLOR; 
    cout << createLine('=', 53) << endl;
    cout << centerText("Forgot Password Menu", 53) << endl;
    cout << createLine('=', 53) << endl;
    std::cout << RESET_COLOR; 
    cout << "Enter your username to recover your password.\n";

}

void UIManager::showMessage(const string& message) {
    const std::string ORANGE_COLOR = "\033[38;5;202m";  
    const std::string RESET_COLOR = "\033[0m";        
    std::cout << ORANGE_COLOR; 
    cout << createLine('*', 53) << endl;  
    cout << centerText(message, 53) << endl;  
    cout << createLine('*', 53) << endl;
    std::cout << RESET_COLOR; 
}




void UIManager::clearScreen() {
    #ifdef _WIN32
        system("cls"); 
    #else
        system("clear");
    #endif
}
