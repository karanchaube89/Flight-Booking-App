#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

// Struct to store flight details
struct Flight {
    string flightNumber;
    string destination;
    int totalSeats;
    int availableSeats;
};

// Class to manage the flight booking system
class FlightBookingSystem {
private:
    vector<Flight> flights;  // Stores all flights
    map<string, vector<int>> bookings;  // Maps flight number to list of booked seat numbers

public:
    // Function to add a new flight
    void addFlight(string flightNumber, string destination, int totalSeats) {
        flights.push_back({flightNumber, destination, totalSeats, totalSeats});
        bookings[flightNumber] = vector<int>(totalSeats, 0);  // Initialize all seats as available (0)
        cout << "Flight " << flightNumber << " to " << destination << " added with " << totalSeats << " seats." << endl;
    }

    // Function to display available flights
    void showFlights() {
        cout << "\nAvailable Flights:\n";
        for (const auto& flight : flights) {
            cout << "Flight Number: " << flight.flightNumber << ", Destination: " << flight.destination
                 << ", Available Seats: " << flight.availableSeats << "/" << flight.totalSeats << endl;
        }
    }

    // Function to book a seat on a specific flight
    bool bookSeat(string flightNumber, int seatNumber) {
        // Find the flight by its number
        for (auto& flight : flights) {
            if (flight.flightNumber == flightNumber) {
                // Check if seat number is valid
                if (seatNumber < 1 || seatNumber > flight.totalSeats) {
                    cout << "Invalid seat number. Please enter a seat number between 1 and " << flight.totalSeats << "." << endl;
                    return false;
                }
                // Check if the seat is already booked
                if (bookings[flightNumber][seatNumber - 1] == 1) {
                    cout << "Seat " << seatNumber << " is already booked." << endl;
                    return false;
                }
                // Book the seat
                bookings[flightNumber][seatNumber - 1] = 1;
                flight.availableSeats--;
                cout << "Seat " << seatNumber << " on flight " << flightNumber << " has been successfully booked." << endl;
                return true;
            }
        }
        cout << "Flight " << flightNumber << " not found." << endl;
        return false;
    }
};

int main() {
    FlightBookingSystem system;
    int choice;

    while (true) {
        cout << "\nFlight Booking System Menu:\n";
        cout << "1. Add Flight\n2. View Flights\n3. Book Seat\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string flightNumber, destination;
            int totalSeats;
            cout << "Enter flight number: ";
            cin >> flightNumber;
            cout << "Enter destination: ";
            cin >> destination;
            cout << "Enter total number of seats: ";
            cin >> totalSeats;
            system.addFlight(flightNumber, destination, totalSeats);
        } else if (choice == 2) {
            system.showFlights();
        } else if (choice == 3) {
            string flightNumber;
            int seatNumber;
            cout << "Enter flight number: ";
            cin >> flightNumber;
            cout << "Enter seat number to book: ";
            cin >> seatNumber;
            system.bookSeat(flightNumber, seatNumber);
        } else if (choice == 4) {
            cout << "Exiting the system. Thank you for using the flight booking system.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}