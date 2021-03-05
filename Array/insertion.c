#include <stdio.h>

//Method to display the element of the array
void display(int arr[], int n)
{
	for(int i =0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//Method to insert element to the array at a given index
int insertion(int arr[], int size, int capacity, int element, int index)
{
	if(size >= capacity){
		return -1;
	}

	for(int i = size-1; i>=index; i--)
	{
		arr[i+1] = arr[i];
	}

	arr[index] = element;
	return 1;

}

int main()
{
	int arr[100] = {2, 4, 5, 7, 13};	//Given array
	int size = 5, element = 23, index = 1;

	printf("Before insertion the array: \n");
	display(arr, size);

	insertion(arr, size, 100, element, index);
	size += 1;

	printf("After insertion the array: \n");
	display(arr, size);

	return 0;
}
