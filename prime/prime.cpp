/*
 * prime.cpp
 *
 *  Created on: Jul 27, 2015
 *      Author: lokisneha
 */
#include<iostream>
#include<math.h>
#include<stack>
using namespace std;

void primeFactors(int n, stack<int>& stk)
{
//	stack<int> stk;
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
       // cout<< 2 <<" ";
        stk.push(2);
        n = n/2;
    }

    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
          //  cout<<i<<" ";
        	stk.push(i);
            n = n/i;
        }
    }

    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2)
       //cout<<n<<" ";
    	stk.push(n);
}

/* Driver program to test above function */
int main()
{
    int n = 420;
    stack<int> stk;
    primeFactors(n , stk);
    while(!stk.empty())
    {
    	cout<<stk.top()<<" ";
    	stk.pop();
    }
    return 0;
}


