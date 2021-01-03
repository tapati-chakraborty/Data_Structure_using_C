#include <stdio.h>
#include <stdlib.h>

//Declaratuon of stack which will be implemented by linkedlist
struct Node
{
	int data;
	struct Node *next;
};

struct Node *top = NULL;

//linkedlist traversal(print the element of stack)
void linkedlistTraversal(struct Node *ptr)
{
	while(ptr != NULL)
	{
		printf("The element of the stack: %d\n", ptr->data);
		ptr = ptr->next;
	}
}

//Check if the stack is empty
int isEmpty(struct Node *top)
{
	if(top == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

//Check if the stack is full
int isFull(struct Node *top)
{
	struct Node *p = (struct Node *) malloc (sizeof(struct Node));
	if(p == NULL){
		return 1;
	}
	else{
		return 0;
	}
	free(p);
}

//Push an element to the stack.....
struct Node * push(struct Node *top, int x)
{
	if(isFull(top))
	{
		printf("Stack Overflow!Cannot push any element to the stack\n");
	}
	else
	{
		struct Node *n = (struct Node *) malloc(sizeof(struct Node));

		n->data = x;
		n->next = top;
		top = n;

		return top;
		free(n);
	}

}

//Traversing the stack
int peek (int position)
{
	struct Node *ptr = top;
	for(int i = 0; (i < position-1 && ptr != NULL); i++)
	{
		ptr = ptr->next;
	}
	if(ptr != NULL){
		return ptr->data;
	}
	else{
		return -1;
	}

}


int main()
{
	top = push(top, 5);
	top = push(top, 7);
	linkedlistTraversal(top);

	//Printhing the element of the stack
	for(int i = 1; i <= 2; i++)
	{
		printf("Value at point %d is: %d\n", i, peek(i));
	}

	return 0;
}

/*#############################################

Output:

The element of the stack: 7
The element of the stack: 5
Value at point 1 is: 7
Value at point 2 is: 5

#############################################*/