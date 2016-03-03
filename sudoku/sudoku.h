#include<iostream>
#include<iomanip>

using namespace std;

class sudoku
{
public:
    sudoku();
      //default constructor
      //Postcondition: grid is initialized to 0

    sudoku(int g[][9]);
      //constructor
      //Postcondition: grid = g

    void initializeSudokuGrid();
      //Function to promt the user to specify the numbers of the
      //partially filled grid.
      //Postcondition: grid is initialized to the numbers 
      //    specified by the user.

    void initializeSudokuGrid(int g[][9]);
      //Function to initialize grid to g
      //Postcondition: grid = g;

    void printSudokuGrid();
      //Function to print the sudoku grid.

    bool solveSudoku();
      //Funtion to solve the sudoku problem.
      //Postcondition: If a solution exits, it returns true,
      //    otherwise it returns false.
    bool findEmptyGridSlot(int &row, int &col);
      //Function to determine if the grid slot specified by 
      //row and col is empty.
      //Postcondition: Returns true if grid[row][col] = 0;

    bool canPlaceNum(int row, int col, int num);
      //Function to determine if num can be placed in 
      //grid[row][col]
      //Postcondition: Returns true if num can be placed in
      //    grid[row][col], otherwise it returns false.

    bool numAlreadyInRow(int row, int num);
      //Function to determine if num is in grid[row][]
      //Postcondition: Returns true if num is in grid[row][],
      //    otherwise it returns false.

    bool numAlreadyInCol(int col, int num);
      //Function to determine if num is in grid[row][]
      //Postcondition: Returns true if num is in grid[row][],
      //    otherwise it returns false.

    bool numAlreadyInBox(int smallGridRow, int smallGridCol, 
                         int num);
      //Function to determine if num is in the small grid
      //Postcondition: Returns true if num is in small grid,
      //    otherwise it returns false.

private:
    int grid[9][9];
};
sudoku::sudoku()
{
    for(int i=0; i<9; i++)
    	for(int j=0; j<9; j++)
    		grid[i][j]=0;
}

sudoku::sudoku(int g[][9])
{
	for(int i=0; i<9; i++)
	    	for(int j=0; j<9; j++)
	    		grid[i][j]=g[i][j];
}

void sudoku::initializeSudokuGrid()
{
	int row, col,digit;
    cout << "Enter row, column and the digit to fill the grid";
    cin>>row>>col>>digit;
    grid[row][col]=digit ;
}

void sudoku::initializeSudokuGrid(int g[][9])
{
	for(int i=0; i<9; i++)
		for(int j=0; j<9; j++)
		    grid[i][j]=g[i][j];
}

void sudoku::printSudokuGrid()
{
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			cout<<setw(4)<<grid[i][j];
		}
		cout<<"\n";
	}
}

bool sudoku::solveSudoku()
{
    int row, col;

    if (findEmptyGridSlot(row, col))
    {
        for (int num = 1; num <= 9; num++)
        {
            if (canPlaceNum(row, col, num))
            {
                grid[row][col] = num;
                if (solveSudoku()) //recursive call
                    return true;
                grid[row][col] = 0; //backtrack
            }
        }
        return false;
    }
    else
        return true; //there are no empty slots
}

bool sudoku::findEmptyGridSlot(int &row, int &col)
{
	for(row=0; row<9; row++)
	{
		for(col=0; col<9; col++)
		{
			if( grid[row][col]== 0)
				return true;
		}
	}
	return false;
}

bool sudoku::canPlaceNum(int row, int col, int num)
{
    if(numAlreadyInRow(row, num) || numAlreadyInCol(col, num) || numAlreadyInBox(row-row%3, col-col%3,num) )
    	return false;
    else
    	return true;
}

bool sudoku::numAlreadyInRow(int row, int num)
{
   for(int column =0; column<9; column++)
   {
	   if(grid[row][column]==num)
		   return true;
   }
   return false;
}

bool sudoku::numAlreadyInCol(int col, int num)
{
	 for(int row =0; row<9; row++)
	   {
		   if(grid[row][col]==num)
			   return true;
	   }
	   return false;
}

bool sudoku::numAlreadyInBox(int smallGridRow, int smallGridCol,
                             int num)
{
   for(int i=smallGridRow; i< smallGridRow+3; i++)
   {
	   for(int j =smallGridCol; j< smallGridCol+3; j++)
	   {
		   if(grid[i][j] == num)
			   return true;
	   }
   }
   return false;
}







