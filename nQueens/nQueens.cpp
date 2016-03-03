#include<iostream>
#include "nQueenPuzzle.h"

using namespace std;

int main()
{

nQueensPuzzle queen(5);
queen.queensConfiguration(0);
cout<<"No of solutions for 5 queens is : "<<queen.solutionsCount();


	return 0;
}


