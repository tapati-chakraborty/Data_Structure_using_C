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

//Method to get partition index
int partition(int A[], int low, int high)
{
	int pivot = A[low];
	int i = low+1;
	int j = high;
	int temp;

	do
	{
		while(A[i] <= pivot)
		{
			i++;
		}
		while(A[j] > pivot)
		{
			j--;
		}
		if(i < j)
		{
			//Swap A[i] and A[j]
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}while(i < j);

	//swap A[low] and A[j]
	temp = A[low];
	A[low] = A[j];
	A[j] = temp;

	return j;
}

//Method for quick sorting
void QuickSort(int A[], int low, int high)
{
	int partitionIndex;//Index of pivot after partition

	if(low < high)
	{
		partitionIndex = partition(A, low, high);
		QuickSort(A, low, partitionIndex-1);//sort left subarray
		QuickSort(A, partitionIndex+1, high);//sort right subarray
	}
}

int main()
{
	/*
	2,3,5,87,4,76,12,32,1
	2,3i,5,87,4,76,12,32,1j
	2,1,5,87,4,76,12,32,3
	*/
	int A[] = {2,3,5,87,4,76,12,32,1};
	int n = 9;

	printf("Before sorting: \n");
	printArray(A, n);
	printf("\n");

	QuickSort(A, 0, n-1);
	printf("After sorting: \n");
	printArray(A, n);

	return 0;
}

/*
Output:
Before sorting:
2 3 5 87 4 76 12 32 1

After sorting:
1 2 3 4 5 12 32 76 87
*/