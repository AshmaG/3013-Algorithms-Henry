// Ashma Henry
// Advanced Algorithms
// Dr. Terry Griffin
// 1/22/2018
/* This program : uses a method called orderedSert that
would add an integer to a list while maintaining ascending order.*/
#include <iostream>
#include <ctime>

using namespace std;

//Create a container for list data
struct node
{
	int data;
	node* next;
};

/**
* Class: intLinkedList
* Purpose:
*     Implements a singly linked list that holds integers and sorts
*     that list in ascending order.
* Methods:
*     void  orderedSert(int x)
*     node* find(int key)
*     node* remove(int key)
*     void  print()
*/
class intLinkedList
{
private:
	node* Head;
public:
	intLinkedList()
	{
		Head = NULL;
	}
	void orderedSert(int x)
	{
		//empty list case
		//adds node to empty list
		if (!Head)
		{
			Head = new node;
			Head->data = x;
			Head->next = NULL;
		}
		//One item case
		// adds node the the single node in linked list
		else if (Head->next == NULL)
		{
			// condition if the new number is less than that what is 
			// stored in the current node
			if (Head->data > x)
			{
				node*T = new node;
				T->data = x;
				T->next = Head;
				Head = T;
			}
			// condition if the new number is more than that what is 
			// stored in the current node
			else
			{
				node*T = new node;
				T->data = x;
				Head->next = T;
			}
		}

		//Code used to insert a node int a list that is not empty 
		else
		{
			// condition if x is less than the value of the current node
			node*T = Head;
			if (Head->next->data > x)
			{
				//code used to insert a node before head
				T = new node;
				T->data = x;
				T = Head->next;
				Head->next = T;
			}
			else
			{
				
				// condition if x is more than the value of the current node
				// while the temporary pointer is not pointing to NULL
				while (T->next != NULL && !(x < T->next->data && x >= T->data))
				{
					// code used to traverse the linked list
					T = T->next;

				}
				if (T->next == NULL)
				{
					T->next = new node;
					T->next->data = x;
					T->next->next = NULL;
				}
				//
				node* newNode = new node;
				newNode->data = x;
				newNode->next = T->next;
				T->next = newNode;
				newNode = NULL;
				delete newNode;
			}

		}
	}

	// find method used to find a node
	node* Find(int key) {
		node* temp = Head;
		while (temp) {
			if (temp->data == key) {
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
	}

	// remove method used to remove a node
	void Remove(int key) {
		node* result = Find(key);
		if (result) {
			node* temp = Head;
			while (temp->next != result) {
				temp = temp->next;
			}
			temp->next = result->next;
			delete result;
		}
	}

	// print method 
	void print() {
		node* p = Head;
		while (p) {
			cout << p->data << endl;
			p = p->next;
		}
	}
};

int main()
{
	// seed random number generator
	srand(time(0));


	// a class definition into an "object"
	intLinkedList mylist;

	//Load 10 random ints into our list
	for (int i = 0; i < 10; i++) {
		mylist.orderedSert(rand() % 100);
	}

	//print the list
	mylist.print();

	system("pause");
}