#include<iostream>
#include<stack>

using namespace std;

int main()
{
	stack<int> stack;
    int num, base=2;

    cout<<"Enter the positive decimal number to find binary equivalent : ";
    cin>>num; // reads decimal number from user
    cout<<endl;

    cout<<"Binary equivalent of "<<num<< " is: ";

    while(num>1)
    {
    stack.push(num%base); //pushes the binary digit, remainder to the stack
    num = num/base; // divides the number further by base and continues till num is <=1
    }
    stack.push(num); //pushes num when it becomes less than or equal to 1

    // prints the stack, the binary equivalent
    while(!stack.empty()) // prints till bottom of stack is reached.
    {
    	cout<<stack.top(); // prints top of the stack
    	stack.pop(); // deletes top element
    }
    cout<<endl;


    return 0;
}

/* algorithm:
 1.reads the positive decimal number from user in to variable num to convert it to bin
 2.it declares stack of type stack(lib <stack> is included)
 3.the number is divided by base and the reminder is pushed on to stack
 4. step 3 is repeated till  the number is less than or equal to 1
 5.the stack is then printed out which is binary equivalent of the decimal number "num".
 */

/* output case1:
 Enter the decimal number to find binary equivalent :13

 Binary equivalent of 13 is: 1101

 output case2:
 Enter the positive decimal number to find binary equivalent : 200

 Binary equivalent of 200 is: 11001000

 */
