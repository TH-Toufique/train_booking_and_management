#include<iostream>
#include<stdlib.h> // Perform system based processes

using namespace std;

void banner()
{
    system("clear"); // For clearing the terminal
    cout << "*****************************************************" << endl;
    cout << "*           Train Ticket Booking Service            *" << endl;
    cout << "*****************************************************" << endl;
}

int adminLogin()
{
        string username, password;
        string login_username = "admin"; // Default Admin dashboard
        string login_password = "admin"; // Default Admin dashboard
        while(true)
        {
            cout << "\n*******************************************************\n" << endl;
            cout << "                   WELCOME ADMIN                         \n" << endl;
            cout << "\n*******************************************************\n" << endl;
            cout << "Enter loginID: ";
            // Specific admin login credentials
            cin >> username;
            cout << "\nEnter password: ";
            cin >> password;
            if (login_username == username && login_password == password )
            {
                system("./adminLogin");
                break;
            }
            else
            {
                cout << "Invalid username or password. Please try again!!" << endl;
                cin.ignore();
                cin.get();
            }
        }
}

int userLogin()
{
    cout << "Hello World"; //Will be implented here for now hello world :)
}

int main()
{

    cout <<"\n*******************************************************\n" << endl;
    cout << "      WELCOME TO THE TRAIN BOOKING TICKET SERVICE       \n" << endl;
    cout <<"\n*******************************************************\n" << endl;
    cout << "You are an Admin/User: " << endl;

    int choice;
    cout << "\n";
    cout << "1. Admin" << endl;
    cout << "2. User" << endl;
    cout << "3. Exit" << endl;
    cout << "Input: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            adminLogin();
            break;
        case 2:
            userLogin();
            break;
        case 3:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
            return 1;
    }

    
    
    banner();
    return 0;

}