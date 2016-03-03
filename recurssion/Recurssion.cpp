/*
 * Recurssion.cpp
 *
 *  Created on: Jul 11, 2015
 *      Author: lokisneha
 */
#include<iostream>
#include<math.h>
using namespace std;

int multiply(int m, int n)
{
	if(m <= 0)
		return 0;
	else
	if(m == 1)
		return n;
	else
		return ( n + multiply(m-1,n));
}

void reverseArray( int intArray[], int low, int high, int length)
{
	int temp;
	if(0<=low && low < length && 0 <= high  && high < length && low < high)
	{
		temp = intArray[low];
		intArray[low] = intArray[high];
		intArray[high] = temp;
		reverseArray( intArray , low+1, high-1, length);
	}
}


int largest(const int a[], int lowerIndex, int upperIndex) // array, lower index, upper index
{
	int max;
	if (lowerIndex == upperIndex)
		return a[lowerIndex];
	else
	{
		max = largest(a, lowerIndex+1, upperIndex);
		if(a[lowerIndex] >= max)
			return a[lowerIndex];
		else
			return max;
	}
}

int factorial(int n)
{
	if(n==0)
		return 1;
	else
		return (n * factorial(n-1));
}

int fib(int a, int b , int n) // nth fibonacci number
{
	if(n==1)
		return a;
	else if(n==2)
		return b;
	else
		return ( fib(a,b,n-1) + fib(a,b,n-2));
}

void decToBin(int num, int base) // decimal to binary conversion
{
	if(num>0)
	{
		decToBin(num/base,base);
		cout<<num%base;
	}
}

int main()
{
	int intArray[10]={3,5,1,0,-2,7,4,9,-3,6};
	int length=10;
	int a[10]={5,4,2,7,9,1,10,11,1,6};
	int num=5,num1, num2, pos , dec , base=2;
	int m=4, n=5;
	cout<<"4 * 5 = "<<multiply(m,n);
	for(int i=0;i<length;i++)
		cout<<intArray[i]<<" ";
	cout<<"\n";
	reverseArray(intArray,1,7,length);
	for(int i=0;i<length;i++)
		cout<<intArray[i]<<" ";
	cout<<"\n";
	cout<<"largest element in array is : " << largest(a,0,10);
	cout<<"\nFactorial of "<< num <<" is: "<< factorial(num) ;
	cout<<"\nenter the 1st number of fibonacci series :" ;
	cin>>num1;
	cout<<"\nenter the 2nd number of fibonacci series :" ;
	cin>>num2;
	cout<<"\nenter the position to print number in that position in fibonacci series :" ;
	cin>>pos;
    cout<<"\nthe "<<pos<<"th fibonacci cumber is: "<< fib(num1,num2,pos);
    cout<<"\nEnter a decimal number to convert it to binary : ";
    cin>>dec;
    cout<<"the binary conversion of the deecimal number "<<dec<<" is : ";
    decToBin(dec,base);
	return 0;
}


