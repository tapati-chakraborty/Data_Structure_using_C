#include <stdio.h>
#include <stdlib.h>

//Declaration of stack
struct stack
{
	int top;
	int size;
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
	if(ptr->top == ptr->size -1)
		return 1;
	else
		return 0;
}

//To push an element to the stack
void push(struct stack *ptr, char val)
{
	if(isFull(ptr))
		printf("Stack Overflow!Can't push any element\n");
	else
	{
		ptr->top ++;
		ptr->arr[ptr->top] = val;
	}
}

//To pop an element from the stack
char pop(struct stack *ptr)
{
	if(isEmpty(ptr))
		printf("Stack Underflow!Can't pop any element\n");
	else
	{
		char exp = ptr->arr[ptr->top];
		ptr->top --;
		return exp;
	}
}

//get the element which is at the top of the stack
char stackTop(struct stack *sp)
{
	return sp->arr[sp->top];
}

//function to find matching
int match (char a, char b)
{
	if(a == '{' && b == '}'){
		return 1;
	}
	if(a == '(' && b == ')'){
		return 1;
	}
	if(a == '[' && b == ']'){
		return 1;
	}
	return 0;
}

//Check if parenthesis is match or not
int paranthesisMatch(char *exp)
{
	//Dyanamic allocation of memory for stack 
	struct stack *s = (struct stack *) malloc(sizeof(struct stack));
	s->top = -1;
	s->size = 100;
	s->arr = (char *)malloc(s->size * (sizeof(char)));
	char popped_char;

	for(int i = 0; exp[i] != '\0'; i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
		{
			push(s,exp[i]);	//--->if any of the char('(','{','[') is matched then push 
		}
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if(isEmpty(s)){
				return 0;
			}
			popped_char = pop(s);	//--->if any of the char(')','}',']') is matched then pop 
			if(!match(popped_char, exp[i])){
				return 0;
			}
		}
	}

	if(isEmpty(s))
	{
		return 1;
	}
	else
	{
		return 0;
	}

free(s); //---->free of the memory is done after use
free(s->arr);
}

int main()
{
char *exp = "[2*{45+987}/(34-7)]";
// char *exp = "[5+90}+{5(45+8)]";

if(paranthesisMatch(exp))
{
	printf( "All the parenthesis is matched\n");
}
else
{
	printf("Parenthesis is not matched at all\n");
}
}

/*################################################
Output:

when exp =  [2*{45+987}/(34-7)]
o/p: All the parenthesis is matched

when exp = [5+90}+{5(45+8)]
o/p: Parenthesis is not matched at all

##################################################*/