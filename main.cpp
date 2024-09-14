#include<iostream>
#include<cstdlib> // Perform system based processes
#include "source/headers.h"
#include "source/administrator.h"

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

    string flag;
    int make_choice;
    cout << "Login as: " << endl;
    cout << "1. Admin" << endl;
    cout << "2. User" << endl;
    cin >> make_choice;

    Authentication authentication;

    //Admin Login
    if (make_choice == 1)
    {
        int admin_choice;
        cout << "\n";
        cout << "1. Create new account" << endl;
        cout << "2. Login to an existing account" << endl;
        cout << "0. Exit" << endl;
        cout << "Input: ";
        cin >> admin_choice;

        switch (admin_choice)
        {
        case 1:
        cout << "Sign Up" << endl;
        if (authentication.signUp(1)) // Values passed from headers.h
        {
            cout << "Account Created Successfully" << endl;
            system("pause");
        }
        break;

        case 2:
            cout << "Login" << endl;
            retry_1:
                if (authentication.login(1)) // Values passed from headers.h
                {
                    cout << "Login successfull" << endl;
                    system("pause");
                    flag = "admin";
                }
                else
                {
                    cout << "Login failed" << endl;
                    system("pause");
                    goto retry_1;
                }
                break;
        }
    }

    //User login
    if (make_choice == 2)
    {
        int user_choice;
        cout << "\n";
        cout << "1. Create new account" << endl;
        cout << "2. Login to an existing account" << endl;
        cout << "0. Exit" << endl;
        cout << "Input: ";
        cin >> user_choice;

        switch (user_choice)
        {
        case 1:
            cout << "Signup " << endl;
            if (authentication.signUp(2))
            {
                cout << "Your account has been created successfully" << endl;
                system("pause");
            }
            break;
        case 2:
            cout << "Login" << endl;
            retry_2:
            if (authentication.login(2)) // Values passed from headers.h
            {
                cout << "Logged in successfully" << endl;
                flag = "user";
                system("pause");
            }
            else
            {
                cout << "Invalid credentials!!" << endl;
                system("pause");
                goto retry_2;
            }
            break;
        }
    }
    
    if (flag == "admin")
    {
        trainManagement tm;
        retry_3:
        adminMenu();
        int choice;
        cin >> choice;
        switch (choice)
        {
            case 1:
                tm.add_train();
                break;

            case 2:
                tm.view_trains();
                break;
            
            case 3:
                tm.search_train();
                break;
            
            case 4:
                cout << "Update train will be implemented later";
                system("pause");
                break;

            case 5:
                tm.delete_train();
                break;
            
            case 0:
                exit(0);
        }
    }
    banner();
    return 0;
}