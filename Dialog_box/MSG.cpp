#include <iostream>
#include<string>
using namespace std;

template <class Type>
Type funcExp(Type list[], int size)
{
Type x = list[0];
Type y = list[size - 1];
    for (int j = 1; j < (size - 1)/2; j++)
{
if (x < list[j])
x = list[j];
if (y > list[size - 1 -j])
y = list[size - 1 -j]; return x + y;
}
}

int main()
{
	int list[10] = {5,3,2,10,4,19,45,13,61,11};
	string strList[] = {"One", "Hello", "Four", "Three", "How", "Six"};
	cout << funcExp(list, 10) << endl;
	cout << funcExp(strList, 6) << endl;

	return 0;
}
