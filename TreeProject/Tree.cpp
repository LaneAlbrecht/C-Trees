#include "Tree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

BinaryTreeClass::BinaryTreeClass() { root = NULL; }

bool BinaryTreeClass::isEmpty() const { return root == NULL; };

void BinaryTreeClass::gotoxy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void BinaryTreeClass::insertNode(int n)
{
	system("cls");
	tree* t = new tree;
	tree* parent;
	t->data = n;
	t->left = NULL;
	t->right = NULL;
	parent = NULL;

	// check if empty
	if (isEmpty()) root = t;
	else
	{
		tree* curr;
		curr = root;
		// Find the Node's parent
		while (curr)
		{
			parent = curr;
			if (t->data > curr->data) curr = curr->right;
			else curr = curr->left;
		}
		if (t->data < parent->data)
			parent->left = t;
		else
			parent->right = t;

	}
	print();
}

void BinaryTreeClass::removeNode(int n)
{
	system("cls");
	//Locate element
	bool found = false;
	if (isEmpty())
	{
		cout << " This Tree is empty! " << endl;
		return;
	}
	tree* curr;
	tree* parent = NULL;
	curr = root;
	while (curr != NULL)
	{
		if (curr->data == n)
		{
			found = true;
			break;
		}
		else
		{
			parent = curr;
			if (n > curr->data) curr = curr->right;
			else curr = curr->left;
		}
	}
	if (!found)
	{
		cout << " [ERROR] \n Number Specified Is Not In The Tree" << endl;

		return;
	}

	// Delete node with single child
	if ((curr->left == NULL && curr->right != NULL) || (curr->left != NULL
		&& curr->right == NULL))
	{
		if (curr->left == NULL && curr->right != NULL)
		{
			if (parent->left == curr)
			{
				parent->left = curr->right;
				delete curr;
			}
			else
			{
				parent->right = curr->right;
				delete curr;
			}
		}
		else // left child present, no right child
		{
			if (parent->left == curr)
			{
				parent->left = curr->left;
				delete curr;
			}
			else
			{
				parent->right = curr->left;
				delete curr;
			}
		}

		return;
	}
	// delete a leaf
	if (curr->left == NULL && curr->right == NULL)
	{
		if (parent->left == curr) parent->left = NULL;
		else parent->right = NULL;
		delete curr;

		return;
	}
	//Node with 2 children
	// replace node with smallest value in right subtree
	if (curr->left != NULL && curr->right != NULL)
	{
		tree* chkr;
		chkr = curr->right;
		if ((chkr->left == NULL) && (chkr->right == NULL))
		{
			curr = chkr;
			delete chkr;
			curr->right = NULL;
		}
		else // right child has children
		{
			//if the node right child has a left child
			// Move all the way down left to locate smallest element
			if ((curr->right)->left != NULL)
			{
				tree* lcurr;
				tree* lcurrp;
				lcurrp = curr->right;
				lcurr = (curr->right)->left;
				while (lcurr->left != NULL)
				{
					lcurrp = lcurr;
					lcurr = lcurr->left;
				}
				curr->data = lcurr->data;
				delete lcurr;
				lcurrp->left = NULL;
			}
			else
			{
				tree* tmp;
				tmp = curr->right;
				curr->data = tmp->data;
				curr->right = tmp->right;
				delete tmp;
			}
		}
		return;
	}
}

void BinaryTreeClass::print()
{
	counter = 3; //set "branch" indent
	system("cls");
	printTree(root, 0);
}

void BinaryTreeClass::printTree(tree* T, int space)
{
	if (T != NULL) { //exit function if current node is null 

		space += counter; //sets spacing as recursion continues

		printTree(T->right, space); //iterate through right nodes

		printf("\n"); //the internet is wonderful and provided me with this print f loop
		for (int i = counter; i < space; i++)
			printf(" ");
		printf("%d\n", T->data); //display node

		printTree(T->left, space); //iterate through left nodes
	}
	else
		return;
}

void BinaryTreeClass::printPreOrder()
{
	system("cls");
	count = 0; //reset times data displayed variable
	cout << "Pre-Order Traversal: \n";
	cout << "________________________________" << endl;
	preOrder(root);
}

void BinaryTreeClass::preOrder(tree* T) //NLR
{
	count++;
	if (T != NULL) {
		if (count > 1)
			cout << " > " << T->data;
		else
			cout << " " << T->data;
	preOrder(T->left);
	preOrder(T->right);
	
	}
	else
		return;
}

void BinaryTreeClass::printPostOrder()
{
	system("cls");
	count = 0; //reset times data displayed variable
	cout << "Post-Order Traversal: \n";
	cout << "________________________________" << endl;
	postOrder(root);
}

void BinaryTreeClass::postOrder(tree* T) //LRN
{
	if (T != NULL) {//exit function if current node is null

	postOrder(T->left);
	postOrder(T->right);
	
	count++;
	if (count > 1)
		cout << " > " << T->data;
	else
		cout << " " << T->data;

	}
	else
		return;
}

void BinaryTreeClass::printInOrder() {
	system("cls");
	count = 0; //reset times data displayed variable
	cout << "In-Order Traversal: \n";
	cout << "________________________________" << endl;
	inOrder(root);
}

void BinaryTreeClass::inOrder(tree* T) //LNR
{
	if (T != NULL) {

	inOrder(T->left);
	
	count++;
	if (count > 1)
		cout << " > " << T->data;
	else
		cout << " " << T->data;
	
	inOrder(T->right);

	}
	else
		return;
}

void BinaryTreeClass::fillTree()
{
	ifstream file;

	file.open("Tree.txt");

	if (!file) {
		cout << " Error opening file. " << endl;
	}

	//tree data variable
	int number;

	while (file >> number)
	{
		insertNode(number);
	}

	file.close();

	print(); //print "default" view of binary tree
}
