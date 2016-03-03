/*
 * hw7.cpp
 *
 *  Created on: Jul 26, 2015
 *      Author: lokisneha
 */

#include<iostream>
#include "queueAsArray.h"

using namespace std;

int main()
{
	queueType<int> intque(80),cpyque;

	intque.addQueue(10);
	intque.addQueue(20);
	intque.addQueue(30);
	intque.addQueue(40);
	intque.addQueue(50);
	intque.addQueue(60);
	intque.deleteQueue();
	intque.addQueue(70);
	intque.addQueue(80);

	cpyque = intque;
	cout<<"queue: ";
	while(!cpyque.isEmptyQueue())
		{
			cout<<cpyque.front()<<" ";
			cpyque.deleteQueue();
		}
	cout<<endl;

	intque.moveNthFront(3);
	cpyque = intque;
	cout<<"Queue, after moving 3rd element to frist : ";
	while(!cpyque.isEmptyQueue())
	{
		cout<<cpyque.front()<<" ";
		cpyque.deleteQueue();
	}
	cout<<endl;
	cout<<endl;

	return 0;
}







