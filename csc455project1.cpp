#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool isValidUserName(string uName) {
    if (uName.length() > 11)
        return false;
    else
    {
        int countAlpha = 0, countDigit = 0;
        for (int i = 0; i < uName.length(); i++)
        {
            if (!(isalpha(uName[i])))
                return false;
            else
            {
                countAlpha++;
                if (countAlpha > 8)
                    return false;
            }
        }
        reverse(uName.begin(), uName.end());
        for (int i = 0; i < uName.length(); i++)
        {
            if (isdigit(uName[i]))
            {
                countDigit++;
                if (countDigit > 3)
                    return false;
            }
        }
        return true;

    }
}

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
        if (isdigit(str[i]) == false) {
            cout << "input should contain  only numbers \n";
            return false; //when one non numeric value is found, return false
        }
        else {}


    return true;
}


int main() {
    string username,firstName, lastName, Input;
    string Carddetails, Variable1, Variable2, dob;
    int Cnumber = 1;
    ofstream file("customer.txt");
    for (;;) {
        cout << "enter username: ";
        cin >> Input;
        username = Input;
        if (isValidUserName(Input)) {
            file << "customer " << Cnumber << " " << "Username : " << Input << endl;
            break;
        }
    }

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

    for (;;) {
        cout << "enter date: ";
        cin >> dob;
        dob.erase(remove(dob.begin(), dob.end(), '-'), dob.end());
        Variable1 = dob;
        if (isNumeric(Variable1))
            break;
    }
    file << "customer " << Cnumber << " " << "Date of Birth : " << dob << endl;
    for (;;) {
        cout << "enter Credit Card details: ";
        cin >> Carddetails;
        Carddetails.erase(remove(Carddetails.begin(), Carddetails.end(), '-'), Carddetails.end());
        Variable2 = Carddetails;
        if (isNumeric(Variable2))
            break;
    }
    file << "customer " << Cnumber << " " << "Credit card Number: " << Carddetails << endl;
}


