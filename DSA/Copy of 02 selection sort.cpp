/* Name: Yash Ishan Gohil
   Roll No: 1313
   Unit 1: Sorting
   Program: selection Sort */
   
#include<iostream>   
using namespace std;
int main()
{
	int n, arr[20];
	int i, j, min, tmp, loc;
	
	cout<<"*** Selection Sort***"<< endl<< endl;
	
	cout<< "Enter the size of array: ";
	cin>> n;
	
	cout<< "Enter the elements of the array: "<<endl;
	for(i=0 ; i<n ; i++)
	{
		cin>> arr[i];
	}
	
	//Selection Sort
	for(i=0 ; i<n ; i++)
	{
		min = arr[i];
		loc = i;
		
		for(j=i+1; j<n; j++)
		{
			if(arr[j] < min)
			{
			
			min + arr[j];
			loc = j;
			
		    }
		
		}//end of loop j
		//found the smallest value and its loc at min and loc
		//swap
	
		tmp = arr[i];
		arr[i] = arr[loc];
		arr[loc] = tmp;
	}//end of loop i
	
	
	
	
	//Display
	cout<<"Sorted Array: ";
	for(i=0 ; i<n ; i++)
	{
		cout<<arr[i]<<" ";
	}
	
 	
}//end of main

