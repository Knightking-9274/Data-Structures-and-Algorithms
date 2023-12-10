/* Name: Yash Ishan Gohil
   Roll No: 1313
   Unit 1: Sorting
   Program: Insertion Sort */
   
#include<iostream>   
using namespace std;
int main()
{
	int n, arr[20];
	int i, temp, loc;
	
	cout << "*** Insertion Sort***\n\n";
	
	cin>> n;
	
	cout<< "Enter the elements of the array:" << endl;
	

	for(i=0 ; i<n ; i++)
	{
		cin >> arr[i];
	}
	
	//Insertion sort
	for(i=1 ; i<n ; i++)
	{
		temp = arr[i];
		loc = i-1;
		
		while(temp<arr[loc] && loc>=0)
		{
			arr[loc+1] = arr[loc];
			loc = loc-1;
		}
		
		arr[loc+1] = temp;
	}
	
	cout << endl << endl << "Sorted array: ";
	for(i=0 ; i<n ; i++)
	{
		cout << arr[i] << " ";
	}
	
}//end of main
	
	
