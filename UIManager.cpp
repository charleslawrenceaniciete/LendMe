#include "UIManager.h"
#include "ui.h"  
#include <cstdlib>
#include <iostream>
#include <regex>

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
    cout << centerText("Login Menu", 53) << endl;  
    cout << createLine('=', 53) << endl;
    cout << "Please enter your username and password.\n";
    std::cout << RESET_COLOR; 
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

/* Rental Management Stuff*/
/* Rental Management Stuff*/
/* Rental Management Stuff*/

void UIManager::showRentalManagementMenu() {
    const string ORANGE_COLOR = "\033[38;5;202m";  
    const string RESET_COLOR = "\033[0m";        
    cout << ORANGE_COLOR; 
    cout << createLine('=', 53) << endl; 
    cout << centerText("Rental Management Menu", 53) << endl;  
    cout << createLine('=', 53) << endl;
    cout << RESET_COLOR; 

    cout << "1. View Rental Agreements\n2. Check Expired Rentals\n3. View Rental History\n4. Return\n";
}

/*Item Listing Stuff*/
/*Item Listing Stuff*/
/*Item Listing Stuff*/

std::string removeEscapeSequences(const std::string& str) {
    std::string cleanStr = std::regex_replace(str, std::regex("\033\\[([0-9;]+)m"), "");
    return cleanStr;
}

void UIManager::showUserDashboard(const std::string& username) {
    const std::string ORANGE_COLOR = "\033[38;5;202m";  
    const std::string WHITE_COLOR = "\033[37m";    // Color for white text
    const std::string RESET_COLOR = "\033[0m";        
    
    const int TOTAL_WIDTH = 53;  // Total width of the line
    
    std::cout << ORANGE_COLOR; 
    std::cout << createLine('=', TOTAL_WIDTH) << std::endl;  

    // Create the welcome message and calculate its length without color codes
    std::string welcomeMessage = "Welcome, " + WHITE_COLOR + username + RESET_COLOR;
    int messageLength = removeEscapeSequences(welcomeMessage).length();
    
    // Calculate padding to center the message
    int padding = (TOTAL_WIDTH - messageLength) / 2;
    
    // Display the message with proper padding
    std::cout << std::string(padding, ' ') << welcomeMessage << std::endl;
    
    std::cout << ORANGE_COLOR;
    std::cout << createLine('=', TOTAL_WIDTH) << std::endl;
    std::cout << RESET_COLOR; 

    std::cout << "1. Item Listing\n2. Rental Management\n3. LendMe Credits\n4. Logout\n";
}

void UIManager::clearScreen() {
    #ifdef _WIN32
        system("cls"); 
    #else
        system("clear");
    #endif
}
