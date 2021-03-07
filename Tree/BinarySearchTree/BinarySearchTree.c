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

//Method to check if the tree is binary search tree or not
int isBST(struct node *root)
{
	static struct node *prev = NULL;
	if(root != NULL){
		if(!isBST(root->left)){
			return 0;
		}
		if(prev != NULL && root->data <= prev->data){
			return 0;
		}
		prev = root;
		return isBST(root->right);
	}
	else
	{
		return 1;
	}
}

int main()
{
	//Constructing the root node using function (**Recomended)
	struct node *p = createNode(5);
	struct node *p1 = createNode(3);
	struct node *p2 = createNode(6);
	struct node *p3 = createNode(1);
	struct node *p4 = createNode(4);

	/*Finally the tree look like this:
			 5
			/ \
		   3   6
		  / \
		 1  4
	*/
	//Linking root node with left and right node
	p->left = p1;
	p->right = p2;
	p1->left = p3;
	p1->right = p4;

	printf("Inorder traversal: \n");
	Inorder(p);	//Inorder Traversal: left->root->right
	printf("\n");
	//printf("%d ", isBST(p));

	if(isBST(p))
	{
		printf("This is a binary search tree\n");
	}
	else
	{
		printf("This is not a binary search tree\n");
	}
	return 0;
}

/*
Output:

Inorder traversal:
11 3 6 2 4
This is a binary search tree
*/