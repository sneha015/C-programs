#include<iostream>
#include "orderedArrayListType.h"

using namespace std;

int main()
{
   orderedArrayListType<int> lst;
   int location,BinNum,SeqNum,num;

   cout<<"Enter elements of List ending with -999:\n";
   cin>>num;

   while(num != -999)
   {
	   lst.insertOrd(num); // inserting elements in to the list
	   cin>>num;
   }
   cout<<"List elements are: \n";
   lst.print();

   //send the start and end index of array with element to be searched
  cout<<"Enter the element to be searched using recursive binary search :\n";
  cin>>BinNum;
  location = lst.recursiveBinarySearch(0, lst.listSize()-1 , BinNum);
  if(location != -1)
  {
	  cout<<"Number "<<BinNum<<" found at index "<<location<<"\n";
  }else
	  cout<<"number "<<BinNum<<" is not foundin the list\n";

  cout<<"Enter the element to be searched using Sequential Search : \n";
  cin>>SeqNum;
  location = lst.sequentialSearch(SeqNum);
    if(location != -1)
    {
  	  cout<<"Number "<<SeqNum<<" found at index "<<location;
    }else
  	  cout<<"Number "<<SeqNum<<" not found in the list";
  cout<<endl;


	return 0;
}

/* output case1:
Enter elements of List ending with -999:
5 8 9 12 25 60 98 111 -999
List elements are:
5 8 9 12 25 60 98 111
Enter the element to be searched using recursive binary search :
9
Number 9 found at index 2
Enter the element to be searched using Sequential Search :
111
Number 111 found at index 7


output case2:
Enter elements of List ending with -999:
-3 -1 0 4 7 9 12 17 28 -999
List elements are:
-3 -1 0 4 7 9 12 17 28
Enter the element to be searched using recursive binary search :
-2
number -2 is not foundin the list
Enter the element to be searched using Sequential Search :
2
Number 2 not found in the list
 */
