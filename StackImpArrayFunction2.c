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

//Traversing the stack
int peek(struct stack *ptr, int i)
{
	int arrIndex = ptr->top -i + 1;
	if(arrIndex < 0)
	{
		printf("Not a valid position for the stack\n");
		return -1;
	}
	else
	{
		return ptr->arr[arrIndex];
	}

}

//Printing Top most element of the stack
int stackTop(struct stack *ptr)
{
	return ptr->arr[ptr->top];
}

//Printing Bottom Most element of the stack
int stackBottom(struct stack *ptr)
{
	return ptr->arr[0];
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
		push(s);	//------>pushing elements
	}

	printf("The top most value of the stack is: %d\n", stackTop(s));
	printf("The bottom most value of the stack is: %d\n", stackBottom(s));

	//printing value of the stack
	for(int j = 1; j <= s->top + 1; j++)
	{
		printf("The value at position %d is %d\n", j, peek(s, j));
	}

	return 0;
}


/*##################################################################

Stack has been created successfully using array......
Before pushing(return 1 if full and 0 if not full),Full: 0
Before pushing(return 1 if empty and 0 if not empty),Empty: 1
enter the total number of element you want to push to stack: 4
Pushing 0th element is....Enter the element which you want to push to the stack: 1
Pushing 1th element is....Enter the element which you want to push to the stack: 2
Pushing 2th element is....Enter the element which you want to push to the stack: 6
Pushing 3th element is....Enter the element which you want to push to the stack: 4
The top most value of the stack is: 4
The bottom most value of the stack is: 1
The value at position 1 is 4
The value at position 2 is 6
The value at position 3 is 2
The value at position 4 is 1

####################################################################*/