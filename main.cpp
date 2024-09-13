#include<iostream>
#include<cstdlib> // Perform system based processes
#include "source/headers.h"

using namespace std;

void banner()
{
    #ifdef _WIN32
    system("cls"); // Clear powershell or windows terminal
    #else
    system("clear"); // For clearing the terminal
    #endif

    cout << "*****************************************************" << endl;
    cout << "*           Train Ticket Booking Service            *" << endl;
    cout << "*****************************************************" << endl;
}

void adminMenu()
{
        cout << "--------------------------Menu------------------------" << endl;
        cout << "1. Add Train" << endl;
        cout << "2. Display Train" << endl;
        cout << "3. Search Train" << endl;
        cout << "4. Update for Train" << endl;
        cout << "5. Delete Train" << endl;
        cout << "0. Logout" << endl;
        cout << "------------------------------------------------------" << endl;
}

int main()
{

    cout <<"*******************************************************" << endl;
    cout <<"      WELCOME TO THE TRAIN BOOKING TICKET SERVICE      " << endl;
    cout <<"*******************************************************" << endl;

    int choice;
    bool flag;
    cout << "\n";
    cout << "1. Create New Account" << endl;
    cout << "2. Login existing account" << endl;
    cout << "3. Exit" << endl;
    cout << "Input: ";
    cin >> choice;

    Authentication authentication;
    switch (choice)
    {
    case 1:
        cout << "Sign Up" << endl;
        if (authentication.signUp())
        {
            cout << "Account Created Successfully" << endl;
            system("pause");
        }
        break;
    
    case 2:
        cout << "Login" << endl;
        if (authentication.login())
        {
            cout << "Logged in successfully" << endl;
            system("pause");
            flag = true;
        }
        break;
    }

    if (flag)
    {
        adminMenu();
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            #ifdef _WIN32
            system("addTrain.exe");
            #else
            system("./addTrain.exe");
            #endif
            break;

        case 2:
            #ifdef _WIN32
            system("displayTrain.exe");
            #else
            system("./displayTrain");
            #endif
            break;

        case 3:
            #ifdef _WIN32
            system("searchTrain.exe");
            #else
            system("./searchTrain");
            #endif
            break;
        case 4:
            #ifdef _WIN32
            system("trainUpdate.exe");
            #else
            system("./trainUpdate");
            #endif
            break;

        case 5:
            #ifdef _WIN32
            system("deleteTrain.exe");
            #else
            system("./deleteTrain");
            #endif
            break;

        case 0:
            cout << "Thanks for using me....!" << endl;
            break;
        default:
            cout << "Wrong Option!!" << endl;
        }
        cout << "Press any key to continue......";
        cin.ignore();
        cin.get();
    }
    banner();
    return 0;
}