#pragma once
//class to handle tree and functions
class BinaryTreeClass
{
private:
	int counter; //indent variable
	int count; //tracks number of times a number was displayed
	//tree struct
	//struct easier to use for the program
	struct tree
	{
		tree* left;
		tree* right;
		int data;
	};
	tree* root;

public:
	BinaryTreeClass();
	bool isEmpty() const;
	void print();
	void printTree(tree *, int space);
	void printPreOrder();
	void preOrder(tree *);
	void printPostOrder();
	void postOrder(tree *);
	void printInOrder();
	void inOrder(tree *);
	void insertNode(int);
	void removeNode(int);
	void fillTree();
	void gotoxy(int x, int y);
};