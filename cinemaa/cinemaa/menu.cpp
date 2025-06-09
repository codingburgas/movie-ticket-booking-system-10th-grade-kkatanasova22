#include <iostream>
#include "menu.h"

using namespace std;

void Menu::printWelcomeMessage() {
    cout << "============================================\n";
    cout << "   Welcome to the Ticket Booking System!    \n";
    cout << "   Your journey starts with a simple step.  \n";
    cout << "============================================\n\n";
}

void Menu::displayMainMenu() {
    cout << "=============================\n";
    cout << "     Ticket Booking System   \n";
    cout << "=============================\n";
    cout << "1. Book a Ticket\n";
    cout << "2. View Booked Tickets\n";
    cout << "3. Cancel a Ticket\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

void Menu::handleUserChoice() {
    int choice;
    printWelcomeMessage();
    while (true) {
        displayMainMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Booking a ticket...\n";
            
            break;
        case 2:
            cout << "Viewing booked tickets...\n";
           
            break;
        case 3:
            cout << "Cancelling a ticket...\n";
            
            break;
        case 4:
            cout << "Exiting the system. Goodbye!\n";
            return;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}