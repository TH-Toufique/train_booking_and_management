#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class train_management
{
public:
    string trainNumber, trainName, trainRoute, numberOfSeats, trainTime, trainFare, line, y; // line & y are used to store the data temporarily
    ofstream train_in;
    ifstream train_out;

    void train_data()
    {
        train_in.open("TrainFile.txt", ios::in | ios::app);
        train_in << "Train number: " << trainNumber << endl;
        train_in << "Name of train: " << trainName << endl;
        train_in << "Route: " << trainRoute << endl;
        train_in << "Number of seats: " << numberOfSeats << endl;
        train_in << "Timing: " << trainTime << endl;
        train_in << "Fare: " << trainFare << endl;
        train_in << "__________________________" << endl;
        train_in.close();
    }
    void add_train()
    {
    loop_back_add_train:
        cout << "Enter train number (4 Digits): ";
        cin >> trainNumber;
        train_out.open("TrainFile.txt", ios ::in);
        while (getline(train_out, line))
        {
            if (line == ("Train number: " + trainNumber))
            {
                cout << "Train already exists" << endl;
                train_out.close();
                goto loop_back_add_train;
            }
        }
        cin.ignore();

        cout << "Enter train name: ";
        getline(cin, trainName);

        cout << "Enter train route: ";
        getline(cin, trainRoute);

        cout << "Enter timings (eg. 6:00pm-7:00am): ";
        cin >> trainTime;

        cout << "Enter number of seats: ";
        cin >> numberOfSeats;

        cout << "Enter fare: ";
        cin >> trainFare;

        train_data();
    }
    void viewTrains()
    {
        train_out.open("TrainFile.txt", ios::out);
        while (getline(train_out, y))
        {
            cout << y << endl;
        }
        train_out.close();
    }
    string searchTrain()
    {
    loop_back_search_train:
        train_out.open("TrainFile.txt", ios::in);
        cout << "Enter train number: ";
        cin >> trainNumber;
        bool found = false;

        while (getline(train_out, line))
        {
            if (line == ("Train number: " + trainNumber))
            {
                found = true;
                getline(train_out, y);
                cout << "\n"
                     << y << endl;
                while (getline(train_out, line))
                {
                    cout << line << endl;
                    if (line == "__________________________")
                        break;
                }
            }
        }

        train_out.close();

        if (!found)
        {
            cout << "Train not found" << endl;
            system("pause");
            goto loop_back_search_train;
        }
        else
        {
            return trainNumber + y.substr(14, y.length() - 14);
        }
    }

    void deleteTrain()
    {
        ifstream trainIn("TrainFile.txt");
        cout << "Enter train number: ";
        cin >> trainNumber;

        ofstream tempFile("TempFile.txt");

        bool found = false;
        while (getline(trainIn, line))
        {
            if (line == "Train number: " + trainNumber)
            {
                found = true;
                while (getline(trainIn, line))
                {
                    if (line == "__________________________")
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
            cout << "Train not found in the file." << endl;
        else
        {
            remove("TrainFile.txt");
            rename("TempFile.txt", "TrainFile.txt");
            cout << "Train deleted successfully." << endl;
        }
    }

    void seatBooked(string TrainNumber, int numberOfPassengerOnBooking, int numberOfPassengerOnCancelling)
    {
        train_out.open("TrainFile.txt", ios::in);
        string old_seat, new_seat;
        int i = 0;

        while (getline(train_out, y))
        {
            if (y == ("Train number: " + TrainNumber))
            {
                while (getline(train_out, y))
                {
                    i++;
                    if (i == 3)
                    {
                        old_seat = y;
                        numberOfSeats = to_string(stoi(y.substr(17, y.length() - 17)) - numberOfPassengerOnBooking + numberOfPassengerOnCancelling);
                        new_seat = "Number of seats: " + numberOfSeats;
                    }
                }
            }
        }
        train_out.close();
        update(old_seat, new_seat);
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
    void update(string oldLine, string newLine)
    {
        ifstream trainIn("TrainFile.txt");
        ofstream tempFile("TempFile.txt");

        while (getline(trainIn, line))
            (line == oldLine) ? tempFile << newLine << '\n' : tempFile << line << '\n';

        trainIn.close();
        tempFile.close();
        remove("TrainFile.txt");
        rename("TempFile.txt", "TrainFile.txt");
    }
};

class updateTrain : public train_management
{
public:
    void dataUpdate()
    {
        searchTrain();
        train_out.open("TrainFile.txt", ios::in);

        while (getline(train_out, y))
        {
            if (y == ("Train number: " + trainNumber))
            {
                trainNumber = y;

                getline(train_out, y);
                trainName = y;

                getline(train_out, y);
                trainRoute = y;

                getline(train_out, y);
                numberOfSeats = y;

                getline(train_out, y);
                trainTime = y;

                getline(train_out, y);
                trainFare = y;
            }
        }
        train_out.close();
    }

    void updateTrainNumber()
    {
        string newTrainNumber;
        cout << "Enter new train number: ";
        cin >> newTrainNumber;
        update(trainNumber, "Train number: " + newTrainNumber);
    }

    void updateTrainName()
    {
        string newTrainName;
        cout << "Enter new train name: ";
        cin.ignore();
        getline(cin, newTrainName);
        update(trainName, "Train name: " + newTrainName);
        cout << "Train name updated successfully." << endl;
    }

    void updateTrainRoute()
    {
        string newTrainRoute;
        cout << "Enter new train route: ";
        getline(cin, newTrainRoute);
        update(trainRoute, "Train route: " + newTrainRoute);
        cout << "Train route updated successfully." << endl;
    }

    void updateTrainNumberOfSeats()
    {
        string newTrainNumberOfSeats;
        cout << "Enter new number of seats: ";
        cin >> newTrainNumberOfSeats;
        update(numberOfSeats, "Number of seats: " + newTrainNumberOfSeats);
        cout << "Number of seats updated successfully." << endl;
    }

    void updateTrainTime()
    {
        string newTrainTime;
        cout << "Enter new time: ";
        cin >> newTrainTime;
        update(trainTime, "Time: " + newTrainTime);
        cout << "Time updated successfully." << endl;
    }

    void updateTrainFare()
    {
        string newTrainFare;
        cout << "Enter new fare: ";
        cin >> newTrainFare;
        update(trainFare, "Fare: " + newTrainFare);
        cout << "Fare updated successfully." << endl;
    }
};

#endif // ADMINISTRATION_H