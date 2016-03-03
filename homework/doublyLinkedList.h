
#ifndef H_doublyLinkedList
#define H_doublyLinkedList

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of an ordered doubly linked list. 
//***********************************************************

#include <iostream>
#include <cassert>

using namespace std;

  //Definition of the node
template <class Type>
struct nodeType
{  
    Type info;
    nodeType<Type> *next;
    nodeType<Type> *back;  
};

template <class Type>
class doublyLinkedList
{
public:
    const doublyLinkedList<Type>& operator=(const doublyLinkedList<Type> &);

    void initializeList();
    bool isEmptyList() const;
    void destroy();
    void print() const;
    void reversePrint() const;
    int length() const;
    Type front() const;
    Type back() const;
    bool search(const Type& searchItem) const;
    void insert(const Type& insertItem);
    void deleteNode(const Type& deleteItem);
    doublyLinkedList(); 
    doublyLinkedList(const doublyLinkedList<Type>& otherList); 
    ~doublyLinkedList(); 

protected:
    int count;
    nodeType<Type> *first; //pointer to the first node
    nodeType<Type> *last;  //pointer to the last node

private:
    void copyList(const doublyLinkedList<Type>& otherList); 

};

template <class Type>
doublyLinkedList<Type>::doublyLinkedList()
{
    first= NULL;
    last = NULL;
    count = 0;
}

template <class Type>
bool doublyLinkedList<Type>::isEmptyList() const
{
    return (first == NULL);
}

template <class Type>
void doublyLinkedList<Type>::destroy()
{ 
    nodeType<Type>  *temp; //pointer to delete the node
	
    while (first != NULL)
    {
        temp = first;
        first = first->next;
        delete temp;
    }

    last = NULL;
    count = 0;
}

template <class Type>
void doublyLinkedList<Type>::initializeList()
{
    destroy();
}

template <class Type>
int doublyLinkedList<Type>::length() const
{
    return count;
}

template <class Type>
void doublyLinkedList<Type>::print() const
{
    nodeType<Type> *current; //pointer to traverse the list

    current = first;  //set current to point to the first node

    while (current != NULL)
    {
        cout << current->info << "  ";  //output info
        current = current->next;
    }//end while
}//end print


template <class Type>
void doublyLinkedList<Type>::reversePrint() const
{
    nodeType<Type> *current; //pointer to traverse 
                             //the list

    current = last;  //set current to point to the 
                     //last node

    while (current != NULL)
    {
        cout << current->info << "  ";  
        current = current->back;
    }//end while
}//end reversePrint

template <class Type>
bool doublyLinkedList<Type>::search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type> *current; //pointer to traverse the list

    current = first;

    while (current != NULL && !found)
        if (current->info >= searchItem)
            found = true;
        else
            current = current->next;

    if (found)
       found = (current->info == searchItem); //test for 
                                              //equality

    return found;
}//end search

template <class Type>
Type doublyLinkedList<Type>::front() const
{
    assert(first != NULL);

    return first->info;
}

template <class Type>
Type doublyLinkedList<Type>::back() const
{
    assert(last != NULL);

    return last->info;
}

template <class Type>
void doublyLinkedList<Type>::insert(const Type& insertItem)
{
    nodeType<Type> *current;      //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    nodeType<Type> *newNode;      //pointer to create a node
    bool found;

    newNode = new nodeType<Type>; //create the node
    newNode->info = insertItem;  //store the new item in the node
    newNode->next = NULL;
    newNode->back = NULL;

    if(first == NULL) //if the list is empty, newNode is 
                      //the only node
    {
       first = newNode;
       last = newNode;
       count++;
    }
    else
    {
        found = false;
        current = first;

        while (current != NULL && !found) //search the list
            if (current->info >= insertItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->next;
            }

        if (current == first) //insert newNode before first
        {
            first->back = newNode;
            newNode->next = first;
            first = newNode;
            count++;
        }
        else
        {
              //insert newNode between trailCurrent and current
            if (current != NULL)
            {
                trailCurrent->next = newNode;
                newNode->back = trailCurrent;
                newNode->next = current;
                current->back = newNode;
            }
            else
            {
                trailCurrent->next = newNode;
                newNode->back = trailCurrent;
                last = newNode;
            }

            count++;
        }//end else
    }//end else
}//end insert

template <class Type>
void doublyLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current

    bool found;

    if (first == NULL)
        cout << "Cannot delete from an empty list." << endl;
    else if (first->info == deleteItem) //node to be deleted is  
                                       //the first node
    {
        current = first;
        first = first->next;

        if (first != NULL)
            first->back = NULL;
        else
            last = NULL;
			
        count--;

        delete current;
    }
    else 
    {
        found = false;
        current = first;

        while (current != NULL && !found)  //search the list
            if (current->info >= deleteItem)
                found = true;
            else
                current = current->next;

        if (current == NULL)
            cout << "The item to be deleted is not in " 
                 << "the list." << endl;
        else if (current->info == deleteItem) //check for 
                                                 //equality
        {
            trailCurrent = current->back; 
            trailCurrent->next = current->next;

            if (current->next != NULL)
                current->next->back = trailCurrent;

            if (current == last)
                last = trailCurrent;

            count--;
            delete current;
        }
        else
            cout << "The item to be deleted is not in list." 
                 << endl;
    }//end else
}//end deleteNode

/*---------------------------------------------------HW5 from here------------------------------------------------*/

template <class Type>
void doublyLinkedList<Type>::copyList(const doublyLinkedList<Type>& otherList)
{
	nodeType<Type> *current; // pointer to traverse the list
	nodeType<Type> *newNode; // pointer to create a node

	if(first != NULL)// if the list is non empty, then make it empty
		destroy();

	if(otherList.first == NULL) // if otherlist is empty, make this list empty
	{
		first=NULL;
		last=NULL;
		count=0;
	}
	else
	{
		current = otherList.first;//current points to the first ned of fist to be copied
		first = new nodeType<Type>; // create new node
		count = otherList.count;

		first->info= current->info; // copy 1st node
		first->next= NULL;
		last=first;

		current=current->next;
		while(current != NULL) // Traverse all the elements till null and copy node by node
		{
			newNode = new nodeType<Type>;//create a node
			newNode->info=current->info; // copy the info
			newNode->next= NULL;
			newNode->back= last;
			last->next =newNode;
			last = newNode;
			current = current->next;
		}

	}

}

template <class Type>
doublyLinkedList<Type>::doublyLinkedList(const doublyLinkedList<Type>& otherList)
{
	  first=NULL; // copyList checks if first is null initially, so set it null before calling the function
	  copyList(otherList);
}

template <class Type>
const doublyLinkedList<Type>& doublyLinkedList<Type>::operator=(const doublyLinkedList<Type>& otherList)
{
	if(this != &otherList) // to make sure otherList=otherList is not performed
	{
		copyList(otherList);
	}

	return *this;
}

template <class Type>
doublyLinkedList<Type>::~doublyLinkedList()
{
	destroy();
}
/*----------------------------------------------------HW5 till here---------------------------------------------------*/

#endif
