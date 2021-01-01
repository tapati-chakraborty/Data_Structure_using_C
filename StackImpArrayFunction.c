#include <stdio.h>
#include <stdlib.h>

//Declaration of stack which will be implemented by array
struct stack
{
	int size;
	int top;
	int *arr;
};

//Check if the stack is full
int isFull(struct stack *ptr)
{
	if(ptr->top == ptr->size-1)
		return 1;
	else
		return 0;
}

//Check if the stack is empty
int isEmpty(struct stack *ptr)
{
	if(ptr->top == -1)
		return 1;
	else
		return 0;
}

//Push an element to the stack
void push(struct stack *ptr)
{
	int val;
	printf("Enter the element which you want to push to the stack: ");
	scanf("%d",&val);
	if(isFull(ptr))
	{
		printf("Stack Overflow! Cannot push %d to the stack\n", val);
	}
	else
	{
		ptr->top ++;
		ptr->arr[ptr->top] = val;
	}

}

//Pop an element from the stack
void pop(struct stack *ptr)
{
	if(isEmpty(ptr))
	{
		printf("Stack Underflow! Cannot pop any element from the stack\n");
	}
	else
	{
		int val = ptr->arr[ptr->top];
		ptr->top --;
		printf("%d poped from the stack\n", val);
	}

}

int main()
{
	//Allocation of memory for stack in heap
	struct stack *s = (struct stack *)malloc(sizeof(struct stack));
	s->size = 10;
	s->top = -1;
	s->arr = (int *) malloc(s->size * sizeof(int));

	/*######################################################
	Another process for allocating memory for stack......

	struct stack s = (struct stack *)malloc(sizeof(struct stack));
	s.size = 10;
	s.top = -1;
	s.arr = (int *) malloc(s.size * sizeof(int));
	########################################################*/

	printf("\nStack has been created successfully using array......\n");

	printf("Before pushing(return 1 if full and 0 if not full),Full: %d\n", isFull(s));
	printf("Before pushing(return 1 if empty and 0 if not empty),Empty: %d\n", isEmpty(s));

	int i,n;
	printf("enter the total number of element you want to push to stack: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		printf("Pushing %dth element is....",i);
		push(s);
	}


	printf("After pushing(return 1 if full and 0 if not full),Full: %d\n", isFull(s));
	printf("After pushing(return 1 if empty and 0 if not empty),Empty: %d\n", isEmpty(s));

	pop(s);	//------>Last In First Out

	return 0;
}