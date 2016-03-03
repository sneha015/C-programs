#include<iostream>
#include "knightsTourTrace.h"

using namespace std;

//test program to check the knightsTourTrace program
int main()
{
	knightsTour kT(5);// initializes board size
	kT.boardTrace();

	return 0;
}

/* output: board size 6x6

   1  22   3   8  11  24
   4   7  12  23  18   9
  21   2   5  10  25  36
   6  13  32  19  28  17
  33  20  15  30  35  26
  14  31  34  27  16  29

  output: board size 5x5

   1  10   3  16  21
   4  15  20  11   6
   9   2   5  22  17
  14  19  24   7  12
  25   8  13  18  23

*/


