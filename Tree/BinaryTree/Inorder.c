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

//Method for Inorder traversal
void Inorder(struct node *root)
{
	if(root != NULL)
	{
		Inorder(root->left);//First same function perform on left subtree
		printf("%d ", root->data);//Then print the root node
		Inorder(root->right);//Then call the inorder function for right subtree
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
            /  \
           3    4
          / \
         11  6
	*/
	//Linking root node with left and right node
	p->left = p1;
	p->right = p2;
	p1->left = p3;
	p1->right = p4;

	printf("Inorder traversal: \n");
	Inorder(p);	//Inorder Traversal: left->root->right

	return 0;
}

/*
Output:

Inorder traversal:
11 3 6 2 4

*/