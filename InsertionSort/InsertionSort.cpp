#include<iostream>
#include "arrayListType.h"
#include"unorderedLinkedList.h"

using namespace std;

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
	   arr.shellSort();

	   arr.print();
	   cout<<endl;

	/*   unorderedLinkedList<int> list1;
	   	    int num1;

	   	    cout << "Enter the elements for list1, numbers ending with -999. \n";
	   	    cin >> num1;
	   	    while (num1 != -999)
	   	    {
	   	        list1.insertLast(num1);
	   	        cin >> num1;
	   	    }

	   	    list1.print();

	   	    list1.insertionSort();

	   	    cout<<endl;
	   	    list1.print();*/




	   cout<<endl;
	return 0;
}


