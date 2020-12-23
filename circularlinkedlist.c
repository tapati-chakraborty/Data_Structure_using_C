#include <stdio.h>
#include <stdlib.h>

//declaration of circular linkedlist
struct Node{
	int data;
	struct Node *next;
};

//linkedlist traversal (print all the element of the circular linkedlist).......
void linkedListTraversal(struct Node *head)
{
	struct Node *ptr = head;
	do
	{
		printf("the element:%d\n",ptr->data);
		ptr = ptr->next;
	}
	while(ptr != head);

	//Another Method of traversal...........
	/*while(ptr->next != head)
	{
		printf("the element:%d\n", ptr->data);
		ptr = ptr->next;
	}*/
}

//case 1:Insertion of an element at first of circular liunkedlist
struct Node *insertAtFirst(struct Node *head)
{
	struct Node *ptr = (struct Node *) malloc (sizeof (struct Node));

	int value;
	printf("Enter the element which you want to insert: ");
	scanf("%d", &value);
	ptr->data = value;

	struct Node *p = head->next;
	while(p->next != head)
	{
		p = p->next;
	}

	p->next = ptr;
	ptr->next = head;
	head = ptr;

	return head;
}

//case 2: Insertion of an element at a given index of circular linkedlist
struct Node *insertAtIndex(struct Node *head)
{
	struct Node *ptr = (struct Node *) malloc (sizeof (struct Node));
	struct Node *p = head;

	int i = 0, index, value;
	printf("Enter the index where you want to insert the element: ");
	scanf("%d", &index);
	while(i != index-1)
	{
		p = p->next;
	}
	printf("Enter the element which you to insert: ");
	scanf("%d", &value);
	ptr->data = value;

	ptr->next = p->next;
	p->next = ptr;

	return head;
}

//case 3:Insertion of an element at the end of circular linkedlist
struct Node * insertAtEnd(struct Node *head)
{
	struct Node *ptr = (struct Node *) malloc (sizeof (struct Node));

	int value;
	printf("Enter the element which you want to insert: ");
	scanf("%d", &value);
	ptr->data = value;

	struct Node *p = head;

	while(p->next != head)
	{
		p = p->next;
	}

	p->next = ptr;
	ptr->next = head;

	return head;
}

//case 4:Insertion of an element after a given node of circular linkedlist
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

	//link fourth and first nodes
	printf("enter 4th element: ");
	scanf("%d", &fourth->data);
	fourth->next = head;

	//Printing of the Linked list.......
	printf("linked list before insertion:\n");
	linkedListTraversal(head);

	head = insertAtFirst(head);				//print case 1
	//head = insertAtIndex(head);				//print case 2
	//head = insertAtEnd(head);					//print case 3
	//head = insertAfterNode(head,third);		//print case 4
	printf("linkedlist after insertion:\n");
	linkedListTraversal(head);

	return 0;
}