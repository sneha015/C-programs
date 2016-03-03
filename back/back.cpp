#include<iostream>
#include<string>

using namespace std;

int vowels(string str , int i, int count)
{
	if(i>= str.length())
	{
		return count;
	}else
	{
		if(str[i] == 'A' || str[i] == 'a' || str[i] == 'e' || str[i] == 'E' || str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O'
				|| str[i] == 'u' || str[i] == 'U')
		count++;
		return vowels(str, i+1 , count);
	}
}
int main()
{

	string str="i love loki";
	cout<<str<<"\n";
	cout<< vowels(str,0,0);







	for(int i=0; i<5; i++)
	{
		int j=i, k=(5-i)-2;
		while(k>=0)
		{
		cout<<" ";
		k--;
		}
		while(j>=0)
		{
		cout<<" "<<i;
		j--;
		}
		cout<<"\n";
	}

	return 0;
}
