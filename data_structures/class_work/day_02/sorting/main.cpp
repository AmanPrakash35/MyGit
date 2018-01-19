/*
 * main.cpp
 *
 *  Created on: 26-Sep-2017
 *      Author: sunbeam
 */

	/* sorting algorithms features:
	 * - simple implementation
	 * - in-place: it does not take extra space for sorting
	 * - stable: if data elements has same key value then the order
	 * of those elements remains unchanged
	 * - adaptive: it is efficient for already sorted data elements
	 * (selection sort cannot be considered as an adaptive sorting algo.)
	 *
	 */


#include<iostream>
using namespace std;

#include<iomanip>

#define SIZE 8

#define SWAP(a,b) { int t = a; a = b; b = t; }

void display_array(int *arr)
{
	for( int index = 0 ; index < SIZE ; index++ )
		cout << setw(4) << arr[index];
	cout << endl;
}

void selection_sort(int *arr)
{
	int iterations = 0;
	int comparisons = 0;

	for( int i = 0 ; i < SIZE-1 ; i++ )//--> loop run n times
	{
		iterations++;
		for( int j = i+1 ; j < SIZE ; j++ )//--> loop runs n times
		/* statements inside inner loop executes n^2 times */
		{
			comparisons++;
			if( arr[i] > arr[j] )
				SWAP(arr[i],arr[j]);
		}

		cout << "after iteration: " << iterations << " => ";
		display_array(arr);
	}

	cout << "no. of iterations are: " << iterations << endl;
	cout << "no. of comparisons are: " << comparisons << endl;

	/* as statements inside inner loop executes n^2 times,
	 * best case time complexity   : O(n^2): omega(n^2)
	 * worst case time complexity  : O(n^2): O(n^2)
	 * average case time complexity: O(n^2): theta(n^2)
	 */

}

void bubble_sort(int *arr)
{
	int iterations = 0;
	int comparisons = 0;
	bool flag = true;

	for( int i = 0 ; i < SIZE-1 && flag == true ; i++ )//--> loop run n times
	{
		iterations++;
		flag = false;

		for( int j = 0 ; j < SIZE-i-1 ; j++ )//--> loop runs n times
		/* statements inside inner loop executes n^2 times */
		{
			comparisons++;
			if( arr[j] > arr[j+1] )//if ele's are in wrong order
			{
				SWAP(arr[j],arr[j+1]);
				flag = true;
			}
		}

		cout << "after iteration: " << iterations << " => ";
		display_array(arr);
	}

	cout << "no. of iterations are: " << iterations << endl;
	cout << "no. of comparisons are: " << comparisons << endl;

	/* as statements inside inner loop executes n^2 times,
	 * best case time complexity   : O(n): omega(n) -> if array ele's are already in sorted manner
	 * worst case time complexity  : O(n^2): O(n^2)
	 * average case time complexity: O(n^2): theta(n^2)
	 */
}

void insertion_sort(int *arr)
{
	for( int i = 1 ; i < SIZE ; i++ )
	{
		int key = arr[i];
		int j = i - 1;

		while( j >= 0 && key < arr[j] )
		{
			arr[j+1] = arr[j];
			j--;
		}

		arr[j+1] = key;
	}
	/* as statements inside inner loop executes n^2 times,
	 * best case time complexity   : O(n): omega(n) -> if array ele's are already in sorted manner
	 * worst case time complexity  : O(n^2): O(n^2)
	 * average case time complexity: O(n^2): theta(n^2)
	 */

}

void quick_sort(int *arr,int left,int right)
{
	if( left >= right )//termination condition for recursive calling
		return;

	int i = left;
	int j = right;

	//partitioning logic
	while( i < j )
	{
		while( i <= right && arr[i] <= arr[left] )
			i++;

		while( arr[j] > arr[left] )
			j--;

		//if i & j are not crossed then swap them
		if( i < j )
			SWAP(arr[i],arr[j])
	}

	//swap the pivot ele with jth pos ele
	SWAP(arr[j],arr[left]);

	//apply quick sort on left partition
	quick_sort(arr, left, j-1);
	//apply quick sort on right partition
	quick_sort(arr, j+1, right);

	/*
	 * best case time complexity   : O(n): omega(n) -> if we select middle ele as a pivot
	 * worst case time complexity  : O(n log n): O(n log n)
	 * average case time complexity: O(n logn): theta(n logn)
	 */

}

void merge(int *arr,int left,int mid,int right)
{
	int i = left;
	int j = mid+1;
	int k = 0;
	int size = (right-left+1);

	//allocate memory dynamically for temp array of size -> size(right-left+1)
	int *ptr = new int[size];
	//merging logic
	while( i <= mid && j <= right )
	{
		if( arr[i] < arr[j] )
			ptr[k++] = arr[i++];
		else
			ptr[k++] = arr[j++];
	}

	//copy ele's from first subarray till the end into the temp array
	while( i <= mid )
		ptr[k++] = arr[i++];

	//OR-> copy ele's from second sub array till the end into the temp array
	while( j <= right )
		ptr[k++] = arr[j++];

	//copy merged temp array(sorted) array into original array
	k=0;
	i=left;

	while( i <= right )
		arr[i++] = ptr[k++];

	//delete the dynamically allocated memory
	delete ptr;
	ptr = NULL;
}

void merge_sort(int *arr,int left,int right)
{
	if( left < right )
	{
		int mid = (left+right)/2;
		merge_sort(arr,left, mid);
		merge_sort(arr,mid+1,right);
		merge(arr,left,mid,right);
	}
}

int main(void)
{
	int arr[SIZE] = {50,30,20,40,70,10,60,80};
	//int arr[SIZE] = {10,20,30,40,50,60,70,80};

	cout << "array ele's bfore sort are: ";
	display_array(arr);

	//selection_sort(arr);
	//bubble_sort(arr);
	//insertion_sort(arr);
	//quick_sort(arr,0,SIZE-1);
	merge_sort(arr,0,SIZE-1);

	cout << "array ele's after sort are: ";
	display_array(arr);


	return 0;
}



