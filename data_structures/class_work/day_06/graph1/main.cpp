	/*
 * main.cpp
 *
 *  Created on: 30-Sep-2017
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>

#include<cstring>

#define MAX 10

class graph_t
{
private:
	int vert_cnt;
	int edge_cnt;
	int arr[MAX][MAX];
public:
	graph_t(void)
	{
		this->vert_cnt = 0;
		this->edge_cnt = 0;
		/*
		for( int i = 0 ; i < MAX; i++ )
			for( int j = 0 ; j < MAX ; j++ )
				this->arr[i][j] = 0;
		*/
		memset(this->arr, 0, sizeof(this->arr));
	}

	void accept_graph(void)
	{
		cout << "enter the  no. of vertices: ";
		cin >> this->vert_cnt;

		cout << "enter the no. of edges: ";
		cin >> this->edge_cnt;

		for( int i = 0 ; i < this->edge_cnt ; i++ )
		{
			int from, to;

			cout << "enter the edge: from to to: ";
			cin >> from >> to;

			this->arr[from][to] = 1;
			this->arr[to][from] = 1;
		}
	}

	void display_graph(void)
	{
		cout << "input graph is: " << endl;
		for( int i = 0 ; i < this->vert_cnt ; i++ )
		{
			for( int j = 0 ; j < this->vert_cnt ; j++ )
			{
				cout << setw(4) << left << this->arr[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
};

int main(void)
{
	graph_t g1;

	g1.accept_graph();
	g1.display_graph();

	return 0;
}



