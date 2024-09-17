#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include "administrator.h"

using namespace std;

class handling_Booking : public trainManagement  // Inherit trainManagement from main
{
    private:
        string train_number, name_of_passenger, number_of_tickets, seat_numbers, boarding_station, train_time, fare, train_info;
        ifstream file_in;
        ofstream file_out;
        int train_inquiry;
        void details()
        {
            file_out.open("booked_tickets.txt", ios :: in | ios :: app);
            file_in.open("train_details.txt", ios :: out);
            file_out << "Train: " << train_info << endl;
            file_out << "Ticket Inquiry Number: " << train_inquiry << endl;
            file_out << "Passenger name: " << name_of_passenger << endl;
            file_out << "Number of tickets: " << number_of_tickets << endl;
            file_out << "__________________________" << endl; // divider
            file_out.close();
            file_in.close();
        }

    public:
        void ticketBooking()
        {
            srand(time(0)); // use the random number generator and set the current time to 0
            /*Restricts the range of the random number to between 0 and 8999 
            (because % 9000 means the remainder when divided by 9000).
            Adding 1000 shifts the range, making it between 1000 and 9999, inclusive*/
            train_inquiry = rand() % 9000 + 1000; // train inquiry number
            train_info = search_train();
            cout << "Train: " << train_info << endl;
            cout << "Train inquiry number: " << train_inquiry << endl;
            cout << "Enter Passenger Name: " << endl;
            cin.ignore();
            getline(cin, name_of_passenger);
            cout << "Enter number of tickets: ";
            cin >> number_of_tickets;
            label:
            cout << "Boarding Station: ";
            cin >> boarding_station;
            details(); // writing above details in details file.
        }
        void view_bookings()
        {
            file_in.open("booked_tickets.txt", ios :: out);
            string booking_details;
            while (getline(file_in, booking_details))
            {
                cout << booking_details << endl;
            }
            file_in.close();
        }
        void search_booking()
        {
            file_in.open("booked_tickets.txt", ios :: out);
            string booking_search;
            cout << "Enter train inquiry number: ";
            cin >> booking_search;
            string search;
            while (getline(file_in, search))
            {
                if (search == ("Booking id: " + search))
                {
                    while (getline(file_in,search))
                    {
                        cout << search << endl;
                        if (search == "__________________________")
                        {
                            break;
                        }  
                    }
                    
                }
            }
            file_in.close();
        }
};