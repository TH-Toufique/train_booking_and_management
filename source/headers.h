#include<iostream>
#include<fstream> //Stream class to both read and write from/to files.
#include<string>
#include<stdlib.h>

using namespace std;

class Authentication
{
    private:
        string username, password, admin;
        ifstream file_in;
        ofstream file_out; 

    public:
        bool signUp(int type) //need to define the type else bool functions won't properly
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
            if (type == 1)
            {
                file_out << "Type: admin" << endl; // determining the type if logged in person is user or admin
            }
            else if (type == 2)
            {
                file_out << "Type: user" << endl; // determining the type if logged in person is user or admin
            }
            
            
            file_out << "Username: " << username << endl;
            file_out << "Password: " << password << endl;
            file_out.close(); // CLosing the stream
            file_in.close(); // CLosing the stream
            return true;
        }
        bool login(int type)
        {
            file_in.open("login.txt", ios :: in);
            cout << "Enter Username: ";
            cin >> username;
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
