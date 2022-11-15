#include <iostream>
#include<fstream>
using namespace std;

void readfile() {
    fstream file("customer.txt", ios::in | ios::out | ios::app);
    file.seekg(0, ios::beg);

    // Read the characters from the file into a
    // buffer
    char A[170];
    file.read(A, 170);
    // Output the contents read from the file and close it
    cout << A << endl;
    file.close();
}

// Driver Code
int main()
{
    readfile();
    return 0;

}

