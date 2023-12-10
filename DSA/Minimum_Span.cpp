/*	Name: Yash Ishan Gohil
	Roll No:1313
	Unit : Graph
	Program: MST - Kruskal's algorithm
	Program 25
*/
#include<iostream>
#include<conio.h>
#define MAX 10 
#define INF 999

using namespace std;
/*1. Node Template - Not Required*/
/*2. Graph Template*/
class Graph

{
	int adj[MAX][MAX];
	int n;
	int e;
	int parent[MAX];
	public:
		
			Graph()
			{
				int i , j;
				for(i=0; i<MAX; i++)
				{
					for(j=0; j<MAX; j++)
					{
						adj[i][j] = INF;
					}
				}
				
				n = 0; e = 0;
				for(i=0; i<MAX; i++)
				{
					parent[i] = -1;
				}
			}
			void CreateGraph();
			void Display();
			void Kruskal();
			int Find(int x);
			int Union(int x, int y);
			
};
/*3.Functions*/
void Graph :: CreateGraph()
{
	cout << " Enter the number of nodes:";
	cin >> n; 			//n is declared in the graph class
	
	cout << "Enter the number of edges:";
	cin >> e;			//e is declared in the graph class
	
	int i, source, dest,weight;
	for(i=1; i<=e ; i++)
	{
		cout << "Input Edge  :"<<i <<endl;
		
		cout << "Enter source Node: ";
		cin >> source;
		
		cout << "Enter destination Node: ";
		cin >> dest;
		
		cout << "Enter the weight: "<< endl;
		cin>>weight;
		adj[source][dest] = weight;
		adj[dest][source] = weight;
	}
	
}
void Graph :: Display()
{
	int i, j;
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(adj[i][j] == INF)
			{
				cout << "0  ";
			}
			else
			{
				cout << adj[i][j] <<"  ";
			}
		}
		cout << endl;
	}
}
void Graph :: Kruskal()
{
	int minimum,i,j ,ne=1;
	int a,b,u,v;
	int mincost=0;
	
	while(ne < n)
	{
		for(i=0, minimum=999;i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				if(adj[i][j] < minimum)
				{
					minimum = adj[i][j];
					a = u = i;
					b = v = j;
				}//end of if
			}//end of j	
		}//end of for i
		
		u = Find(u);
		v = Find(v);
		
		if(Union(u,v))
		{
			cout << "Edge" <<ne++ << " (" << a << "," <<b <<")= " <<minimum << endl;
			mincost += minimum;
		}
		
		adj[a][b] = adj[b][a] = INF;
	}//end of while loop
	
	cout<< "MST Minimum cost ="<< mincost;
	
	
}int Graph :: Find(int x)
{
	while(parent[x] != -1)
	{
		x = parent[x];
	}
	
	return x;
}
int Graph :: Union(int x, int y)
{
	if (x!=y)
	{
		parent[y] = x ;
		return 1 ;
	}
}

/*4. Menu*/
int main()
{
	int ch, num;
	Graph g;
	
	
	while(1)
	{
		system("cls");
		
		cout << " ***Minimum Spanning Tree using Kruskal's Algorithm' ***\n\n";
		
		cout << "1. Create a Graph"<<endl;
		cout << "2. Display" << endl;
		cout << "3. MST Using Kruskal's Algorithm"<< endl;
		cout << "4. Exit" << endl;
		
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
				g.Kruskal();
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
