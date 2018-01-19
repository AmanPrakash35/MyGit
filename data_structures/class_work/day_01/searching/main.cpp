/*
 * main.cpp
 *
 *  Created on: 25-Sep-2017
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;

#include<iomanip>

#define SIZE 5

/*
int rec_sum(int *arr, int index )
{
	if( index < 0 )
		return 0;
	else
	{
		return ( arr[index] + rec_sum(arr,index-1) );
	}
}



void fun(int n)
{
	if( n == 0 )
		return;
	else
	{
		fun(--n);//tail recursive function
		cout << setw(4) << n;
	}
}

*/

/* tail recursive function: the recursive function in which the recursive
 * call is the last statement in that function
 */

int comp = 0;

bool linear_search(int *arr, int key)
{
	comp = 0;
	for( int i = 0 ; i < SIZE && arr[i] < key ; i++ )
	{
		comp++;
		if( key == arr[i] )
			return true;
	}

	return false;
}

bool rec_linear_search(int *arr, int index, int key)
{
	if( index == SIZE )
		return false;

	if( key == arr[index])
		return true;
	else
		return ( rec_linear_search(arr, index+1, key));
}

bool binary_search(int *arr, int key)
{
	int left = 0;
	int right = SIZE-1;

	while( left <= right )
	{
		int mid = (left + right ) / 2;

		if( key == arr[mid] )
			return true;

		if( key < arr[mid] )
			right = mid-1;
		else
			left = mid+1;
	}

	return false;
}

void display_array(int *arr)
{
	for( int index = 0 ; index < SIZE ; index++ )
	{
		cout << setw(4) << arr[index];
	}
	cout << endl;
}

bool rec_binary_search(int *arr, int left, int right, int key)
{
	if( left > right )
		return false;

	int mid = (left + right) / 2;
	if( key == arr[mid] )
		return true;

	if( key < arr[mid] )
		return rec_binary_search(arr, left, mid-1, key);
	else
		return rec_binary_search(arr, mid+1, right, key);
}

int main(void)
{

	int arr[5] = { 10,20,30,40,50};


	cout << "array els's are: "; display_array(arr);
	int key;
	cout << "enter the key : ";
	cin >> key;

	bool ret_val = linear_search(arr, key);
_
	cout << "no. of comparisons are: " << comp << endl;

	//bool ret_val = rec_linear_search(arr, 0, key);
	//bool ret_val = binary_search(arr,key);
	//bool ret_val = rec_binary_search(arr,0,SIZE-1,key);

	if( ret_val == true )
		cout << "key is found in an array" << endl;
	else
		cout << "key is not found in an array" << endl;

	return 0;
}


