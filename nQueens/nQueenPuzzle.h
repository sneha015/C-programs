#include<iostream>
#include<math.h>

using namespace std;

class nQueensPuzzle
{
public:
    nQueensPuzzle(int queens);
 		//constructor
		//Postcondition: noOfSolutions = 0; noOfQueens = queens;
 		//               queensInRow is a pointer to the array 
		//               that store the n-tuple.
		//   If no value is specified for the parameter queens, 
		//   the default value, which is 8, is assigned to it.
    bool canPlaceQueen(int k, int i);
		//Function to determine whether a queen can be placed
 		//in row k and column i.
		//Postcondition: returns true if a queen can be placed in
		//   row k and column i; otherwise it returns false

    void queensConfiguration(int k); 
 		//Function to determine all solutions to the n-queens 
 		//puzzle using backtracking.
 		//The function is called with the value 0.
 		//Postcondition: All n-tuples representing solutions of
 		//   n-queens puzzle are generated and printed.

    void printConfiguration();
		//Function to output an n-tuple containing a solution
 		//to the n-queens puzzle.

    int solutionsCount();
		//Function to return the total number of solutions.
 		//Postcondition: The value of noOfSolution is returned.

private:
    int noOfSolutions;
    int noOfQueens;
    int *queensInRow;
};

nQueensPuzzle::nQueensPuzzle(int queens)
{
	noOfQueens = queens;
	queensInRow = new int[noOfQueens];
	noOfSolutions = 0;
}

bool nQueensPuzzle::canPlaceQueen(int k, int i)
{
	for(int j=0; j<k ; j++)
		if((queensInRow[j] == i) || (abs(j-k) == abs(queensInRow[j]-i)))
			return false;
		return true;
}

void nQueensPuzzle::queensConfiguration(int k)
{
for(int i=0; i< noOfQueens ; i++)
{
	if(canPlaceQueen(k,i))
	{
		queensInRow[k] = i;
	if(k == noOfQueens -1)
		printConfiguration();
	else
		queensConfiguration(k+1);
	}
}
}

void nQueensPuzzle::printConfiguration()
{
	noOfSolutions++;
	cout<<"(";
	for(int n=0; n < noOfQueens-1 ; n++)
	{
		cout<<queensInRow[n]<<", ";
	}
	cout<<queensInRow[noOfQueens-1]<<") \n";
}

int nQueensPuzzle::solutionsCount()
{
return noOfSolutions;
}
