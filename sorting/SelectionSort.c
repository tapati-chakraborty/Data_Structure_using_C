/*##########################

***In selection sort, the smallest value among the unsorted elements of the array
is selected in every pass and inserted to its appropriate position into the array.

First, find the smallest element of the array and place it on the first position.
Then, find the second smallest element of the array and place it on the second position.
The process continues until we get the sorted array.***

Complexity:
Space: O(1)
Worst-Case: O(n^2)
Average-Case: O(n^2)
Best-Case: O(n)

############################*/


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

//Method for selection sorting
void SelectionSort(int *A, int n)
{
	int IndexOfMin, temp;
	printf("Running selection sort....\n");
	for (int i = 0; i < n-1; i++)//For number of passes
	{
		IndexOfMin = i;
		for (int j = i+1; j < n ; j++)
		{
			if(A[j] < A[IndexOfMin])
			{
				IndexOfMin = j;
			}
		}
		//Swap A[i] and A[IndexOfMin]
		temp = A[i];
		A[i] = A[IndexOfMin];
		A[IndexOfMin] = temp;
	}
}

int main()
{

	/*
    Input array (There will be total n-1 passes, here no of passes will be 5-1=4)
    0     1     2     3    4
    |03,  05,  02,   13,  12

    After 1st pass
    0     1      2      3    4
    02, |05,    03,    13,   12

    After 2nd pass
    0     1     2      3     4
    02,  03,   |05,    13,  12

    After 3rd pass
    0     1     2      3     4
    02,  03,   05,    |13,  12

    After 4th pass
    0     1     2      3     4
    02,  05,   03,     12,  |13

	*/
	int A[] = {3,5,2,13,12};
	int n = 5;

	printf("Before sorting: \n");
	printArray(A, n);
	printf("\n");

	SelectionSort(A, n);
	printf("\n");
	printf("After sorting: \n");
	printArray(A, n);

	return 0;
}

/*
Output:
Before sorting:
3 5 2 13 12

Running selection sort....

After sorting:
2 3 5 12 13

*/