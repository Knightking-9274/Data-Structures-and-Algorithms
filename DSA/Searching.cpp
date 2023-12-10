/*  Name: Yash Ishan Gohil
	Roll NO: 1313
	Unit 2 : Searching
	Program : Binary Search*/
	
#include<iostream>

using namespace std;

int main()
{
	int n, arr[20], key;
	int i;
	int first, last, mid, flag=0;
	
	cout<< "*** Binary Search ***" << endl << endl ;
	
	cout <<"Enter the size of array :";
	cin>> n;
	
	cout<< "Enter the elements: " << endl;
	
	for(i=0 ; i<n ; i++ )
	
	{
		cin >> arr[i];
	}
	
	cout << "Enter the key :";
	cin >> key;
	
	first = 0;
	last = n-1;
	
	while(first <= last)
	{
		mid = (first+last)/2;
		
		if(key < arr[mid])
		{
			last = mid-1;
		}
		else if (key > arr[mid])
		{
			first = mid+1;
		}
		else // Key is found
		{
			flag=1;
			break;
		}
	}//end of while
	
	if(flag==1)
	{
		cout << "Key" << key << " is found at index " << mid;
		
	}
	else
	{
		cout << "Key" << key << "is not found ";
	}
}
	
	
