#include <iostream>
#include "Tree.h"
using namespace std;

void printDiagram();
void menu();

int main()
{
	BinaryTreeClass t;
	int choice; //user choice
	int keynum; //variable to search and delete specific number
	int num; //user entered number

	t.fillTree();

	while (1)
	{
		t.gotoxy(13, 15);
		
		menu();//print menu for user
		cin >> choice;

		switch (choice) //execute options from menu
		{
		case 1: { //insert node case
			cout << " Enter number to insert: ";
			cin >> num;
			t.insertNode(num);
		}break;
		case 2: {
			t.print(); 
		}break;
		case 3: {
			t.printInOrder();
		}break;
		case 4: {
			t.printPreOrder();
		}break;
		case 5: {
			t.printPostOrder(); 
		}break;
		case 6: { //handle delete node case
			cout << " Enter number you wish to delete: ";
			cin >> keynum;
			t.removeNode(keynum);
		}break;
		case 7: { return 0; 
		} break;
		case 8: {
			printDiagram();
		}
		}
	}
}

void menu() {
	cout << " Binary Tree Menu " << endl;
	cout << " ___________________________________________ " << endl; //seperator
	cout << " ---[WARNING: TREE IS DISPLAYED SIDEWAYS]--- " << endl; //warning that tree is sideways
	cout << " 1. Insertion/Creation " << endl;
	cout << " 2. Print Tree in 2D " << endl;
	cout << " 3. In-Order Traversal " << endl;
	cout << " 4. Pre-Order Traversal " << endl;
	cout << " 5. Post-Order Traversal " << endl;
	cout << " 6. Remove A Node " << endl;
	cout << " 7. Exit " << endl;
	cout << " 8. Show Diagram of how the Tree is displayed " << endl; //the make sure its not a '0' option
	cout << " Enter your choice: " << endl;
}

void printDiagram() {
	system("cls");
	cout << "Diagram: " << endl;
	cout << "\n\t              Right->Right Node" << endl;
	cout << "        Right Node  +\n";
	cout << "\t              Right->Left Node";
	cout << "\nROOT\n";
	cout << "\n                        Left->Right Node";
	cout << "\n        Left Node   +";
	cout << "\n                        Left->Left Node" << endl;
	cout << endl;
}