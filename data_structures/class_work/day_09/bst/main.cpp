/*
 * main.cpp
 *
 *  Created on: 03-Oct-2017
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;

#include<iomanip>
#include<stack>
#include<queue>


class bst;

class node_t
{
private:
	int data;
	node_t *left;
	node_t *right;
	bool visited;
public:
	node_t(int data)
	{
		this->data= data;
		this->left = NULL;
		this->right = NULL;
		visited = false;
	}

	friend class bst;
};

class bst
{
private:
	node_t *root;
public:
	bst(void)
	{
		this->root = NULL;
	}

	bool is_empty(void)
	{
		return ( this->root == NULL );
	}

	/*
	void add_node(int data)
	{
		if( is_empty() )
		{
			root = new node_t(data);
		}
		else
		{
			node_t *trav = root;

			while(1)
			{
				//if data is less than data of cur node
				if( data < trav->data )
				{
					//newnode will be the part of its left subtree
					//if left link is null then attach newnode to the left of the cur node
					if( trav->left == NULL )
					{
						trav->left = new node_t(data);
						break;
					}
					else//if it is having left subtree go to left subtree
					{
						trav = trav->left;
					}
				}
				else//data >= trav->data
				{
					//newnode will be the part of its right subtree
					//if right link is null then attach newnode to the right of the cur node
					if( trav->right == NULL )
					{
						trav->right = new node_t(data);
						break;
					}
					else//if it is having right subtree goto the right subtree
					{
						trav = trav->right;
					}
				}
			}
		}
	}
	*/

	void add_node(node_t *trav, int data)
	{
		if( data < trav->data )
		{
			if( trav->left == NULL )
			{
				trav->left = new node_t(data);
				return;
			}
			else
			{
				add_node(trav->left, data);
			}
		}
		else//data >= trav->data
		{
			if( trav->right == NULL )
			{
				trav->right = new node_t(data);
				return;
			}
			else
			{
				add_node(trav->right,data);
			}
		}
	}

	void add_node(int data)
	{
		if( is_empty())
		{
			root = new node_t(data);
		}
		else
		{
			add_node(root,data);
		}
	}

	void inorder(node_t *trav)
	{
		if( trav == NULL )
			return;
		else
		{
			this->inorder(trav->left);
			cout << setw(4) << left << trav->data;
			this->inorder(trav->right);
		}
	}

	void inorder(void)
	{
		if( !is_empty() )
		{
			cout << "INORDER  : ";
			this->inorder(root);
			cout << endl;
		}
		else
			cout << "tree is empty !!!" << endl;
	}

	void preorder(node_t *trav)
	{
		if( trav == NULL )
			return;
		else
		{
			cout << setw(4) << left << trav->data;
			this->preorder(trav->left);
			this->preorder(trav->right);
		}
	}

	void preorder(void)
	{
		if( !is_empty() )
		{
			cout << "PREORDER : ";
			this->preorder(root);
			cout << endl;
		}
		else
			cout << "tree is empty !!!" << endl;
	}

	void postorder(node_t *trav)
	{
		if( trav == NULL )
			return;
		else
		{
			this->postorder(trav->left);
			this->postorder(trav->right);
			cout << setw(4) << left << trav->data;
		}
	}

	void postorder(void)
	{
		if( !is_empty() )
		{
			cout << "POSTORDER  : ";
			this->postorder(root);
			cout << endl;
		}
		else
			cout << "tree is empty !!!" << endl;
	}

	void nonrec_preorder(void)
	{
		if( root == NULL )
			return;

		cout << "PREORDER : ";
		stack<node_t *> s;
		node_t *trav = root;

		while( trav != NULL || !s.empty() )
		{
			//traverse the left sub tree till its left not becomes null
			while( trav != NULL )
			{
				//visit the cur node
				cout << setw(4) << left << trav->data;

				//if it is having right child push it onto the stack
				if( trav->right != NULL )
					s.push(trav->right);

				//goto the left subtree
				trav = trav->left;
			}

			if( !s.empty() )
			{
				//pop the node from the stack
				trav = s.top(); s.pop();
			}
		}//end of while loop
		cout << endl;
	}

	void nonrec_inorder(void)
	{
		if( root == NULL )
			return;

		cout << "INORDER  : ";
		stack<node_t *> s;
		node_t *trav = root;

		while( trav != NULL || !s.empty() )
		{
			//traverse the left sub tree till its left not becomes null
			while( trav != NULL )
			{
				s.push(trav);
				//goto the left subtree
				trav = trav->left;
			}

			if( !s.empty() )
			{
				//pop the node from the stack
				trav = s.top(); s.pop();
				cout << setw(4) << left << trav->data;
				trav = trav->right;
			}

		}//end of while loop
		cout << endl;
	}

	void nonrec_postorder(void)
	{
		if( root == NULL )
			return;

		cout << "POSTORDER  : ";
		stack<node_t *> s;
		node_t *trav = root;

		while( trav != NULL || !s.empty() )
		{
			//traverse the left sub tree till its left not becomes null
			while( trav != NULL )
			{
				s.push(trav);

				//goto the left subtree
				trav = trav->left;
			}

			if( !s.empty() )
			{
				//pop the node from the stack
				trav = s.top(); s.pop();

				if( trav->right != NULL && !trav->right->visited )
				{
					//push the node onto the stack
					s.push(trav);
					//goto its right subtree
					trav = trav->right;
				}
				else
				{
					cout << setw(4) << left << trav->data;
					trav->visited = true;
					trav = NULL;
				}
			}

		}//end of while loop
		cout << endl;
	}

	node_t *search_node(int data, node_t **parent)
	{
		node_t *trav  = root;

		while( trav != NULL )
		{
			if( trav->data == data )
				return trav;

			*parent = trav;
			if( data < trav->data )
				trav = trav->left;
			else
				trav = trav->right;
		}

		*parent = NULL;
		return NULL;
	}


	/* --> to check search node function
	bool delete_node(int data)
	{
		node_t *parent = NULL;
		node_t *temp = search_node(data, &parent);

		if( temp != NULL )
		{
			if( parent != NULL )
				cout << "temp->data: " << temp->data << " parent->data : " << parent->data << endl;
			else
				cout << "temp->data: " << temp->data << endl;
		}
		else
			cout << "node is not found ..." << endl;
	}
	*/

	bool delete_node(int data)
	{
		node_t *parent = NULL;
		node_t *temp = search_node(data, &parent);

		if( temp == NULL )
			return false;

		//if node has left subtree as well right subtree
		if( temp->left != NULL && temp->right != NULL )
		{
			node_t *succ = temp->right;
			parent = temp;

			while(succ->left != NULL )
			{
				parent = succ;
				succ = succ->left;
			}

			temp->data = succ->data;
			temp = succ;
		}

		//if left subtree of node is NULL
		if( temp->left == NULL )
		{
			if( temp == root )//if node is root node
				root = temp->right; //right child becomes a root
			else
			if( temp == parent->left )//if node is left child of its parent
				parent->left = temp->right;
			else//if node is right child of its parent
				parent->right = temp->right;
		}
		else//if temp->right == NULL
		{
			if( temp == root )
				root = temp->left;
			else
			if( temp == parent->left )//if node is left child of its parent
				parent->left = temp->left;
			else//if node is right child of its parent
				parent->right = temp->right;
		}

		//delete the node
		delete temp;
		temp = NULL;
	}

	void clear(node_t *trav)
	{
		if( trav == NULL )
			return;

		clear(trav->left);
		clear(trav->right);

		delete trav;
	}

	void dfs_traversal(void)
	{
		node_t *trav = root;

		if( trav == NULL )
			return;

		cout << "DFS TRAVERSAL IS: ";

		stack<node_t *> s;
		//1. push the root node onto the stack
		s.push(trav);

		while( !s.empty() )
		{
			//2. pop the node from the stack and visit it
			trav = s.top(); s.pop();

			cout << setw(4) << left << trav->data;

			//3. if node has right child then push it onto the stack
			if( trav->right != NULL )
				s.push(trav->right);

			//4. if node has left child then push it onto the stack
			if( trav->left != NULL )
				s.push(trav->left);
		}//5. repeat steps 2, 3 & 4 till stack not becomes empty
		cout << endl;
	}

	void bfs_traversal(void)
	{
		node_t *trav = root;

		if( trav == NULL )
			return;

		cout << "DFS TRAVERSAL IS: ";

		queue<node_t *> s;
		//1. push the root node onto the queue
		s.push(trav);

		while( !s.empty() )
		{
			//2. pop the node from the stack and visit it
			trav = s.front(); s.pop();

			cout << setw(4) << left << trav->data;

			//3. if node has left child then push it onto the stack
			if( trav->left != NULL )
				s.push(trav->left);

			//4. if node has right child then push it onto the stack
			if( trav->right != NULL )
				s.push(trav->right);

		}//5. repeat steps 2, 3 & 4 till stack not becomes empty
		cout << endl;
	}

	int height(void)
	{
		if( root == NULL )
			return 0;

		return height(root);
	}


	int height(node_t *trav)
	{
		if( trav == NULL )
			return 0;

		return ( max( height(trav->left), height(trav->right) ) + 1 );
	}

	node_t *left_rotate(node_t *axis, node_t *parent )
	{
		if( axis == NULL || axis->right == NULL )
			return NULL;

		node_t *newaxis = axis->right;
		axis->right = newaxis->left;
		newaxis->left = axis;

		if( axis == root )
			root = newaxis;
		else
		if( axis == parent->left)
			parent->left = newaxis;
		else
			parent->right = newaxis;

		return newaxis;
	}

	node_t *right_rotate(node_t *axis, node_t *parent)
	{
		if( axis == NULL || axis->left == NULL )
			return NULL;

		node_t *newaxis = axis->left;
		axis->left = newaxis->right;
		newaxis->right = axis;

		if( axis == root )
			root = newaxis;
		else
		if( axis == parent->left)
			parent->left = newaxis;
		else
			parent->right = newaxis;

		return newaxis;
	}

	void balance(node_t *trav, node_t *parent)
	{
		if( trav == NULL )
			return;

		int hl = height(trav->left);
		int hr = height(trav->right);

		int bf = ( hl - hr );

		//cout << "balance factor: " << bf << endl;

		while( bf < -1 || bf > +1 )
		{
			if( bf < -1 )
			{
				trav = left_rotate(trav, parent);
				bf = bf + 2;
			}
			else//bf > +1
			{
				trav = right_rotate(trav, parent);
				bf = bf - 2;
			}
		}

		balance(trav->left,trav);
		balance(trav->right,trav);
	}

	void balance(void)
	{
		node_t *trav = root;

		if( trav != NULL )
			balance(root, NULL);

	}

	~bst(void)
	{
		if( !is_empty() )
		{
			clear(root);
			cout << "all heap memory freed succesfully...." << endl;
		}
		else
		{
			cout << "tree is empty ..." << endl;
		}
	}
};

int main(void)
{
	bst t1;

	t1.add_node(1);
	t1.add_node(2);
	t1.add_node(3);
	t1.add_node(4);
	t1.add_node(5);
	t1.add_node(6);
	t1.add_node(7);

	/*
	t1.add_node(50);
	t1.add_node(20);
	t1.add_node(90);
	t1.add_node(85);
	t1.add_node(10);
	t1.add_node(30);
	t1.add_node(100);
	t1.add_node(15);
	t1.add_node(75);
	t1.add_node(95);
	t1.add_node(120);
	t1.add_node(5);
	t1.add_node(50);
	*/

	t1.inorder();

	cout << "ht of t1 is: " << t1.height() << endl;
	t1.bfs_traversal();

	t1.balance();

	cout << "ht of t1 is: " << t1.height() << endl;

	t1.bfs_traversal();

	//t1.dfs_traversal();
	//t1.bfs_traversal();

	//t1.nonrec_inorder();

	//t1.preorder();
	//t1.nonrec_preorder();
	//t1.postorder();
	//t1.nonrec_postorder();

	//t1.delete_node(95);

	//t1.inorder();
	//t1.preorder();


	return 0;
}















