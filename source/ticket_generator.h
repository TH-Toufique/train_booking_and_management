#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string firstPart = R"(
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Ticket Portal</title>
        <link rel="icon" href="image/favicon.ico" type="image/ico">
        <style>
            body, h1, h2, p, ul {
                margin: 0;
                padding: 0;
                text-align: center;
            }
            body {
                font-family: Arial, Helvetica, sans-serif;
                background-color: #e0f2f1;
            }
            header, footer {
                background-color: rgba(255, 255, 255, 0.2);
                backdrop-filter: blur(12px);
                color: #ffffff;
                text-align: center;
                padding: 20px;
                border-radius: 15px;
                box-shadow: 0 4px 15px rgba(0, 0, 0, 0.2);
            }
            header h1, header p {
                color: black;
            }
            .Ticketinfo, .passinfo, .guide {
                max-width: 80%;
                margin: 20px auto;
                padding: 30px;
                background-color: rgba(255, 255, 255, 0.15);
                backdrop-filter: blur(12px);
                border-radius: 20px;
                box-shadow: 0 8px 30px rgba(0, 0, 0, 0.2);
                color: #000;
            }
            table {
                width: 100%;
                border-collapse: collapse;
                text-align: center;
                margin-top: 20px;
                margin-bottom: 20px;
                background-color: rgba(255, 255, 255, 0.1);
                backdrop-filter: blur(10px);
                border-radius: 10px;
                box-shadow: 0 4px 10px rgba(0, 0, 0, 0.15);
            }
            h3 {
                margin-top: 10px;
                margin-bottom: 10px;
                text-align: left;
            }
            th, td {
                border: 1px solid rgba(33, 87, 85, 0.5);
                padding: 10px;
                background-color: rgba(255, 255, 255, 0.2);
            }
            th {
                font-weight: bold;
                color: #000;
            }
            td {
                color: #444;
            }
            a {
                color: #ffffff;
                text-decoration: none;
            }
            a:hover {
                color: #ffeb3b;
            }
        </style>
    </head>
    <body>
    <header>
        <h1>Welcome to the Train Booking System</h1>
        <p>Wishing you a happy and safe journey.</p>
    </header>
    <section class="Ticketinfo">
        <h2>Train Ticket Booking Information :</h2>
)";

string secondPart = R"(
    </section>
    <section class="passinfo">
        <h2>Passenger details :</h2>
        <table>
            <tr>
                <th>S.No</th>
                <th>Passenger Name</th>
                <th>Age</th>
                <th>Gender</th>
                <th>Seat No.</th>
            </tr>
)";

string thirdPart = R"(
        </table>
    </section>
    <section class="guide">
        <h2>Printing Guide :</h2>
        <p>To print the ticket press ctrl + p.</p>
        <p>It will open a new tab where you can now print the ticket.</p>
    </section>
    <footer>
        <p>&copy; 2023 Train Booking. All rights reserved.</p>
        <p>Powered by ticket portal</p>
        <p><a href="#top">Back to top</a></p>
    </footer>
    </body>
    </html>
)";

string train_identification_number, train_detail, total_number_of_passenger, passenger_name, gender, age, seat, ticket_info;
int nop, i;

void printTicket();
void searchBooking() {
    fstream file_in;
    file_in.open("Tickets.txt", ios::in);
    string search;
    cout << "Enter ticket inquiry number: ";
    cin >> search;
    string y;
    while (getline(file_in, y)) {
        if (y.find("Ticket inquiry number: " + search) != string::npos) {
            train_identification_number = y;
            getline(file_in, y);
            train_detail = y;

            getline(file_in, y);
            total_number_of_passenger = y;
            nop = stoi((total_number_of_passenger).substr(28, 1));
            getline(file_in, y);
            for (i = 1; i <= nop; i++) {
                getline(file_in, y);
                passenger_name = y.substr(15, y.length() - 15);
                getline(file_in, y);
                gender = y.substr(7, 8);
                age = y.substr(24, y.length() - 24);
                getline(file_in, y);
                seat = y.substr(12, y.length() - 12);

                getline(file_in, y); // it is for the extra empty line in the Trainfile

                printTicket();
            }
        }
    }
    file_in.close();
}

void printTicket() {
    if (i == 1) {
        ofstream outputFile("yourTicket.html");
        outputFile << firstPart;
        outputFile << "<h3>" + train_identification_number + "</h3> <h3>" + train_detail + "</h3> <h3> " + total_number_of_passenger + "</h3>";
        outputFile << secondPart;
        outputFile.close();
    }
    {
        ofstream outputFile("yourTicket.html", ios::app);
        outputFile << "<tr> <td>" + to_string(i) + "</td> <td>" + passenger_name + "</td> <td>" + age + "</td> <td>" + gender + "</td> <td>" + seat + "</td> </tr>" << endl;
        outputFile.close();
    }

    if (i == nop) {
        ofstream outputFile("yourTicket.html", ios::app);
        outputFile << thirdPart;
        outputFile.close();
        cout << "Your Ticket generated successfully." << std::endl;
    }
}