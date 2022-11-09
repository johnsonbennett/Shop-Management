#include <iostream>
using namespace std;

//Node Structure for linked list
struct node {
	string id;
	string name;
	double price;
	int onHand;
	struct node *next;
};

struct node *head = NULL; //A global variable for the head of the linked list

//A function to insert new nodes into the linked list
void insert(string id, string name, double price, int onHand) {
	struct node *newNode = new struct node;
	newNode->id = id;
	newNode->name = name;
	newNode->price = price;
	newNode->onHand = onHand;

	newNode->next = head;
	head = newNode;
}

//A function to delete items with a certain ID number
void deleteID(string id) {
	struct node* current = head;
	struct node* previous = NULL;

	if (head == NULL) {
		cout << "List is empty" << endl;
		return;
	}
	else {

		while (current->id != id) {

			if (current->next == NULL) {
				cout << "ID not found" << endl;
				return;
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
		cout << "Deleted succesfully" << endl;
	}
}

//A function to print the linked list
void printList()
{
	struct node* ptr = head;

	while (ptr != NULL)
	{
		cout << ptr->id << " ";
		cout << ptr->name << " ";
		cout << ptr->price << endl;
		ptr = ptr->next;
	}

	cout << endl;
}

//int main() {
//	insert("P12345", "ABC", 12.99, 4);
//	insert("P22345", "ABC", 12.99, 4);
//	insert("P32345", "ABC", 12.99, 4);
//	printList();
//	deleteID("P22345");
//	printList();
//}