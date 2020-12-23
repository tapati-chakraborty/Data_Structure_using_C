#include <stdio.h>
#include <stdlib.h>

//declaration of a singly linkedlist
struct Node
{
	int data;
	struct Node *next;
};

//linkedlist traversal(print the linkedlist).......
void linkedListTraversal(struct Node *ptr)
{
	while(ptr != NULL)
	{
		printf("the element:%d\n",ptr->data);
		ptr = ptr->next;
	}
}

//case 1:Deletion of an element from first of singly linkedlist
struct Node * deleteAtFirst(struct Node * head)
{
	struct Node *ptr = head;

	head = head->next;
	free(ptr);

	return head;
}

//case 2:Deletion of an element from a given index of singly linkedlist
struct Node * deleteAtIndex(struct Node *head)
{
	struct Node *p = head;
	struct Node *q = head->next;

	int i,index;
	printf("Enter the index where you want to delete the element: ");
	scanf("%d", &index);

	for(i = 0; i < index; i++)
	{
		p = p->next;
		q = q->next;
	}

	p->next = q->next;
	free(q);

	return head;
}

//case 3:Deletion of an element from end of singly linkedlist
struct Node * deleteAtEnd(struct Node *head)
{
	struct Node *p = head;
	struct Node *q = head->next;

	while(q->next != NULL)
	{
		p = p->next;
		q = q->next;
	}

	p->next = NULL;
	free(q);

	return head;
}

//case 4:Deletion of a given element of singly linkedlist
struct Node * deleteGivenValue(struct Node *head)
{
	struct Node *p = head;
	struct Node *q = head->next;

	int value;
	printf("Enter the value which you want to delete: ");
	scanf("%d", &value);

	while(q->data != value && q->next != NULL)
	{
		p = p->next;
		q = q->next;
	}

	if(q->data == value)
	{
		p->next = q->next;
		free(q);
	}

	return head;
}


int main()
{
	//Allocation of memory for nodes in the linkedlist in heap
	struct Node *head = (struct Node *) malloc (sizeof (struct Node));
	struct Node *second = (struct Node *) malloc (sizeof (struct Node));
	struct Node *third = (struct Node *) malloc (sizeof (struct Node));
	struct Node *fourth = (struct Node *) malloc (sizeof (struct Node));

	//link first and second nodes
	printf("enter 1st element: ");
	scanf("%d", &head->data);
	head->next = second;

	//link second and third nodes
	printf("enter 2nd element: ");
	scanf("%d", &second->data);
	second->next = third;

	//link third and forth nodes
	printf("enter 3rd element: ");
	scanf("%d", &third->data);
	third->next = fourth;

	//terminate the list
	printf("enter 4th element: ");
	scanf("%d", &fourth->data);
	fourth->next = NULL;

	//Printing of the Linked list.......
	printf("linked list before Deletion:\n");
	linkedListTraversal(head);

	head = deleteAtFirst(head);				//print case 1
	// head = deleteAtIndex(head);			//print case 2
	// head = deleteAtEnd(head);			//print case 3
	// head = deleteGivenValue(head);		//print case 4
	printf("linkedlist after deletion:\n");
	linkedListTraversal(head);

	return 0;
}
