#include <iostream>
#include <string>
#include "payment.h"

using namespace std;

bool processPayment(double amount) {
    int method;
    cout << "\n====== Payment ======\n";
    cout << "Ticket Price: $" << amount << "\n";
    cout << "Choose Payment Method:\n";
    cout << "1. Credit/Debit Card\n";
    cout << "2. PayPal\n";
    cout << "3. Cancel Payment\n";
    cout << "Enter choice: ";
    cin >> method;

    switch (method) {
    case 1:
    case 2: {
        string confirm;
        cout << "Confirm payment of $" << amount << "? (yes/no): ";
        cin >> confirm;
        if (confirm == "yes" || confirm == "y") {
            cout << " Payment successful!\n";
            return true;
        }
        else {
            cout << " Payment cancelled.\n";
            return false;
        }
    }
    case 3:
        cout << " Payment cancelled.\n";
        return false;
    default:
        cout << " Invalid option. Payment failed.\n";
        return false;
    }
}
