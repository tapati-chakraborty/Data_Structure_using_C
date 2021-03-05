#include <stdio.h>

//Method to display the element of array
void display(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//Delete an element from a given index
int deletion(int arr[], int size)
{
	int index;

	printf("Enter the index from where you want to delete item: ");
	scanf("%d", &index);
	for(int i = index; i < size; i++)
	{
		arr[i] = arr[i+1];	//At index i the element deleted and (i+1)th element takes the place
	}
}

int main()
{
	int arr[100] = {2, 3, 4, 5, 16};	//Given array
	int size = 5;

	printf("Before deletion the array: \n");
	display(arr, size);

	deletion(arr, size);
	size -= 1;

	printf("After deletion the array: \n");
	display(arr, size);

	return 0;
}