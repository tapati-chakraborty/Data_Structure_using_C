#include <stdio.h>
#include <stdlib.h>

struct myArray{
	int total_size;
	int used_size;
	int *ptr;
};

//Method to create an array
void createArray(struct myArray *a)
{
	// (*a).total_size = tSize;
	// (*a).used_size = uSize;
	// (*a).ptr = (int *) malloc (tSize * sizeof(int));

	int tSize;
	printf("Enter total size of the array: ");
	scanf("%d", &tSize);
	a->total_size = tSize;

	printf("Enter the size you want to use: ");
	scanf("%d", &(a->used_size));

	a->ptr = (int *) malloc (tSize * sizeof(int));
}

//Method to set the value of the array
void setVal(struct myArray *a)
{
	int n;
	for(int i = 0; i < a->used_size; i++)
	{
		printf("Enter the value: ");
		scanf("%d" ,&n);
		(a->ptr)[i] = n;
	}
}

//Method to show the element of the array
void showArray(struct myArray *a)
{
	for(int i = 0; i < a->used_size; i++)
	{
		printf("%d\n", (a->ptr)[i]);
	}
}

int main()
{
	struct myArray meao;
	createArray(&meao);
	printf("Before setting any value: \n");
	setVal(&meao);


	printf("After setting value the array is like: \n");
	showArray(&meao);

	free(meao.ptr);

	return 0;
}