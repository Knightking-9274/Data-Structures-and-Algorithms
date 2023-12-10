/*	Name: Yash Ishan Gohil
	Roll No:1313
	Unit 3: Stacks
	Program: List Based Stack
*/
#include<iostream>
#include<conio.h>

using namespace std;

/* 1. Node Template */
class SNode
{
	public:
		int data;
		SNode *next;
};

/* 2. Stack Template */
class LStack
{
	SNode *tos;
	
	public:
		LStack()
		{
			tos = NULL;
			
		}
		
		void Push(int x);
		void Pop();
		void Peek();
		void Display();
};

/* 3. Functions*/
void LStack :: Push(int x)
{
	// make a node
	SNode *t = new SNode();
	t->data = x;
	t->next = NULL;
	
	//First Node
	if(tos==NULL)
	{
		tos = t;
	}
	else // invert at head
	{
		t->next = tos;
		tos = t;
	}
}
void LStack :: Pop()
{
	if(tos == NULL)
	{
		cout << "Stack Underflow";
	}
	else
	{
		SNode *t = tos;
		tos = tos->next;
		
		cout << "Element popped: " << t->data;
		delete t;
	}
}
void LStack :: Peek()
{
	if(tos == NULL)
	{
		cout << "Stack underflow";
	}
	else
	{
		cout << "Element at the toss: " << tos->data;
	}
}
void LStack :: Display()
{
	if(tos == NULL)
	{
		cout << "Stack Underflow";
	}
	else
	{
		SNode *tmp = tos;
		
		while(tmp!=NULL)
		{
			cout << tmp->data << "->" << endl;
			tmp = tmp->next;
		}
		cout << "NULL";
	}
}
/* 4. Menu*/
int main()
{
	int num, ch;
	LStack s;
	
	while(1)
	{
		system("cls");
		cout << "*** List Based stack ***\n\n";	
		cout << "1. Push an Element"<< endl;
		cout << "2. Pop an Element"<< endl;
		cout << "3. peek an Element" << endl;
		cout << "4. Display the Stack" << endl;
		cout << "5. Exit"<< endl; 
		
		cout << "Enter your Choice:" << endl;
		cin >> ch;
		
		switch(ch)
		{
			case 1:
				cout << "Enter a value: ";
				cin >> num;
				
				s.Push(num);
			
				getch();
				break;
		
			case 2:
				s.Pop();
			
				getch();
				break;
			
			case 3:
				s.Peek();
			
				getch();
				break;
			
			case 4:
				s.Display();
			
				getch();
				break;
			
			case 5:		
				exit(1);
		}
			
	}	
}
	
