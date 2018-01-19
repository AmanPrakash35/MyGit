/*
 * main.cpp
 *
 *  Created on: 30-Sep-2017
 *      Author: sunbeam
 */


#include<iostream>
using namespace std;

#include<stack>
#include<cstring>

void infix_to_postfix(char *in, char *post);
void infix_to_prefix(char *in, char *pre);
bool is_operand(char ch);
int priority(char opr);
void string_reverse(char *str);
int postfix_evaluation(char *post);
int calculate(int op1,int op2, char opr);


int main(void)
{
	//char infix[64] = "a+b-c*d/e";
	//char infix[64] = "a*(b-c)*d/(e+f)";
	char infix[64] = "4+5-6/9*3";

	char postfix[64] = " ";
	char prefix[64] = " ";


	cout << "infix expression is: " << infix << endl;

	infix_to_postfix(infix, postfix);
	//infix_to_prefix(infix, prefix);

	cout << "postfix expression is: " << postfix << endl;

	cout << "result : " << postfix_evaluation(postfix);

	//cout << "infix expression is  : " << prefix << endl;


	return 0;
}

int postfix_evaluation(char *post)
{
	stack<int> s;
	int res;

	//start reading postfix string from left to right
	for( int i = 0 ; post[i] != '\0' ; i++ )
	{
		//if it is operand then push it into the stack
		if( is_operand(post[i]))
		{
			s.push(post[i]-'0');
		}
		else//it is operator
		{
			//pop two ele's from the stack
			//first popped ele will be the second operand
			int op2 = s.top(); s.pop();

			//second popped ele will be the first operand
			int op1 = s.top(); s.pop();

			//perform operation on it
			res = calculate(op1,op2,post[i]);

			//push the result into the stack
			s.push(res);
		}
	}

	res = s.top(); s.pop();

	return res;
}

int calculate(int op1,int op2, char opr)
{
	switch(opr)
	{
	case '+': return ( op1 + op2 );
	case '-': return ( op1 - op2 );
	case '*': return ( op1 * op2 );
	case '/': return ( op1 / op2 );
	case '%': return ( op1 % op2 );
	}
}

void infix_to_prefix(char *in, char *pre)
{
	stack<int> s;
	int j = 0;

	//start reading the infix string from right to left (scan the infix string in reverse order)
	for( int i = strlen(in)-1 ; i >= 0 ; i-- )
	{
		//if the cur ele is operand
		if( is_operand(in[i]))
		{
			//append it into the prefix string
			pre[j++] = in[i];
		}
		else//if the cur ele is operator
		{
			//if the stack is not empty and priority of topmost ele is greater
			//or equal to priority of cur ele

			while(!s.empty() && priority(s.top()) > priority(in[i]) )
			{
				//pop ele from the stack and append it into prefix string
				pre[j++] = s.top(); s.pop();
			}

			//push the cur ele into the stack
			s.push(in[i]);
		}
	}

	//pop ele one by one by from the stack and then into the postfix string
	//till stack not become empty
	while( !s.empty())
	{
		pre[j++] = s.top(); s.pop();
	}

	pre[j] = '\0';

	string_reverse(pre);
}

void string_reverse(char *str)
{
	char *left = str;
	char *right = str;

	while( *right )
		right++;

	right--;

	while( left <= right )
	{
		char temp = *left;
		*left = *right;
		*right = temp;

		left++;
		right--;
	}
}

void infix_to_postfix(char *in, char *post)
{
	stack<int> s;
	int j = 0;

	//start reading the infix string from left to right (scan the infix string)
	for( int i = 0 ; in[i] != '\0' ; i++ )
	{
		//if the cur ele is operand
		if( is_operand(in[i]))
		{
			//append it into the postfix string
			post[j++] = in[i];
		}
		else
		if( in[i] == '(')//if the cur element is opening brace
		{
			//push it into the stack
			s.push(in[i]);
		}
		else
		if( in[i] == ')' )
		{
			while( s.top() != '(' )
			{
				post[j++] = s.top(); s.pop();
			}
			s.pop();
		}
		else//if the cur ele is operator
		{
			//if the stack is not empty and priority of topmost ele is greater
			//or equal to priority of cur ele

			while(!s.empty() && priority(s.top()) >= priority(in[i]) )
			{
				//pop ele from the stack and append it into postfix string
				post[j++] = s.top(); s.pop();
			}

			//push the cur ele into the stack
			s.push(in[i]);
		}
	}

	//pop ele one by one by from the stack and then into the postfix string
	//till stack not become empty
	while( !s.empty())
	{
		post[j++] = s.top(); s.pop();
	}

	post[j] = '\0';
}


/*
void infix_to_postfix(char *in, char *post)
{
	stack<int> s;
	int j = 0;

	//start reading the infix string from left to right (scan the infix string)
	for( int i = 0 ; in[i] != '\0' ; i++ )
	{
		//if the cur ele is operand
		if( is_operand(in[i]))
		{
			//append it into the postfix string
			post[j++] = in[i];
		}
		else//if the cur ele is operator
		{
			//if the stack is not empty and priority of topmost ele is greater
			//or equal to priority of cur ele

			while(!s.empty() && priority(s.top()) >= priority(in[i]) )
			{
				//pop ele from the stack and append it into postfix string
				post[j++] = s.top(); s.pop();
			}

			//push the cur ele into the stack
			s.push(in[i]);
		}
	}

	//pop ele one by one by from the stack and then into the postfix string
	//till stack not become empty
	while( !s.empty())
	{
		post[j++] = s.top(); s.pop();
	}

	post[j] = '\0';
}
*/


int priority(char opr)
{
	switch(opr)
	{

	case '(': return 1;

	case '-':
	case '+': return 2;

	case '*':
	case '/':
	case '%': return 3;
	}
}

bool is_operand(char ch)
{
	return ( (ch >= 65 && ch <= 90 ) || ( ch >= 97 && ch <= 122 ) || ( ch >= 48 && ch <= 57 ) );
}















