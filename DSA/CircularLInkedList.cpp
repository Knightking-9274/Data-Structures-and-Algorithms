/*	Name: Yash Ishan Gohil
	Roll No: 1313
	Unit 5: Linked List
	Program: Circular Linked List */
	
#include<iostream>
#include<conio.h>

using namespace std;


/* 1. Node Template */
class CNode
{
	public:
		int data;
		CNode *next;
};

/* 2. List Template */
class CList
{
		CNode *first;
		CNode *last;
		
		public:
			CList()
			{
				first = NULL;
				last = NULL;
			}
			void Insert(int x);
			void Display();
			void Length();
			void Search(int x);
			void Remove(int x);
			
		
};

/* 3. Functions */
void CList :: Insert(int x)
{
	CNode *t = new CNode();
	t->data = x;
	t->next = NULL;
	
	//first node in the CLL
	
	if(first==NULL && last==NULL)
	{
		first = t;
		last = t;
		last->next = first;
	}
	else // Attach t to last, shift last, make it circular
	{
		last->next = t;
		last = t;
		last->next = first;
	}
}
void CList :: Display()
{
	if(first == NULL)
	{
		cout << "Empty List";
		return;
	}
	
	CNode *tmp = first;
	
	do
	{
		cout << tmp->data << "->";
		tmp = tmp->next;
	}
	while(tmp!=first); // tmo has not come to first
	
	cout << "Back to first";
}
void CList :: Length()
{
	CNode *tmp = first;
	int cnt = 0;
	
	if(first == NULL)
	{
		cout << "Empty List";
		return;
	}
	
	do
	{
		cnt++;
		tmp = tmp->next;
	}
	while(tmp!=first);

	
	cout << "Number of nodes: " << cnt;
}
void CList :: Search(int x)
{
	CNode *tmp = first;
	int flag = 0;
	
	do
	{
		if(tmp->data == x)
		{
			flag = 1;
			break;
		}
		tmp = tmp->next;
	}
	while(tmp!=first);
	if(flag == 1)
	{
		cout << "Element is found in the list:";
	}
	else
	{
		cout << "Element is not found in the list";
	}
	
}
 
/* 4. Menu */ 

int main()
{
	int ch;
	int num;
	CList c;
	
	
	while(1)
	{
		system("cls");
		cout << "*** Circular Linked List ***\n\n";
		
		cout << "1. Insert a node" << endl;
		cout << "2. Display the lsit " << endl;
		cout << "3. Length of the list" << endl;
		cout << "4. Search for a node" << endl;
		cout << "5. Remove a node" << endl;
		cout << "6. Exit" << endl << endl ;
		
		cout << "Enter your choice:";
		cin >>ch;
		
		switch(ch)
		
		{
			case 1 :
				cout << "Enter an Element:";
				cin >> num;
				c.Insert(num);
				getch();
				break;
				
				
			case 2:
				c.Display();
				getch();
				break;
				
			
			case 3:
				c.Length();
				getch();
				break;
					
			
			case 4:
				cout << "Enter element to be searched";
				cin >> num;
				c.Search(num);
				getch();
				break;
				
				
			case 5:
				cout << "Reverse a code";
				getch();
				break;
				
				
			case 6:
				exit(1);
				
			default:
				cout << "Incorrect Option!";
				
				getch();
				break;					
		}
	}
}	
