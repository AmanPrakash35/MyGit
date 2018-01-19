/*
 * main.cpp
 *
 *  Created on: 03-Oct-2017
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;

#include<iomanip>

#define MAX 10
#define INF 999

#include<vector>
#include<algorithm>

class graph_t;

int parent[MAX];
int g_rank[MAX];

class edge_t
{
private:
	int src;
	int dest;
	int weight;
public:
	edge_t(int src=0, int dest=0, int weight=0)
	{
		this->src = src;
		this->dest = dest;
		this->weight = weight;
	}

	bool operator<(edge_t& other)
	{
		return ( this->weight < other.weight );
	}

	friend class graph_t;

};


class graph_t
{
private:
	int vert_cnt;
	int edge_cnt;
	int mat[MAX][MAX];
	vector<edge_t> edges;

public:
	graph_t(void)
	{
		this->vert_cnt = 0;
		this->edge_cnt = 0;

		for( int  i = 0 ; i < MAX ; i++ )
			for( int j = 0 ; j < MAX ; j++ )
				this->mat[i][j] = INF;
	}

	void accept_graph(void)
	{
		cout << "enter the no. of vertices: ";
		cin >> this->vert_cnt;

		cout << "enter the no. of edges: ";
		cin >> this->edge_cnt;

		for( int i = 0 ; i < this->edge_cnt ; i++ )
		{
			int from,to,weight;

			cout << "enter the edge: from to to: weight: ";
			cin >> from >> to >> weight;

			//create object of edge_t class
			edge_t ed(from,to,weight);
			//add the edge into the vector
			this->edges.push_back(ed);

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

		this->display_edges();
	}

	void display_edges(void)
	{
		vector<edge_t>::iterator itr;
		cout << "edges in the input graph are: " << endl;
		for( itr = this->edges.begin(); itr != this->edges.end() ; itr++ )
		{
			cout << itr->src << " -> " << itr->dest << " : " << itr->weight << endl;
		}
		cout << endl;
	}

	int root(int i)
	{
		if( i != parent[i] )
			parent[i] = root(parent[i]);

		return parent[i];
	}

	void combine(int x, int y)
	{
		int xroot = root(x);
		int yroot = root(y);

		if( g_rank[xroot] > g_rank[yroot] )
			parent[yroot] = xroot;
		else
		if( g_rank[xroot] < g_rank[yroot] )
			parent[xroot] = yroot;
		else
		{
			parent[yroot] = xroot;
			g_rank[xroot]++;
		}
	}

	void kruskals(void)
	{
		//sort the edges in the ascending order of their weights
		sort(this->edges.begin(), this->edges.end());

		cout << "edges in sorted order are:" << endl;
		this->display_edges();

		for( int v = 0 ; v < this->vert_cnt ; v++ )
		{
			parent[v] = v;
			g_rank[v] = 0;
		}

		vector<edge_t> mst;
		int i = 0;

		while( mst.size() < this->vert_cnt-1 )
		{
			edge_t next = this->edges[i++];

			int x = root(next.src);
			int y = root(next.dest);

			if( x != y )
			{
				mst.push_back(next);

				combine(x,y);
			}
		}

		//print MST set of edges:
		cout << "MST SET OF EDGES ARE: " << endl;
		vector<edge_t>::iterator itr;

		for( itr = mst.begin() ; itr != mst.end() ; itr++ )
		{
			cout << itr->src << " -> " << itr->dest << " : " << itr->weight << endl;
		}

		cout << endl;
	}
};

int main(void)
{
	graph_t g1;

	g1.accept_graph();
	g1.display_graph();

	g1.kruskals();

	return 0;
}



