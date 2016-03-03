#include<iostream>
#include "queueAsArray.h"

using namespace std;

int main()
{
	queueType<int> intque;
	int num, position;

	cout<<"enter the elements of queue and at end -999 to stop reading the inputs \n";
	cin>>num;

	while(num != -999) // adds numbers to the queue
	{
		intque.addQueue(num);
		cin>>num;
	}

	cout<<"enter the place value of element to move it to front : ";
	cin>>position;
	intque.moveNthFront(position); //moves element at position to front of the queue
	cout<<"Queue, after moving element at position "<<position<<" to front of the queue : ";
	intque.printQueue();
	cout<<endl;
	cout<<endl;

	return 0;
}


/* output case1:
enter the elements of queue and at end -999 to stop reading the inputs
5 7 8 2 9 10 13 -999
enter the place value of element to move it to front : 4
Queue, after moving element at position 4 to front of the queue : 2 5 7 8 9 10 13

output case2:
enter the elements of queue and at end -999 to stop reading the inputs
9 4 5 10 -99 6 45 -999
9 4 5 10 -99 6 45
enter the place value of element to move it to front : 1
1st element stays in 1st position only, no changes to queue !!
Queue, after moving element at position 1 to front of the queue : 9 4 5 10 -99 6 45
 */




