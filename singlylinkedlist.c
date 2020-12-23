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

//case 1:Insertion of an element at the beginning of a singly linkedlist
struct Node * insertAtFirst(struct Node *head)
{
	struct Node *ptr = (struct Node *) malloc (sizeof (struct Node));

	int value;
	printf("Enter the element which you want to insert: ");
	scanf("%d", &value);
	ptr->data = value;

	ptr->next = head;

	return ptr;
}

//case 2:Insertion of an element at any index of a singly linkedlist
struct Node * insertAtIndex(struct Node *head)
{
	struct Node * ptr = (struct Node *) malloc (sizeof (struct Node));
	struct Node * p = head;
	int i = 0;

	int index, value;
	printf("Enter the index where you want to insert the element: ");
	scanf("%d", &index);
	while(i != index-1)
	{
		p = p->next;
		i++;
	}

	printf("Enter the element which you want to insert: ");
	scanf("%d", &value);
	ptr->data = value;

	ptr->next = p->next;
	p->next = ptr;

	return head;
}

//case 3:Insertion of an element at the end of a singly linkedlist
struct Node * insertAtEnd(struct Node *head)
{
	struct Node *ptr = (struct Node *) malloc (sizeof (struct Node));

	int value;
	printf("Enter the element which you want to insert: ");
	scanf("%d", &value);
	ptr->data = value;

	struct Node *p = head;

	while(p->next != NULL)
	{
		p = p->next;
	}

	p->next = ptr;
	ptr->next = NULL;

	return 0;
}

//case 4:Insertion of an element after a given node of a singly linkedlist
struct Node * insertAfterNode(struct Node *head, struct Node *prevNode)
{
	struct Node *ptr = (struct Node *) malloc (sizeof (struct Node));

	int value;
	printf("Enter the element which you want to insert: ");
	scanf("%d", &value);
	ptr->data = value;

	ptr->next = prevNode->next;
	prevNode->next = ptr;

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
	printf("linked list before insertion:\n");
	linkedListTraversal(head);

	// head = insertAtFirst(head);			//print case 1
	head = insertAtIndex(head);				//print case 2
	// head = insertAtEnd(head);			//print case 3
	//head = insertAfterNode(head,third);	//print case 4
	printf("Linked list after insertion:\n");
	linkedListTraversal(head);

	return 0;

}