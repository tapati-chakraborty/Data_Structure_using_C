#include <stdio.h>

//Method to print a array
void printArray(int *A, int n)
{
	for(int i =0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

void Merge(int A[], int low, int high, int mid)
{
	int i, j, k, B[100];
	i = low;
	j = mid + 1;
	k = low;

	while(i <= mid && j <= high)
	{
		if(A[i] < A[j])
		{
			B[k] = A[i];
			i++;
			k++;
		}
		else
		{
			B[k] = A[j];
			j++;
			k++;
		}
	}
	while(i <= mid)
	{
		B[k] = A[i];
		i++;
		k++;
	}
	while(j <= high)
	{
		B[k] = A[j];
		j++;
		k++;
	}
	for(i = low; i <= high; i++)
	{
		A[i] = B[i];
	}
}

//Method for merge sorting
void mergeSort(int A[], int low, int high)
{
	int mid;
	if(low < high)
	{
		mid = low + (high - low)/2;
		mergeSort(A, low, mid);
		mergeSort(A, mid+1, high);
		Merge(A, low, high, mid);
	}
}

int main()
{
	int A[] = {2, 7, 5, 4, 6, 3, 8};
	int n = sizeof(A) / sizeof(int);

	printf("Before sorting: \n");
	printArray(A, n);
	mergeSort(A, 0, 6);
	printf("After sorting: \n");
	printArray(A, n);

	return 0;
}

/*
Output:

Before sorting:
2 7 5 4 6 3 8
After sorting:
2 3 4 5 6 7 8

*/