#include <stdio.h>
#include <stdlib.h>

//Declaration of circular linkedlist
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
	free(ptr);
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
	free(ptr);
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
	free(ptr);
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
	free(ptr);
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

	//head = insertAtFirst(head);				//print case 1
	//head = insertAtIndex(head);				//print case 2
	//head = insertAtEnd(head);					//print case 3
	head = insertAfterNode(head,third);		//print case 4
	printf("linkedlist after insertion:\n");
	linkedListTraversal(head);

	free(head);
	free(second);
	free(third);
	free(fourth);

	return 0;
}

/*#################################

Output:

head = insertAtFirst(head);----------------output:

enter 1st element: 4
enter 2nd element: 5
enter 3rd element: 6
enter 4th element: 7
linked list before insertion:
the element:4
the element:5
the element:6
the element:7
Enter the element which you want to insert: 89
linkedlist after insertion:
the element:89
the element:4
the element:5
the element:6
the element:7
#########################################################

head = insertAtIndex(head);-------------------output:

enter 1st element: 5
enter 2nd element: 4
enter 3rd element: 7
enter 4th element: 8
linked list before insertion:
the element:5
the element:4
the element:7
the element:8
Enter the index where you want to insert the element: 1
Enter the element which you to insert: 56
linkedlist after insertion:
the element:5
the element:56
the element:4
the element:7
the element:8
########################################################

head = insertAtEnd(head);-----------------output:

enter 1st element: 5
enter 2nd element: 4
enter 3rd element: 1
enter 4th element: 2
linked list before insertion:
the element:5
the element:4
the element:1
the element:2
Enter the element which you want to insert: 65
linkedlist after insertion:
the element:5
the element:4
the element:1
the element:2
the element:65
########################################################

head = insertAfterNode(head,third);--------------output:

enter 1st element: 2
enter 2nd element: 4
enter 3rd element: 5
enter 4th element: 1
linked list before insertion:
the element:2
the element:4
the element:5
the element:1
Enter the element which you want to insert: 54
linkedlist after insertion:
the element:2
the element:4
the element:5
the element:54
the element:1

###################################*/