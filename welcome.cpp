#include <iostream>
#include "ui.h"
#include "UIManager.h"
#include <cstdlib>  // For system("clear")
#include <limits>   // For std::numeric_limits

UIManager welcomeStuff;

void displayWelcome() {
    welcomeStuff.clearScreen(); 
    const std::string ORANGE_COLOR = "\033[38;5;202m";  
    const std::string RESET_COLOR = "\033[0m";        
    std::cout << ORANGE_COLOR; 
    
    std::cout << "██╗     ███████╗███╗   ██╗██████╗ ███╗   ███╗███████╗\n";
    std::cout << "██║     ██╔════╝████╗  ██║██╔══██╗████╗ ████║██╔════╝\n";
    std::cout << "██║     █████╗  ██╔██╗ ██║██║  ██║██╔████╔██║█████╗  \n";
    std::cout << "██║     ██╔══╝  ██║╚██╗██║██║  ██║██║╚██╔╝██║██╔══╝  \n";
    std::cout << "███████╗███████╗██║ ╚████║██████╔╝██║ ╚═╝ ██║███████╗\n";
    std::cout << "╚══════╝╚══════╝╚═╝  ╚═══╝╚═════╝ ╚═╝     ╚═╝╚══════╝\n";
    std::cout << RESET_COLOR; 
    
    std::cout << createLine('-', 53) << std::endl; 
    std::cout << "Welcome to LendMe!" << std::endl;
    std::cout << "A Peer-to-Peer Resource Sharing Application" << std::endl << std::endl;
    std::cout << "Press Enter to continue..." << std::endl;

    std::string userInput;
    while (true) { 
        std::cout << "Do you want to continue? (yes/no): ";
        std::getline(std::cin, userInput);

        if (userInput == "yes" || userInput == "Yes") {
            std::cout << "Thank you for continuing!" << std::endl;
            break; 
        } else if (userInput == "no" || userInput == "No") {
            std::cout << "Goodbye!" << std::endl;
            exit(0);
        } else {
            std::cout << "Invalid input. Please enter 'yes' or 'no'." << std::endl;
        }
    }
}