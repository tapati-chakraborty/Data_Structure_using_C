#include <stdio.h>
#include <stdlib.h>

//declaration of doubly linkedlist
struct Node{
	int data;
	struct Node *prev;
	struct Node *next;
};

//linkedlist traversal(print the element of doubly linkedlist)......
void linkedlistTraversal(struct Node *ptr)
{
	while(ptr != NULL)
	{
		printf("the element:%d\n",ptr->data);
		ptr = ptr->next;
	}
}

//case 1:Insertion of an element at the beginning of the doubly linkedlist
struct Node * insertAtFirst(struct Node *head)
{
	struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

	int value;
	printf("Enter the element which you want to insert: ");
	scanf("%d", &value);
	ptr->data = value;

	ptr->prev = NULL;
	ptr->next = head;
	head->prev = ptr;

	return ptr;
	free(ptr);
}

//case 2:Insertion of an element at a given index of the doubly linkedlist
struct Node * insertAtIndex(struct Node *head)
{
	struct Node *ptr = (struct Node *) malloc (sizeof (struct Node));
	struct Node *p = head;

	int i = 0, value, index;
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
	ptr->prev = p;
	p->next = ptr;
	p->next->prev = ptr;

	return head;
	free(ptr);
}

//case 3:Insertion of an element at the end of doubly linkedlist
struct Node *insertAtEnd(struct Node *head)
{
	struct Node *ptr = (struct Node *) malloc (sizeof (struct Node));
	struct Node *p = head;

	int value;
	printf("Enter the element which you want to insert: ");
	scanf("%d", &value);
	ptr->data = value;

	while(p->next != NULL)
	{
		p = p->next;
	}

	ptr->next = NULL;
	ptr->prev = p;
	p->next = ptr;
	p->next->prev = ptr;

	return head;
	free(ptr);
}

//case 4:Insertion of an element after a given node
struct Node * insertAfterNode(struct Node *head, struct Node *prevNode)
{
	struct Node *ptr = (struct Node *) malloc (sizeof (struct Node));

	int value;
	printf("Enter the element which you want to insert: ");
	scanf("%d", &value);
	ptr->data = value;

	ptr->next = prevNode->next;
	ptr->prev = prevNode;
	prevNode->next = ptr;
	prevNode->next->prev = ptr;

	return head;
	free(ptr);
}


int main()
{
	//Allocation of memory for the nodes in the linkedlist in heap
	struct Node *head = (struct Node *) malloc (sizeof (struct Node));
	struct Node *N2 = (struct Node *) malloc (sizeof (struct Node));
	struct Node *N3 = (struct Node *) malloc (sizeof (struct Node));
	struct Node *N4 = (struct Node *) malloc (sizeof (struct Node));

	//link head and N2 node
	printf("Enter the 1st element: ");
	scanf("%d", &head->data);
	head->next = N2;
	head->prev = NULL;

	//link N2 to head and N3 node
	printf("Enter the 2nd element: ");
	scanf("%d", &N2->data);
	N2->next = N3;
	N2->prev = head;

	//link N3 to N2 and N4 node
	printf("Enter the 3rd element: ");
	scanf("%d", &N3->data);
	N3->next = N4;
	N3->prev = N2;

	//Terminate linkedlist at N4 node
	printf("Enter the 4th element: ");
	scanf("%d", &N4->data);
	N4->next = NULL;
	N4->prev = N3;

	//Print the doubly linkedlist.........
	printf("linked list before insertion:\n");
	linkedlistTraversal(head);

	//head = insertAtFirst(head);		//print case 1
	//head = insertAtIndex(head);		//print case 2
	head = insertAtEnd(head);			//print case 3
	//head = insertAfterNode(head, N2);	//print case 4
	printf("linkedlist after insertion:\n");
	linkedlistTraversal(head);

	free(head);
	free(N2);
	free(N3);
	free(N4);

	return 0;
}

/*########################################

Output:

head = insertAtFirst(head);--------------------output:

Enter the 1st element: 5
Enter the 2nd element: 4
Enter the 3rd element: 6
Enter the 4th element: 1
linked list before insertion:
the element:5
the element:4
the element:6
the element:1
Enter the element which you want to insert: 58
linkedlist after insertion:
the element:58
the element:5
the element:4
the element:6
the element:1
##############################################################

head = insertAtIndex(head);--------------------output:

Enter the 1st element: 5
Enter the 2nd element: 4
Enter the 3rd element: 7
Enter the 4th element: 8
linked list before insertion:
the element:5
the element:4
the element:7
the element:8
Enter the index where you want to insert the element: 1
Enter the element which you want to insert: 85
linkedlist after insertion:
the element:5
the element:85
the element:4
the element:7
the element:8
############################################################

head = insertAtEnd(head);-------------------output:

Enter the 1st element: 1
Enter the 2nd element: 2
Enter the 3rd element: 3
Enter the 4th element: 4
linked list before insertion:
the element:1
the element:2
the element:3
the element:4
Enter the element which you want to insert: 96
linkedlist after insertion:
the element:1
the element:2
the element:3
the element:4
the element:96
##############################################################

head = insertAfterNode(head, N2);--------------output:

Enter the 1st element: 5
Enter the 2nd element: 6
Enter the 3rd element: 4
Enter the 4th element: 7
linked list before insertion:
the element:5
the element:6
the element:4
the element:7
Enter the element which you want to insert: 65
linkedlist after insertion:
the element:5
the element:6
the element:65
the element:4
the element:7


#########################################*/