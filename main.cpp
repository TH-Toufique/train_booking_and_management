#include<iostream>
#include<cstdlib> // Perform system based processes
#include "source/headers.h"
#include "source/administrator.h"
#include "source/handlingBooking.h"

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

void userMenu()
{
    banner();
    cout << "--------------------------Menu------------------------" << endl;
    cout << "1. Display train" << endl;
    cout << "2. Search train" << endl;
    cout << "3. Book tickets" << endl;
    cout << "4. Print ticket" << endl;
    cout << "5. Change password" << endl;
    cout << "6. Cancel train" << endl;
    cout << "0. Logout" << endl;
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

    if (make_choice == 1 || make_choice == 2)
    {
        handlingBooking(make_choice);
        flag = (make_choice == 1) ? "admin" : "user";
    }
    else if (make_choice == 0)
    {   
        //nop
    }
    else
    {
        cout << "Invalid choice. Closing the program";
    }
    
    char selection;
    trainManagement train_manage;
    handling_Booking handle_booking;

    // Admin section
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
            retry_4:
                tm.add_train();
                cout << "Do you want to add more train? (y/n): ";
                cin >> selection;
                if (selection == 'y' || selection == 'Y' ) // Alternatively cctype header can be used
                {
                    goto retry_4;
                }
                else
                {
                    goto retry_3;
                }
                break;

            case 2:
                tm.view_trains();
                break;
            
            case 3:
                tm.search_train();
                break;
            
            case 4:
                handle_booking.view_bookings();
                goto retry_3;
                break;

            case 5:
                tm.delete_train();
                break;
            
            case 0:
                exit(0);
        }
    }

    //User section
    if (flag == "user")
    {
        retry_6:
            userMenu();
            int user_choice;
            cin >> user_choice;
            switch (user_choice)
            {
                case 1:
                    train_manage.view_trains();
                    system("pause");
                    goto retry_6;
                    break;
                
                case 2:
                    train_manage.search_train();
                    system("pause");
                    goto retry_6;
                    break;

                case 3:
                    handle_booking.ticketBooking();
                    system("pause");
                    goto retry_6;
                    break;
                
                case 4:
                    cout << "Will be implemented later";
                    system("pause");
                    goto retry_6;
                    break;
                
                case 5:
                    cout << "Will be implemented later";
                    system("pause");
                    goto retry_6;
                    break;

                case 6:
                    cout << "Will be implemented later";
                    system("pause");
                    goto retry_6;
                    break;

                case 0:
                    exit(0);
            }
    }
    banner();
    return 0;
}