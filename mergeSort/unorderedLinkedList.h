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
    void separate(nodeType<Type>* first1, nodeType<Type>* &first2);
    nodeType<Type>* merge(nodeType<Type>* first1, nodeType<Type>* first2);
    void mergeRecSort(nodeType<Type>* &first);
    
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
    void mergeSort();


};

template <class Type>
void unorderedLinkedList<Type>::mergeSort()
{
	mergeRecSort(first);
	if(first == NULL)
		last = NULL;
	else
		{
			last = first;
			while(last->link != NULL)
				last = last->link;
		}
}

template <class Type>
void unorderedLinkedList<Type>::mergeRecSort(nodeType<Type>* &first)
{
	nodeType<Type> *first2;
	if(first != NULL)
	if(first->link != NULL)
	{
		separate(first, first2);
		mergeRecSort(first);
		mergeRecSort(first2);
		first = merge(first, first2);
	}


}

template <class Type>
void unorderedLinkedList<Type>::separate(nodeType<Type>* first1, nodeType<Type>* &first2)
{
	nodeType<Type> *cur,*mid;
	if(first1 == NULL)
		first2=NULL;
	else if(first1->link == NULL) //there is only one node
		first2= NULL;
	else{
		mid = first1;
		cur = first1->link;
		if(cur != NULL)
			cur = cur->link;
		while(cur != NULL)
		{
			mid = mid->link;
			cur = cur->link;
			if(cur != NULL)
			cur = cur->link;
		}

		first2 = mid->link;
		mid->link = NULL;
	}
}
template <class Type>
nodeType<Type>* unorderedLinkedList<Type>::merge(nodeType<Type>* first1, nodeType<Type>* first2)
{
	nodeType<Type> *newHead, *cur;
	if(first1 == NULL)
		return first2;
	else if(first2 == NULL)
		return first1;
	else
	{
		if(first1->info < first2->info)
		{
			newHead = first1;
			first1 = first1->link;
			cur =newHead;
		}else
		{
			newHead = first2;
			first2 = first2->link;
			cur =newHead;
		}
		while(first1 != NULL && first2 != NULL)
		{
		if(first1->info < first2->info)
		{
			cur->link = first1;
			cur = cur->link;
			first1=first1->link;
		}else
		{
			cur->link = first2;
			cur=cur->link;
			first2=first2->link;
		}
		}
		if(first1 == NULL)
			cur->link = first2;
		else
		if(first2 == NULL)
			cur->link = first1;

		return newHead;
	}

}


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
