#include <stdio.h>
#include <stdlib.h>

//Declaratuon of stack which will be implemented by linkedlist
struct Node
{
	int data;
	struct Node *next;
};

//linkedlist Traversal(print the stack...)
void linkedlistTraversal(struct Node *ptr)
{
	while(ptr != NULL)
	{
		printf("The elements of the linkedlist: %d\n",ptr->data);
		ptr = ptr->next;
	}
}

//Check if the Stack is empty....
int isEmpty(struct Node *top)
{
	if(top == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

//Check if the Stack is full....
int isFull(struct Node *top)
{
	struct Node *p = (struct Node *) malloc(sizeof(struct Node));
	if(p == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

int main()
{
	//Allocation of memory for Stack in heap
	struct Node *top = (struct Node *) malloc(sizeof(struct Node));

	printf("Stack has been created successfully using linkedlist\n");

	linkedlistTraversal(top);

	//check if the stack is empty or not
	if(isEmpty(top))
	{
		printf("The stack is empty.....\n");
	}
	else
	{
		printf("The stack is not empty...\n");
	}

	//check if the stack is full or not
	if(isFull(top))
	{
		printf("The stack is full....\n");
	}
	else
	{
		printf("The stack is not full..\n");
	}

	return 0;
}


/*############################################

Output:

Stack has been created successfully using linkedlist
The elements of the linkedlist: 0
The stack is not empty...
The stack is not full..

############################################*/
