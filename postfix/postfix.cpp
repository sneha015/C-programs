#include<iostream>
#include<string>
#include"infixToPostfix.h"

using namespace std;

int main()
{
	string str;
	str="((A+B)/C)+D";
	postfix ITP(str);
	ITP.showInfix();
	ITP.convertToPostfix();
	ITP.showPostfix();

	cout<<endl;
	cout<<endl;
	cout<<endl;
	return 0;
}


