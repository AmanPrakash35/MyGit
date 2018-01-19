/*
 * main.cpp
 *
 *  Created on: 02-Oct-2017
 *      Author: sunbeam
 */

/* un-directed un-weighted graph: adjacency list representation */


#include<iostream>
using namespace std;

#include<iomanip>
#include<vector>
#include<list>
#include<stack>

#define MAX 10

class graph_t
{
private:
	int vert_cnt;
	int edge_cnt;
	vector< list<int> > gr;

public:
	graph_t(void)
	{
		this->vert_cnt = 0;
		this->edge_cnt = 0;
	}

	void accept_graph(void)
	{
		cout << "enter no. of vertices: ";
		cin >> this->vert_cnt;

		cout << "enter the no. of edges: ";
		cin >> this->edge_cnt;

		//create vert_cnt no. of empty lists
		list<int> empty_list;

		for( int i = 0 ; i < this->vert_cnt ; i++ )
		{
			this->gr.push_back(empty_list);
		}

		for( int i = 0 ; i < this->edge_cnt ; i++ )
		{
			int from, to;
			cout << "enter the edge: from to to: ";
			cin >> from >> to;

			this->gr[from].push_back(to);
			this->gr[to].push_back(from);
		}
	}

	void display_graph(void)
	{
		cout << "input graph is: " << endl;

		for( int i = 0 ; i < this->vert_cnt ; i++ )
		{
			list<int>::iterator itr;
			cout << i << " => ";
			for( itr = this->gr[i].begin() ; itr != this->gr[i].end() ; itr++ )
			{
				cout << *itr << " -> ";
			}
			cout << "null" << endl;
		}
	}

	void dfs_travsersal(int start)
	{
		bool marked[MAX];
		int trav;
		stack<int> s;

		for( int v = 0 ; v < this->vert_cnt ; v++ )
		{
			marked[v] = false;
		}

		cout << "DFS TRAVERSAL IS: ";
		//1. push the start vertex onto the stack and mark it
		s.push(start);
		marked[start] = true;

		while( !s.empty() )
		{
			//2. pop the vertex from the stack and visit it
			trav = s.top(); s.pop();
			cout  << setw(4) << left << trav;

			//3. push all its adjacent but unmarked vertices onto the stack and mark them
			list<int>::iterator itr;
			for( itr = this->gr[trav].begin() ; itr != this->gr[trav].end() ; itr++ )
			{
				int v = *itr;
				if( marked[v] == false )
					{
						s.push(v);
						marked[v] = true;
					}
			}

		}//4. repeat steps 2 & 3 till stack not becomes empty
		cout << endl;
	}

};

int main(void)
{

	graph_t g1;

	g1.accept_graph();
	g1.display_graph();

	g1.dfs_travsersal(0);

	return 0;
}






