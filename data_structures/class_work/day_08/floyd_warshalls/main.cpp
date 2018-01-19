/*
 * main.cpp
 *
 *  Created on: 03-Oct-2017
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;

#include<iomanip>

#define MAX 4
#define INF 999


void display_graph(int graph[MAX][MAX])
{
	for( int i = 0 ; i < MAX ; i++ )
	{
		for( int j = 0 ; j < MAX ; j++ )
		{
			if( graph[i][j] != INF )
				cout << setw(4) << left << graph[i][j];
			else
				cout << setw(4) << left << "#";
		}
		cout << endl;
	}
}

void floyd_warshall(int graph[MAX][MAX])
{
	//copy input matrix into the dist matrix(solution)
	int dist[MAX][MAX];

	for( int i = 0 ; i < MAX ; i++ )
		for( int j = 0 ; j < MAX ; j++ )
			dist[i][j] = graph[i][j];

	for( int i = 0 ; i < MAX ; i++ )
	{
		for( int j = 0 ; j < MAX ; j++ )
		{
			for( int k = 0 ; k < MAX ; k++ )
			{
				if( dist[i][j] > dist[i][k] + dist[k][j] )
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	cout << "soultion matrix is: " << endl;
	display_graph(dist);

}

int main(void)
{
	int graph[MAX][MAX] = { { 0,5,INF,10}, {INF, 0, 3, INF} ,
						  { INF,INF,0,1 }, {INF, INF, INF,0}};

	cout << "input graph is: " << endl;

	display_graph(graph);

	floyd_warshall(graph);

	return 0;
}


