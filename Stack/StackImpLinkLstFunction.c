#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};


void linkedlistTraversal(struct Node *ptr)
{
	while(ptr != NULL)
	{
		printf("The element of the stack: %d\n", ptr->data);
		ptr = ptr->next;
	}
}

int isEmpty(struct Node *top)
{
	if(top == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

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

struct Node * push(struct Node *top)
{




	if(isFull(top))
	{
		printf("Stack Overflow!\n");
	}
	else
	{
		struct Node *n = (struct Node *) malloc(sizeof(struct Node));
		int x;
		printf("Enter the value: ");
		scanf("%d\n", &x);
		n->data = x;
		n->next = top;
		top = n;

		return top;
	}

}

int pop(struct Node *p)
{
	if(isEmpty(p))
	{
		printf("Stack Underflow!\n");
	}
	else
	{
		int x = p->data;
		p = p->next;

		return x;
	}

}

int main()
{
	struct Node *top = (struct Node*) malloc (sizeof(struct Node));

	printf("Stack has been created successfully using linkedlist\n");

	top = push(top);
	top = push(top);
	linkedlistTraversal(top);

	int element = pop(top);
	printf("Pooped element is: %d\n", element);
	linkedlistTraversal(top);

	return 0;
}