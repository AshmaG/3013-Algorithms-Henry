#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*Struct: node
* Purpose :
*implements nodes used in the binary tree
* functions :
*       node ()
*       node (int)
*/
struct node
{
	string data;
	string type;
	node *left;
	node *right;
	node()
	{
		data = "";
		type = "";
		left = NULL;
		right = NULL;
	}
	node(string x, string y)
	{
		data = x;
		type = y;
		left = NULL;
		right = NULL;
	}
};

/**
* Class: BSTree
* Purpose:
*    implements a binary tree
* functions:
*   Private:
*   int count(node *root)
*	void insert(node *&root, node *&temp)
*	void print_node(node *n, string label)
*	node *minValueNode(node *root)
*	node *deleteNode(node *&root, int key)
*	int height(node *root)
*	void printGivenLevel(node *root, int level)
*	void GraphVizGetIds(node *nodePtr, ofstream &VizOut)
*	void GraphVizMakeConnections(node *nodePtr, ofstream &VizOut)
*
*   Public:
*   BSTree()
*	~BSTree()
*	int count()
*	void insert(int x)
*	void deleteNode(int key)
*	void minValue()
*	int height(int key)
*	int top()
*	void printLevelOrder()
*	void GraphVizOut(string filename)
*/
class BSTree
{
private:
	node *root;
	int count(node *root);
	void insert(node *&root, node *&temp);
	void print_node(node *n, string label);
	node *minValueNode(node *root);
	node *deleteNode(node *&root, string key);
	int height(node *root);
	void printGivenLevel(node *root, int level);
	void GraphVizGetIds(node *nodePtr, ofstream &VizOut);
	void GraphVizMakeConnections(node *nodePtr, ofstream &VizOut);


public:
	int countadj = 0;
	int countverb = 0;
	int countnoun = 0;
	int countadverb = 0;
	int counter = 0;

	BSTree();
	~BSTree();
	int count();
	void insert(string x, string y);
	void deleteNode(string key);
	void minValue();
	int height(int key);
	string top();
	void printLevelOrder();
	void GraphVizOut(string filename);
	bool search(string word);
	
	int retcounts(string x);
};

