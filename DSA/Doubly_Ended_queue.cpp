/*
	Name: Yash Ishan Gohil
	Roll No:1313
	UNIT 4:Queues
	Program:Double Ended-Queue 
*/
#include<iostream>
#include<conio.h>

using namespace std;

/* 1. Node Template*/

class DQNode
{
	public:
		int data;
		DQNode *right;
		DQNode *left;
		
};
/* 2. Double Ended-Queue Template*/
class DQueue
{
	DQNode *front;
	DQNode *rear;
	
	public:
		DQueue()
		{
			front = NULL;
			rear = NULL;
		}
		
		void EnqueueFront(int x);
		void EnqueueRear(int x);
		void DequeueFront();
		void DequeueRear();
		void PeekFront();
		void PeekRear();
		void Display();
};
void DQueue :: EnqueueFront(int x)
{
	//Make a new Node
	DQNode *t = new DQNode();
	t->data = x;
	t->right = NULL;
	t->left = NULL;
	
	//first node in the queue
	
	if(front==NULL)
	{
		front = t;
		rear = t;
	}
	else //Any other node
	{
		t->right = front;
		front->left = t;
		front = t;
	}
}
void DQueue :: EnqueueRear(int x)
{
	// Make a node
	DQNode *t = new DQNode();
	t->data = x;
	t->right = NULL;
	t->left = NULL;
	
	// special case first case
	if(front==NULL)
	{
		front = t;
		rear = t;
	}
	else//any other node
	{
		rear->right = t;
		t->left = rear;
		rear = t;
	}
}
void DQueue :: Display()
{
	if (front == NULL)
	{
		cout << "Queue Overflow";
		return;
	}
	DQNode *tmp = front;
	
	while(tmp != NULL)
	{
		cout << tmp->data << "<->";
		tmp = tmp->right;
	}
	
	cout << "NULL";
}

void DQueue :: DequeueFront()
{
	//Empty Queue
	if(front== NULL)
	{
		cout << "Queue Undeflow";
		return;
	}
	
	DQNode *tmp = front;
	
	if(front == rear)//single node deletion
	{
		front = NULL;
		rear = NULL;
	}
	else
	{
		front = front->right;
		front->left = NULL;
	}
	
	cout << "Element removed:" <<tmp->data;
	delete tmp;
}
void DQueue :: DequeueRear()
{
	//Empty Queue
	if(front == NULL)
	{
		cout << "Queue Underflow";
		return;
	}
	DQNode *tmp = rear;
	
	if(front == rear)//single node deletion
	{
		front = NULL;
		rear = NULL;
	}
	else
	{
		rear = rear->left;
		rear->right = NULL;
	}
	
	cout <<"Element removed:" <<tmp->data;
	delete tmp;
}
void DQueue :: PeekFront()
{
	if(front == NULL)
	{
		cout <<"Underflow";
		return;
	}
	cout << "Element at front is:" <<front->data;
}
void DQueue :: PeekRear()
{
	if(front==NULL)
	{
		cout <<"Queue overflow";
		return;
	}
	cout << "Element at the rear is: "<< rear->data;
}
/* 4. Menu*/
int main()
{
	int ch, num;
	DQueue d;
	
	while(1)
	{
		system("cls");
		cout << "*** Double Ended-Queue ***\n\n";
		
		cout << "1.Enqueue Front" << endl;
		cout << "2.Enqueue Rear" << endl;
		cout << "3.Dequeue Front" << endl;
		cout << "4.Dequeue Rear" << endl;
		cout << "5.Peek Front" << endl;
		cout << "6.Peek Rear" <<endl;
		cout << "7.Dispaly the Queue" <<endl;
		cout << "8.Exit" <<endl <<endl;
		
		cout << "Enter your choice:";
		cin>> ch;
		
		
		switch(ch)
		{
			case 1:
			cout << "Enter an element: ";
			cin >> num;
			d.EnqueueFront(num);	
			getch();
			break;
		
			case 2:
			d.EnqueueRear(num);
			getch();
			break;
			
			case 3:
			d.DequeueFront();
			getch();
			break;
			
			
			case 4:
			d.DequeueRear();
			getch();
			break;
			
			case 5:
			d.PeekFront();
			getch();
			break;
			
			case 6: 
		 	d.PeekRear();
		 	getch();
		 	break;
		 	
		 	case 7:
		 	d.Display();
		 	getch();
		 	break;
		 	
		 	case 8:
		 	cout << "Exit";
		 	getch();
		 	break;
		 	
			default :
			cout << "Incorrect Choice:";
  			break;
		}//end of switch		
	}//end of while
}//end of main


