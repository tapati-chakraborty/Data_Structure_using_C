/*
____________________________________________________________________________
    👉____Linear search____             |       👉_____Binary search____
                                        |
1.)works on both sorted and unsorted    |1.)works only on sorted array
    array.                              |
                                        |
2.)equality operation                   |2.)inequality operation
                                        |
                                        |
3.)O(n) worst case complexity.          |3.)O(logn) worst case complexity.
                                        |
                                        |
____________________________________________________________________________
*/

#include <stdio.h>

//Method of linear searching
int linearSearch(int arr[], int size, int element)
{
	for(int i = 0; i < size-1; i++)
	{
		if(arr[i] == element) {
			return i;
		}
	}
	return -1;
}

//Method of binary search
int binarySearch(int arr[], int size, int element)
{
	int low, mid, high;
	low = 0;
	high = size - 1;

	//keep searching until
	while(low <= high)
	{
		mid = (high + low)/2;
		if(arr[mid] == element) {
			return mid;     //in best-case the middle element will be the search element
		}
		if(arr[mid] < element) {
			low = mid + 1;   //if middle element is less than the search element then low range become mid+1
		}
		else {
			high = mid - 1;  //if middle element is greater than search element then high range become mid-1
		}
	}
	return -1;
}

int main()
{
    //unsorted array for linear search
	int arr[] = {3,56,2,89,1,65,8,65,345,98};
	int element;
	printf("Enter the element you want to search: ");
	scanf("%d", &element);
	int size = sizeof(arr)/sizeof(int);	//sizeof(arr) = 10*4 = 40 & sizeof(int) = 4
	int searchIndex = linearSearch(arr, size, element);
	printf("The lement %d was found at index %d 😊\n",element, searchIndex);

    //sorted array for binary search
    // int arr[] = {2,3,4,5,6,7,89,97,102};
    // int element;
    // printf("Enter the element you want to search: ");
    // scanf("%d", &element);
    // int size = sizeof(arr)/sizeof(int);
    // int searchIndex = binarySearch(arr, size, element);
    // printf("The lement %d was found at index %d 😊\n",element, searchIndex);

	return 0;
}