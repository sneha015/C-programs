#include <iostream>
#include "doublyLinkedList.h"

using namespace std;

int main()
{
    doublyLinkedList<int> list1, list2; //declaring list1 and list2 as doublyLinkedList type

    list1.insert(45); // adds elements in to the list1
    list1.insert(-5);
    list1.insert(23);
    list1.insert(8);
    list1.insert(5);

    cout<<"\nlist1: ";
    list1.print();   // prints list1 on to screen

    list2=list1;// demonstrating copy constructor, overloaded = operator
    if(!list2.isEmptyList())
    {
    cout<<"\nlist1 is copied to list2 successfully!! ";
    cout<<"\nlist2: ";
    list2.print();
    }

    list1.deleteNode(23); // deletes a node from the list if the node is present else gives error message

    if(list1.isEmptyList())  // checks if the list is empty
    	cout<<"\nList1 is empty!! \n";
    else
    	cout<<"\nlist1 is not empty!! \n";

    if(list1.search(25)) // searches for an element in the list
    	cout<<"25 present in List1 !! \n";
    else
    	cout<<"25 not present in list1 !! \n";

    list1.insert(25);// inserts new element 25 to the list1
    cout<<"list1 after deletion of 23 and insertion of 25 \n";
    list1.print();

    cout<<"\nlist1 one length before destroy: " <<list1.length(); // to check destroy and length operations
    list1.destroy(); // list1 is destroyed now its empty.
    cout<<"\nlist1 one length after destroy: " <<list1.length();


    return 0;
}

/* output:

list1: -5  5  8  23  45
list1 is copied to list2 successfully!!
list2: -5  5  8  23  45
list1 is not empty!!
25 not present in list1 !!
list1 after deletion of 23 and insertion of 25
-5  5  8  25  45
list1 one length before destroy: 5
list1 one length after destroy: 0
 */




