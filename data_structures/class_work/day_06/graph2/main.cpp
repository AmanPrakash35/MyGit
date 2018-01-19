/*
 * main.cpp
 *
 *  Created on: 30-Sep-2017
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>

#include<stack>
#include<queue>

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

	void dfs_traversal(int start)
	{
		stack<int> s;
		int trav;
		bool marked[MAX];

		//initially all vertices can be considered as unmarked
		for( int v = 0 ; v < this->vert_cnt ; v++ )
		{
			marked[v] = false;
		}

		cout << "DFS TRAVERSAL: ";
		//1. push the start vertex onto the stack and mark it
		s.push(start);
		marked[start] = true;

		while( !s.empty() )
		{
			//2. pop the vertex from the stack and visit it
			trav = s.top(); s.pop();
			cout << setw(4) << trav;

			//3. push all its adjacent but unmarked vertices onto the stack and mark them
			for( int v = 0 ; v < this->vert_cnt ; v++ )
			{
				if( this->arr[trav][v] != 0 && marked[v] == false )
				{
					s.push(v);
					marked[v] = true;
				}
			}

		}//4. repeat steps 2 & 3 till stack not becomes empty

		cout << endl;
	}

	void dfs_spann_tree(int root)
	{
		stack<int> s;
		int trav;
		bool marked[MAX];

		//initially all vertices can be considered as unmarked
		for( int v = 0 ; v < this->vert_cnt ; v++ )
		{
			marked[v] = false;
		}

		cout << "DFS SPANNING TREE : " << endl;
		//1. push the root vertex onto the stack and mark it
		s.push(root);
		marked[root] = true;

		while( !s.empty() )
		{
			//2. pop the vertex from the stack and visit it
			trav = s.top(); s.pop();


			//3. push all its adjacent but unmarked vertices onto the stack and mark them
			for( int v = 0 ; v < this->vert_cnt ; v++ )
			{
				if( this->arr[trav][v] != 0 && marked[v] == false )
				{
					s.push(v);
					marked[v] = true;
					cout << trav << " -> " << v << endl;
				}
			}

		}//4. repeat steps 2 & 3 till stack not becomes empty

		cout << endl;
	}

	bool dfs_search(int start, int key)
	{
		stack<int> s;
		int trav;
		bool marked[MAX];

		//initially all vertices can be considered as unmarked
		for( int v = 0 ; v < this->vert_cnt ; v++ )
		{
			marked[v] = false;
		}

		//1. push the start vertex onto the stack and mark it
		s.push(start);
		marked[start] = true;

		while( !s.empty() )
		{
			//2. pop the vertex from the stack and visit it
			trav = s.top(); s.pop();
			if( trav == key )
				return true;

			//3. push all its adjacent but unmarked vertices onto the stack and mark them
			for( int v = 0 ; v < this->vert_cnt ; v++ )
			{
				if( this->arr[trav][v] != 0 && marked[v] == false )
				{
					s.push(v);
					marked[v] = true;
				}
			}

		}//4. repeat steps 2 & 3 till stack not becomes empty

		cout << endl;
		return false;
	}

	void bfs_traversal(int start)
	{
		queue<int> s;
		int trav;
		bool marked[MAX];

		//initially all vertices can be considered as unmarked
		for( int v = 0 ; v < this->vert_cnt ; v++ )
		{
			marked[v] = false;
		}

		cout << "BFS TRAVERSAL: ";
		//1. push the start vertex onto the queue and mark it
		s.push(start);
		marked[start] = true;

		while( !s.empty() )
		{
			//2. pop the vertex from the queue and visit it
			trav = s.front(); s.pop();
			cout << setw(4) << trav;

			//3. push all its adjacent but unmarked vertices onto the queue and mark them
			for( int v = 0 ; v < this->vert_cnt ; v++ )
			{
				if( this->arr[trav][v] != 0 && marked[v] == false )
				{
					s.push(v);
					marked[v] = true;
				}
			}

		}//4. repeat steps 2 & 3 till queue not becomes empty

		cout << endl;
	}

	void bfs_spann_tree(int root)
	{
		queue<int> s;
		int trav;
		bool marked[MAX];

		//initially all vertices can be considered as unmarked
		for( int v = 0 ; v < this->vert_cnt ; v++ )
		{
			marked[v] = false;
		}

		cout << "BFS SPANNING TREE : " << endl;
		//1. push the root vertex onto the queue and mark it
		s.push(root);
		marked[root] = true;

		while( !s.empty() )
		{
			//2. pop the vertex from the queue and visit it
			trav = s.front(); s.pop();

			//3. push all its adjacent but unmarked vertices onto the queue and mark them
			for( int v = 0 ; v < this->vert_cnt ; v++ )
			{
				if( this->arr[trav][v] != 0 && marked[v] == false )
				{
					s.push(v);
					marked[v] = true;
					cout << trav << " -> " << v << endl;
				}
			}

		}//4. repeat steps 2 & 3 till queue not becomes empty

		cout << endl;
	}

	bool bfs_search(int start, int key)
	{
		queue<int> s;
		int trav;
		bool marked[MAX];

		//initially all vertices can be considered as unmarked
		for( int v = 0 ; v < this->vert_cnt ; v++ )
		{
			marked[v] = false;
		}

		//1. push the start vertex onto the queue and mark it
		s.push(start);
		marked[start] = true;

		while( !s.empty() )
		{
			//2. pop the vertex from the queue and visit it
			trav = s.front(); s.pop();
			if( trav == key )
				return true;

			//3. push all its adjacent but unmarked vertices onto the queue and mark them
			for( int v = 0 ; v < this->vert_cnt ; v++ )
			{
				if( this->arr[trav][v] != 0 && marked[v] == false )
				{
					s.push(v);
					marked[v] = true;
				}
			}

		}//4. repeat steps 2 & 3 till queue not becomes empty

		return false;
		cout << endl;
	}

	bool is_connected(int start)
	{
		stack<int> s;
		int trav;
		bool marked[MAX];
		int conn_vert_cnt = 0;

		//initially all vertices can be considered as unmarked
		for( int v = 0 ; v < this->vert_cnt ; v++ )
		{
			marked[v] = false;
		}

		//1. push the start vertex onto the stack and mark it
		s.push(start);
		marked[start] = true;

		while( !s.empty() )
		{
			//2. pop the vertex from the stack and visit it
			trav = s.top(); s.pop();

			//3. push all its adjacent but unmarked vertices onto the stack and mark them
			for( int v = 0 ; v < this->vert_cnt ; v++ )
			{
				if( this->arr[trav][v] != 0 && marked[v] == false )
				{
					s.push(v);
					marked[v] = true;
					conn_vert_cnt++;

					if( conn_vert_cnt == this->vert_cnt-1 )
						return true;
				}
			}

		}//4. repeat steps 2 & 3 till stack not becomes empty

		cout << endl;

		return ( conn_vert_cnt == this->vert_cnt-1 ? true : false );
	}

	void path_length(int source)
	{
		queue<int> s;
		int trav;
		bool marked[MAX];
		int path_len[MAX];

		//initially all vertices can be considered as unmarked
		for( int v = 0 ; v < this->vert_cnt ; v++ )
		{
			marked[v] = false;
			path_len[v] = 0;
		}

		//1. push the start vertex onto the queue and mark it
		s.push(source);
		marked[source] = true;

		while( !s.empty() )
		{
			//2. pop the vertex from the queue and visit it
			trav = s.front(); s.pop();

			//3. push all its adjacent but unmarked vertices onto the queue and mark them
			for( int v = 0 ; v < this->vert_cnt ; v++ )
			{
				if( this->arr[trav][v] != 0 && marked[v] == false )
				{
					s.push(v);
					marked[v] = true;
					path_len[v] = path_len[trav] + 1;
				}
			}

		}//4. repeat steps 2 & 3 till queue not becomes empty

		cout << "path length of vertices from source arr: " << endl;
		for( int v = 0 ; v < this->vert_cnt ; v++ )
			cout << source << " -> " << v << " : " << path_len[v] << endl;
		cout << endl;
	}

};

int main(void)
{
	graph_t g1;

	g1.accept_graph();
	g1.display_graph();

	g1.dfs_traversal(0);
	g1.bfs_traversal(0);

	/*
	if( g1.bfs_search(0, 3))
		cout << "key is found in the graph" << endl;
	else
		cout << "key is not found in the graph" << endl;
		*/
	//g1.dfs_spann_tree(0);
	//g1.bfs_spann_tree(0);

	/*
	if( g1.is_connected(0))
		cout << "g1 is connected" << endl;
	else
		cout << "g1 is not connected" << endl;
		*/
	g1.path_length(0);


	return 0;
}







