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

void swap(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

/*To heapify a subtree rooted with node i which is an index of A[]
and n is the size of the array*/
void heapify(int A[], int n, int i)
{
	int largest = i; //initialize largest as root
	int l = 2*i+1; //left subtree
	int r = 2*i + 2; //right subtree

	//if left child is greater than root
	if(l < n && A[l] > A[largest])
	{
		largest = l;
	}
	//if right xhild is greater
	if(r < n && A[r] > A[largest])
	{
		largest = r;
	}

	//if largest is not root
	if(largest != i)
	{
		swap(A[i], A[largest]);

		heapify(A, n, largest);
	}
}

void heapSort(int A[], int n)
{
	for(int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(A, n, i);
	}
	for(int i = n-1; i > 0; i--)
	{
		//move current root to end
		swap(A[0], A[i]);

		//call heapify on reduced heap
		heapify(A, i, 0);
	}
}

int main()
{
	int A[] = {2, 4, 5, 6, 3, 9};
	int n = sizeof(A) / sizeof(int);

	printArray(A, n);
	heapSort(A, n);
	printArray(A, n);

	return 0;
}