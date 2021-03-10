/*############################

***Insertion sort is the simple sorting algorithm which is commonly used in the
daily lives while ordering a deck of cards. In this algorithm, we insert each element
onto its proper place in the sorted array. This is less efficient than the other sort algorithms
like quick sort, merge sort, etc.***

Complexity:
Space: O(1)
Worst-Case: O(n^2)
Average-Case: O(n^2)
Best-Case: O(n)

##############################*/


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

//Method for insertion sorting
void insertionSort(int *A, int n)
{
	int key, j;
	//loop for passes
	for(int i = 1; i <= n-1; i++)
	{
		key = A[i];
		j = i-1;

		//loop for each pass
		while(j >= 0 && A[j] > key) //if A[j] is greater than key
		{
			A[j+1] = A[j];  //A[j+1] becomes A[j]***(main logic)
			j --;
		}
		A[j+1] = key;
	}
}

int main()
{
	/*
    -1  0    1   2     3    4    5
        12,| 54,  65,  07,  23,  09 --> i=1, key=54, j=0
        12,| 54,  65,  07,  23,  09 --> 1st pass done(i = 1)!

        12,  54,| 65,  07,  23,  09 -->i=2, key=65, j=1
        12,  54,| 65,  07,  23,  09 -->2nd pass done(i = 2)!

        12,  54,  65,| 07,  23,  09 -->i=3, key=07, j=2
        12,  54,  65,| 65,  23,  09 -->i=3, key=07, j=1
        12,  54,  54,| 65,  23,  09 -->i=3, key=07, j=0
        12,  12,  54,| 65,  23,  09 -->i=3, key=07, j=-1
        07,  12,  54,| 65,  23,  09 -->3rd pass done(i = 3)!

        07,  12,  54,  65,| 23, 09 -->i=4, key=23, j=3
        07,  12,  54,  65,| 65, 09 -->i=4, key=23, j=2
        07,  12,  54,  54,| 65, 09 -->i=4, key=23, j=1
        07,  12,  23,  54,| 65, 09 -->4th pass done(i = 4)!

        07,  12,  23,  54,  65,| 09 -->i=5, key=09, j=4
        07,  12,  23,  54,  65,| 65 -->i=5, key=09, j=3
        07,  12,  23,  54,  54,| 65 -->i=5, key=09, j=2
        07,  12,  23,  23,  54,| 65 -->i=5, key=09, j=1
        07,  12,  12,  23,  54,| 65 -->i=5, key=09, j=0
        07,  09,  12,  23,  54,| 65 -->5th pass done(i = 5)!

        07,  09,  12,  23,  54,  65| -->After the 5th pass
	*/

	int A[] = {12, 54, 65, 7, 23, 9};
	int n = 6;

	printf("Before sorting: \n");
	printArray(A, n);

	printf("\n");
	insertionSort(A, n);
	printf("After insertion sorting: \n");
	printArray(A, n);

	return 0;
}

/*
Output:
Before sorting:
12 54 65 7 23 9

After insertion sorting:
7 9 12 23 54 65
*/