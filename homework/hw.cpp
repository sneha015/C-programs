/*
 * hw.cpp
 *
 *  Created on: Jul 6, 2015
 *      Author: lokisneha
 */



#include <iostream>
#include "doublyLinkedList.h"

using namespace std;

int main()
{
    doublyLinkedList<int> list1, list2;

    list1.insert(100);
   list1.insert(45); // adds elements in to the list
    list1.insert(-5);
    list1.insert(23);
    list1.insert(8);
    list1.insert(5);

    cout<<"\nlist1: ";
    list1.print();   // prints the doubly linked list

    list2=list1; // demonstrating copy constructor, overloaded = operator
    cout<<"\nlist2: ";
    list2.print();

    list1.deleteNode(23); // deletes a node from the list if the node is present else gives error message

    if(list1.isEmptyList())  // checks if the list is empty
    	cout<<"\nList1 is empty!! \n";
    else
    	cout<<"\nlist1 is not empty!! \n";

    if(list1.search(25)) // searches for an element in the list
    	cout<<"25 present in List1 !! \n";
    else
    	cout<<"25 not present in list1 !! \n";

    list1.insert(25);
    cout<<"list1 after deletion of 23 and insertion of 25 \n";
    list1.print();

    cout<<"\nlist1 one length before destroy: " <<list1.length(); // to check destroy and length operations
    list1.destroy();
    cout<<"\nlist1 one length after destroy: " <<list1.length();

    cout << endl;

    return 0;
}






