#include<iostream>
#include<fstream>
using namespace std;

void DeleteCustomer() {
	string line, name;
	cout << "Enter the customer ID  you want to delete: ";
	cin >> name;
	ifstream myfile;
	ofstream outfile;
	myfile.open("customer.txt");
	outfile.open("customer.txt");

	while (!myfile.eof()) {
		myfile >> line;
		if (line == name) {
			if (line == " ")  // mention charaacter between " " that will clear up there.
				cout << myfile.eof() << endl;
			break;
		}
	}
	myfile.close();
	outfile.close();
}
int main()
{
	DeleteCustomer();
}

