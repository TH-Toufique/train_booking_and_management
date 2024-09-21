#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include "administrator.h"

using namespace std;

class handling_Booking : public train_Management  // Inherit trainManagement from main
{
    private:
	string trainNo, name_of_passenger, gender, seat, age, boarding_station, timing, fare, totalFare, train_info;
        ifstream file_in;
        ofstream file_out;
        int train_inquiry, number_of_passenger, userCount;
        void details()
        {
            file_out.open("booked_tickets.txt", ios :: out | ios :: app);
            file_in.open("train_details.txt", ios :: in);
		    if (userCount == 1)
		    {
			    file_out << "Train : " << train_info << endl;
			    file_out << "Total number of passengers: " << number_of_passenger << endl << endl;
		    }
            file_out << "Passenger name: " << name_of_passenger << endl;
		    file_out << "Gender: " << gender << "      Age: " << age << endl;
		    file_out << "Seat number: " << seat << endl << endl;
		    if (userCount == number_of_passenger)
		    {
			    file_out << "_________________________" << endl;
		    }
            else file_out << endl;
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
		    cout << "Number of Passenger: ";
		    cin >> number_of_passenger;
            label:
            cout << "Boarding Station: ";
            cin >> boarding_station;
            for (userCount = 1; userCount <= number_of_passenger; userCount++)
		    {
			    cout << "Enter name of " << userCount << "th passenger: ";
			    cin.ignore();
			    getline(cin, name_of_passenger);
			    cout << "Gender :";
			    cin >> gender;
			    cout << "Age :";
			    cin >> age;
			    seatNumberShow();
			    cin >> seat;
			    details();
		    }
        #ifdef _WIN32
        system("cls"); // Clear powershell or windows terminal
        #else
        system("clear"); // For clearing the terminal
        #endif
		paymentPage(getFare(train_info.substr(0, 4)) * number_of_passenger);
		cin >> fare;
		cout <<"Payment done successfully"<< endl << endl;
		booked_seats(train_info.substr(0, 4), number_of_passenger, 0);
		cout << "Please note down your TIN number for further reference: " << endl;
		cout << "\t\tTicket inquiry number: " << train_inquiry << endl << endl;
        }

        void view_bookings()
        {
            file_in.open("booked_tickets.txt", ios :: out);
            string bookings;
            while (getline(file_in, bookings))
            {
                cout << bookings << endl;
            }
            file_in.close();
        }
        void search_booking()
        {
            file_in.open("tickets.txt", ios :: out);
            string search_booked;
            string booking_reading;
            cout << "Enter train inquiry number: ";
            cin >> search_booked;
            while (getline(file_in, booking_reading))
            {
                if (booking_reading == ("Train inquiry number: " + search_booked))
                {
                    while (getline(file_in, booking_reading))
                    {
                        cout << booking_reading << endl;
                        if (booking_reading == "__________________________")
                        {
                            break;
                        }
                    }
                }
            }
            file_in.close();
        }

    void cancelTicket()
    {
        ifstream readTicket("tickets.txt");
        string search, line;
        cout << "Enter ticket inquiry number: ";
        cin >> search;
		while(getline(readTicket, line)){
			if (line == "Ticket inquiry number: " + search){
				string tn, nop, y;
				getline(readTicket,y);
				tn = y.substr(8,4); 
				getline(readTicket,y);
				nop = y.substr(28,1);
				cout<<tn<<nop<<endl;
				booked_seats(tn, 0, stoi(nop));
			}
		}
		readTicket.close();
		ifstream trainIn("tickets.txt");
        ofstream tempFile("temp_file.txt");
        bool found = false;
        while (getline(trainIn, line))
        {
            if (line == "Ticket inquiry number: " + search)
            {
				found = true;
                while (getline(trainIn, line))
                {
                    if (line == "_________________________")
                        break;
                }
            }
            else
            {
                tempFile << line << '\n';
            }
        }
        trainIn.close();
        tempFile.close();
        if (!found)
            cout << "Ticket not found in the file." << endl;
        else
        {
            remove("Tickets.txt");
            rename("TempFile.txt", "Tickets.txt");
            cout << "Ticket cancelled successfully." << endl;
        }
    }

};