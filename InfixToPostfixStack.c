#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaration of stack
struct stack
{
	int size;
	int top;
	char *arr;
};

//Check if the stack is empty or not
int isEmpty(struct stack *ptr)
{
	if(ptr->top == -1)
		return 1;
	else
		return 0;
}

//Check if the stack is full or not
int isFull(struct stack *ptr)
{
	if(ptr->top == ptr->size - 1)
		return 1;
	else
		return 0;
}

//Get the top most character of the stack
int stackTop(struct stack *ptr)
{
	return ptr->arr[ptr->top];
}

//Push an character to the stack
void push(struct stack *ptr, char val)
{
	if(isFull(ptr))
	{
		printf("Stack Overflow!Cannot push an element to the stack\n");
	}
	else
	{
		ptr->top++;
		ptr->arr[ptr->top] = val;
	}
}

//Pop an character from the stack
char pop(struct stack *ptr)
{
	if(isEmpty(ptr))
	{
		printf("Stack Underflow!cannot pop any element from the stack\n");
		return -1;
	}
	else
	{
		char val = ptr->arr[ptr->top];
		ptr->top--;
		return val;
	}
}

//Check the precedence of all the operator
int precedence(char ch)
{
	if(ch == '*' || ch == '/')
		return 3;
	else if(ch == '+' || ch == '-')
		return 2;
	else
		return 0;

}

//Check if the character is an operator or not
int isOperator(char ch)
{
	if(ch == '+' || ch == '-' || ch == '/' || ch == '*')
		return 1;
	else
		return 0;

}

//Convert the expression from Infix to Postfix
char *InfixToPostfix(char *infix)
{
	struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
	sp->size = 10;
	sp->top = -1;
	sp->arr = (char *) malloc(sp->size * sizeof(char));

	char *postfix = (char *) malloc ((strlen(infix)+1) * sizeof(char));

	int i = 0;	//------Track Infix traversal
	int j = 0;	//------Track Postfix traversal

	while(infix[i] != '\0')
	{
		if(!isOperator(infix[i]))
		{
			postfix[j] = infix[i];

			j++;
			i++;
		}
		else
		{
			if (precedence(infix[i]) > precedence(stackTop(sp)))
			{
				push(sp, infix[i]);
				i++;
			}
			else
			{
				postfix[j] = pop(sp);
				j++;
			}
		}
	}

	while(!isEmpty(sp))
	{
		postfix[j] = pop(sp);
		j++;
	}
	postfix[j] = '\0';
	return postfix;

	free(sp);

}

int main()
{
	char *infix = "x+y-z+3/a*4";

	printf("postfix is: %s\n", InfixToPostfix(infix));

	return 0;
}

/*#############################

Output:

postfix is: xy+z-3a/4*+

###############################*/