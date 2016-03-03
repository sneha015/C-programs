#include<iostream>
#include"arrayListType.h"
using namespace std;

//void quicksort( int arr[]);





int main()
{
	arrayListType<int> arr;
		   int num;

		   cout<<"Enter elements of List ending with -999:\n";
		   cin>>num;

		   while(num != -999)
		   {
			   arr.insert(num); // inserting elements in to the list
			   cin>>num;
		   }
		   cout<<"List elements are: \n";
		   arr.print();
		   cout<<endl;
		   arr.quickSort();

		   arr.print();
		   cout<<endl;

	return 0;
}





