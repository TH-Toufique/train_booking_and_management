#ifndef ADMINISTRATOR_H //To avoid compiling error it has been assinged for unique header file
#define ADMINISTRATOR_H
#include<iostream>
#include<fstream>
#include<string>

using namespace std;


class train_Management
{
public:
    string train_number, train_name, train_route, number_of_seats, train_time, train_fare, line, y; // line & y are used to store the data temporarily
    ofstream train_in;
    ifstream train_out;
    // Store train data in the file
    void trainData()
    {
        train_in.open("train_details.txt", ios::app);  // Writing to file
        train_in << "Train number: " << train_number << endl;
        train_in << "Name of train: " << train_name << endl;
        train_in << "Number of seats: " << number_of_seats << endl;
        train_in << "Route: " << train_route << endl;
        train_in << "Train time: " << train_time << endl;
        train_in << "Fare: " << train_fare << endl;
        train_in << "___________________________" << endl;  // Dividing details
        train_in.close();
    }

public:
    // Add train details
    void add_train()
    {
        return_loop:
        cout << "Enter train number(4 digits): ";
        cin >> train_number;
                train_out.open("TrainFile.txt", ios::in);
        while (getline(train_out, line))
        {
            if (line == ("Train number: " + train_number))
            {
                cout << "Train already exists" << endl;
                train_out.close();
                goto return_loop;
            }
        }
        cin.ignore(); // Ignore the new line character

        cout << "Enter train name: ";
        getline(cin, train_name);
        cout << "Enter route: ";
        getline(cin, train_route);
        cout << "Enter train timings(eg. 6:00pm-7:00am): ";
        cin >> train_time;
        cout << "Enter number of seats: ";
        cin >> number_of_seats;
        cout << "Enter fare: ";
        cin >> train_fare;
        trainData();
    }

    // View all trains
    void view_trains()
    {
        train_out.open("train_details.txt", ios::out);
        while (getline(train_out, y))
        {
            cout << y << endl;
        }
        train_out.close();
    }

string search_train() {
    train_out.open("train_details.txt", ios::in);  // Open file for reading

    if (!train_out) {
        cout << "No trains found!" << endl;
        return ""; // Return empty string instead of 0
    }

    string train_number;
    cout << "Enter train number: ";
    cin >> train_number;

    bool found = false;
    string line;
    string train_details;

    while (getline(train_out, line)) {
        if (line == "Train number: " + train_number) {
            found = true;
            cout << "\n" << line << endl; // Display the train number
            while (getline(train_out, line)) {
                if (line == "___________________________") {
                    break; // Stop when the delimiter is found
                }
                cout << line << endl; // Display the train details
                train_details += line + "\n"; // Collect train details
            }
            break; // Exit the loop after finding the train
        }
    }

    train_out.close();
    
    if (!found) {
        cout << "Train not found" << endl;
        return ""; // Return empty string when not found
    } else {
        // Safely return the details
        if (train_details.length() > 14) {
            return train_number + train_details.substr(14); // Adjusted to avoid out of range
        } else {
            return train_number + train_details; // If details are shorter than 14 characters
        }
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
        int i = 0;
        while (getline(train_out, y))
        {
            if (y ==("Train Number: " + train_number))
            {
                while (getline(train_out, y))
                {
                    i++;
                    if (i == 3)
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
        int i = 0;
        while (getline(train_out, y))
        {
            if (y == ("Train number: " + TrainNumber))
            {
                while (getline(train_out, y))
                {
                    i++;
                    if (i == 5)
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


class updateTrain : public train_Management
{
public:
    void dataUpdate()
    {
        search_train();
        train_out.open("TrainFile.txt", ios::in);
        while (getline(train_out, y))
        {
            if (y == ("Train number: " + train_number))
            {
                train_number = y;
                getline(train_out, y);
                train_name = y;
                getline(train_out, y);
                train_route = y;
                getline(train_out, y);
                number_of_seats = y;
                getline(train_out, y);
                train_time = y;
                getline(train_out, y);
                train_fare = y;
            }
        }
        train_out.close();
    }
    void updateTrainNumber()
    {
        string new_train_number;
        cout << "Enter new train number: ";
        cin >> new_train_number;
        update(train_number, "Train number: " + new_train_number);
    }
    void update_train_name()
    {
        string newtrain_name;
        cout << "Enter new train name: ";
        cin.ignore();
        getline(cin, newtrain_name);
        update(train_name, "Train name: " + newtrain_name);
        cout << "Train name updated successfully." << endl;
    }
    void update_train_route()
    {
        string newtrain_route;
        cout << "Enter new train route: ";
        getline(cin, newtrain_route);
        update(train_route, "Train route: " + newtrain_route);
        cout << "Train route updated successfully." << endl;
    }
    void update_number_of_seats()
    {
        string newTrainnumber_of_seats;
        cout << "Enter new number of seats: ";
        cin >> newTrainnumber_of_seats;
        update(number_of_seats, "Number of seats: " + newTrainnumber_of_seats);
        cout << "Number of seats updated successfully." << endl;
    }
    void updatetrain_time()
    {
        string newtrain_time;
        cout << "Enter new time: ";
        cin >> newtrain_time;
        update(train_time, "Time: " + newtrain_time);
        cout << "Time updated successfully." << endl;
    }
    void update_train_fare()
    {
        string newtrain_fare;
        cout << "Enter new fare: ";
        cin >> newtrain_fare;
        update(train_fare, "Fare: " + newtrain_fare);
        cout << "Fare updated successfully." << endl;
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
    #ifdef _WIN32
    system("cls"); // Clear powershell or windows terminal
    #else
    system("clear"); // For clearing the terminal
    #endif
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "                         -----CHANGE PASSWORD-----                       " << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Enter your old password: ";
}

void updateTrainMenu() 
{
    #ifdef _WIN32
    system("cls"); // Clear powershell or windows terminal
    #else
    system("clear"); // For clearing the terminal
    #endif
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "                         -----UPDATE TRAIN-----" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "What do you want to update?" << endl << endl;
    cout << "1. Train Number                                    2. Train Name\n\n";
    cout << "3. Train Route                                     4. Number of Seats\n\n";
    cout << "5. Train Time                                      6. Fare\n\n";
    cout << "0. Return to Main menu\n\n";
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Select an option: ";
}

#endif // ADMINISTRATOR_H