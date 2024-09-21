#include<iostream>
#include<string>
#include<cstdlib> // Perform system based processes
using namespace std;

void print_header()
{
    #ifdef _WIN32
    system("cls"); // Clear powershell or windows terminal
    #else
    system("clear"); // For clearing the terminal
    #endif
    cout << "***********************************************************" << endl;
    cout << "*                 Train Ticket Booking Service            *" << endl;
    cout << "***********************************************************" << endl;
}

void admin_menu()
{
    cout << "***********************************************************" << endl;
    cout << "*                      Admin Menu                         *" << endl;
    cout << "***********************************************************" << endl;
    cout << "1. Add Train" << endl;
    cout << "2. Display Trains" << endl;
    cout << "3. Search Trains" << endl;
    cout << "4. Display Bookings" << endl;
    cout << "5. Delete Train" << endl;
    cout << "6. Update Train" << endl;
    cout << "0. Logout" << endl;
    cout << "Select an option: ";
}

void user_menu()
{
    cout << "***********************************************************" << endl;
    cout << "*                       User Menu                         *" << endl;
    cout << "***********************************************************" << endl;
    cout << "1. Display Trains" << endl;
    cout << "2. Search Trains" << endl;
    cout << "3. Book Ticket" << endl;
    cout << "4. Print Ticket" << endl;
    cout << "5. Change Password" << endl;
    cout << "6. Cancel Ticket" << endl;
    cout << "0. Logout" << endl;
    cout << "Select an option: ";
}

void login_page_1() {
    cout << "***********************************************************" << endl;
    cout << "*                       login Page                        *" << endl;
    cout << "***********************************************************" << endl;
    cout << "***********************************************************" << endl;
    cout << "1. Admin" <<endl;
    cout << "2. User"  <<endl;
    cout << "0. Exit"  <<endl;
    cout << "***********************************************************" << endl;
    cout << "Select an option: ";
}

void login_page_2() {
    cout << "***********************************************************" << endl;
    cout << "*                       login Page                        *" << endl;
    cout << "***********************************************************" << endl;
    cout << "***********************************************************" << endl;
    cout << "1. Create new account" <<endl;
    cout << "2. Login to existing account" <<endl;
    cout << "0. Exit" <<endl;
    cout << "***********************************************************" << endl;
    cout << "Select an option: ";
}

void passwordMenu(){
    #ifdef _WIN32
    system("cls"); // Clear powershell or windows terminal
    #else
    system("clear"); // For clearing the terminal
    #endif
    cout << "***********************************************************" << endl;
    cout << "*                     Change Password                     *" << endl;
    cout << "***********************************************************" << endl;
    cout << "Enter your old password: ";
}

void payment_page(int totalFare) {
    cout << "***********************************************************" << endl;
    cout << "*                       Payment Page                       *" << endl;
    cout << "***********************************************************" << endl;
    cout << "***********************************************************" << endl;
    cout << "Total amount is TK." <<endl;
    cout << "Choose payment Method : " <<endl;
    cout << "1. Credit Card" <<endl;
    cout << "2. Cash" <<endl;
    cout << "3. Bkash" <<endl;
    cout << "***********************************************************" << endl;
    cout << "Select an option: ";
}

void seat_number_show() {
    #ifdef _WIN32
    system("cls"); // Clear powershell or windows terminal
    #else
    system("clear"); // For clearing the terminal
    #endif
    cout << "**********************************************************" << endl;
    cout << "*                      Seat Number                       *"<< endl;
    cout << "**********************************************************" << endl;
    cout << "SL         SU          LB          MB          UB" << endl << endl;
    cout << "01         02          03          04          05"<< endl;
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
void updateTrainMenu() {
    #ifdef _WIN32
    system("cls"); // Clear powershell or windows terminal
    #else
    system("clear"); // For clearing the terminal
    #endif
    cout << "**********************************************************" << endl;
    cout << "*                      Seat Number                       *"<< endl;
    cout << "**********************************************************" << endl;
    cout << "What do you want to update?" << endl << endl;

    cout << "1. Train Number"<< endl;
    cout << "2. Train Name\n\n" << endl;
    cout << "3. Train Route" << endl;
    cout << "4. Number of Seats\n\n" << endl;
    cout << "5. Train Time" << endl;
    cout << "6. Fare\n\n" << endl;
    cout << "0. Return to Main menu\n\n" << endl;
    cout << "**********************************************************" << endl;
    cout << "Select an option: ";
}
