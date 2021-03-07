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

//Method for preorder traversal
void Preorder(struct node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);	//First print the root node
		Preorder(root->left);	//Then perform the same function on left subtree
		Preorder(root->right);	//After that perform preorder function on right node
	}
}

int main()
{
	//Constructing the root node using function (**Recomended)
	struct node *p = createNode(2);
	struct node *p1 = createNode(3);
	struct node *p2 = createNode(4);
	struct node *p3 = createNode(11);
	struct node *p4 = createNode(6);

	/*Finally the tree look like this:
			 2
			/ \
		   3   4
		  / \
		 11  6
	*/
	//Linking root node with left and right node
	p->left = p1;
	p->right = p2;
	p1->left = p3;
	p1->right = p4;

	printf("Preorder traversal: \n");
	Preorder(p);	//Preorder Traversal: root->left->right

	return 0;
}

/*
Output:

Preorder traversal:
2 3 11 6 4

*/