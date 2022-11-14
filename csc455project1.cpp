#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool validateUsername(string Name) {
    int count = 0;
    for (int i = 0; i <= 8; i++) {
        if ((isalpha(Name[i])))
            count++;
    }
    if (count < 8) {
        cout << "input should contain sequence of 8 characters" << endl;
        return false;
    }
    else
        return true;
}

bool isValidUserName(string uName) {
    int countAlpha = 0, countDigit = 0;
    if (uName.length() > 11) {
        cout << "username must contain only 11 characters, try again......" << endl;
        return false;

    }
    else
    {
        for (int i = 0; i < uName.length(); i++)
        {
            if ((isalpha(uName[i])))
                countAlpha++;
            else {}
            if ((isdigit(uName[i])))
                countDigit++;
            else {}
        }

    }
    if (countAlpha > 8 && countDigit > 3) {
        cout << "username cannot contain more than 8 characters and 3 numbers, try again....." << endl;
        return false;
    }
    else {}
    if (!(countAlpha == 8 && countDigit == 3)) {
        cout << "username should contain atleast 8 characters followed by 3 numbers" << endl;
        return false;
    }
    else if (countAlpha == 8 && countDigit == 3)
        return true;
    cout << countDigit << " " << countAlpha;
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

bool isNumeric(string str, int num) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false) {
            cout << "input should contain  only numbers, try again... \n";
            return false; //when one non numeric value is found, return false
        }
        else {}
    if (!(str.length() == num)) {
        cout << "enter full format of input, try again.... \n";
        return false;
    }
    else {}


    return true;
}


auto getName() {
    string username, firstName, lastName;
    fstream file("customer.txt", ios::in | ios::out | ios::app);
    for (;;) {
        cout << "enter username: ";
        cin >> username;
        if (isValidUserName(username) && validateUsername(username)) {
           file << "customer " << "Username : " << username << endl;
            break;
        }
    }

    for (;;) {
        cout << "First Name: ";
        cin >> firstName;
        if (ValidLength(firstName, 15) && Allalphabets(firstName)) {
            file << "customer " << "First name : " << firstName << endl;
            break;
        }
    }



    for (;;) {
        cout << "Last Name: ";
        cin >> lastName;
        if (ValidLength(lastName, 15) && Allalphabets(lastName)) {
            file << "customer " << "last name : " << lastName << endl;
            break;
        }
        
    }
    file.close();
   
}



void dates() {
    string dob,DOB;
    fstream file("customer.txt", ios::in | ios::out | ios::app);
    for (;;) {
        cout << "enter date: ";
        cin >> dob;
        DOB = dob;
        dob.erase(remove(dob.begin(), dob.end(), '-'), dob.end());
        if (isNumeric(dob,8)) {
            file << "customer DOB: " << DOB << endl;
            break;
        }
    }
    file.close();
}

void cards()
{
    string Carddetails,CD;
    for (;;) {
        cout << "enter Credit Card details: ";
        cin >> Carddetails;
        CD = Carddetails;
        Carddetails.erase(remove(Carddetails.begin(), Carddetails.end(), '-'), Carddetails.end());
        if (isNumeric(Carddetails,12)) {
            break;
        }
  
    }
}

void RandomNumber() {
    fstream file("customer.txt", ios::in | ios::out | ios::app);
   // ofstream file("customer.txt");
    // Providing a seed value
    srand((unsigned)time(NULL));

    // Get a random number
    int random = rand();
    random = random + 10000000000;
    // Print the random number
    file << "customer ID: " <<"CID"<< random << endl;
    file.close();
}
void rewards() {
    int rewardpoints;
    fstream file("customer.txt", ios::in | ios::out | ios::app);
    cout << "enter reward points:";
    cin >> rewardpoints;
    file << "Customer total reward points: " << rewardpoints<< endl;
    file << "              " << endl;
    file.close();
}

int main() {
    RandomNumber();
    getName();
    dates();
    cards();
    rewards();
    return 0;
}
