/*############################

***	In this sorting algorithm,  Each element of the array is compared with its adjacent element.
The algorithm processes the list in passes. A list with n elements requires n-1 passes for sorting.***

Complexity:
Space: O(1)
Worst-Case: O(n^2)
Average-Case: O(n^2)
Best-Case: O(n)

##############################*/


#include <stdio.h>

//Method to print the element of the array
void printArray(int *A, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

//Method for bubble sorting
void bubbleSort(int *A, int n)
{
	int temp;
	int issorted = 0;

	for(int i = 0; i < n-1; i++)	//for number of pass
	{
		printf("Working on pass no %d\n", i+1);
		for (int j = 0; j < n-1-i; j++)	//for comparison in each pass
		{
			if(A[j] > A[j+1]){
				temp = A[j]; 	//if previous no is greater than swap them
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
}

//Another method of bubble sorting
//(if array is already sorted then this method print the array in only one pass)
void bubbleSortAdaptive(int *A, int n)
{
	int temp;
	int issorted = 0;

	for(int i = 0; i < n; i++)	//for number of pass
	{
		printf("Working on the pass no %d\n", i+1);
		issorted = 1;
		for(int j = 0; j < n-1-i; j++)	//for comparison in each pass
		{
			if(A[j] > A[j+1]){
				temp = A[j]; 	//if previous no is greater than swap them
				A[j] = A[j+1];
				A[j+1] = temp;
				issorted = 0;
			}
		}
		if(issorted){
			return;
		}
	}
}

int main()
{
	int A[] = {2,3,56,76,3,89,65,41,18,22,6};
	int n = 11;

	printf("Before sorting the array: \n");
	printArray(A, n);
	bubbleSort(A, n);

	printf("After sorting the array: \n");
	printArray(A, n);

	// int A[] = {2,3,4,5,6,7,8,9};
	// int n = 8;
	// bubbleSortAdaptive(A, n);
	// printArray(A, n);

	return 0;
}

/*
output:

Before sorting the array:
2 3 56 76 3 89 65 41 18 22 6
Working on pass no 1
Working on pass no 2
Working on pass no 3
Working on pass no 4
Working on pass no 5
Working on pass no 6
Working on pass no 7
Working on pass no 8
Working on pass no 9
Working on pass no 10
After sorting the array:
2 3 3 6 18 22 41 56 65 76 89

***when array is sorted adaptive sorting function work in one pass
Working on the pass no 1
2 3 4 5 6 7 8 9
*/