#include<iostream>
#include<sstream>
#include<string>
#include<ctype.h>

using namespace std;

int main()
{
	string str, word;

	cout<<"enter the sentence: \n";
	getline(cin,str);
	stringstream ss(str);

	int count=0;
	while(ss>>word)
	{
		count++;
		cout<<count<<". "<<word<<"\n";
	}

	return 0;
}
