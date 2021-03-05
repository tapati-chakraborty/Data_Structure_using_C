#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
	int size;
	int f;
	int r;
	int *arr;
};

int isEmpty(struct circularQueue *q)
{
	if(q->f == q->r)
	{
		return 1;
	}
	return 0;
}

int isFull(struct circularQueue *q)
{
	if((q->r+1) % q->size == q->f)	//condition to check the queue is full
	{
		return 1;
	}
	return 0;
}

void enqueue(struct circularQueue *q, int val)
{
	if(isFull(q))
	{
		printf("The queue is full can't push more element\n");
	}
	else
	{
		q->r = q->r+1 % q->size;
		q->arr[q->r] = val;
		printf("Enqueued element: %d\n", val);
	}
}

int dequeue(struct circularQueue *q)
{
	int a = -1;
	if(isEmpty(q))
	{
		printf("The queue is empty\n");
	}
	else
	{
		q->f = q->f+1 % q->size;
		a = q->arr[q->f];
	}
	return a;
}

int main()
{
	struct circularQueue q;
	q.size = 4;
	q.f = q.r = 0;
	q.arr = (int *) malloc (q.size * sizeof(int));

	//Enqueue some element to the queue
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);
	//Dequeue some element from the queue
	printf("Dequeueing element %d\n: ", dequeue(&q));
	printf("Dequeueing element %d\n: ", dequeue(&q));
	printf("Dequeueing element %d\n: ", dequeue(&q));
	enqueue(&q, 5);
	enqueue(&q, 6);
	enqueue(&q, 7);
	enqueue(&q, 8);

	if(isEmpty(&q)){
		printf("The queue is empty\n");
	}
	if(isFull(&q)){
		printf("The queue is full\n");
	}
	free(q.arr);

	return 0;
}
/*
output:

Enqueued element: 2
Enqueued element: 3
Enqueued element: 4
Dequeueing element 2
: Dequeueing element 3
: Dequeueing element 4
: Enqueued element: 5
Enqueued element: 6
Enqueued element: 7
The queue is full can't push more element
The queue is full*/