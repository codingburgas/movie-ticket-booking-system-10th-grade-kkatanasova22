#include <iostream>
#include "ticket.h"

using namespace std;


vector<Ticket> bookedTickets = {
    {"Inception", "2025-06-10", "18:00", 12},
    {"Titanic", "2025-06-17", "22:00", 5}
};

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
