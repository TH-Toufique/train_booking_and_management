#include<iostream>
#include<fstream> //Stream class to both read and write from/to files.
#include<stdlib.h>

using namespace std;

class Authentication
{
    private:
        string username, password, admin;
        ifstream file_in;
        ofstream file_out; 

    public:
        bool signUp()
        {
            file_out.open("login.txt", ios :: out | ios :: app ); //handle file output
            file_in.open("login.txt", ios :: in); //handle file input
            cout << "Enter admin username: " << endl;
            cin >> admin;
        
        label:
            cout << "Enter username: ";
            cin >> username;
            string check_username;
            while (file_in >> check_username)
            {
                if (check_username == "Username: " + username)
                {
                    cout << "Username already exist!!!";
                    goto label;
                }
            }
            cout << "Enter password: ";
            cin >> password;
            file_out << "Admin Username: " << admin << endl;
            file_out << "Username: " << username << endl;
            file_out << "Password: " << password << endl;
            file_out.close(); // CLosing the stream
            file_in.close(); // CLosing the stream
            return true;
        }
        bool login()
        {
            file_in.open("login.txt", ios :: in);
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;
            string check_username;
            string user_name = "Username:" + username;
            string user_pass = "Password:" + password;
            while (getline(file_in, check_username)) // getline function os fstream use for read line from files
            {
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
            file_in.close();
            return true;
        }
};
