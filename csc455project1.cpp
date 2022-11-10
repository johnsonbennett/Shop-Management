#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool ValidLength(string s, int i) {
    if (s.size() <= i) {
        return true;
    }
    else
    {
        cout << "Name can have maximum length of " << i << ". enter again..." << endl;
        return false;
    }
}

bool Allalphabets(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (!isalpha(s[i])) {
            cout << "Name cannot contain any number and special characters,enter again... " << endl;
            return false;
        }
        else {

        }

    
    }
}


bool isNumeric(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false; //when one non numeric value is found, return false
    return true;
}


int main() {
    string firstName, lastName, Input;
    string date, month, year;
    int Cnumber = 1;
    ofstream file("customers.txt");

    for (;;) {
        cout << "First Name: ";
        cin >> Input;
        firstName = Input;
        if (ValidLength(firstName, 15) && Allalphabets(firstName)) {
            file << "customer " << Cnumber << " " << "First name : " << Input << endl;
            break;
        }
    }



    for (;;) {
        cout << "Last Name: ";
        cin >> Input;
        lastName = Input;
        if (ValidLength(lastName, 15) && Allalphabets(lastName)) {
            file << "customer " << Cnumber << " " << "last name : " << Input << endl;
            break;
        }
    }
    file << "customer " << Cnumber << " " << "date of birth : ";

    cout << "enter DOB:";
    cin >> date;
 

        while (cin.get() != '-')
        {
            cout << "expected  '-' \n";
            cout << "enter full date......[ MM-DD-YYYY],";
            cin >> date;
        }
            cout << "enter month";
        cin >> month;
        while (cin.get() != '-')
        {
                cout << "expected  '-' \n";
                cout << "enter full date......[ MM-DD-YYYY],";
                cin >> month;
        }
        cout << "enter year";
        cin >> year;
        file << " " << date << "-" << month << "-" << year << endl;

        file <<"customer "<<Cnumber<<" " << "credt card details : " << endl;
    
}








