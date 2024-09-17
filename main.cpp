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