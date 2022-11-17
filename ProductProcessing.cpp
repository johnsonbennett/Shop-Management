#ifndef PRODUCTPROCESSING_CPP
#define PRODUCTPROCESSING_CPP

#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.h"

using namespace std;

extern struct node* head; //A global variable for the head of the linked list

static void writeFile() {
	printList("products.txt");
}

static bool checkID(string id){
	bool isWrong = false;
	if (id[0] != 'P')
	{
		cout << "Enter a valid ID number starting with P." << endl;
		isWrong = true;
	}
	else {}
	if (id.length() != 6) {
		cout << "Enter a id that is 6 characters long." << endl;
		isWrong = true;
	}
	else {}
	for (int i = 1; i < 5; i++) {
		if (isdigit(id[i])) {
			continue;
		}
		else {
			cout << "Enter an id that is a P followed by 6 digits." << endl;
			isWrong = true;
			break;
		}
	}
	if (isWrong)
		return true;
	else
		return false;
}

static void addItem() {
	string idEnter;
	string nameEnter;
	double priceEnter = 0;
	int onHandEnter = 0;
	bool check = true;

	while (check) {
		cout << endl << "Enter an ID number, with a P followed by 5 digits. Enter E to exit: ";
		cin >> idEnter;
		if (idEnter == "E") {
			return;
		}
		else {}
		bool idCheck = checkID(idEnter);
		if (idCheck)
		{
			continue;
		}
		else {}
		if (checkUnique(idEnter)) {
			cout << "Enter a unique ID number." << endl;
			continue;
		}
		else {}
		check = false;
	}
	cout << endl << "Enter a product name: ";
	cin >> nameEnter;
	cout << endl << "Enter a product price: ";
	cin >> priceEnter;
	check = true;
	while (check) {
		cout << endl << "Enter a product quantity: ";
		cin >> onHandEnter;
		if (onHandEnter < 0) {
			cout << "Enter a positive quantity." << endl;
			continue;
		}
		else {}
		check = false;
	}

	insert(idEnter, nameEnter, priceEnter, onHandEnter);
	writeFile();

}

static void deleteItem() 
{
	string idEnter;
	bool check = true;
	while (check) {
		cout << endl << "Enter an ID number, with a P followed by 5 digits. Enter E to exit: ";
		cin >> idEnter;
		if (idEnter == "E") {
			return;
		}
		else {}
		
		if (checkID(idEnter))
		{
			continue;
		}
		else {}
		check = deleteID(idEnter);
		writeFile();
	}
}

static void readProductFile()
{
	string line;
	string id;
	string name;
	double price = 0;
	int onHand = 0;
	int lineCount = 1;
	ifstream myFile("products.txt");
	if (myFile.is_open())
	{
		while (getline(myFile, line))
		{
			if(lineCount%5==1){
				line = line.substr(line.find(" ") + 1);
				line = line.substr(line.find(" ") + 1);
				id = line;
				lineCount++;
			}
			else if (lineCount % 5 == 2) {
				line = line.substr(line.find(" ") + 1);
				line = line.substr(line.find(" ") + 1);
				name = line;
				lineCount++;
			}
			else if (lineCount % 5 == 3) {
				line = line.substr(line.find(" ") + 1);
				line = line.substr(line.find(" ") + 1);
				price = stod(line);
				lineCount++;
			}
			else if (lineCount % 5 == 4) {
				line = line.substr(line.find(" ") + 1);
				line = line.substr(line.find(" ") + 1);
				onHand = stoi(line);
				lineCount++;
			}
			else {
				insert(id, name, price, onHand);
				lineCount++;
			}
		}
		myFile.close();
	}

	else cout << "Unable to open file";
}

#endif
