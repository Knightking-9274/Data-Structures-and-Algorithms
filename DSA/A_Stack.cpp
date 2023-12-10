/*	Name: Yash Ishan Gohil
	Roll No:1313
	Unit 3:Stacks
	Program: Array Based Stack
*/
#include<iostream>	
#include<conio.h>
#define MAX 5 // it remains constant throughout the program

using namespace std;

/* Node Template - Not Required */

/* Stack Template */
class AStack
{
	int a[MAX];
	int tos;

	
	public:
		AStack()
		{
			tos = -1;
		}
		
		void Push(int x);
		void Pop();
		void Peek();
		void Display();
		int Full();
		int Empty();
			
};


/* Functions */
void AStack::Push(int x)
{
	if(Full())
	{
		cout << "Stack Overflow" <<endl;
	}
	else
	{
		tos++;
		a[tos] = x;
	}
}

int AStack :: Full()
{
	if(tos == MAX-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void AStack :: Pop()
{
	if(Empty())
	{
		cout << " Stack Underflow";
	}
	else
	{
		int t = a[tos];
		tos--;
		cout << "Element Popped:" << t << endl;
	
	}
}

int AStack :: Empty()
{
	if(tos== -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void AStack :: Peek()
{
	if(Empty())
	{
		cout << "Stack Underflow!";
	}
	else
	{
		cout << "Element at the tos is:" << a[tos];
	}
}
void AStack :: Display()
{
	if(Empty())
	{
		cout << "Stack Underflow!";
	}
	else
	{
		for(int i=tos ; i>=0; i--)
		{
			cout << a[i] << endl;
		}
	}
}
/* Menu */
int main()
{
	int ch, num;
	AStack s;
	
	while(1)
	{
		system("cls");
		cout << "*** Array Based Stack***\n\n";
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
}//end of main
	
