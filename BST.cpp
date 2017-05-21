#include <iostream>
#include <cstdlib>
#include "BST.h"


using namespace std;

BST::BST()
{
	root = NULL;
}

BST::node* BST::SeeRoot()
{
	if (root == NULL)
	{
		cout << "impty";
	}
	else
	{
		return root;
	}

}

BST::node* BST::newNode(int num, string name, string drugs, int age)
{
	node*data = new node;
	data->key = num;
	data->name = name;
	data->Drugs = drugs;
	data->age = age;
	data->left = data->right = NULL;
	return data;
}
/*void BST::insertKeyPri(int num, string name, string drugs, int age, node*Pt)
{


	if (root == NULL)
	{
		root = newNode(num, name, drugs, age);

	}
	else
	{
		node* Ptr1 = root;

		if (Ptr1->key < num)
		{
			if (Ptr1->left == NULL)
			{
				Ptr1->left = newNode(num, name, drugs, age); ;
			}
			else
			{
				insertKeyPri(num, name, drugs, age, Ptr1->left);
			}
		}

		else if (Ptr1->key > num) {
			{
				if (Ptr1->right == NULL)
				{
					Ptr1->right = newNode(num, name, drugs, age);
				}
				else
				{
					insertKeyPri(num, name, drugs, age, Ptr1->right);
				}
			}

		}
	}
}
*/
BST :: node* BST :: insertKeyPriv(int key, string name, string drugs,int age, node* ptr)
{
	node*Pt = root;

	if (root == NULL)
	{
		root = newNode(key, name,drugs , age );
		return root;
	}
	else if (key < root->key)
	{
		root->left = insertKeyPriv(key, name, drugs ,age, root->left);
	}
	else
	{
		root->right = insertKeyPriv(key, name, drugs , age, root->right);
	}

	return root;
}
void BST::insertKey(int num, string name, string drugs, int age)
{
	insertKeyPriv (num, name, drugs, age, root); 
}

void BST::inOrder()
{
	inOrderPrivate(root);
}
void BST::inOrderPrivate(node* Ptr)
{
	if (root != NULL)
	{
		if (Ptr->left != NULL)
		{
			Ptr = Ptr->left;
		}
		cout << Ptr;
		if (Ptr->right != NULL)
		{
			inOrderPrivate(Ptr->right);
		}
	}
	else
	{
		cout << "the Tree is empty";
	}
}
BST::node* BST::FindMin(node* root)
{
	while (root->left != NULL) root = root->left;
	return root;
}

// To find the patient who I wanna delete
BST::node* BST::Delete(node *root, int data) {
	if (root == NULL) return root; //The BsT is empty
	else if (data < root->key) root->left = Delete(root->left, data);
	else if (data > root->key) root->right = Delete(root->right, data);
	// I have found the patient I wanna delete so I will check the suitable case to delete that patient+
	else {
		// Case 1:  No child
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//Case 2: One child
		else if (root->left == NULL) {
			node *temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else {
			node *temp = FindMin(root->right);
			root->key = temp->key;
			root->right = Delete(root->right, temp->key);
		}
	}
	return root;
}

void BST::search_patient(int Num)
{

	search->key = Num;
	node* tmp = root;
	if (root == NULL)
		cout << "Empty Tree" << endl;
	else
	{
		while (Num != tmp->key) // compare patient given number (x) with keys
		{
			if (Num  < tmp->key)
				tmp = tmp->left; //go to left
			if (Num > tmp->key)
				tmp = tmp->right; //go to right
		}
		//  print_patient_data(data); //How to print a structure??
		if (tmp == NULL)
			cout << "ITEM NOT FOUND" << endl;
		else
		{
			cout << search;
		}
	}
}

void BST::display(node *ptr, int level)
{
	int i;
	if (ptr != NULL)
	{
		display(ptr->right, level + 1);
		cout << endl;
		if (ptr == root)
			cout << "Root->:  ";
		else
		{
			for (i = 0; i < level; i++)
				cout << "       ";
		}
		cout << ptr->key;
		display(ptr->left, level + 1);
	}

}
void BST :: TextFile(FILE* newFile,  node *tree)
{
	if (tree != NULL)
	{ 
		TextFile(newFile, tree->left);
		fprintf(newFile, "%s %d\n",tree ->name, tree ->key);
		TextFile(newFile, tree->right);
	}
}
void BST::PatientsFile(node *tree)
{
	FILE *newFile = fopen("PatientsList.txt", "w");
	TextFile(newFile, tree);
	fclose(newFile);
}
