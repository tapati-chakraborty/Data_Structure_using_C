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

//case 1:Deletion of an element at first of circular linkedlist
struct Node * deleteAtFirst(struct Node *head)
{
	struct Node *ptr = head;
	struct Node *p = head->next;
	while(p->next != head)
	{
		p = p->next;
	}
	p->next = head->next;

	head = head->next;
	free (ptr);

	return head;
}

//case 2:Deletion of an element at a given index of circular linkedlist
struct Node *deleteAtIndex(struct Node *head)
{
	struct Node *p = head;
	struct Node *q = head->next;

	int index;
	printf("Enter the index where you want to delete the element: ");
	scanf("%d", &index);
	for (int i = 0; i < index-1; i++)
	{
		p = p->next;
		q = q->next;
	}
	p->next = q->next;
	free(q);

	return head;
}

//case 3:Deletion of an element at the end of circular linkedlist
struct Node *deleteAtEnd(struct Node *head)
{
	struct Node *p = head;
	struct Node *q = head->next;
	while(q->next != head)
	{
		p = p->next;
		q = q->next;
	}
	p->next = head;

	free(q);

	return head;
}

//case 4:Deletion of a given element of circular linkedlist
struct Node *deleteGivenValue(struct Node *head)
{
	struct Node *p = head;
	struct Node *q = head->next;

	int value;
	printf("Enter the element which you want to delete: ");
	scanf("%d", &value);

	while(q->data != value && q->next != head)
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

	//link fourth and first nodes
	printf("enter 4th element: ");
	scanf("%d", &fourth->data);
	fourth->next = head;

	//Printing of the Linked list.......
	printf("linked list before deletion:\n");
	linkedListTraversal(head);

	//head = deleteAtFirst(head);			//print case 1
	head = deleteAtIndex(head);			//print case 2
	///head = deleteAtEnd(head);				//print case 3
	//head = deleteGivenValue(head);		//print case 4
	printf("linkedlist after deletion:\n");
	linkedListTraversal(head);

	return 0;
}

/*#######################################

Output:

head = deleteAtFirst(head);---------------output:

enter 1st element: 2
enter 2nd element: 1
enter 3rd element: 4
enter 4th element: 5
linked list before deletion:
the element:2
the element:1
the element:4
the element:5
linkedlist after deletion:
the element:1
the element:4
the element:5
######################################################

head = deleteAtIndex(head);	--------------output:

enter 1st element: 2
enter 2nd element: 5
enter 3rd element: 4
enter 4th element: 5
linked list before deletion:
the element:2
the element:5
the element:4
the element:5
Enter the index where you want to delete the element: 1
linkedlist after deletion:
the element:2
the element:4
the element:5
######################################################

head = deleteAtEnd(head);-----------------output:

enter 1st element: 4
enter 2nd element: 5
enter 3rd element: 1
enter 4th element: 2
linked list before deletion:
the element:4
the element:5
the element:1
the element:2
linkedlist after deletion:
the element:4
the element:5
the element:1
#####################################################

head = deleteGivenValue(head);	-------------output:

Enter the 1st element: 3
Enter the 2nd element: 2
Enter the 3rd element: 4
Enter the 4th element: 5
linked list before deletion:
the element:3
the element:2
the element:4
the element:5
Enter the element which you want to delete: 2
linkedlist after deletion:
the element:3
the element:4
the element:5

#########################################*/