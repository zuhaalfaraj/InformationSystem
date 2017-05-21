#pragma once
#include <iostream>

using namespace std;
class BST
{
private:
	struct node
	{
		string name;
		string Drugs;
		char age;
		int key;
		node* left;
		node* right;


	};
	node* root;
	node* search;


	void inOrderPrivate(node* Ptr);
	node* insertKeyPriv(int key, string name, string drugs, int age, node* ptr);

public:
	node* Patient;
	BST();
	node* newNode(int num, string name, string drugs, int age);
	node* SeeRoot();
	void  insertKey(int num, string name, string drugs, int age);
	
	void inOrder();
	void display(node *ptr, int level);
	node* FindMin(node* root);
	node* Delete(node *root, int data);
	void search_patient(int key);
	void  TextFile(FILE* newFile,  node *tree);
	void PatientsFile(node *tree);

}; 
