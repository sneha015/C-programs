#ifndef H_OrderedListType
#define H_OrderedListType

#include <iostream>
#include "arrayListType.h"

using namespace std;

template<class elemType>
class orderedArrayListType: public arrayListType<elemType>
{
public:
	void insertOrd(const elemType&);
	
	int binarySearch(const elemType& item) const;
	int recursiveBinarySearch(int start , int end, const elemType& item) const;
	int sequentialSearch(const elemType& item) const;

	orderedArrayListType(int size = 100);
};
 
template <class elemType>
void orderedArrayListType<elemType>::insertOrd(const elemType& item)
{
    int first = 0;
    int last = this->length - 1;
    int mid;

    bool found = false;

    if (this->length == 0)   //the list is empty
    {
        this->list[0] = item;
        this->length++;
    }
    else if (this->length == this->maxSize)
        cerr << "Cannot insert into a full list." << endl;
    else
    {
        while (first <= last && !found)
        {
            mid = (first + last) / 2;

            if (this->list[mid] == item)
                found = true;
            else if (this->list[mid] > item)
                last = mid - 1;
            else
                first = mid + 1;
        }//end while

        if (found)
            cerr << "The insert item is already in the list. "
                 << "Duplicates are not allowed." << endl;
        else
        {
            if (this->list[mid] < item)
                mid++;

            this->insertAt(mid, item);
        }
    }
}//end insertOrd

template<class elemType>
int orderedArrayListType<elemType>::binarySearch
                                       (const elemType& item) const
{
    int first = 0;
    int last = this->length - 1;
    int mid;

    bool found = false;

    while (first <= last && !found)
    {
        mid = (first + last) / 2;

        if (this->list[mid] == item)
            found = true;
        else if (this->list[mid] > item)
            last = mid - 1;
        else
            first = mid + 1;
    }

    if (found) 
        return mid;
    else
        return -1;
}//end binarySearch

template<class elemType>
int orderedArrayListType<elemType>::recursiveBinarySearch
                                       (int start , int end, const elemType& item) const
{
    int first = start;
    int last = end;
    int mid= (first + last) / 2;

    if(first <= last) //till all the elements are traversed
    {
        if (this->list[mid] == item)
            return mid;
        else if (this->list[mid] > item) //recursively search if item is not equal to mid
        	return recursiveBinarySearch(first , mid-1, item); //search 1st half of array
        else
        	return recursiveBinarySearch(mid+1,last, item);//search second half of array
    }
    else
        return -1;
}

template<class elemType>
int orderedArrayListType<elemType>::sequentialSearch
                                       (const elemType& item) const
{
	int i;

	for(i=0; i< this->length; i++) //traverses all the elements of array starting from index 0 and searches for item
	{
		if(this->list[i]>item) // since its ordered list, it need not search once the array element is greater than item
			return -1;
		else if(this->list[i]==item) // continues to search for item till end of array or till it reaches element greater than item
			return i; //if found returns location/index
	}
	return -1;

}

template<class elemType>
orderedArrayListType<elemType>::orderedArrayListType(int size)
   : arrayListType<elemType>(size)
{
}

#endif
