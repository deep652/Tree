// tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

typedef struct Node
{
	int m_data;
	struct Node *Left;
	struct Node *Right;
};
int FindHeight(Node *root);
using namespace std;

int main()
{
	Node *root;
	Node *n1, *n2, *n3, *n4, *n5;
	n1 = new Node();
	n2 = new Node();
	n3 = new Node();
	n4 = new Node();
	n5 = new Node();

	n1->m_data = 1;
	n2->m_data = 2;
	n3->m_data = 3;
	n4->m_data = 4;
	n5->m_data = 5;

	root = n1;
	root->Left = n2;
	root->Right = n3;
	n2->Left = n4;
	n4->Left = n5;
	cout<<"Height of the tree is"<<FindHeight(root);

	getchar();
    return 0;
}

int FindHeight(Node *root)
{
	int hl = 0;
	int hr = 0;
	if (!root)
	{
		return 0;
	}
	else
	{
		hl = 1 + FindHeight(root->Left);
		hr = 1 + FindHeight(root->Right);
		return(hl >= hr ? hl : hr);
	}
	
}