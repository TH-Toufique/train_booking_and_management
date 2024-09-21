#include<iostream>
#include<fstream>
#include<string>
#include"misc_handler.h"


//Global variable declaration
string name, temp_password;

class Authentication
{

    private:
        string username, password, admin;
        ifstream file_in;
        ofstream file_out;


    public:
    bool signup(char type)
    {
        file_out.open("login.txt", ios::out | ios::app);
        file_in.open("login.txt", ios::in);
    label:
        cout << "\nEnter username: ";
        cin >> username;
        string x;
        while (file_in >> x)
        {
            if (x == "Username:" + username)
            {
                cout << "Username already exists";
                goto label;
            }
        }
        cout << "\nEnter password: ";
        cin >> password;
        if (type == '1')
        {
            file_out << "Type: admin" << endl;
        }
        else if (type == '2')
        {
            file_out << "Type: user" << endl;
        }
        file_out << "Username:" << username << endl;
        file_out << "Password:" << password << endl
             << endl;
        file_out.close();
        file_out.close();
        return true;
    }
        bool login(char type)
        {
            file_in.open("login.txt", ios :: in);
            cout << "\nEnter username: ";
            cin >> username;
            name = username;
            cout << "\nEnter password: ";
            cin >> password;
            temp_password = password;
            string x;
            string user_line = "Username: " + username;
            string pass_line = "Password: " + password;
            string type_line;
            if (type == '1')
            {
                type_line = "Type: admin";
            }
            else if (type == '2')
            {
                type_line = "Type: user";
            }
            while (getline(file_in, x))
            {
                if (x == type_line)
                {
                    getline(file_in, x);
                    if (x == user_line)
                    {
                        getline(file_in, x);
                        if (x == pass_line)
                        {
                            file_in.close();
                            return true;
                        }
                    }
                }
            }
            file_in.close();
        }
};

void print_name()
{
    cout << "Hello " << name << ", Welcome Back!" << endl;
}

bool changePassword()
{
    passwordMenu();
    string password;
    cin >>password;

    if (password == temp_password)
    {
        cout << "\nEnter new password: ";
        cin >> password;
        string line;
        ifstream file_in("login.txt");
        ofstream file_out("TempFile.txt");

        while (getline(file_in, line))
        {
            (line == "Password: " + temp_password) ? file_out << "Password:" + password << endl : file_out << line << endl;
            file_in.close();
            file_out.close();
            remove("login.txt");
            rename("TempFile.txt", "login.txt");
            return true;
        }
    }
    else
    {
        return false;
    }
    
}

void user_choice(char userType)
{
    Authentication authentication;
    loop_back_1:
        char choice;
        cin >> choice;
        print_header();
        if (choice == '1')
        {
        cout << "***********************************************************" << endl;
        cout << "*                         Signup                          *" << endl;
        cout << "***********************************************************" << endl;

        if (authentication.signup(userType))
        {
            cout << "\n\t\tYour account has been created successfully....\n"
                 << endl;
            system("pause");
            exit(0);
        }
        }  
        else if (choice == '2')
        {
            cout << "***********************************************************" << endl;
            cout << "*                         Login                           *" << endl;
            cout << "***********************************************************" << endl;
            retryLogin:
                if (authentication.login(userType))
                {
                    cout << "\n\t\t\tLogin successful....\n" << endl;
                    system("pause");
                }
                else
                {
                    cout << "Login failed" << endl;
                    system("pause");
                    goto retryLogin;
                }
        }
        else if (choice == '0')
        {
            cout << "Thanks for reaching out !!";
            exit(0);
        }
        else
        {
            cout << "Invalid input" << endl;
            system("pause");
            cout << "\nSelect an option: ";
            goto loop_back_1;
        }
}     