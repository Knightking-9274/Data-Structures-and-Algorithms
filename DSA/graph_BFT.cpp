/*	Name: Yash Ishan Gohil
	Roll No:1313
	Unit : Graph
	Program: Breadth first traversal
*/
#include<iostream>
#include<conio.h>
#define MAX 10 

using namespace std;
/*Stack Template*/
class Queue
{
	
	int a[MAX];
	int front,rear;
	public:
	
	Queue()
	{
		front=rear=-1;
	}
	void Enqueue(int x);
	int Dequeue();
	int Empty();
};
void Queue :: Enqueue(int x)
{
	if(front == -1)
	{
		front++;
		
	}
	rear++;
	a[rear] = x;
}

int Queue :: Dequeue()
{
	
	if(front == -1)
	{
		cout << "Underflow!";
		return -1;
	}
	int x = a[front];
	
	if(front == rear)
	{
		front = rear = -1;
	}
	else
	{
		front++;
	}
}

int Queue :: Empty()
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


	
/*1. Node Template - Not Required*/
/*2. Graph Template*/
class Graph

{
	int adj[MAX][MAX];
	int n;
	int e;
	int visited[MAX];
	
	public:
		
			Graph()
			{
				int i , j;
				for(i=0; i<MAX; i++)
				{
					for(j=0; j<MAX; j++)
					{
						adj[i][j] = 0;
					}
				}
				
				n = 0; e = 0;
			}
			void CreateGraph();
			void Display();
			void BFT(int x);
};
/*3.Functions*/
void Graph :: CreateGraph()
{
	cout << " Enter the number of nodes:";
	cin >> n; 			//n is declared in the graph class
	
	cout << "Enter the number of edges:";
	cin >> e;			//e is declared in the graph class
	
	int i, source, dest;
	for(i=1; i<=e ; i++)
	{
		cout << "Input Edge  :"<<i <<endl;
		
		cout << "Enter source Node: ";
		cin >> source;
		
		cout << "Enter destination Node: ";
		cin >> dest;
		
		adj[source][dest] = 1;
		adj[dest][source] = 1;
	}
	
}
void Graph :: Display()
{
	int i, j;
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			cout << adj[i][j] <<" ";
		}
		cout << endl;
	}
}
void Graph :: BFT(int x)

{
	Queue q;
	int i;
	
	//updated visited i
	
	for(i=0; i<n; i++)
	{
		visited[i] = 0;
	}
	
	q.Enqueue(x);
	visited[x] = 1;
	
	while(!q.Empty())
	{
		x = q.Dequeue();
		cout << x << " ";
		
		for(i=0; i<n; i++)
		{
			if(adj[x][i]==1 && visited[i]==0)
			{
				q.Enqueue(i);
				visited[i] = 1;
				
			}//end of if
		}//end of for
	}//end of while
}
int main()
{
	int ch, num;
	Graph g;
	
	
	while(1)
	{
		system("cls");
		
		cout << " ***Graph ***\n\n";
		
		cout << "1.Create a Graph"<<endl;
		cout << "2. Display" << endl;
		cout << "3. BFT" << endl;
		cout << "4.Exit" << endl;
		
		cout << "Enter your choice:";
		cin>> ch;
		
		switch(ch)
		{
			case 1:
				
				g.CreateGraph();
				getch();
				break;
		
			case 2:
				g.Display();
				getch();
				break;
				
			case 3:
				cout << "Enter the node:";
				cin>>num;
				g.BFT(num);
				getch();
				break;
				
		
			case 4:
				exit(1);
					
			default :
				cout << "Incorrect Choice:";
  				break;		
		}
	}
}
