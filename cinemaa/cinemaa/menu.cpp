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
    cout << "6. Admin Panel\n";
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
    };

    cout << "\n========== Available Movies ==========\n";
    for (const auto& movie : movies) {
        cout << "Title       : " << movie.title << "\n";
        cout << "Description : " << movie.description << "\n";
        cout << "Date        : " << movie.date << "\n";
        cout << "Hour        : " << movie.hour << "\n";
        cout << "Seats       : " << movie.availableSeats << "\n";
        cout << "--------------------------------------\n";
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
        case 6:
            adminPanel();
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
void Menu::adminPanel() {
    string password;
    cout << "\n=== Admin Login ===\n";
    cout << "Enter admin password: ";
    cin >> password;

    if (password != "admin") {
        cout << "Wrong password. Access denied.\n";
        return;
    }

    struct Movie {
        string title;
        string description;
        string date;
        string time;
        int seats;
    };

    static vector<Movie> movies = {
        {"Inception", "A mind-bending thriller.", "2025-06-10", "18:00", 25},
        {"Titanic", "A romance on a sinking ship.", "2025-06-17", "22:00", 28}
    };

    int choice;

    while (true) {
        cout << "\n--- Admin Panel ---\n";
        cout << "1. View Movies\n";
        cout << "2. Add Movie\n";
        cout << "3. Remove Movie\n";
        cout << "4. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nMovie List:\n";
            for (int i = 0; i < movies.size(); i++) {
                cout << i + 1 << ". " << movies[i].title << " - " << movies[i].date
                    << " " << movies[i].time << ", Seats: " << movies[i].seats << "\n";
                cout << "   " << movies[i].description << "\n";
            }
        }
        else if (choice == 2) {
            Movie m;
            cout << "Title: ";
            cin.ignore(); getline(cin, m.title);
            cout << "Description: ";
            getline(cin, m.description);
            cout << "Date (YYYY-MM-DD): ";
            cin >> m.date;
            cout << "Time (HH:MM): ";
            cin >> m.time;
            cout << "Available Seats: ";
            cin >> m.seats;

            movies.push_back(m);
            cout << "Movie added.\n";
        }
        else if (choice == 3) {
            int index;
            cout << "Enter movie number to remove: ";
            cin >> index;
            if (index >= 1 && index <= movies.size()) {
                movies.erase(movies.begin() + index - 1);
                cout << "Movie removed.\n";
            }
            else {
                cout << "Invalid number.\n";
            }
        }
        else if (choice == 4) {
            cout << "Exiting Admin Panel.\n";
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }
}
