#include <iostream>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;

// Struct
struct Avlnode {
	string value;
	string typeval;
	Avlnode *left;
	Avlnode *right;
	Avlnode *parent;
	int avlValue;
	Avlnode(string word, string wtype) {
		value = word;
		typeval = wtype;
		left = right = parent = NULL;
		avlValue = 0;
	}
};

class avlTree {

private:
	Avlnode *root;
	bool rightHeavy(Avlnode *);
	bool leftHeavy(Avlnode *);
	void insert(Avlnode *&, Avlnode *&);
	void inorder(Avlnode *);
	void preorder(Avlnode *);
	void postorder(Avlnode *);
	Avlnode* remove(Avlnode*&, string);
	Avlnode* predSuccessor(Avlnode*);
	void printNode(Avlnode *, string);
	int  height(Avlnode *);
	void computeAvlValues(Avlnode *&);
	void rotateLeft(Avlnode *&);
	void rotateRight(Avlnode *&);
	int  avlValue(Avlnode *);
	int countadj = 0;
	int countverb = 0;
	int countnoun = 0;
	int countadverb = 0;
	int counter = 0;
public:
	

	avlTree();
	~avlTree();
	void doDumpTree(Avlnode *);
	void dumpTree() {
		cout << "---------------------------------" << endl;
		cout << "Root:   " << root << "\n";
		doDumpTree(root);
	};
	void insert(string, string);
	void showInorder() { inorder(root); };
	void showPreorder() { preorder(root); };
	void showPostorder() { postorder(root); };
	bool search(string);
	void remove(string word) { root = remove(root, word); };
	int  treeHeight();
	void graphVizGetIds(Avlnode *, ofstream &);
	void graphVizMakeConnections(Avlnode *, ofstream &);
	void graphVizOut(string);

	int retcounts(string x);
};
