#include<iostream>
#include<cstdlib>

using namespace std;

void printBanner()
{
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
    cout << "----------------------------------------------------------" << endl;
    cout << "*               Train Booking ticket service             *" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "" << endl;
}

int main()
{
    int choice;
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
    printBanner();

    do
    {
        cout << "--------------------------Menu------------------------" << endl;
        cout << "1. Add Train" << endl;
        cout << "2. Display Train" << endl;
        cout << "3. Search Train" << endl;
        cout << "4. Update for Train" << endl;
        cout << "5. Delete Train" << endl;
        cout << "0. Logout" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "Input: ";
        
        cin >> choice;
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif

        switch (choice)
        {
        case 1:
            #ifdef _WIN32
            system("addTrain.exe");
            #else
            system("./addTrain.exe");
            #endif
            break;

        case 2:
            #ifdef _WIN32
            system("displayTrain.exe");
            #else
            system("./displayTrain");
            #endif
            break;

        case 3:
            #ifdef _WIN32
            system("searchTrain.exe");
            #else
            system("./searchTrain");
            #endif
            break;
        case 4:
            #ifdef _WIN32
            system("trainUpdate.exe");
            #else
            system("./trainUpdate");
            #endif
            break;

        case 5:
            #ifdef _WIN32
            system("deleteTrain.exe");
            #else
            system("./deleteTrain");
            #endif
            break;

        case 0:
            cout << "Thanks for using me....!" << endl;
            break;
        default:
            cout << "Wrong Option!!" << endl;
        }
        cout << "Press any key to continue......";
        cin.ignore();
        cin.get();
    }while (choice != 5); //Validate options
}