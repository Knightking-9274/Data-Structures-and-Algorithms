/*	Name : Yash Ishan Gohil
	Roll No: 1314
	Unit 4: Queues
	Program: Ordinary Queue
*/

#include<iostream>
#include<conio.h>
#define MAX 5

using namespace std;
//1.Node  Template - Not Required

//2.Queue Template
class OQueue
{
	int a[MAX];
	int front , rear;
	public:
		OQueue()
		{
			front =-1;
			rear=-1;
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


void OQueue :: Enqueue(int x)
{
	if(Full())
	{
		cout << "Queue Overflow!"<< endl;
		return;
	}
	if( front == -1)
	{
		front ++;
	}
	
	rear++;
	a[rear] = x;
}

int OQueue :: Full()
{
	return (rear == MAX -1 ? 1:0);
}

void OQueue :: Dequeue()
{
	if(Empty())
	{
		cout << "Queue Underflow!";
	}
	int t = a[front];
	
	if(front == rear) //Single element
	{
		front = -1;
		rear = -1;
	}
	else
	{
		front++;
	}
	
	cout << "Element Removed is:" << t;
}

int OQueue :: Empty()
{
	if(front == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void OQueue :: Display()
{
	if(Empty())
	{
		cout << "Underflow";
		return;
	}
	for(int i=front; i<=rear; i++)
	{
		cout << a[i] << " ";
	}
}

void OQueue :: PeekFront()
{
	if(Empty())
	{
		cout << "Underflow";
		return;
	}
	
	cout << "Element at Front is:" << a[front];
}
void OQueue :: PeekRear()
{
		if(Empty())
	{
		cout << "Underflow";
		return;
	}
	
	cout << "Element at rear is:" << a[rear];
}

//4.Menu
int main()
{
	int ch, num;
	OQueue q;
	
	while(1)
	{
		system("cls");
		cout << "***Ordinary Queue ***\n\n";
		
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
			q.Enqueue(num);
			getch();
			break;
		
		case 2:
			q.Dequeue();
			getch();
			break;
			
		case 3:
			q.PeekFront();
			getch();
			break;
			
			
		case 4:
			q.PeekRear();
			getch();
			break;
			
		case 5:
			q.Display();
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


