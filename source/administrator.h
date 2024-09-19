#ifndef ADMINISTRATOR_H //To avoid compiling error it has been assinged for unique header file
#define ADMINISTRATOR_H
#include<iostream>
#include<fstream>
#include<string>

using namespace std;


class train_Management
{
private:
    string train_number, number_of_seats,train_name,route, train_time, fare;
    ofstream train_in;
    ifstream train_out;

    // Store train data in the file
    void trainData()
    {
        train_in.open("train_details.txt", ios::app);  // Writing to file
        train_in << "Train number: " << train_number << endl;
        train_in << "Name of train: " << train_name << endl;
        train_in << "Number of seats" << number_of_seats << endl;
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
        cout << "Enter train number: ";
        cin >> train_number;
        cin.ignore(); // Ignore the new line character

        cout << "Enter train name: ";
        getline(cin, train_name);
        cout << "Enter route: ";
        getline(cin, route);
        cout << "Enter train timings: ";
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

        string search;
        cout << "Enter train number: ";
        cin >> search;
        string train_misc;
        bool found = false;

        while (getline(train_out, train_misc))
        {
            if (train_misc == "Train number: " + search)
            {
                cout << train_misc << endl;
                found = true;
                while (getline(train_out, train_misc))
                {
                    cout << train_misc << endl;
                    if (train_misc == "___________________________")
                    {
                        break;
                    }
                }
            }
        }

        if (!found)
        {
            cout << "Train not found" << endl;
        }
        train_out.close();
    }

    // Delete a train
    void delete_train()
    {
        ifstream train_in("train_details.txt");
        if (!train_in) {
            cout << "No trains found!" << endl;
            return;
        }

        string search;
        cout << "Enter train number: ";
        cin >> search;

        string line;
        ofstream tempFile("tempFile.txt");
        bool train_found = false;

        while (getline(train_in, line))
        {
            if (line == "Train number: " + search)
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
};

#endif // ADMINISTRATOR_H