#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "administrator.h"

using namespace std;

class ticket_booking : public train_management
{
private:
    string trainNo, nameOfPassenger, gender, seat, age, boardingStation, timing, fare, totalFare, train_info;
    ifstream file_in;
    ofstream file_out;
    int tin, numberOfPassenger, userCount;
    void storeInFile()
    {
        file_out.open("Tickets.txt", ios::in | ios::app);
        file_in.open("TrainFile.txt", ios::out);
        if (userCount == 1)
        {
            file_out << "Ticket inquiry number: " << tin << endl;
            file_out << "Train : " << train_info << endl;
            file_out << "Total number of passengers: " << numberOfPassenger << endl
                     << endl;
        }
        file_out << "Passenger name: " << nameOfPassenger << endl;
        file_out << "Gender: " << gender << "      Age:  " << age << endl;
        file_out << "Seat number: " << seat << endl;
        if (userCount == numberOfPassenger)
        {
            file_out << "_________________________" << endl;
        }
        else
            file_out << endl;
        file_out.close();
        file_in.close();
    }
};

public:
void bookTicket()
{
    srand(time(0));
    tin = rand() % 9000 + 1000; // train inquiry number
    train_info = searchTrain();
    cout << "Number of Passenger: ";
    cin >> numberOfPassenger;
    cout << "Boarding Station: ";
    cin >> boardingStation;
    for (userCount = 1; userCount <= numberOfPassenger; userCount++)
    {
        cout << "Enter name of " << userCount << "th passenger: ";
        cin.ignore();
        getline(cin, nameOfPassenger);
        cout << "Gender :";
        cin >> gender;
        cout << "Age :";
        cin >> age;
        seatNumberShow();
        cin >> seat;
        storeInFile();
    }
    system("cls");
    paymentPage(getFare(train_info.substr(0, 4)) * numberOfPassenger);
    cin >> fare;
    cout << "Payment done successfully" << endl
         << endl;
    seatBooked(train_info.substr(0, 4), numberOfPassenger, 0);
    cout << "Please note down your TIN number for further reference: " << endl;
    cout << "\t\tTicket inquiry number: " << tin << endl
         << endl;
}
void viewBookings()
{
    fin.open("Tickets.txt", ios::out);
    string x;
    while (getline(fin, x))
    {
        cout << x << endl;
    }
    fin.close();
}

void cancelTicket()
{
    ifstream readTicket("Tickets.txt");
    string search, line;
    cout << "Enter ticket inquiry number: ";
    cin >> search;
    while (getline(readTicket, line))
    {
        if (line == "Ticket inquiry number: " + search)
        {
            string tn, nop, y;
            getline(readTicket, y);
            tn = y.substr(8, 4);
            getline(readTicket, y);
            nop = y.substr(28, 1);
            cout << tn << nop << endl;
            seatBooked(tn, 0, stoi(nop));
        }
    }
    readTicket.close();

    ifstream train_in("Tickets.txt");
    ofstream temp_file("TempFile.txt");
    bool found = false;
    while (getline(train_in, line))
    {
        if (line == "Ticket inquiry number: " + search)
        {
            found = true;
            while (getline(train_in, line))
            {
                if (line == "_________________________")
                    break;
            }
        }
        else
        {
            temp_file << line << '\n';
        }
    }
    train_in.close();
    temp_file.close();
    if (!found)
        cout << "Ticket not found in the file." << endl;
    else
    {
        remove("Tickets.txt");
        rename("TempFile.txt", "Tickets.txt");
        cout << "Ticket cancelled successfully." << endl;
    }
};