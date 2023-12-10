/*  NAME: Yash Ishan Gohil
    ROLL NO: 1313
    UNIT: 2 -Searching
    PROGRAM: Linear/ Sequential search */
    
    
#include<iostream>

using namespace std;

int main()
{
	int n, arr[20], key;
	int i, flag=0;
	
	cout << "*** Linear Search ***" << endl <<endl;
	
	cout << "Enter the size of the array: ";
	cin >> n;
	
	cout << "Enter the elements: " << endl;
	for(i=0 ; i<n ; i++)
	{
		cin >> arr[i];
	}
	
	cout << "Enter the target value: ";
	cin >> key;
	
	for(i=0 ; i<n ; i++)
	{
		if (arr[i] ==  key)
		{
			flag = 1;
			break;
		}
	}
	if(flag == 1)
	{
		cout << "Target value " << key << " is found at index " << i; 
	}
	else
	{
		cout << "Target value is not found";
	}
}//end of main
