#include <iostream>
#include <string>
#include "source/authentication.h"
#include "source/misc_handler.h"
#include "source/ticket_booking.h"
#include "source/ticket_generator.h"

using namespace std;

int main()
{
    ticket_booking train_book;
    train_management train_manage;
    string flag;
    char userChoice;
    system("pause");
    login_page_1:
    print_header();
    login_page_1();
    cin >> userChoice;

    if (userChoice == '1' || userChoice == '2')
    {
#ifdef _WIN32
        system("cls"); // Clear powershell or windows terminal
#else
        system("clear"); // For clearing the terminal
#endif
        print_header();
        login_page_2();
        user_choice(userChoice);
        flag = (userChoice == '1') ? "admin" : "user";
    }
    else if (userChoice == '0')
    {
        exit(0);
    }
    else
    {
        cout << "Invalid choice. Terminating the program now " << endl;
        system("pause");
        goto login_page_1;
    }

    // admin section
    if (flag == "admin")
    {
    retry3:
        print_header();
        print_name();
        admin_menu();
        char choice;
        cin >> choice;
        switch (choice)
        {
        case '1': //add train
        {
            retry4:
            train_manage.add_train();
            char option;
            cout << "Do you want to add more?(y/n)";
            cin >> option;
            if (option == 'y' || option == 'Y')
            {
                goto retry4;
            }
            else
                goto retry3;
            break;
        }
        case '2': //display train
        {    
            train_manage.viewTrains();
            system("pause");
            goto retry3;
            break;
        }
        case '3': //search train
        {
            train_manage.searchTrain();
            system("pause");
            goto retry3;
            break;
        }
        case '4': //display bookings
        {
            train_book.viewBookings();
            system("pause");
            goto retry3;
            break;
        }
        case '5': //delete train
        {
        retry5:
            train_manage.deleteTrain();
            cout << "Do you want to delete more?(y/n)";
            char option;
            cin >> option;
            if (option == 'y' || option == 'Y')
            {
                goto retry5;
            }
            else
                goto retry3;
            break;
        }    
        case '6': //update train
        {
            updateTrain ut;
            ut.dataUpdate();
            system("pause");
            updateTrainMenu();
            char subChoice;
            cin>>subChoice;

            if(subChoice == '1') {
                ut.updateTrainNumber();
                system("pause");
            }
            else if(subChoice == '2') {
                ut.updateTrainName();
                system("pause");
            }
            else if(subChoice == '3') {
                ut.updateTrainRoute();
                system("pause");
            }
            else if(subChoice == '4') {
                ut.updateTrainNumberOfSeats();
                system("pause");
            }
            else if(subChoice == '5') {
                ut.updateTrainFare();
                system("pause");
            }
            else if(subChoice == '0') {
                goto retry3;
            }
            else {
                cout << "Invalid choice...." << endl;
                system("pause");
            }
            goto retry3;
        }    
        case '0': //logout
            exit(0);
        default:
        {
            cout << "Invalid choice...." << endl;
            system("pause");
            goto retry3;
        }
        }
    }
    // for user
    if (flag == "user")
    {
    retry6:
        print_header();
        print_name();
        user_menu();
        char choice;
        cin >> choice;
        switch (choice)
        {
        case '1': //display train
            train_manage.viewTrains();
            system("pause");
            goto retry6;
            break;
        case '2': //search train
            train_manage.searchTrain();
            system("pause");
            goto retry6;
            break;
        case '3': //book ticket
            train_book.bookTicket();
            system("pause");
            goto retry6;
            break;
        case '4': //print ticket
            searchBooking();
            system("pause");
            goto retry6;
            break;
        case '5': //change password
            bool flag;
            flag = changePassword();
            if(flag) {
                cout << "\n\t\tPassword changed successfully" << endl << endl;
                cout << "\t\tLogin again ..." << endl <<endl;
                exit(0);
            }else {
                cout << "Password not changed" << endl;
                system("pause");
                goto retry6;
            }
            break;
        case '6': //cancel ticket
            train_book.cancelTicket();
            system("pause");
            goto retry6;
            break;
        case '0': //logout
            exit(0);
        default:
            cout << "Invalid choice...." << endl;
            system("pause");
            goto retry6;
        }
    }
    return 0;
}