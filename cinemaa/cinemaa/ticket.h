#ifndef TICKET_H
#define TICKET_H

#include <string>
#include <vector>

struct Ticket {
    std::string movieTitle;
    std::string date;
    std::string hour;
    int seatNumber;
};

void viewBookedTickets();
extern std::vector<Ticket> bookedTickets;

#endif // TICKET_H
