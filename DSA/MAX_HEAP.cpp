/*	Name: Yash Ishan Gohil
	Roll No:1313
	Unit : TRESSS
	Program: MAX-HEAP
*/

#include<iostream>
#include<conio.h>
#define MAX 20
using namespace std;

/* 1.Node Template - Not Required */

class Heap
{
	int a[MAX];
	int n;
	
	public:
			Heap()
			{
				for(int i=0; i<MAX; i++)
				{
					a[i] =0;	
				}
				n= 0;
				
			}
			
			void BuildHeap();
			void Insert(int x);
			void DeleteHeap();
			void Display();
			void ReHeapDown(int pos);
			void ReHeapUp(int x);
		
};
/* Function */
void Heap :: BuildHeap()
{
	int i;
	cout<<"Enter the size of the array: ";
	cin>>n;//n declared in the Heap class
	
	cout<<"Enter"<<" values in the Heap"<<endl;
	for( i=0; i<n; i++)
	{
		cin>>a[i];
	}
	//last non- leaf position (n/2)-1
	for(i =(n/2)-1 ; i>=0; i--)
	{
		ReHeapDown(i);
	}
	
}
void Heap :: Insert(int x)
{
	a[n] = x;
	n++;
	
	ReHeapUp(n-1);
}

void Heap :: DeleteHeap()
{
	int x=a[0];//copy root element to x;
	
	a[0]= a[n-1]; // copy last element to root
	
	a[n-1]=0; //overwrite last element with 0
	
	n--; // decrement size of Heap
	
	ReHeapDown(0); //Reheapdown from root
	cout<<"Element deleted is: "<<x;
}

void Heap::ReHeapUp(int x)
{
	int tmp=a[x];
	while(a[(x-1)/2] <= tmp && x>0)
	{
		a[x] = a[(x-1)/2];
		x= (x-1)/2;
	}
	a[x] = tmp;
}

void Heap::ReHeapDown(int pos)
    {
    	int tmp=a[pos];
    	int i;
    	while(pos<= (n/2)-1) //comparing with lasta leaf position
		{
			i=(2*pos)+1;	 //left child
	
			if(a[i+1]> a[i]) // compare index of larger child
			{
				i++;        // i contains index of larger child
			}
		
			if(tmp>a[i])
			{
				break;
			}
			a[pos] = a[i];
			pos= i;
		
		}
		a[pos] = tmp;
	}
	
void Heap::Display()	
{
	int i;
	for(i=0; i<n; i++)
	{
		cout<<a[i]<<" ";
		
	}
}
//menu0
int main()
{
	int ch, num;
	Heap h;
	
	while(1)
	{
		system("cls");
		cout<<"*** MAX-Heap ***\n\n";
		cout<<" 1. Build a Heap "<<endl;
		cout<<" 2. Insert an element "<<endl;
		cout<<" 3. Delete"<<endl;
		cout<<" 4. Display"<<endl;
		cout<<" 5. Exit"<<endl;
	
		cout<<"Enter you choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				h.BuildHeap();				
				getch();
				break;
					
					
			case 2:
				cout<<"Enter an element: ";
				cin>>num;
				
				h.Insert(num);
				getch();
				break;
										
			case 3:
				h.DeleteHeap();
				getch();
				break;	
				
			case 4:
				h.Display();
				getch();
				break;						
				
			case 5:
				exit(1);
				
			default:
				cout<<"Incorrect Choice!";
				getch();
				break;
		}//end of switch
	
	}	
}


