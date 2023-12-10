/*	Name:Yash gohil
	Roll No: 1313
	Unit 5: Linked lists
	Program: Singly linked list		
*/

#include<iostream>
#include<conio.h>
using namespace std;


/* 1.Node template */
class Node
{
	public:
		int data;
		Node *next;
};

/* 2.list template */
class list
{
	Node *head;
	
	public:
		list()
	{
		head = NULL;
	}
	
	void Insert(int x);
	void Display();
	void Length();
	void Search(int x);
	void Remove(int x);
	void Reverse();
};

/* 3. Functions */
void list :: Insert(int x)
{
	//create a node
	Node *t = new Node();
	t->data = x;
	t->next = NULL;
	
	//if list is empty
	if(head == NULL)
	{
		head =t;
		return;
	}
	
	//transverse till the last node and attack t
	Node *tmp = head;
	while(tmp->next != NULL)
	{
		tmp = tmp->next; 
	}
	//attach t to tmp
	tmp->next = t;
}


void list :: Display()
{
	Node *tmp = head;
	
	while(tmp!=NULL)
	{
		
		cout << tmp->data << "->";
		tmp = tmp->next;
	}
	
	cout << "NULL";
}

void list :: Length()
{
	Node *tmp = head;
	int cnt = 0;
	
	while(tmp!=NULL)
	{
		cnt++; // cnt = cnt+1;
		tmp = tmp->next;
	}
	cout << "number of nodes: " << cnt;
}
void list :: Search(int x)
{
	Node *tmp = head;
	int flag = 0;
	
	while(tmp!=NULL)
	{
		if (tmp->data == x)
		{
			flag = 1;
			break;
		}
		
		tmp = tmp->next;
	}
	
	if(flag == 1)
	{
		cout << x << "is found in the lsit";
	}
	else
	{
		cout << x << "is not found in the list";
	}
}
 void list :: Remove(int x)
 {
 	// Step 1: Empty List - Return Control
 	if(head == NULL)
 	{
 		cout << "Empty List";
 		return;
	}
	
	//Step 2: Search for x
	Node *tmp = head;
	int flag = 0;
	Node *prev = NULL;
	
	while(tmp!=NULL)
	{
		if(tmp->data == x)
		{
			flag=1;
			break;
		}
		
		prev = tmp;
		tmp = tmp->next;
	}
	
	//Step 3: Unsucessful search - return control
	if(flag==0)
	{
		cout << x << "is not found in the list";
		return;
	}
	
	// Step 4: search is successful
	//Step 4a: Single node Deletion
	if(tmp==head && tmp->next==NULL)
	{
		head = NULL;
	}
	else if(tmp==head)//Step 4b: Head node deletion
	{
		head = tmp->next;
	}
	
	else if(tmp->next==NULL)// Step 4c : Tail Node Deletion
	{
		prev->next = NULL;		
	}	 
	else // Step 4d: Any other node int he middle
	{
		prev->next = tmp->next;
	}
	// Step: Delete tmp
	delete tmp;
 }
 
 void list :: Reverse()
 {
 	if(head == NULL)
 	{
 		cout << "Empty List";
		return;	
	}
	
	Node *tmp = head;
	Node *revHead = NULL;
	
	while(tmp!=NULL)
	{
		//Make a new node
		Node *r = new Node();
		r->data = tmp->data;
		r->next = revHead; // For the first node it is NULL
		
		//Update revHead
		revHead = r;
		
		//Advance tmp to the next node
		tmp = tmp->next; 
	}
	
	//Update head to revHead
	head = revHead;
	cout << endl << "Reversed List:";
	list :: Display();
 }
 

int main()
{
	int ch;
	int num;
	list s;
	
	while(1)
	{
		system("cls");
		cout << "*** Singly linked List menu *** "  <<endl << endl;
		
		cout << "1. Insert a node" << endl;
		cout << "2. Display the List" << endl;
		cout << "3. length of the List" << endl;
		cout << "4. search for a node" << endl;
		cout << "5. remove the node" << endl;
		cout << "6. reverse the node" << endl;
		cout << "7. Exit" << endl << endl;
		
		cout << " enter your choice: ";
		cin >> ch;
		
		switch(ch)
		{
			case 1 :
				cout << "Enter the element: ";
				cin >> num;
				s.Insert(num);
				
				getch();
				break;
				
			case 2 :
				s.Display();
				getch();
				break;
				
			case 3 :
				s.Length();
				getch();
				break;
				
			case 4 : 
				cout << "Enter the element: " ;
				cin >> num;
				s.Search(num);
				getch();
				break;
				
			case 5 :
				cout << " Enter the element: ";
				cin >> num;
				s.Remove(num);
				s.Display();
				getch();
				break;
					
			case 6 :
				s.Reverse();
				getch();
				break;	
				
			case 7 :
				exit(1);	
				
				
			default:
					cout << "incorrect option";
					getch();
				
		}//end of switch
	}//end of while
} //end of main

