#include<iostream>
#include<string>
#include<ctype.h>
#include<stack>

using namespace std;

class postfix
{
public:
	postfix(string& str);
	//constructor
	void getInfix(string& str);
	//Stores the infix expression
	void showInfix();
	//Outputs the infix expression
	void showPostfix();
	//Outputs the postfix expression
	void convertToPostfix();
	//Converts the infix expression into a postfix expression.
	//The resulting postfix expression is stored in pfx.
	bool precedence(char sym1, char sym2);
	//Determines the precedence between two operators.
	//If the first operator is of higher or equal precedence than the second operator,
	//it returns the value true; otherwise, it returns the value false.
private:
	string infix;
	string post;
	int length;
};

postfix::postfix(string& str)
{
	infix = str;
	length = str.length();
	post=str;
	for(int i=0;i<length;i++)
		post[i]=' ';
}
void postfix::getInfix(string& str)
{
	str = infix;
}
void postfix::showInfix()
{
	cout<<infix;
	cout<<endl;
}
void postfix::showPostfix()
{
	cout<<post;
	cout<<endl;
}
bool postfix::precedence(char sym1, char sym2)
{
	int s1=0,s2=0;
	if(sym1 == '(')
	{
		s1=0;
	}else
	if(sym1 == '*' || sym1 == '/')
	{
		s1=2;
	}else
	if(sym1 == '+' || sym1 == '-')
	{
		s1=1;
	}

	if(sym2 == '(')
	{
		s2=0;
	}else
	if(sym2 == '*' || sym2 == '/')
	{
		s2=2;
	}else
	if(sym2 == '+' || sym2 == '-')
	{
		s2=1;
	}

	if(s1>=s2)
		return true;
	else
		return false;
}

void postfix::convertToPostfix()
{
	stack<char> symStack;
	int j=0;
	int i=0;

while(i<length)
   {
		if(infix[i]=='A' || infix[i]=='B' || infix[i]=='C' || infix[i]=='D' || infix[i]=='E' || infix[i]=='F' || infix[i]=='G' || infix[i]=='H' || infix[i]=='I' || infix[i]=='J' || infix[i]==' ')
		    {
			post[j]= infix[i];
			j++;
			i++;
		    }
		else if(infix[i]=='*' || infix[i]=='+' || infix[i]=='/' || infix[i]=='-')
			{
				if(!symStack.empty())
				{
					if(precedence(infix[i],symStack.top()))
					{
						symStack.push(infix[i]);
						i++;
					}
					else
					{
						post[j]= symStack.top();
						j++;
						symStack.pop();
						symStack.push(infix[i]);
						i++;
					}
				}else
				{
					symStack.push(infix[i]);
					i++;
				}

			}
		else if(infix[i] == '(')
		   {
			symStack.push(infix[i]);
			i++;
		   }
		else if(infix[i]==')')
			{
				i++;
				while(symStack.top() != '(')
				{
					post[j]=symStack.top();
					j++;
					symStack.pop();
				}
				symStack.pop();
			}
   }
    while(!symStack.empty())
	{
    	post[j]=symStack.top();
		j++;
		symStack.pop();
	}

}




