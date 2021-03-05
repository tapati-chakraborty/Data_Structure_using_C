#include <stdio.h>
#include <stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;

struct Node
{
	int data;
	struct Node *next;
};

void LinkedlistTraversal(struct Node *ptr)
{
	printf("Printing element of this linked list:\n");
	while(ptr != NULL)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
}

void enqueue(int val)
{
	struct Node *n = (struct Node *) malloc (sizeof(struct Node));
	if(n == NULL)
	{
		printf("Queue is full\n");
	}
	else
	{
		n->data = val;
		n->next = NULL;
		if(r == NULL){
			f = r = n;
		}
		else{
			r->next = n;
			r = n;
		}
	}
}

int dequeue()
{
	int val = -1;
	struct Node *ptr = f;
	if(f == NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		f = f->next;
		val = ptr->data;
		free(ptr);
	}
	return val;
}

int main()
{
	LinkedlistTraversal(f);
	printf("dequeuimg element %d:\n", dequeue());
	
	enqueue(3);
	enqueue(4);
	enqueue(5);
	enqueue(6);
	enqueue(7);
	printf("After Enqueuing element to the queue: \n");
	LinkedlistTraversal(f);

	printf("dequeuimg element %d:\n", dequeue());
	printf("dequeuimg element %d:\n", dequeue());
	printf("After dequeuing element from the queue: \n");
	LinkedlistTraversal(f);

	return 0;
}