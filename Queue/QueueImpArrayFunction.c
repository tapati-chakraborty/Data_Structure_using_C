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

//Check if the queue is empty or not
int isEmpty(struct queue *q)
{
	if(q->r == q->f)
		return 1;

	else
		return 0;
}

//Check if the queue is full or not
int isFull(struct queue *q)
{
	if(q->r == q->size-1)
		return 1;

	else
		return 0;
}

//Enqueue an element to the queue
void enqueue(struct queue *q, int val)
{
	if(isFull(q))
	{
		printf("The queue is full!Cannot push any element to the stack\n");
	}
	else
	{
		q->r++;
		q->arr[q->r] = val;
		printf("Enqueued element: %d\n", val);
	}
}

//Dequeue en element from the queue
int dequeue(struct queue *q)
{
	int a = 0;
	if(isEmpty(q))
	{
		printf("The queue is empty!Cannot remove any element from the queue\n");
	}
	else
	{
		q->f++;
		a = q->arr[q->f];
	}
	return a;
}

int main()
{
	//Allocation of memory for queue in heap
	struct queue *q = (struct queue *) malloc (sizeof(struct queue));
	q->size = 5;
	q->f = q->r = 0;
	q->arr = (int *) malloc (q->size *(sizeof(int)));
	printf("Queue has been created successfully\n");

	//Enqueue few element
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 45);

	printf("Dequeuing element: %d\n", dequeue(q));	//------->First in firt out
	printf("Dequeuing element: %d\n", dequeue(q));

	free(q);
	free(q->arr);
	return 0;

	/*Another process.....

	struct queue q;
	q.size = 5;
	q.f = q.r = 0;
	q.arr = (int *) malloc (q.size *(sizeof(int)));
	printf("Queue has been created successfully\n");

	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 45);

	printf("Dequeuing element: %d\n", dequeue(&q));
	printf("Dequeuing element: %d\n", dequeue(&q));

	free(q.arr);
	return 0;
	*/
}

/*#############################################
Output:

Queue has been created successfully
Enqueued element: 2
Enqueued element: 3
Enqueued element: 45
Dequeuing element: 2
Dequeuing element: 3

#############################################*/