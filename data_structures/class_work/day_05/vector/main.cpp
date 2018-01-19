/*
 * main.cpp
 *
 *  Created on: 29-Sep-2017
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;

#include<iomanip>
#include<algorithm>
#include<vector>

int main(void)
{
	vector<int> v1;

	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(50);

	cout << "vector v1 is: ";

	vector<int>::iterator itr;

	for( itr = v1.begin() ; itr != v1.end() ; itr++ )
	{
		cout << *itr << " ";
	}
	cout << endl;

	/*
	for( int index = 0 ; index < v1.size() ; index++ )
	{
		cout << setw(4) << v1[ index ];
	}
	cout << endl;
	*/

	//sort(v1.begin(),v1.end());

	/*
	cout << "vector v1 is: ";
	for( int index = 0 ; index < v1.size() ; index++ )
	{
		cout << setw(4) << v1[ index ];
	}
	cout << endl;
	*/
	cout << "min ele of v1 : " << *min_element(v1.begin(), v1.end()) << endl;
	cout << "max ele of v1 : " << *max_element(v1.begin(), v1.end()) << endl;
	return 0;
}



