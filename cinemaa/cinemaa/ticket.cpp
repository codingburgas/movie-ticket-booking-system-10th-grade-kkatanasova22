#include <iostream>
#include <vector>
#include <limits>
#include "ticket.h"

using namespace std;


vector<Ticket> bookedTickets = {};



void viewBookedTickets() {
    if (bookedTickets.empty()) {
        cout << "\nYou have no booked tickets.\n";
        return;
    }

    cout << "\n========== Your Booked Tickets ==========\n";
    for (size_t i = 0; i < bookedTickets.size(); ++i) {
        const Ticket& t = bookedTickets[i];
        cout << "Ticket " << i + 1 << ":\n";
        cout << "Movie Title : " << t.movieTitle << "\n";
        cout << "Date        : " << t.date << "\n";
        cout << "Hour        : " << t.hour << "\n";
        cout << "Seat Number : " << t.seatNumber << "\n";
        cout << "-----------------------------------------\n";
    }
}

void bookTicket() {
    vector<Ticket> availableMovies = {
        {"Inception", "2025-06-10", "18:00", 25},
        {"The Lion King", "2025-06-11", "15:00", 40},
        {"Interstellar", "2025-06-12", "20:00", 15},
        {"Avengers: Endgame", "2025-06-13", "19:30", 30}
    };

    cout << "\nAvailable Movies:\n";
    for (size_t i = 0; i < availableMovies.size(); ++i) {
        cout << i + 1 << ". " << availableMovies[i].movieTitle
            << " (" << availableMovies[i].date << " at " << availableMovies[i].hour
            << ") - Seats Available: " << availableMovies[i].seatNumber << "\n";
    }

    int choice;
    cout << "Select a movie by number: ";
    cin >> choice;

    if (cin.fail() || choice < 1 || choice > availableMovies.size()) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Invalid choice.\n";
        return;
    }

    Ticket selected = availableMovies[choice - 1];

    int seat;
    cout << "Enter seat number to book (1 to " << selected.seatNumber << "): ";
    cin >> seat;

    if (cin.fail() || seat < 1 || seat > selected.seatNumber) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid seat number.\n";
        return;
    }


    Ticket booked = selected;
    booked.seatNumber = seat;

    bookedTickets.push_back(booked);

    cout << "\n Ticket booked successfully!\n";
    cout << "Movie: " << booked.movieTitle << "\n";
    cout << "Date: " << booked.date << " at " << booked.hour << "\n";
    cout << "Seat: " << booked.seatNumber << "\n\n";
}void cancelTicket() {
    if (bookedTickets.empty()) {
        cout << "\nYou have no tickets to cancel.\n";
        return;
    }

    cout << "\n========== Your Booked Tickets ==========\n";
    for (size_t i = 0; i < bookedTickets.size(); ++i) {
        const Ticket& t = bookedTickets[i];
        cout << i + 1 << ". " << t.movieTitle << " - " << t.date << " at " << t.hour
            << " | Seat: " << t.seatNumber << "\n";
    }

    int cancelIndex;
    cout << "Enter the number of the ticket you want to cancel: ";
    cin >> cancelIndex;

    if (cin.fail() || cancelIndex < 1 || cancelIndex > bookedTickets.size()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid selection.\n";
        return;
    }

    bookedTickets.erase(bookedTickets.begin() + (cancelIndex - 1));
    cout << " Ticket cancelled successfully.\n";
}
