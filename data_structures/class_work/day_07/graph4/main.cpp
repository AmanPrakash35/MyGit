/* un-directed weighted graph: adjacency list representation */

#include<iostream>
using namespace std;

#include<vector>
#include<list>


class graph_t;

class edge_t
{
private:
	int v;
	int w;

public:
	edge_t(int v = 0, int w = 0 )
	{
		this->v = v;
		this->w = w;
	}

	friend class graph_t;
};



class graph_t
{
private:
	int vert_cnt;
	int edge_cnt;
	vector< list<edge_t> > gr;

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
		list<edge_t> empty_list;

		for( int i = 0 ; i < this->vert_cnt ; i++ )
		{
			this->gr.push_back(empty_list);
		}

		for( int i = 0 ; i < this->edge_cnt ; i++ )
		{
			int from, to, weight;
			cout << "enter the edge: from to to: ";
			cin >> from >> to >> weight;

			edge_t ed1(to,weight);
			this->gr[from].push_back(ed1);

			edge_t ed2(from,weight);
			this->gr[to].push_back(ed2);
		}
	}

	void display_graph(void)
	{
		cout << "input graph is: " << endl;

		for( int i = 0 ; i < this->vert_cnt ; i++ )
		{
			list<edge_t>::iterator itr;
			cout << i << " => ";
			for( itr = this->gr[i].begin() ; itr != this->gr[i].end() ; itr++ )
			{
				cout << "|" << itr->v <<  ":" << itr->w << "|" << " -> ";
			}
			cout << "null" << endl;
		}
	}

};

int main(void)
{

	graph_t g1;

	g1.accept_graph();
	g1.display_graph();

	return 0;
}

