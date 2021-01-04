#include <stdio.h>
#include <stdlib.h>

//Declaration of queue
struct queue
{
	int size;
	int f;
	int r;
	int *arr;
};

//Check if the queue is empty
int isEmpty(struct queue *q)
{
	if(q->r == q->f)
		return 1;

	else
		return 0;

}

//Check if the queue is full
int isFull(struct queue *q)
{
	if(q->r == q->size-1)
		return 1;

	else
		return 0;
}

int main()
{
	/*Another way to allocate memory for queue

	struct queue q;
	q.size = 4;
	q.f = q.r = 0;
	q.arr = (int *) malloc (q.size * sizeof(int));*/

	//Allocation of memory for queue in heap.....
	struct queue *q = (struct queue *) malloc (sizeof(struct queue));
	q->size = 4;
	q->f = q->r = 0;
	q->arr = (int *) malloc (q->size * sizeof(struct queue));

	printf("The queue has been created successfully\n");

	//Check if the queue is empty or not
	if(isEmpty(q))
	{
		printf("The queue is empty\n");
	}
	else
	{
		printf("The queue is not empty\n");
	}

	//Check if the queue is full or not
	if(isFull(q))
	{
		printf("The queue is full\n");
	}
	else
	{
		printf("The queue is not full\n");
	}

	free(q);
	return 0;
}

/*#############################################

Output:

The queue has been created successfully
The queue is empty
The queue is not full

##############################################*/