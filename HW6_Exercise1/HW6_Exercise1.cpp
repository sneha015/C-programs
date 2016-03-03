#include<iostream>

using namespace std;

// sprints * in a given pattern using recursive function print_star
void print_Star(int num)
{
	int i;

	if(num==1) // base case
	{
		cout<<"*\n*\n";
	}
	else
	{
	for(i=0;i<num;i++) // prints * in the decreasing number pattern
	cout<<"*";
	cout<<"\n";
	print_Star((num-1)); // general case , everytime num is reduced by 1 and called recursively till base case
	for(i=0;i<num;i++)// prints after the above function is returned, used to print * in increasing numbers pattern
	cout<<"*";
	cout<<"\n";
	}
}

//Test program to test print_Star function
int main()
{
	int num;
	cout<<"Enter a positive integer to generate the star pattern: ";
	cin>>num;
	cout<<"\n";
	print_Star(num); // calls recursive function to print * in the given pattern of given num size

	return 0;
}

/*
 Algorithm:
 1.main function reads the positiver integer number from user in to variable num and calls print_Star(num) recursive function.
 2.prist_Star(num) reads the integer num, it checks if it is equal to 1(base case) and prints single stars and return to the calling function.
 3.if the num is greater than 1(general case) it prints the "num" number of stars and calls prist_Star(num-1) recursively.
 4.step 2 and 3 is repeated till num becomes equal to 1 and executes base case
 5.after returning from the base case it continues with next instrucion to print stars in the reverse order

 */

/* output:
 Enter a positive integer to generate the star pattern: 5

 *****
 ****
 ***
 **
 *
 *
 **
 ***
 ****
 *****

output case2:

Enter a positive integer to generate the star pattern: 10

**********
*********
********
*******
******
*****
****
***
**
*
*
**
***
****
*****
******
*******
********
*********
**********

*/

