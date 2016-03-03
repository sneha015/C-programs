#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of an unordered linked list. This class is
// derived from the class linkedListType. 
//***********************************************************

#include "linkedList.h"

using namespace std;

template <class Type>
class unorderedLinkedList: public linkedListType<Type>
{
    using linkedListType<Type>::first;
    using linkedListType<Type>::last;
    using linkedListType<Type>::count;
    
public:
    bool search(const Type& searchItem) const;
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the list,
      //    otherwise the value false is returned.

    void insertFirst(const Type& newItem);
      //Function to insert newItem at the beginning of the list.
      //Postcondition: first points to the new list, newItem is
      //    inserted at the beginning of the list, last points to
      //    the last node, and count is incremented by 1.
      //               

    void insertLast(const Type& newItem);
      //Function to insert newItem at the end of the list.
      //Postcondition: first points to the new list, newItem is
      //    inserted at the end of the list, last points to the
      //    last node, and count is incremented by 1.

    void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing deleteItem
      //    is deleted from the list. first points to the first 
      //    node, last points to the last node of the updated 
      //    list, and count is decremented by 1.

    void selectionSort();

    void insertionSort();

    void quickSort();
    void quickRecSort(nodeType<Type>& start,nodeType<Type>& end);
    nodeType<Type> partition(nodeType<Type>& start,nodeType<Type>& end);
};

template <class Type>
void unorderedLinkedList<Type>::quickSort()
{
	quickRecSort(first,last);
}

template <class Type>
void unorderedLinkedList<Type>::quickRecSort(nodeType<Type>& start,nodeType<Type>& end)
{
	nodeType<Type> pivotLocation;

}

/*template <class Type>
nodeType<Type> unorderedLinkedList<Type>::partition(nodeType<Type>& start,nodeType<Type>& end)
{
	nodeType<Type> small,cur;
	Type pivot;
	pivot = first->info;
	small = first;
	cur=first->link;
	while(cur->link != NULL)
	{
		if(cur->info < pivot)
		{
			small=small->next;
			temp= small->info;
			small->info = cur->info;
			cur->info = temp;
		}
		cur = cur->link;
	}
	temp= small->info;
	small->info = pivot;
	pivot = temp;

	return small;
}
*/
template <class Type>
void unorderedLinkedList<Type>::selectionSort()
{
	nodeType<Type> *current;
	nodeType<Type> *loc;
	nodeType<Type> *small;
	Type temp;

	loc = first;
	while(loc != NULL)
	{
	current= loc;
	small=loc;
	while(current!=NULL)
	{
		if(current->info < small->info)
		{
			small=current;
		}
		current = current->link;
	}
	if(small->info != loc->info)
	{
		temp = loc->info;
		loc->info = small->info;
		small->info = temp;
	}
	loc = loc->link;
	}
}

template <class Type>
void unorderedLinkedList<Type>::insertionSort()
{
	nodeType<Type> *cur,*prev,*LastInOrder,*FirstOutOfOrder;

	LastInOrder = first;

	if(LastInOrder == NULL)
		cout<<"list is empty \n";
	else
		if (LastInOrder->link == NULL)
		cout<<"list has only one element and its sorted \n";
	else
	{
	while(LastInOrder->link != NULL)
	{
	FirstOutOfOrder = LastInOrder->link;
	if(FirstOutOfOrder->info < first->info)
	{
		LastInOrder->link = FirstOutOfOrder->link;
		FirstOutOfOrder->link = first;
		first = FirstOutOfOrder;
	}else
	{
		prev = first;
		cur = first->link;
		while(cur->info < FirstOutOfOrder->info)
		{
			prev = cur;
			cur = cur->link;
		}

		if(cur->info != FirstOutOfOrder->info)
		{
			LastInOrder->link = FirstOutOfOrder->link;
			FirstOutOfOrder->link = cur;
			prev->link = FirstOutOfOrder;
		}
		else
		LastInOrder = LastInOrder->link;

	}//end if
	}//end while
	}//end if

}


template <class Type>
bool unorderedLinkedList<Type>::
                   search(const Type& searchItem) const
{
    nodeType<Type> *current; //pointer to traverse the list
    bool found = false;
    
    current = first; //set current to point to the first 
                     //node in the list

    while (current != NULL && !found)    //search the list
        if (current->info == searchItem) //searchItem is found
            found = true;
        else
            current = current->link; //make current point to
                                     //the next node
    return found; 
}//end search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem;    //store the new item in the node
    newNode->link = first;      //insert newNode before first
    first = newNode;            //make first point to the
                                //actual first node
    count++;                    //increment count

    if (last == NULL)   //if the list was empty, newNode is also 
                        //the last node in the list
        last = newNode;
}//end insertFirst

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem;  //store the new item in the node
    newNode->link = NULL;     //set the link field of newNode
                              //to NULL

    if (first == NULL)  //if the list is empty, newNode is 
                        //both the first and last node
    {
        first = newNode;
        last = newNode;
        count++;        //increment count
    }
    else    //the list is not empty, insert newNode after last
    {
        last->link = newNode; //insert newNode after last
        last = newNode; //make last point to the actual 
                        //last node in the list
        count++;        //increment count
    }
}//end insertLast


template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;

    if (first == NULL)    //Case 1; the list is empty. 
        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
        if (first->info == deleteItem) //Case 2 
        {
            current = first;
            first = first->link;
            count--;
            if (first == NULL)    //the list has only one node
                last = NULL;
            delete current;
        }
        else //search the list for the node with the given info
        {
            found = false;
            trailCurrent = first;  //set trailCurrent to point
                                   //to the first node
            current = first->link; //set current to point to 
                                   //the second node

            while (current != NULL && !found)
            {
                if (current->info != deleteItem) 
                {
                    trailCurrent = current;
                    current = current-> link;
                }
                else
                    found = true;
            }//end while

            if (found) //Case 3; if found, delete the node
            {
                trailCurrent->link = current->link;
                count--;

                if (last == current)   //node to be deleted 
                                       //was the last node
                    last = trailCurrent; //update the value 
                                         //of last
                delete current;  //delete the node from the list
            }
            else
                cout << "The item to be deleted is not in "
                     << "the list." << endl;
        }//end else
    }//end else
}//end deleteNode


#endif
