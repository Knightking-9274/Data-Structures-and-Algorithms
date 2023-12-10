/*
	Name: Yash Ishan Gohil
	Roll No: 1313
	Unit 6: Trees
	Program: Binary Search Trees
*/

#include<iostream>
#include<conio.h>

using namespace std;

/*1. Node Template*/
class BSTNode
{
	public:
		int data;
		BSTNode *right;
		BSTNode *left;
};

/*2. BST Template */
class BST
{
	BSTNode *root;
	int cnt;
	
	public:
		BST()
		{
			root = NULL;
			cnt = 0;
		}
		
		void Insert(int x);
		void Display();
		void Inorder(BSTNode *t);
		void Preorder(BSTNode *t);
		void Postorder(BSTNode *t);		
		void Count();
		void Search(int x);
		void FindMax();
		void FindMin();
};
/*3.Functions*/
void  BST :: Insert(int x)
{
	// make a new node
	BSTNode *t = new BSTNode();
	t->data = x;
	t->right = NULL;
	t->left = NULL;
	
	//first node in the tree
	if( root == NULL)
	{
		root = t;
		cnt++;
		return;
	}
	//Traverse
	BSTNode *tmp = root;
	BSTNode *prev = NULL;
	
	while(tmp != NULL)
	{
		prev = tmp;
		
		if(x > tmp->data)
		{
			tmp = tmp->right;
		}
		else if(x < tmp->data)
		{
			tmp = tmp->left;
		}
		else//duplicate
		{
			cout << "Duplicate value!";
			return;
		}
	}
	
	//Attach t to prev
	if(t->data < prev->data)
	{
		prev->left = t;
	}
	else
	{
		prev->right = t;
	}
	cnt++;
}
void BST :: Display()
{
	if(root == NULL)
	{
		cout << "Empty Tree";
		return;
	}
	
	cout << "Inorder Traversal";
	Inorder(root);
	
	cout << endl;
	cout << "Preorder Traversal";
	Preorder(root);
	
	cout << endl;
	cout << "Postorder Traversal";
	Postorder(root);
}
void BST :: Inorder(BSTNode *t)
{
	if(t)
	{
		Inorder(t->left);
		cout << t->data << " ";
		Inorder(t->right);
	}
}
void BST :: Postorder(BSTNode *t)
{
	if(t)
	{
		Postorder(t->left);
		Postorder(t->right);
		cout << t->data << " ";
	}
}
void BST :: Preorder(BSTNode *t)
{
	if(t)
	{
		cout << t->data << " ";
		Preorder(t->left);
		Preorder(t->right);
		
	}
}
void BST :: Count()
{
	cout << "Number of Nodes:" <<cnt;
}
void BST :: FindMax()
{
	if(root == NULL)
	{
		cout << " Empty Tree";
		return;
	}
	
	BSTNode *tmp = root;
	
	while(tmp->right!=NULL)
	{
		tmp = tmp->right;
	}
	
	cout << "Maximum Value:" << tmp->data;
}
void BST :: FindMin()
{
	if(root == NULL)
	{
		cout << " Empty Tree";
		return;
	}
	
	BSTNode *tmp = root;
	
	while(tmp->left!=NULL)
	{
		tmp = tmp->left;
	}
	
	cout << "Minimum Value:" << tmp->data;
}
void BST :: Search(int x)
{
	if(root == NULL)
	{
		cout << "Empty tree";
		return;
	}
	 BSTNode *tmp = root;
	 int flag = 0;
	 
	 while(tmp!=NULL)
	 {
	 	if(x < tmp->data)
	 	{
	 		tmp = tmp->left;	
		}
		else if(x > tmp->data)
		{
			tmp = tmp->right;
		}
		else
		{
			flag = 1;
			break;
		}
	 }//end of while
	 	if(flag == 1)
	 		{
	 			cout << "Node is found in the tree";
	 		}
	 	else
			{
				cout << "Node is not found in the Tree";
			}
}
/*4.Menu*/
int main()
{
	int ch, num;
	BST b;
	
	while(1)
	{
		system("cls");
		
		cout << "*** Binary Search Tree ***\n\n";
		
		cout << "1. Insert " << endl;
		cout << "2. Display the BST" << endl;
		cout << "3. Count the node in BST" << endl;
		cout << "4. Find a node int BST" <<endl;
		cout << "5. Find the Maximum value" <<endl;
		cout << "6. Find the Minimum value" <<endl;
		cout << "7. Exit" << endl;
		
		cout << "Enter your choice:";
		cin>> ch;
		
		switch(ch)
		{
			case 1:
				cout << "Enter an element: ";
				cin >> num;
				b.Insert(num);
				getch();
				break;
		
			case 2:
				b.Display();
				getch();
				break;
			
			case 3:
				b.Count();
				getch();
				break;
			
			
			case 4:
				cout << "Enter a value:";
				cin>>num;
				b.Search(num);
				getch();
				break;
			
			case 5:
		
				b.FindMax();
				getch();
				break;
				
			
			case 6:
				
				b.FindMin();
				getch();
				break;
			
			case 7:
				exit(1);
				
			default :
				cout << "Incorrect Choice:";
  				break;
  		}
	}
}
