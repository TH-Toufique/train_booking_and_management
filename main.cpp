#include<iostream>
#include<string>
#include "source/authentication.h"

using namespace std;

int main()
{
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

    //admin section
    if (flag == "admin")
    {
        loop_back_1:
            print_header();
            print_name();
            admin_menu();
            char choice;
            cin >> choice;
            switch (choice)
            {
                case '1':
                {
                    cout << "Hello world";
                }
            }
    }
    
    
}