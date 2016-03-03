//Header file QueueAsArray

#ifndef H_QueueAsArray
#define H_QueueAsArray
 
#include <iostream>
#include <cassert>

#include "queueADT.h"

using namespace std;

//*************************************************************
// Author: D.S. Malik
//
// This class specifies the basic operation on a queue as an 
// array.
//*************************************************************

template <class Type>
class queueType: public queueADT<Type>
{
public:
    const queueType<Type>& operator=(const queueType<Type>&); 
      //Overload the assignment operator.

    bool isEmptyQueue() const;
      //Function to determine whether the queue is empty.
      //Postcondition: Returns true if the queue is empty,
      //    otherwise returns false.

    bool isFullQueue() const;
      //Function to determine whether the queue is full.
      //Postcondition: Returns true if the queue is full,
      //    otherwise returns false.

    void initializeQueue();
      //Function to initialize the queue to an empty state.
      //Postcondition: The queue is empty

    Type front() const;
      //Function to return the first element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: If the queue is empty, the program 
      //    terminates; otherwise, the first element of the
      //    queue is returned.  

    Type back() const;
      //Function to return the last element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: If the queue is empty, the program 
      //    terminates; otherwise, the last element of the queue
      //    is returned.

    void addQueue(const Type& queueElement);
      //Function to add queueElement to the queue.
      //Precondition: The queue exists and is not full.
      //Postcondition: The queue is changed and queueElement is
      //    added to the queue.

    void deleteQueue();
      //Function to remove the first element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: The queue is changed and the first element
      //    is removed from the queue.

    void printQueue();
    //Function to print queue elements
    //Precondition: The queue exists and is not empty.
    //Postcondition: All the queue elements between queueFront and qeueuBack are printed on screen

    void moveNthFront(int n);
    //Function moves nth element of the queue to front of the queue
    //Precondition: The queue exists and is not empty.
    //Postcondition: nth element is moved to the front and order of the remaining elements remains unchanged.

    queueType(int queueSize = 100); 
      //Constructor

    queueType(const queueType<Type>& otherQueue); 
      //Copy constructor

    ~queueType(); 
      //Destructor

private:
    int maxQueueSize; //variable to store the maximum queue size
    int count;        //variable to store the number of
                      //elements in the queue
    int queueFront;   //variable to point to the first
                      //element of the queue
    int queueRear;    //variable to point to the last
                      //element of the queue
    Type *list;       //pointer to the array that holds 
                      //the queue elements 
};


template <class Type>
bool queueType<Type>::isEmptyQueue() const
{
    return (count == 0);
} //end isEmptyQueue

template <class Type>
bool queueType<Type>::isFullQueue() const
{
    return (count == maxQueueSize);
} //end isFullQueue

template <class Type>
void queueType<Type>::initializeQueue()
{
    queueFront = 0;
    queueRear = maxQueueSize - 1;
    count = 0;
} //end initializeQueue

template <class Type>
Type queueType<Type>::front() const
{
    assert(!isEmptyQueue());
    return list[queueFront]; 
} //end front

template <class Type>
Type queueType<Type>::back() const
{
    assert(!isEmptyQueue());
    return list[queueRear];
} //end back

template <class Type>
void queueType<Type>::addQueue(const Type& newElement)
{
    if (!isFullQueue())
    {   
        queueRear = (queueRear + 1) % maxQueueSize; //use mod
                            //operator to advance queueRear  
                            //because the array is circular
        count++;
        list[queueRear] = newElement;
    }
    else
        cout << "Cannot add to a full queue." << endl; 
} //end addQueue

template <class Type>
void queueType<Type>::deleteQueue()
{
    if (!isEmptyQueue())
    {   
        count--;
        queueFront = (queueFront + 1) % maxQueueSize; //use the
                        //mod operator to advance queueFront 
                        //because the array is circular 
    }
    else
        cout << "Cannot remove from an empty queue" << endl;
} //end deleteQueue

    //Constructor
template <class Type>
queueType<Type>::queueType(int queueSize)   
{
    if (queueSize <= 0)
    {
        cout << "Size of the array to hold the queue must "
             << "be positive." << endl;
        cout << "Creating an array of size 100." << endl;

        maxQueueSize = 100;
    }
    else
        maxQueueSize = queueSize;   //set maxQueueSize to 
                                    //queueSize

    queueFront = 0;                 //initialize queueFront
    queueRear = maxQueueSize - 1;   //initialize queueRear
    count = 0;
    list = new Type[maxQueueSize];  //create the array to
                                    //hold the queue elements
} //end constructor

    //Destructor
template <class Type>
queueType<Type>::~queueType()   
{
    delete [] list;
} //end destructor

template <class Type>
const queueType<Type>& queueType<Type>::operator=
	                   (const queueType<Type>& otherQueue)
{
	if(this != &otherQueue)
	{
		delete [] list;
		maxQueueSize = otherQueue.maxQueueSize;
			count = otherQueue.count;
			queueFront = otherQueue.queueFront;
			queueRear = otherQueue.queueRear;
			list = new Type[maxQueueSize];
			assert(list!=NULL);
			for(int i=otherQueue.queueFront ; i< count; i++)
				list[i]=otherQueue.list[i];
	}
	return *this;

} //end assignment operator

template <class Type>
queueType<Type>::queueType(const queueType<Type>& otherQueue)
{
	maxQueueSize = otherQueue.maxQueueSize;
	count = otherQueue.count;
	queueFront = otherQueue.queueFront;
	queueRear = otherQueue.queueRear;
	list = new Type[maxQueueSize];
	assert(list!=NULL);
	for(int i=otherQueue.queueFront ; i< count; i++)
		list[i]=otherQueue.list[i];
} //end copy constructor

template <class Type>
void queueType<Type>::printQueue()
{
 if(count !=0 ) // if queue is not empty then it prints all elements
 {
 for(int i=queueFront ; i<=queueRear; i++)
	 cout<<list[i]<<" ";
 cout<<"\n";
 }
 else
	 cout<<"empty list!! \n";
}


template <class Type>
void queueType<Type>::moveNthFront(int n)
{
	if(n==1)
	{
		cout<<"1st element stays in 1st position only, no changes to queue !!\n";
	}
	else if(n<count && n>1) // if n is greater than number of elements in the queue the give error message and quit, else proceed
	{
	Type temp=list[n-1]; // copy the nth element to a temporary variable

	for(int i = n-1 ; i>queueFront ; i--) // moves all elements starting from 1st element to next location
	{
		list[i]=list[i-1]; //(n-1)th element is moved to nth position
	}
	list[queueFront]=temp; //move nth element to queue front
	}else
		cout<<"Invalid place value or position";
}

#endif