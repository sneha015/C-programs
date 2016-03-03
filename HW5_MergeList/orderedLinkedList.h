#ifndef H_orderedListType
#define H_orderedListType

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of an ordered doubly linked list. 
//***********************************************************

#include "linkedList.h"

using namespace std;

template <class Type>
class orderedLinkedList: public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const; 
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the list, 
      //    otherwise the value false is returned.

    void insert(const Type& newItem);
      //Function to insert newItem in the list.
      //Postcondition: first points to the new list, newItem 
      //    is inserted at the proper place in the list, and
      //    count is incremented by 1.

    void insertFirst(const Type& newItem);
      //Function to insert newItem at the beginning of the list.
      //Postcondition: first points to the new list, newItem is
      //    inserted at the beginning of the list, last points to the
      //    last node in the list, and count is incremented by 1.

    void insertLast(const Type& newItem);
      //Function to insert newItem at the end of the list.
      //Postcondition: first points to the new list, newItem is
      //    inserted at the end of the list, last points to the 
      //    last node in the list, and count is incremented by 1.

    void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing deleteItem is
      //    deleted from the list; first points to the first node
      //    of the new list, and count is decremented by 1. If
      //    deleteItem is not in the list, an appropriate message 
      //    is printed.

    void mergeLists(orderedLinkedList<Type> &list1, orderedLinkedList<Type> &list2);
    //This function creates a new list by merging the elements of list1 and list2.
    //Postcondition: first points to the merged list; list1 and list2 are empty

};

/*------------------------------------------HW5 merge 2 lists----------------------------------------------------------*/

template <class Type>
void orderedLinkedList<Type>::mergeLists(orderedLinkedList<Type> &list1, orderedLinkedList<Type> &list2)
{

	if(!list1.isEmptyList() && !list2.isEmptyList()) //if both list1 and list2 are not empty
	{
		while(!list1.isEmptyList()) // till list1 is not empty, copy 1st node of list1 to this(calling list) and delete first node
		{
			this->insert(list1.front());
			list1.deleteNode(list1.front());
		}
			list1.destroyList(); // to ensure list1 is empty after copying all nodes
		while(!list2.isEmptyList()) // till list2 is not empty, copy 1st node of list2 to this(calling list) and delete first node.
		{
			this->insert(list2.front());
			list2.deleteNode(list2.front());
		}

	}
	else // if any one of the list1 and list2 is empty
	if(list1.isEmptyList() && !list2.isEmptyList()) // case where list1 is empty and list2 is not empty, then just copy list2 to this(calling list) and destroy list2.
	{
		while(!list2.isEmptyList())
				{
					this->insert(list2.front());
					list2.deleteNode(list2.front());
				}
		list2.destroyList(); //to ensure list2 is empty after copying all nodes

	}
	else
	if(list2.isEmptyList() && !list1.isEmptyList())// case where list2 is empty and list2 is not empty, then just copy list1 to this(calling list) and destroy list1.
	{
		while(!list1.isEmptyList())
				{
					this->insert(list1.front());
					list1.deleteNode(list1.front());
				}
		list1.destroyList();//to ensure list1 is empty after copying all nodes

	}
	else
	if(list1.isEmptyList() && list2.isEmptyList())//if both the lists are empty then appropriate message is printed on screen and program terminates.
	{
		cout<<"both lists are empty !!";
	}

}

/* --------------------------------------------HW5 till here ---------------------------------------------------------------*/

template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type> *current; //pointer to traverse the list

    current = this->first;  //start the search at the first node

    while (current != NULL && !found)
        if (current->info >= searchItem)
            found = true;
        else
            current = current->link;
 
    if (found)
       found = (current->info == searchItem); //test for equality

    return found;
}//end search


template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    nodeType<Type> *newNode;  //pointer to create a node

    bool  found;

    newNode = new nodeType<Type>; //create the node
    newNode->info = newItem;   //store newItem in the node
    newNode->link = NULL;      //set the link field of the node
                               //to NULL

    if (this->first == NULL)  //Case 1
    {
        this->first = newNode;
        this->last = newNode;
        this->count++;
    }
    else
    {
        current = this->first;
        found = false;

        while (current != NULL && !found) //search the list
           if (current->info >= newItem)
               found = true;
           else
           {
               trailCurrent = current;
               current = current->link;
           }
 
        if (current == this->first)      //Case 2
        {
            newNode->link = this->first;
            this->first = newNode;
            this->count++;
        }
        else                       //Case 3
        {
            trailCurrent->link = newNode;
            newNode->link = current;

            if (current == NULL)
                this->last = newNode;

            this->count++;
        }
    }//end else
}//end insert

template<class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    insert(newItem);
}//end insertFirst

template<class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
    insert(newItem);
}//end insertLast

template<class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;

    if (this->first == NULL) //Case 1
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        current = this->first;
        found = false;

        while (current != NULL && !found)  //search the list
            if (current->info >= deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }

        if (current == NULL)   //Case 4
            cout << "The item to be deleted is not in the " 
                 << "list." << endl;
        else
            if (current->info == deleteItem) //the item to be 
                                   //deleted is in the list
            {
                if (this->first == current)       //Case 2
                {
                    this->first = this->first->link;

                    if (this->first == NULL)
                        this->last = NULL;

                    delete current;
                }
                else                         //Case 3
                {
                    trailCurrent->link = current->link;

                    if (current == this->last)
                        this->last = trailCurrent;

                    delete current;
                }
                this->count--;
            }
            else                            //Case 4
                cout << "The item to be deleted is not in the "
                     << "list." << endl;
    }
}//end deleteNode


#endif
