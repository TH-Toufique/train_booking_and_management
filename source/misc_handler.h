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