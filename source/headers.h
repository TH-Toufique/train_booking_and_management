#include<iostream>
#include<fstream> //Stream class to both read and write from/to files.
#include<string>
#include<stdlib.h>
#include "administrator.h"

using namespace std;



string Name, temp_password;
class Authentication
{
    private:
        string username, password, admin;
        ifstream file_in;
        ofstream file_out; 

    public:
        bool signUp(char type) //need to define the type else bool functions won't properly
        {
            file_out.open("login.txt", ios :: out | ios :: app ); //handle file output
            file_in.open("login.txt", ios :: in); //handle file input
            cout << "Enter admin name: " << endl;
            cin >> admin;
            cout << "Enter username: ";
            cin >> username;
            string check_username;
            while (file_in >> check_username)
            {
                if (check_username == "Username: " + username)
                {
                    cout << "Username already exist!!!";
                }
            }
            cout << "Enter password: ";
            cin >> password;
            if (type == '1')
            {
                file_out << "Type: admin" << endl; // determining the type if logged in person is user or admin
            }
            else if (type == '2')
            {
                file_out << "Type: user" << endl; // determining the type if logged in person is user or admin
            }
            
            
            file_out << "Username: " << username << endl;
            file_out << "Password: " << password << endl;
            file_out.close(); // CLosing the stream
            file_in.close(); // CLosing the stream
            return true;
        }
        bool login(char type)
        {
            file_in.open("login.txt", ios :: in);
            cout << "Enter Username: ";
            cin >> username;
            Name = username;
            cout << "Enter Password: ";
            cin >> password;
            string check_username;
            string user_name = "Username:" + username;
            string user_pass = "Password:" + password;
            string user_type;
            if (type == 1)
            {
                user_type = "Type: admin";
            }
            else if (type == 2)
            {
                user_type = "Type: user";
            }
            
            
            while (getline(file_in, check_username)) // getline function os fstream use for read line from files
            {
                if (check_username == user_type)
                {
                    getline(file_in, check_username);
                    if (check_username == user_name)
                    {
                        getline(file_in, check_username);
                        if (check_username == user_pass)
                        {
                            file_in.close();
                            return true;
                        }
                    }
                }
            }
            file_in.close();
            return true;
        }
};

void print_name()
{
    cout << "Hello " << Name << ", Welcome back!" << endl;
}
bool changePassword()
{
    passwordMenu();
    string password;
    cin >> password;
    if (password == temp_password)
    {
        cout << "\nEnter new password: ";
        cin >> password;
        string line;
        ifstream fin("login.txt");
        ofstream fout("TempFile.txt");
        while (getline(fin, line))
            (line == "Password:" + temp_password) ? fout << "Password:" + password << endl : fout << line << endl;
        fin.close();
        fout.close();
        remove("login.txt");
        rename("TempFile.txt", "login.txt");
        return true;
    }
    else
    {
        return false;
    }
}
// For users
void handlingBooking(char userType)
{
    Authentication authentication;
    string choice;
    cin >> choice;

        if (choice == "1")
        {
            cout << "*******************************************************" << endl;
            cout << "                    Sign Up                            " << endl;
            cout << "*******************************************************" << endl;
            if (authentication.signUp(userType))
            {
                cout << "Your account has been created successfully" << endl;
                system("pause");
                exit(0);
            }
        }
        
            cout << "*******************************************************" << endl;
            cout << "                    Login Page                         " << endl;
            cout << "*******************************************************" << endl;
            string flag = (userType == '1') ? "admin" : "user"; //ternary operator to assign a value to the flag variable based on the value of userType
            retry_login:
            if (authentication.login(userType))
            {
                cout << "Logged in successfully" << endl;
                system("pause");
                flag = (userType == '1') ? "admin" : "user";
            }
            else
            {
                cout << "Invalid credentials" << endl;
                system("pause");
                goto retry_login;
            }
        }

