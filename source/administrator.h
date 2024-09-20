#ifndef ADMINISTRATOR_H //To avoid compiling error it has been assinged for unique header file
#define ADMINISTRATOR_H
#include<iostream>
#include<fstream>
#include<string>

using namespace std;


class train_Management
{
private:
    string train_number, number_of_seats, train_name, route, train_time, fare, line, y;
    ofstream train_in;
    ifstream train_out;

    // Store train data in the file
    void trainData()
    {
        train_in.open("train_details.txt", ios::app);  // Writing to file
        train_in << "Train number: " << train_number << endl;
        train_in << "Name of train: " << train_name << endl;
        train_in << "Number of seats: " << number_of_seats << endl;
        train_in << "Route: " << route << endl;
        train_in << "Train time: " << train_time << endl;
        train_in << "Fare: " << fare << endl;
        train_in << "___________________________" << endl;  // Dividing details
        train_in.close();
    }

public:
    // Add train details
    void add_train()
    {
        cout << "Enter train number(4 digits): ";
        cin >> train_number;
        cin.ignore(); // Ignore the new line character

        cout << "Enter train name: ";
        getline(cin, train_name);
        cout << "Enter route: ";
        getline(cin, route);
        cout << "Enter train timings(eg. 6:00pm-7:00am): ";
        cin >> train_time;
        cout << "Enter number of seats: ";
        cin >> number_of_seats;
        cout << "Enter fare: ";
        cin >> fare;
        trainData();
    }

    // View all trains
    void view_trains()
    {
        train_out.open("train_details.txt", ios::in);  // Reading from file
        if (!train_out) {
            cout << "No trains found!" << endl;
            return;
        }
        string train_list;
        while (getline(train_out, train_list))
        {
            cout << train_list << endl;
        }
        train_out.close();
    }

    // Search for a specific train
    string search_train()
    /*value will be returned and in handlingBooking header file 
    we are using = operator or assign operator which  is essential for assigning values*/
    {
        train_out.open("train_details.txt", ios::in);  // Reading from file

        if (!train_out) {
            cout << "No trains found!" << endl;
            return 0;
        }

        cout << "Enter train number: ";
        cin >> train_number;

        bool found = false;

        while (getline(train_out, line))
        {
            if (line == "Train number: " + train_number)
            {
                found = true;
                getline(train_out, line);
                cout << "\n" << y << endl;
                while (getline(train_out, y))
                {   
                    cout << line << endl;
                    if (line == "___________________________")
                    {
                        break;
                    }
                }
            }
        }
        train_out.close();
        if (!found)
        {
            cout << "Train not found" << endl;
            system("pause");
        }
        else
        {
            return train_number + y.substr(14, y.length() - 14);
        }

    }

    // Delete a train
    void delete_train()
    {
        ifstream train_in("train_details.txt");
        if (!train_in) {
            cout << "No trains found!" << endl;
            return;
        }

        cout << "Enter train number: ";
        cin >> train_number;

        ofstream tempFile("tempFile.txt");
        bool train_found = false;

        while (getline(train_in, line))
        {
            if (line == "Train number: " + train_number)
            {
                train_found = true;
                while (getline(train_in, line))
                {
                    if (line == "___________________________")
                    {
                        break;
                    }
                }
            }
            else
            {
                tempFile << line << '\n';
            }
        }
        train_in.close();
        tempFile.close();

        if (!train_found)
        {
            cout << "Train not found in the database" << endl;
        }
        else
        {
            remove("train_details.txt");
            rename("tempFile.txt", "train_details.txt");
            cout << "Train deleted successfully" << endl;
        }
    }

    void booked_seats(string TrainNumber, int number_of_passenger_on_booking, int number_of_passenger_on_cancelling)
    {
        train_out.open("Train_details.txt", ios :: app);
        string old_seat, new_seat;
        int line = 0;
        while (getline(train_out, y))
        {
            if (y ==("Train Number: " + train_number))
            {
                while (getline(train_out, y))
                {
                    line++;
                    if (line == 3)
                    {
                        old_seat = y;
                        number_of_seats = (to_string)(stoi(y.substr(17, y.length() - 17)) - number_of_passenger_on_booking + number_of_passenger_on_cancelling);
                        new_seat = "Number of seats: " + number_of_seats;
                    }
                    
                }
                
            }
            train_out.close();
            update(old_seat, new_seat);
        }
    }

    int getFare(string TrainNumber)
    {
        train_out.open("TrainFile.txt", ios::in);
        int line = 0;
        while (getline(train_out, y))
        {
            if (y == ("Train number: " + TrainNumber))
            {
                while (getline(train_out, y))
                {
                    line++;
                    if (line == 5)
                    {
                        train_out.close();
                        return stoi(y.substr(5, y.length() - 5));
                    }
                }
            }
        }
    }

    void update(string old_line, string new_line)
    {
        ifstream trainIn("train_details.txt");
        ofstream tempFile("tempFile.txt");

        while (getline(trainIn, line))
        {
            (line == old_line) ? tempFile << new_line << '\n' : tempFile << line << '\n';

            trainIn.close();
            tempFile.close();
            remove("train_details.txt");
            remove("tempFile.txt");
        }
    }

};


void seatNumberShow() {
    #ifdef _WIN32
    system("cls"); // Clear powershell or windows terminal
    #else
    system("clear"); // For clearing the terminal
    #endif
    cout <<"--------------------------------------------------------------------------" << endl;
    cout << "                         -----SEAT NUMBER-----                           " << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "SL         SU          LB          MB          UB" << endl << endl;
    cout << "01         02          03          04          05" << endl;
    cout << "06         07          08          09          10" << endl;
    cout << "11         12          13          14          15" << endl;
    cout << "16         17          18          19          20" << endl;
    cout << "21         22          23          24          25" << endl;
    cout << "26         27          28          29          30" << endl;
    cout << "31         32          33          34          35" << endl;
    cout << "36         37          38          39          40" << endl;
    cout << "41         42          43          44          45" << endl;
    cout << "46         47          48          49          50" << endl;
    cout << "51         52          53          54          55" << endl << endl;
    cout << "Choose the seat number: ";
}
void paymentPage(int amount) {
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "                         -----PAYMENT PAGE-----                          " << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Total Amount is TK. "<< amount<< endl << endl;
    cout << "Choose the mode of payment ... " << endl << endl;
    cout << "1. Cash\n\n";
    cout << "2. Card\n\n";
    cout << "3. Bkash\n\n";
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Select an option: ";
}

void passwordMenu(){
    system("cls");
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "                         -----CHANGE PASSWORD-----                       " << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Enter your old password: ";
}

#endif // ADMINISTRATOR_H