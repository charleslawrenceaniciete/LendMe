#ifndef UIMANAGER_H
#define UIMANAGER_H
//#pragma message("Including UIManager.h")


#include <string>
using namespace std;

class UIManager {
public:
    void showMainMenu();
    void showLoginMenu();
    void showRegistrationMenu();
    void showForgotPasswordMenu();
    void showMessage(const string& message);
    void clearScreen();
    void showRentalManagementMenu();
    void showUserDashboard(const std::string& username);
};

#endif
