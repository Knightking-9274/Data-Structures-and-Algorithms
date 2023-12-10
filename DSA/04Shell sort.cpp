/* Name: Yash Ishan Gohil
   Roll No: 1313
   Unit 1: Sorting
   Program: Shell Sort */
   
#include<iostream>   
#include<math.h>
using namespace std;
int main()
{
	int n, arr[20] , i;
	int gap, loc, extractData;
	
	cout << "*** Shell Sort***\n\n";
	
	cout << "Enter the size of the array:";
	
	cin>> n;
	
	cout<< "Enter the elements of the array:\n" << endl;
	

	for(i=0 ; i<n ; i++)
	{
		cin >> arr[i];
	}
	
	gap = floor(n/2);
	
	while(gap > 0)
	{
		for(i=0 ; i<n-gap ; i++ )
		{
			extractData = arr[i+gap];
			loc = i + gap;
			
			while((loc-gap)>=0 && extractData < arr[loc-gap])
			{
			
			
			arr[loc] = arr[loc-gap];
			loc = loc-gap;
			
			}
			arr[loc] = extractData;
			
		}//end for i
		gap = floor(gap/2);
	}//end of while loop
	
	cout<< endl << endl << "Sorted array:\n";
	for(i=0 ; i<n ; i++)
	{
		cout << arr[i] << " ";
	}
}//end of main
