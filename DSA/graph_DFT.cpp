/*	Name: Yash Ishan Gohil
	Roll No:1313
	Unit : Graph
	Program: Depth first traversal
*/
#include<iostream>
#include<conio.h>
#define MAX 10 

using namespace std;

/* Stack Template */
class Stack
{
	int a[MAX];
	int tos;
	
	public:
			Stack()
			{
				tos = -1;
			}
			void Push(int x);
			int Pop();
			int Empty();
};

void Stack :: Push(int x)
{
	tos++;
	a[tos] = x;
}

int Stack :: Pop()
{
	int x = a[tos];
	tos--;
	return x;
}

int Stack :: Empty()
{
	if(tos == -1)
	return 1;
	
	else
	return 0;
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
			void DFT(int x);
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
void Graph :: DFT(int x)

{
		Stack s;
		int i;
		
		//update visited
		for(i=0 ; i<n ; i++)
		{
			visited[i] = 0;
		}
		
		s.Push(x);
		visited[x] = 1;
		
		while(!s.Empty())
		{
			x = s.Pop();
			cout << x << " ";
			
			for(i=0 ; i<n ; i++)
			{
				if(adj[x][i]==1 && visited[i]==0)
				{
					s.Push(i);
					visited[i] = 1;
				}
			}
		}
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
		cout << "3. DFT" << endl;
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
				g.DFT(num);
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
