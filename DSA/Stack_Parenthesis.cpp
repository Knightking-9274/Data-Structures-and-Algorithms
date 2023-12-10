/*	Name : Yash Ishan Gohil
	Roll : 1313
	Unit 3: Stacks
	program: Balancing of Paranthesis
*/
#include<iostream>
#define SIZE 20
#include<conio.h>

using namespace std;

/* 2.Stack Template */

class Stack
{
	char a[SIZE];
	int tos;
	
	public:
		Stack()
		{
			tos = -1;	
		}
		
		void Push(char x);
		char Pop();
		int Full();
		int Empty();	
};	

/* 3. Functions*/

void Stack :: Push(char x)
{
	if(Full())
	{
		cout<< "Stack Overflow";
	}
	else
	{
		tos++;
		a[tos] = x; 
	}
}

char Stack :: Pop()
{
	if(Empty())
	{
		cout<< "Stak Underflow";
		return -1;
	}
	else
	{
		char t = a[tos];
		tos--;
		return t;
	}
}

int Stack :: Full()
{
	return (tos == SIZE-1 ? 1:0);	
}

int Stack :: Empty()
{
	return (tos == -1 ? 1:0);
}

/* 4. Main Application*/

int main()
{
	char expr[20], temp;
	int i=0; 
	int flag = 0;
	
	
	Stack s;system("cls");
	cout<< "Program to Check if the parenthesis are balanced in an expression\n\n";
	
	cout << "Enter an expression: ";
	cin >> expr;
	
	while(expr[i] != '\0')
	{
		if(expr[i]== '(' || expr[i]== '{' || expr[i]== '[')
		{
			s.Push(expr[i]);
		}// end of if open Bracket
		
		if(expr[i]== ')' || expr[i]== '}' || expr[i]== ']')
		{
			if(s.Empty())
			{
				flag = 1;// Takes care of extra bracketat the end
				break;
			}
			temp = s.Pop();
			
			if((temp == '(' && expr[i]== ')') ||
			  (temp == '{' && expr[i]== '}') ||
			  (temp == '[' && expr[i]== ']'))
			  
			  {
			  	i++;
			  	continue;
			  }
			  else //Brackets dont match
			  {
			  		flag = 1;
			  		break;
			  }	   	
		}// end of if close Bracket
		
		i++;
	}// end of while
	
	if(s.Empty() && flag==0)
	{
		cout << "Parenthesis are balanced";
	}
	else
	{
		cout << "Paraenthesis are not balanced";
	}
}// end of main
