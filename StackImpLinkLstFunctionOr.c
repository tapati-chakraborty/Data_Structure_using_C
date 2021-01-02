#include <stdio.h>
#include <stdlib.h>

//Declaratuon of stack which will be implemented by linkedlist
struct Node
{
	int data;
	struct Node *next;
};

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
	}

}

//pop element from the stack.....
int pop(struct Node **top)
{
	if(isEmpty(*top))
	{
		printf("Stack Underflow!Cannot pop any element from the stack\n");
	}
	else
	{
		struct Node *n = *top;
		*top = (*top)->next;
		int x = n->data;
		free(n);

		return x;
	}
}

int main()
{
	//Allocation of memory for stack in heap
	struct Node *top = NULL;
	printf("Stack has been created successfully using linkedlist\n");

	top = push(top, 8);
	top = push(top, 7);
	printf("After pushing the stack-------- \n");
	linkedlistTraversal(top);

	int element = pop(&top);//------>last in first out
	printf("popped element of the stack: %d\n", element);
	printf("After popping the stack -------- \n");
	linkedlistTraversal(top);

	return 0;
}


/*########################################################

Output:

Stack has been created successfully using linkedlist
After pushing the stack--------
The element of the stack: 7
The element of the stack: 8
popped element of the stack: 7
After popping the stack --------
The element of the stack: 8

########################################################*/