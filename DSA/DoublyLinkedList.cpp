/*  
	Name: Yash Ishan Gohil
    Roll No. : 1313
    UNIT 5: Linked List
    PROGRAM : Doubly Linked List 
*/

#include<iostream>
#include<conio.h>

using namespace std;

/*1. Node Template */
class DNode
{
	
	public:
		int data;
		DNode *right;
		DNode *left;
};

/*2. List Template */
class DList
{
	DNode *head;
	DNode *tail;
	
	public:
		DList(){
			head=NULL;
			tail=NULL;
		}
		
		void Insert(int x);
		void Display();
		void Length();
		void Search(int x);
		void Remove(int x);		
};

/*3. Function */
// Insertion
void DList :: Insert(int x)
{
	//Make a new node
	DNode *t = new DNode();
	t->data = x;
	t->right = NULL;
	t->left = NULL;
	
	//Head Node
	if(head == NULL)
	{
		head = t;
		tail = t;
	}
	//Attach t to tail and shift tail
	else
	{
		tail->right = t;
		t->left = tail;
		tail = t;
	}
}

//Display
void DList :: Display(){
	if(head == tail)
	{
		cout << "Empty List";
		return;
	}
	
	cout << "Forward Direction: " << endl;
	DNode *tmp = head;
	while(tmp!=NULL)
	{
		cout << tmp->data << "<->";
		tmp = tmp->right;
	}
	cout << "End Of List" << endl << endl;
	
	cout << "Reverse Direction: " << endl;
	
	tmp = tail;
	while(tmp!=NULL)
	{
		cout << tmp->data << "<->";
		tmp = tmp->left;
	}
	cout << "Start Of List" << endl;
}

//Length
void DList :: Length()
{
	int cnt = 0;
	DNode *tmp = head;
	
	if(head == NULL)
	{
		cout << "List is Empty. \nLength: " << cnt;
		return;
	}
	while(tmp!=NULL)
	{
		cnt++;
		tmp = tmp->right;
	}
	cout << "Number Of Nodes: " << cnt;
}

//Search
void DList :: Search(int x)
{
	DNode *tmp = head;
	int flag = 0;
	
	while(tmp!=NULL)
	{
		if(tmp->data == x )
		{
			flag = 1;
			break;
		}
		tmp = tmp->right;
	}
	if(flag == 1)
	{
		cout << x << " is found in the List.";
	}
	else
	{
		cout << x << " is not found in the List.";
	}
}

//Delete
void DList :: Remove(int x)
{
	//1. Empty list - Return Control
	if(head==NULL)
	{
		cout << "Empty List";
		return;
	}
	
	//2. Search for x
	DNode *tmp = head;
	DNode *prev = NULL;
	int flag = 0;
	
	while(tmp!=NULL)
	{
		if(tmp->data == x )
		{
			flag = 1;
			break;
		}
		prev = tmp;
		tmp = tmp->right;
	}
	
	//3. Search unsuccessful - Return Control
	if(flag == 0)
	{
		cout << x << " is not found";
		return;
	}
	
	//4. Search Successful
	//4a. Single Node Deletion
	if(head == tail)
	{
		head = NULL;
		tail = NULL;
	}
	//4b. Head Node Deletion
	else if(tmp == head)
	{
		head = tmp->right;
		head->left = NULL; 
	}
	else if(tmp == tail)// 4c.Tail Node Deletion
	{
		tail = prev;
		tail->right = NULL;
	}
	else // 4d. any Node int the Middle
	{
		prev->right = tmp->right;
		
		DNode * r = tmp->right;
		r->left = prev;
				
	}
	
	//5. Delete tmp
	delete tmp;
	DList :: Display();
	
}

/* 4. Menu Interface */

int main()
{
	int ch;
	int num;
	DList d;
	
	while(1)
	{
		system("cls");
		cout << "*** Doubly Linked List *** \n\n";
		
		cout << "1. Insert a node" << endl;
		cout << "2. Display the list" << endl;
		cout << "3. Length of the list" << endl;
 		cout << "4. Search a node" << endl;
 		cout << "5. Remove a node" << endl;
 		cout << "6. Exit" << endl << endl;
 		
 		cout << "Enter your choice: ";
		cin >> ch;
		
		switch(ch)
		{
			case 1:
				cout << "Enter an Element: ";
				cin >> num;
				d.Insert(num);
				
				getch();
				break;
			
			case 2:
				d.Display();
				
				getch();
				break;
				
			case 3:
				d.Length();
				
				getch();
				break;
				
			case 4:
				cout << "Enter an Element: ";
				cin >> num;
				d.Search(num);
				
				getch();
				break;
				
			case 5:
				cout << "Enter an Element";
				cin >> num;
				d.Remove(num);
				
				getch();
				break;
				
			
			case 6:
				exit(1);
				
			default:
				cout << "This is an incorrectly entered option" << endl;
				getch();
				break;
		}//end of switch
	}//end of while
}//end of main
