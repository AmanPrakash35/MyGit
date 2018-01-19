/*
 * main.cpp
 *
 *  Created on: 02-Oct-2017
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;

#include<iomanip>
#define INF 999

#include<cstring>

#define MAX 10

class graph_t
{
private:
	int vert_cnt;
	int edge_cnt;
	int mat[MAX][MAX];
public:
	graph_t(void)
	{
		this->vert_cnt = 0;
		this->edge_cnt = 0;

		for( int i = 0 ; i < MAX ; i++ )
			for( int j = 0 ; j < MAX ; j++ )
				this->mat[i][j] = INF;

		//memset(this->mat,INF,sizeof(this->mat));
	}

	void accept_graph(void)
	{
		cout << "enter the no. of vertices: ";
		cin >> this->vert_cnt;

		cout << "enter the no. of edges: ";
		cin >> this->edge_cnt;

		for( int  i = 0 ; i < this->edge_cnt ; i++ )
		{
			int from, to, weight;

			cout << "enter the edge: from to to: weight: ";
			cin >> from >> to >> weight;

			this->mat[from][to] = weight;
			this->mat[to][from] = weight;
		}
	}

	void display_graph(void)
	{
		cout << endl << "input graph is: " << endl;

		for( int i = 0 ; i < this->vert_cnt ; i++ )
		{
			for( int j = 0 ; j < this->vert_cnt ; j++ )
			{
				if( this->mat[i][j] != INF )
					cout << setw(4) << left << this->mat[i][j];
				else
					cout << setw(4) << left << "#";
			}
			cout << endl;
		}
	}

	int get_min(bool mst_vert[], int dist[], int n)
	{
		int min_ind = 0;
		int temp = INF;

		for( int i = 0 ; i < n ; i++ )
		{
			if( mst_vert[i] == false && dist[i] < temp )
			{
				min_ind = i;
				temp = dist[i];
			}
		}

		return min_ind;
	}

	void dijsktras(int source)
	{
		bool mst_vert[MAX];
		int dist[MAX];
		int mst_vert_cnt = 0;


		for( int v = 0 ; v < this->vert_cnt ; v++ )
		{
			/* initially all vertices are marked as false(not yet included in
			MST*/
			mst_vert[v] = false;

			//initialize dist of each vertex from source vertex as INF
			dist[v] = INF;
		}

		//initialize dist of source vertex from itself is 0
		dist[source] = 0;

		while( mst_vert_cnt < this->vert_cnt )
		{
			int min_key_vert = get_min(mst_vert, dist, this->vert_cnt);
			cout << "min_key_vert = " << min_key_vert << endl;
			//inlcude the minimum key vertex into the MST
			mst_vert[min_key_vert] = true;
			mst_vert_cnt++;

			for( int v = 0 ; v < this->vert_cnt ; v++ )
			{
				if( mat[min_key_vert][v] != INF && mst_vert[v] == false
					&& mat[min_key_vert][v] + dist[min_key_vert] < dist[v] )
				{
					 dist[v] = mat[min_key_vert][v] + dist[min_key_vert];
				}
			}
		}

		//print the shortest path: print dist array
		cout << "shortest distance of all vertices from source vertex are: " << endl;
		for( int v = 0 ; v < this->vert_cnt ; v++ )
		{
			cout << source << " -> " << v << " : " << dist[v] << endl;
		}
		cout << endl;
	}

	void prims(int root)
	{
		bool mst_vert[MAX];
		int vert_key[MAX];
		int mst_vert_cnt = 0;
		int parent[MAX];


		for( int v = 0 ; v < this->vert_cnt ; v++ )
		{
			/* initially all vertices are marked as false(not yet included in
			MST*/
			mst_vert[v] = false;

			//initialize dist of each vertex from source vertex as INF
			vert_key[v] = INF;
			parent[v] = v;
		}

		//initialize dist of source vertex from itself is 0
		vert_key[root] = 0;

		while( mst_vert_cnt < this->vert_cnt )
		{
			int min_key_vert = get_min(mst_vert, vert_key, this->vert_cnt);
			cout << "min_key_vert = " << min_key_vert << endl;
			//include the minimum key vertex into the MST
			mst_vert[min_key_vert] = true;
			mst_vert_cnt++;

			for( int v = 0 ; v < this->vert_cnt ; v++ )
			{
				if( mat[min_key_vert][v] != INF && mst_vert[v] == false
					&& mat[min_key_vert][v] < vert_key[v] )
				{
					 vert_key[v] = mat[min_key_vert][v];
					 parent[v] = min_key_vert;
				}
			}
		}
		cout << endl;

		cout << "MST SET IS:" << endl;
		for( int i = 1 ; i < this->vert_cnt ; i++ )
		{
			cout << parent[i] << " -> " << i << " : " << " ( " << mat[ parent[i] ][ i ] << " ) " << endl;
		}
	}

};

int main(void)
{
	graph_t g1;

	g1.accept_graph();
	g1.display_graph();

	//g1.dijsktras(0);
	g1.prims(0);

	return 0;
}



