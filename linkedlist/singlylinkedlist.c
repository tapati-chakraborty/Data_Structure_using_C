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

	free(ptr);
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
	free(ptr);
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

	return head;
	free(ptr);
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

	//terminate the list
	printf("enter 4th element: ");
	scanf("%d", &fourth->data);
	fourth->next = NULL;

	//Printing of the Linked list.......
	printf("linked list before insertion:\n");
	linkedListTraversal(head);

	//head = insertAtFirst(head);			//print case 1
	//head = insertAtIndex(head);				//print case 2
	//head = insertAtEnd(head);			//print case 3
	head = insertAfterNode(head,third);	//print case 4
	printf("Linked list after insertion:\n");
	linkedListTraversal(head);

	free(head);
	free(second);
	free(third);
	free(fourth);

	return 0;

}

/*###########################################

Output:

#################################################################
head = insertAtFirst(head);-----------------------output:

enter 1st element: 5
enter 2nd element: 6
enter 3rd element: 7
enter 4th element: 8
linked list before insertion:
the element:5
the element:6
the element:7
the element:8
Enter the element which you want to insert: 52
Linked list after insertion:
the element:52
the element:5
the element:6
the element:7
the element:8

##################################################################
head = insertAtIndex(head);------------------------output

enter 1st element: 8
enter 2nd element: 9
enter 3rd element: 7
enter 4th element: 4
linked list before insertion:
the element:8
the element:9
the element:7
the element:4
Enter the index where you want to insert the element: 1
Enter the element which you want to insert: 65
Linked list after insertion:
the element:8
the element:65
the element:9
the element:7
the element:4

####################################################################
head = insertAtEnd(head);----------------------------output

enter 1st element: 4
enter 2nd element: 5
enter 3rd element: 7
enter 4th element: 8
linked list before insertion:
the element:4
the element:5
the element:7
the element:8
Enter the element which you want to insert: 65
Linked list after insertion:
the element:4
the element:5
the element:7
the element:8
the element:65

###################################################################
head = insertAfterNode(head,third);-------------------output:

enter 1st element: 5
enter 2nd element: 4
enter 3rd element: 6
enter 4th element: 1
linked list before insertion:
the element:5
the element:4
the element:6
the element:1
Enter the element which you want to insert: 96
Linked list after insertion:
the element:5
the element:4
the element:6
the element:96
the element:1


###########################################*/