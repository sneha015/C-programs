#include<iostream>
#include<string>
#include<ctype.h>
#include<stack>
#include<queue>

using namespace std;

//recursive function to check if the given string is a palindrome.two index front and back points to 1st and last character
// of the string and compares if it is equal
bool palindrome(string str, int front, int back)
{
	if(front >= back) // base case, both the index reached middle of the string
		return true;
	else
	{
		if(str[front]==' ') // to ignore the space and advance front if the character is space
		{
			front = front +1;
		}
		if(str[back]==' ') // to ignore the space
		{
			back = back -1;
		}
	if(tolower(str[front]) != tolower(str[back])) // if if the front and corresponding back character do no match its not a palindrome
		return false;
	return palindrome( str, front+1, back-1);// general case, recursively sends front+1 and back-1 index for comparison till the middle of the string is reached
	}
}

void pali(string str)
{
	stack<char> stk;
	queue<char> qu;
	for(int i=0; i<str.length(); i++)
	{
		if(str[i] != ' ')
		{
		stk.push(tolower(str[i]));
		qu.push(tolower(str[i]));
		}
	}
	while(!stk.empty() && !qu.empty())
	{
		if(qu.front()== stk.top())
		{
			qu.pop();
			stk.pop();
		}
		else
		{
			cout<<"not palindrome \n";
			break;
		}
	}
	cout<<"palindrome !! \n";
}

// Test program to test recursive function palindrome.
int main()
{
	string str;
	cout<<"Enter the string to check if it is palindrome : ";
	getline(cin,str);
	cout<<"\n";

	pali(str);
	/*if(palindrome(str, 0 , (str.length()-1)))// sends string, starting index and last index of the string
		cout<<str<<" is a palindrome !!";
	else
		cout<<str<<" is not a palindrome !!";*/

	return 0;
}

/* Algorithm & pseudocode:
 1.main function reads a string from user and checks if it’s a palindrome by recursive function
 2.recursive function palindrome take string and two index front and back points to 1st and last character as parameters
 3.Base case check the front and back index of the string if it is equal, which means both the index have reached middle of the string and returns true.
 4.general case compares the characters at both the respective index if it is equal then recursively calls palindrome function by advancing both the index towards center.
 5.steps 3 and 4 are called till base care is reached or till step 6
 6.if the characters at front and back indexes are not equal then returns false and exits.
 7.it also checks between upper case and lower case characters by converting them to lower case.

 */

/* output case1:
Enter the string to check if it is palindrome : MadAm

MadAm is a palindrome !!

output case2:
Enter the string to check if it is palindrome : Compe

Compe is not a palindrome !!

output case3:(with space in between)
Enter the string to check if it is palindrome : MADAM IM ADAM

MADAM IM ADAM is a palindrome !!

 */
