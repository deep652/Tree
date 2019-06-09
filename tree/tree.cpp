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
int findLeaves(Node *root);
//For Binary Tree
Node * LCA(Node * root, int n1, int n2);
//For Binary Search Tree
Node * LCABST(Node * root, int n1, int n2);
bool identical(Node *root1, Node *root2);
Node * createTree();
using namespace std;

int main()
{
	Node *root,*root2;
	root = createTree();
	root2 = createTree();

	cout<<"Height of the tree is"<<FindHeight(root)<<endl;
	cout << "Number of Leaves in the tree is: " << findLeaves(root) << endl;

	int num1 = 3, num2 = 2;
	//Node *lcaofnode=LCA(root, num1, num2);
	//cout << "Lowest common ancestor of " << num1 << " and " << num2 << " is: " << lcaofnode->m_data;

	Node *lcaofnode = LCABST(root, num1, num2);
	cout << "LCABST: Lowest common ancestor of " << num1 << " and " << num2 << " is: " << lcaofnode->m_data<<endl;
	if (identical(root, root2))
	{
		cout << "Trees are identical" << endl;
	}
	else
	{
		cout << "Sorry! Trees are not identical" << endl;
	}
	getchar();
    return 0;
}
Node * createTree()
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

	//tree is root->N4->leftN3 root->N4->right n5 n3->left=n1 n3 ->right=n2
	root = n4;
	root->Left = n3;
	root->Right = n5;
	n3->Left = n1;
	n3->Right = n2;
	return root;
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

int findLeaves(Node *root)
{
	int c = 0;
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		if (root->Left == NULL && root->Right == NULL)
		{
			c += 1;
			//c = 1 + findLeaves(root);
		}
		else
		{
			c=c+findLeaves(root->Left);
			c=c+findLeaves(root->Right);
		}
		
		return c;
	}

}

Node * LCA(Node * root,int n1,int n2)//For Binary Tree
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->m_data == n1 || root->m_data == n2)
	{
		return root;
	}
	
	
		Node *ln = NULL, *rn = NULL;
		ln = LCA(root->Left, n1, n2);
		rn = LCA(root->Right, n1, n2);
		if (ln != NULL && rn != NULL)
		{
			return root;
		}
		if (ln == NULL && rn == NULL)
		{
			return NULL;
		}
		return ln != NULL ? ln : rn;

	
}

Node * LCABST(Node * root, int n1, int n2)
{
	if (root == NULL)
	{
		return root;
	}
	if (root->m_data == n1 || root->m_data == n2)
	{
		return root;
	}
	Node *ln = NULL, *rn = NULL;
	
	if (root->m_data > n1 && root->m_data >n2)
	{
		ln = LCABST(root->Left, n1, n2);
		return ln;
	}
	if (root->m_data < n1 && root->m_data<n2)
	{
		rn = LCABST(root->Right, n1, n2);
		return rn;
	}
	return root;
}

//identical trees Recursive
bool identical(Node *root1, Node *root2)
{
	if (root1 == NULL && root2 == NULL)
	{
		return true;
	}
	if (root1 == NULL || root2 == NULL)
	{
		return false;
	}
	if (root1->m_data != root2->m_data)
	{
		return false;
	}
	if (identical(root1->Left, root1->Left) &&
		identical(root1->Right, root2->Right))
	{
		return true;
	}
	return true;
}