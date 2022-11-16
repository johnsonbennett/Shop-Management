#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include <sstream>
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

    if (!(countAlpha == 8 && countDigit == 3)) {
        cout << "username should contain atleast 8 characters followed by 3 numbers" << endl;
        return false;
    }
    else if (countAlpha == 8 && countDigit == 3)
        return true;
    cout << countDigit << " " << countAlpha;

    return false;
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
        else {}
    }
    return true;
}

bool isNumeric(string str, int num, int digit, string str1) {
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) == false) {
            cout << "input should contain  only numbers, try again... \n";
            return false; //when one non numeric value is found, return false
        }
        else {}
        if (!(str.length() == num)) {
            cout << "input should be in specified format, try again.... \n";
            return false;
        }
        else {}
    }
    for (int j = 0; j < str1.length(); j++) {
        if (str1[j] == '-')
            count++;
    }
    if (!(count == digit)) {
        cout << "characters '-' should be in format as asked, try again.... " << endl;
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
        else {}
    }
    
    for (;;) {
        cout << "First Name: ";
        cin >> firstName;
        if (ValidLength(firstName, 15) && Allalphabets(firstName)) {
            file << "customer " << "First name : " << firstName << endl;
            break;
        }
        else {}
    }

    for (;;) {
        cout << "Last Name: ";
        cin >> lastName;
        if (ValidLength(lastName, 15) && Allalphabets(lastName)) {
            file << "customer " << "last name : " << lastName << endl;
            break;
        }
        else {}
    }
    file.close();
}



void dates() {
    string dob;
    fstream file("customer.txt", ios::in | ios::out | ios::app);
    for (;;) {
        cout << "enter date (MM-DD-YYYY) : ";
        cin >> dob;

        stringstream ss;
        ss << dob;
        vector <string>list;
        string token;
        while(getline(ss,token,'-')) {
            list.push_back(token);
        }
        
        if (list.size() == 3) {
            auto month = stoi(list[0]);
            auto day = stoi(list[1]);
            auto year = stoi(list[2]);
            if (month < 0 || month > 12) continue;
            else if (day < 0 || day > 31) continue;
            else if (year < 0) continue;
            else {
                file << "customer DOB: " << dob << endl;
                break;
            }
        }
        else { /*do nothing */ }
    }
    file.close();
}

void cards()
{
    string Carddetails;
    fstream file("customer.txt", ios::in | ios::out | ios::app);
    for (;;) {
        cout << "enter Credit Card details (XXXX-XXXX-XXXX) : ";
        cin >> Carddetails;

        stringstream ss;
        ss << Carddetails;
        vector <string>list;
        string token;
        while(getline(ss,token,'-')) {
            list.push_back(token);
        }

        if (list.size() == 3) {
            auto seg1 = stoi(list[0]);
            auto seg2 = stoi(list[1]);
            auto seg3 = stoi(list[2]);
            if (seg1 < 0 || seg1 > 9999) continue;
            else if (seg2 < 0 || seg2 > 9999) continue;
            else if (seg3 < 0 || seg3 > 9999) continue;
            else {
                file << "customer card: " << Carddetails << endl;
                break;
            }
        }
        else { /*do nothing */ }
    }
    file.close();
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
    file << "customer ID: " << random << endl;
    file.close();
}
void rewards() {
    int rewardpoints;
    fstream file("customer.txt", ios::in | ios::out | ios::app);
    cout << "enter reward points:";
    cin >> rewardpoints;
    file << "Customer total reward points: " << rewardpoints << endl;
    file << "              " << endl;
    file.close();
}

bool find_id(string id){
    fstream file("customer.txt");
    string lines;
    while(!file.eof()){
        getline(file,lines);
        if(lines.find(id) != std::string::npos)
            return 1;
        else {
            //Do nothing
        }
    }
    return 0;
}

int main() {
    RandomNumber();
    getName();
    dates();
    cards();
    rewards();
    return 0;
}
