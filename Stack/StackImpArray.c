#include <stdio.h>
#include <stdlib.h>

//Declaration of stack which will be implemented by array
struct stack
{
	int size;
	int top;
	int *arr;
};

//Check if the stack is empty
int isEmpty(struct stack * ptr)
{
	if(ptr->top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//Check if the stack is full
int isFull(struct stack * ptr)
{
	if(ptr->top == ptr->size-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int main()
{
	//Allocation of memory for stack in heap
	struct stack *s = (struct stack *)malloc(sizeof(struct stack));
	s->size = 80;
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

	//check if the stack is empty or not.....
	if(isEmpty(s))
	{
		printf("The stack is empty....\n");
	}
	else
	{
		printf("The stack is not empty....\n");
	}

	//check if the stack is full or not
	if(isFull(s))
	{
		printf("The stack is full.....\n");
	}
	else
	{
		printf("The stack is not full....\n");
	}

	free(s);

	return 0;
}


/*############################################

Output:

Stack has been created successfully using array......
The stack is empty....
The stack is not full....

############################################*/