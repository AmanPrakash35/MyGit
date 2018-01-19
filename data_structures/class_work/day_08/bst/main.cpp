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

class bst;

class node_t
{
private:
	int data;
	node_t *left;
	node_t *right;
public:
	node_t(int data)
	{
		this->data= data;
		this->left = NULL;
		this->right = NULL;
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
			cout << "POSTORDER: ";
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

		cout << endl << "PREORDER : ";
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

		cout << endl << "INORDER  : ";
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

};

int main(void)
{
	bst t1;

	t1.add_node(90);
	t1.add_node(20);
	t1.add_node(25);
	t1.add_node(70);
	t1.add_node(100);
	t1.add_node(50);
	t1.add_node(90);


	t1.inorder();
	t1.nonrec_inorder();

	//t1.preorder();
	//t1.nonrec_preorder();

	//t1.postorder();


	return 0;
}















