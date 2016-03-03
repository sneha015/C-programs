#include<iostream>
#include<iomanip>

using namespace std;

class knightsTour
{
public:
	void printTour();
	//prints the board on the screen
	knightsTour(int n);
	//constructor which initializes the board size NxN (N=n) and initializes dynamic two dimension array board.
	bool moveLegal(int row,int col);
	//checks if the Knight's move is legal, if there are any entry already and if it is within the board
	bool boardTrace();
	//knight traverses board and enters the step number (move) when it lands on a cell and covers all the cells in the board
	//returns true if it can traverse complete board or false if it cant reach all the cells
	bool knightsPath(int row, int col, int move,int rowAdd[8], int colAdd[8]);
	//returns true if it can find the path for every move of the knight by recursively trying all the paths if
	//the knight dont have any move,it returns false.

private:
	int N;
	int **board;
};

//constructor
knightsTour::knightsTour(int n)
{
	N = n;
	for (int row = 0; row < n; row++)
		board[row] = new int[n];
}

//checks if the knights move is withing board range and if there is no entry already
bool knightsTour::moveLegal(int row,int col)
{
	if(row>=0 && row<N && col>=0 && col<N && (board[row][col] == -1))
		return true;
	else
		return false;
}

//prints the board
void knightsTour::printTour()
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cout<<setw(4)<<board[i][j];
		}
		cout<<"\n";
	}
}

bool knightsTour::boardTrace()
{
	int move;

	//8 possible moves of the knight, pattern array row and columns respectively
	int rowAdd[8]={-2,-2,-1,-1,1,1,2,2};
	int colAdd[8]={-1,1,-2,2,-2,2,-1,1};

	//initializes the board cells to -1 which is empty
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
			board[i][j]= -1;
	}

	move=1; //knight starts here leaving , 1st move
	board[0][0]=move; //move entry on to the cell

	//find the knights path sends row and column of knights current cell,with next move count, knights movement pattern array row and column
	if(knightsPath(0, 0, move+1, rowAdd, colAdd))
	{
		printTour();
		return true;
	}else
	{
		cout<<"There is no solution!! \n";
		return false;
	}


}

bool knightsTour::knightsPath(int row, int col, int move, int colAdd[8], int rowAdd[8])
{
	int nextRow, nextCol;

	//if all the cells are successfully traversed by knight and filled then return true
	if(move-1 == N*N)
	{
		return true;
	}

	for(int i=0; i<8; i++) // i specifies one of the 8 possible movements of knight
	{
		nextRow = row + rowAdd[i];
		nextCol = col + colAdd[i];

		if(moveLegal(nextRow, nextCol)) //if the move is legal proceed
		{
			board[nextRow][nextCol]= move; //marks the cell with move count

			//recursively calls knightsPath till all the cells are traversed or till there is no legal move available
			if(knightsPath(nextRow, nextCol, move+1, rowAdd, colAdd))
			return true;
			else
			board[nextRow][nextCol]= -1; // go back to previous movement by assigning the present cell back to -1
		}
	}
	return false;
}
