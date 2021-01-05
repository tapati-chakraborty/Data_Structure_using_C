#include <stdio.h>
#include <stdlib.h>

//Declaration of doubly linkedlist
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

//case 1:Deletion of an element at first of a doubly linkedlist
struct Node * deleteAtFirst(struct Node *head)
{
	struct Node *ptr = head;

	head = head->next;
	head->prev = NULL;
	free(ptr);

	return head;
}

//case 2:Deletion of an element at a given index of a doubly linkedlist
struct Node * deleteAtIndex(struct Node *head)
{
	struct Node *p = head;
	struct Node *q = head->next;

	int i, index;
	printf("Enter the index which you want to delete: ");
	scanf("%d", &index);
	for(i = 0; i < index-1; i++)
	{
		p = p->next;
		q = q->next;
	}
	p->next = q->next;
	q->next->prev = p;
	free(q);

	return head;
}

//case 3:Deletion of an element at the end of a doubly linkedlist
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

//case 4:Deletion of a given element of a doubly linkedlist
struct Node * deleteGivenValue(struct Node *head)
{
	struct Node *p = head;
	struct Node *q = head->next;

	int value;
	printf("Enter the element which you want to delete: ");
	scanf("%d", &value);

	while(q->data != value && q->next != NULL)
	{
		p = p->next;
		q = q->next;
	}
	if(q->data == value)
	{
		p->next = q->next;
		q->next->prev = p;
		free(q);
	}

	return head;

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
	printf("linked list before deletion:\n");
	linkedlistTraversal(head);

	//head = deleteAtFirst(head);		//print case 1
	//head = deleteAtIndex(head);		//print case 2
	//head = deleteAtEnd(head);			//print case 3
	head = deleteGivenValue(head);		//print case 4
	printf("linkedlist after deletion:\n");
	linkedlistTraversal(head);

	return 0;
}
/*###################################

Output:

head = deleteAtFirst(head);-------------output:

Enter the 1st element: 4
Enter the 2nd element: 5
Enter the 3rd element: 7
Enter the 4th element: 8
linked list before deletion:
the element:4
the element:5
the element:7
the element:8
linkedlist after deletion:
the element:5
the element:7
the element:8
######################################################

head = deleteAtIndex(head);-------------output:

Enter the 1st element: 5
Enter the 2nd element: 6
Enter the 3rd element: 1
Enter the 4th element: 2
linked list before deletion:
the element:5
the element:6
the element:1
the element:2
Enter the index which you want to delete: 1
linkedlist after deletion:
the element:5
the element:1
the element:2
####################################################

head = deleteAtEnd(head);---------------output:

Enter the 1st element: 5
Enter the 2nd element: 4
Enter the 3rd element: 7
Enter the 4th element: 8
linked list before deletion:
the element:5
the element:4
the element:7
the element:8
linkedlist after deletion:
the element:5
the element:4
the element:7
###################################################

head = deleteGivenValue(head);------------output:

Enter the 1st element: 5
Enter the 2nd element: 4
Enter the 3rd element: 6
Enter the 4th element: 7
linked list before deletion:
the element:5
the element:4
the element:6
the element:7
Enter the element which you want to delete: 6
linkedlist after deletion:
the element:5
the element:4
the element:7


#####################################*/