///////////////////////////////////////////////////////////////////////////////
// Title: Fix delete function
// Files: main.cpp, BSTree.h, BSTree.cpp
// Semester: 3013- Advance Structures and Algorithms Spring 2018
// Author: Ashma Henry
// Email: geneve.ash@gmail.com
// Description:
// This program : this program creates and and calls an insert function 
// to insert numbers into a binary tree. It then calls the delete function 
// and deletes numbers inserted into the function.It also works when
// the root node doesn't have a left or a right child.
/////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BSTree.h"

using namespace std;


int main()
{
	srand(2342);

	// instantiation of class
	BSTree B;

	// insert function called
	B.insert(38);
	B.insert(10);
	B.insert(29);
	B.insert(27);
	B.insert(5);
	B.insert(43);
	B.insert(36);
	B.insert(3);
	B.printLevelOrder();
	B.GraphVizOut("before.txt");

	// whileloop called which deletes the node while there is a top
	while(B.top()){
	    cout<<"removing: "<<B.top()<<endl;
	    B.deleteNode(B.top());
	}

	// delete function called
	B.deleteNode(3);
	B.deleteNode(29);
	B.deleteNode(27);
	B.deleteNode(10);
	B.printLevelOrder();

	B.GraphVizOut("after.txt");
	system ("pause");
	return 0;
}