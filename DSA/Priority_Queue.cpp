/*
	Name: Yash Ishan Gohil
	Roll No:1313
	Unit 4:Queues
	Program:Priority Queue
*/

#include<iostream>
#include<conio.h>

using namespace std;
/* 1.node template */
class PQNode
{
	public:
		int data;
		int priority;
		PQNode *next;
};

/*2. Queue template*/
class PQueue
{
	PQNode *front;
	
	public:
		PQueue()
		{
			front = NULL;
			
		}
		
		void Enqueue(int x, int p);
		void Dequeue();
		void PeekFront();
		void PeekRear();
		void Display();
};
/*3.Functions*/
void PQueue :: Enqueue(int x , int p)
{
	//Make a new Node
	PQNode *t = new PQNode();
	t->data = x;
	t->priority = p;
	t->next = NULL;
	
	//First Node in the List
	if(front == NULL)
	{
		front = t;
		return;
	}
	
	//Ordered Traversal
	PQNode *tmp = front;
	PQNode *prev;
	
	while(tmp!= NULL && tmp->priority<p)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	
	//Insert t in queue in order of priority
	
 	if(tmp == NULL)
 	{
 		t->next = front;
		 front = t;	
	}
	else if(tmp == NULL)
	{
		prev->next = t;
	}
	else
	{
		prev->next = t;
		t->next = tmp;
	}
	
}
void PQueue :: Display()
{
	if(front == NULL)
	{
		cout << "Queue Underflow!";
		return;
	}
	
	PQNode *tmp = front;
	
	while(tmp!= NULL)
	{
		cout << "Data: " << tmp->data << "Priority: " << tmp->priority <<endl;
		tmp = tmp->next;
	}
	cout << "NULL";
	
}
void PQueue :: Dequeue()
{
	if(front == NULL)
	{
		cout << "Queue underflow";
		return;
	}
	

	PQNode *tmp = front;
	if(front->next == NULL)
	{
		front = NULL;
	}
	else
	{
		front = front->next;
	}
	
	cout << "Element Dequeued :" <<tmp->data;
	cout << "with Priority: " <<tmp->priority;
	
	delete tmp;
	
}
void PQueue :: PeekFront()
{
	if(front == NULL)
	{
		cout <<"Underflow";
		return;
	}
	cout << "Element at front is: " <<front->data << "And its Priority: " << front->priority ;
}
void PQueue :: PeekRear()
{
	if(front==NULL)
	{
		cout <<"Queue overflow";
		return;
	}
	//Traverse till last node
	PQNode *tmp = front;
	
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	
	cout << "Element at rear is:" << tmp->data;
	cout << "with Priority:" << tmp->priority; 
}

/*4.Menu*/
int main()
{
	int ch, num, pri;
	PQueue p;
	
	while(1)
	{
		system("cls");
		cout << "*** Priority Queue ***\n\n";
		
		cout << "1.Enqueue Front" << endl;
		cout << "2.Dequeue Front" << endl;
		cout << "3.Peek Front" << endl;
		cout << "4.Peek Rear" <<endl;
		cout << "5.Dispaly the Queue" <<endl;
		cout << "6.Exit" <<endl <<endl;
		
		cout << "Enter your choice:";
		cin>> ch;
		
		
		switch(ch)
		{
			case 1:
			cout << "Enter an element: ";
			cin >> num;
			cout << "Enter and its Priority:";
			cin >> pri;
			
			p.Enqueue(num,pri);
				
			getch();
			break;
		
			case 2:
			p.Dequeue();
			getch();
			break;
			
			case 3:
			p.PeekFront();
			getch();
			break;
			
			
			case 4:
			p.PeekRear();
			getch();
			break;
			
			case 5:
			p.Display();
			
			getch();
			break;
				
			
			case 6:
			exit(1);
				
			default :
			cout << "Incorrect Choice:";
  			break;
		}//end of switch		
	}//end of while
}//end of main






