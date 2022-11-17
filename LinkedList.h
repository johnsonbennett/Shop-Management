#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <fstream>
using namespace std;

struct node {
	string id;
	string name;
	double price;
	int onHand;
	struct node* next;
};

extern struct node* head; //A global variable for the head of the linked list

//A function to insert new nodes into the linked list
static void insert(string id, string name, double price, int onHand) {
	struct node *newNode = new struct node;
	newNode->id = id;
	newNode->name = name;
	newNode->price = price;
	newNode->onHand = onHand;

	newNode->next = head;
	head = newNode;

	cout << "Insert successful." << endl;
}

//A function to delete items with a certain ID number
static bool deleteID(string id) {
	struct node* current = head;
	struct node* previous = NULL;

	if (head == NULL) {
		cout << "List is empty." << endl;
		return false;
	}
	else {

		while (current->id != id) {

			if (current->next == NULL) {
				cout << "ID not found." << endl;
				return true;
			}
			else {
				previous = current;
				current = current->next;
			}

		}

		if (current == head) {
			head = head->next;
		}
		else {
			previous->next = current->next;
		}

		current = NULL;
		delete current;
		cout << "Deleted succesfully." << endl;
		return false;
	}
}

//A function to print the linked list
static void printList(string fileName)
{
	ofstream myFile;
	myFile.open(fileName);
	struct node* ptr = head;

	while (ptr != NULL)
	{
		myFile << ptr->id << "/" << ptr->name << "/" << ptr->price << "/" << ptr->onHand << endl;
		ptr = ptr->next;
	}

	cout << endl;
	myFile.close();
}

static bool checkUnique(string id)
{
	struct node* ptr = head;

	while (ptr != NULL)
	{
		if (ptr->id == id) 
			return true;
		else
			ptr = ptr->next;
	}
	return false;
}

#endif
