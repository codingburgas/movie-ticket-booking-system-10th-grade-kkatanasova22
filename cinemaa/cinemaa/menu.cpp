#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "menu.h"
#include "ticket.h"


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
    cout << "5. Help\n";
    cout << "Enter your choice: ";
}

void Menu::displayMovies() {
    struct Movie {
        string title;
        string description;
        string date;
        string hour;
        int availableSeats;
    };

    vector<Movie> movies = {
        {"Inception", "A mind-bending thriller by Christopher Nolan.", "2025-06-10", "18:00", 25},
        {"The Lion King", "An animated masterpiece about the circle of life.", "2025-06-11", "15:00", 40},
        {"Interstellar", "A journey through space and time.", "2025-06-12", "20:00", 15},
        {"Avengers: Endgame", "Superheroes assemble for an epic battle.", "2025-06-13", "19:30", 30},
        {"Parasite", "A darkly comedic tale of class struggle.", "2025-06-14", "17:00", 18},
        {"The Godfather", "A classic mafia family saga.", "2025-06-15", "21:00", 12},
        {"Spirited Away", "A magical journey in a mysterious world.", "2025-06-16", "13:00", 20},
        {"Titanic", "A timeless romance on the ill-fated ship.", "2025-06-17", "22:00", 28}
    };

    cout << "\nAvailable Movies:\n";
    cout << "--------------------------------------------------\n";
    for (const auto& movie : movies) {
        cout << "Title: " << movie.title << "\n";
        cout << "Description: " << movie.description << "\n";
        cout << "Date: " << movie.date << "\n";
        cout << "Hour: " << movie.hour << "\n";
        cout << "Available Seats: " << movie.availableSeats << "\n";
        cout << "--------------------------------------------------\n";
    }
}

void Menu::printHelp() {
    cout << "\n========== Help Menu ==========\n";
    cout << "1. Book a Ticket        - Choose this to see available movies and book a seat.\n";
    cout << "2. View Booked Tickets  - Shows all your current bookings.\n";
    cout << "3. Cancel a Ticket      - Allows you to cancel a previously booked ticket.\n";
    cout << "4. Exit                 - Exit the Ticket Booking System.\n";
    cout << "5. Help                 - Show this help information.\n";
    cout << "===============================\n\n";
}

void Menu::handleUserChoice() {
    int choice;
    printWelcomeMessage();
    while (true) {
        displayMainMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            bookTicket();
            break;
        case 2:
            viewBookedTickets();
            break;

        case 3:
            cancelTicket();
            break;

        case 4:
            cout << "Exiting the system. Goodbye!\n";
            return;
        case 5:
            printHelp();
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
