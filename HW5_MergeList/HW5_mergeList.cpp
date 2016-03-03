#include <iostream>
#include "orderedLinkedList.h"

using namespace std;

int main()
{
    orderedLinkedList<int> list1, list2,newList;
    int num,num1;

    list1.destroyList();
    list2.destroyList();
    cout << "Enter the elements for list1, numbers ending with -999. \n";
    cin >> num;
    while (num != -999)
    {
        list1.insert(num);
        cin >> num;
    }

    cout << "\nEnter the elements for list2, numbers ending with -999. \n";
    cin >> num1;
    while (num1 != -999)
        {
            list2.insert(num1);
            cin >> num1;
        }

 cout<< " rev list: ";
 list1.printRev();
 if(!list1.isEmptyList())
 {
    cout << "\nlist1: ";
    list1.print();
 }
 if(!list2.isEmptyList())
 {
    cout << "\nlist2: ";
    list2.print();
 }
    cout << endl;

   newList.mergeLists(list1,list2);
   if(!newList.isEmptyList())
    {
    cout<<"\nAfter merge the content of newList: ";
    newList.print();

    if(list1.isEmptyList())
    {
    	cout<<"\nAfter merge the List1 is empty !!";
    }
    if(list2.isEmptyList())
    {
       	cout<<"\nAfter merge the List2 is empty !!";
    }
    }



    return 0;
}

/*
=> Output: (Case1: when both lists are not empyt)
 Enter the elements for list1, numbers ending with -999.
 -1 4 6 3 -999

 Enter the elements for list2, numbers ending with -999.
 5 9 -5 2 -999

 list1: -1 3 4 6
 list2: -5 2 5 9
 After merge the content of newList:-5 -1 2 3 4 5 6 9
 After merge the List1 is empty !!
 After merge the List2 is empty !!


=> case2: when both lists are empty:

 Enter the elements for list1, numbers ending with -999.
-999

Enter the elements for list2, numbers ending with -999.
-999

both lists are empty !!


=> case3: when only one list is empty and other has numbers:

Enter the elements for list1, numbers ending with -999.
0 -5 3 7 23 -30 999 -999

Enter the elements for list2, numbers ending with -999.
-999

list1: -30 -5 0 3 7 23 999

After merge the content of newList: -30 -5 0 3 7 23 999
After merge the List1 is empty !!
After merge the List2 is empty !!

 */




