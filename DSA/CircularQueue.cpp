/*
Name: Yash Ishan Gohil
Roll No: 1313
Unit 4: Queues
Program: Circular Queues */


#include<iostream>
#include<conio.h>
#define MAX 5

using namespace std;
//1.Node  Template - Not Required

//2.Queue Template
class CQueue
{
	int a[MAX];
	int front , rear;
	int cnt;
	public:
		CQueue()
		{
			front =-1;
			rear=-1;
			cnt = 0;
		}
		void Enqueue(int x);
		void Dequeue();
		void PeekFront();
		void PeekRear();
		void Display();
		int Full();
		int Empty();
};
//3.Functions
void CQueue :: Enqueue(int x)
{
	if(Full())
	{
		cout << "Queue Overflow";
		return;
	}
	
	if(front == -1)
	{
		front ++;
	}
	
	rear = (rear+1) % MAX;
	a[rear] = x;
	cnt++;
} 
int CQueue :: Full()
{
	if(cnt == MAX )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void CQueue :: Dequeue()
{
	if (Empty())
	{
		cout << "Queue Underflow!";
		return;
	}
	
	int t = a[front];
	
	if(front == rear) //Single Element
	{
		front = -1;
		rear = -1;
	}
	else
	{
		front = (front+1)%MAX;
	}
	
	cout << "Element removed is:" << t;
	cnt--;
}
int CQueue :: Empty()
{
	if(cnt==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void CQueue :: Display()
{
	if(Empty())
	{
		cout << "Queue Undeflow";
		return;
	}
	
	int i, x = front;
	
	for(x=1 ; x<=cnt ; x++)
	{
		cout << a[i] << " ";
		i = (i+1) % MAX;
	}
}
void CQueue :: PeekFront()
{
	if(Empty())
	{
		cout << "Underflow";
		return;
	}
	
	cout << "" << a[front];
}
void CQueue :: PeekRear()
{
		if(Empty())
	{
		cout << "Underflow";
		return;
	}
	
	cout << "" << a[rear];
}

//4.Menu
int main()
{
	int ch, num;
	CQueue c;
	
	while(1)
	{
		system("cls");
		cout << "***Circular Queue ***\n\n";
		
		cout << "1.Enqueue an element" << endl;
		cout << "2.Dequeue" << endl;
		cout << "3.Peek Front" << endl;
		cout << "4.Peek Rear" << endl;
		cout << "5.Display the queue" << endl;
		cout << "6.exit" <<endl <<endl;
		
		cout << "Enter your choice:";
		cin>> ch;
		
		
		switch(ch)
		{
			case 1:
			cout << "Enter an element: ";
			cin >> num;
			c.Enqueue(num);
			getch();
			break;
		
		case 2:
			c.Dequeue();
			getch();
			break;
			
		case 3:
			c.PeekFront();
			getch();
			break;
			
			
		case 4:
			c.PeekRear();
			getch();
			break;
			
		case 5:
			c.Display();
			getch();
			break;
			
		case 6: 
		 	exit(1);
		 	
		default :
			cout << "Incorrect Choice:";
			
		
			break;
		}
		
			
			
			
			
	}//end of switch
}//end of while


