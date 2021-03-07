#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

//Methood for creating a node
struct node* createNode(int data)
{
	struct node *n;//Creating a node pointer
	n = (struct node *) malloc (sizeof(struct node));//Allocating memory in heap
	n->data = data;	//setting the data
	n->left = NULL;	//setting the left child to NULL
	n->right = NULL;//setting the right child to NULL

	return n;	//Finally returning the created node
}

int main()
{
	/*
	//constructing the root node
	struct node *p;
	p = (struct node *) malloc (sizeof(struct node));
	p->data = 2;
	p->left = NULL;
	p->right = NULL;

	//constructing the second node
	struct node *p1;
	p1 = (struct node *) malloc (sizeof(struct node));
	p1->data = 3;
	p1->left = NULL;
	p1->right = NULL;

	//constructing the root node
	struct node *p2;
	p2 = (struct node *) malloc (sizeof(struct node));
	p2->data = 4;
	p2->left = NULL;
	p2->right = NULL;
	*/

	//Constructing the root node using function (**Recomended)
	struct node *p = createNode(2);
	struct node *p1 = createNode(3);
	struct node *p2 = createNode(4);

	//Linking root node with left and right node
	p->left = p1;
	p->right = p2;

	return 0;
}

/*
Binary Tree:

	 2
	/ \
   3   4
   
*/