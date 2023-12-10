/*	Name: Yash Ishan Gohil
	Roll No:1313
	Unit : Graph
	Program: Graph Storage
*/
#include<iostream>
#include<conio.h>
#define MAX 10 

using namespace std;
/*1. Node Template - Not Required*/
/*2. Graph Template*/
class Graph

{
	int adj[MAX][MAX];
	int n;
	int e;
	
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
		cout << "3.Exit" << endl;
		
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
				exit(1);
					
			default :
				cout << "Incorrect Choice:";
  				break;		
		}
	}
}
