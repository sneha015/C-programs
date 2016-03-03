#include<iostream>
#include<math.h>

using namespace std;

void print_a_sentence(); //prints a sentence
void square_of_integer(); //outputs square of an integer
void addition(); //calls overloaded functions to add different type arguments
void prime(); //Determines if K is prime
void add(char *array1,int size1,char *array2, int size2);
void add(int number1,int number2);
void add(double number1,double number2);

int main(){

	print_a_sentence();
	square_of_integer();
	addition();
	prime();
	return 0;
}

void print_a_sentence()
{

	cout<<"A fool thinks himself to be wise, but a wise man knows himself to be a fool.\n";
}

void square_of_integer()
{
	int x;
	cout<<"enter an integer number to square\n";
	cin>>x;
	cout<<pow(x,2)<<"\n";
}

void addition()
{
	cout<<"1. add two integers\n"<<"2. add two double\n"<<"3. add two character arrays\n";
	cout<<"enter the option (1/2/3)\n";
	int option;
	cin>>option;
	switch (option)
	{
	case 1:
	    {
		int num1,num2;
		cout<<"Enter two integer numbers\n";
		cin>>num1>>num2;
		add(num1,num2);
	    }
	    break;
	case 2:
	    {
		double num1,num2;
	    cout<<"Enter two floating point numbers\n";
		cin>>num1>>num2;
		add(num1,num2);
	    }
	    break;
	case 3:
	    {
		char array1[100],array2[100];
		int size1,size2,i,j;
		cout<<"Enter the size of the array1 less than 100\n";
		cin>>size1;
		cout<<"Enter the elements of 1st character array\n";
		for(i=0;i<size1;i++)
		{
			cin>>array1[i];
		}
		cout<<"Enter the size of the array2 less than 100\n";
		cin>>size2;
		cout<<"Enter the elements of 2nd character array\n";
		for(j=0;j<size2;j++)
		{
		cin>>array2[j];
		}
		add(array1,size1,array2,size2);
	    }
	    break;
	default : cout<<"Invalid option!! \n";
	}

}

void add(char *array1,int size1,char *array2,int size2)
{
	//int i,j;
	//for(i=0;i<size1;i++)
	//{
	//cout<<array1[i]<<" ";
	//}
	//for(j=0;j<size2;j++)
	//{
	//cout<<array2[j]<<" ";
	//}
	cout<<array1<<array2<<"\n";
}

void add(int number1,int number2)
{
	int sum;
	sum=number1+number2;
	cout<<sum<<"\n";;
}

void add(double number1,double number2)
{
	double sum;
	sum=number1+number2;
	cout<<sum<<"\n";
}

void prime()
{
	int i,k,j,n;
	bool is_prime=true;

	cout<<"enter an integer number \n";
	cin>>k;

	if(k==2||k==3)
	{
		cout<<k<<" is prime. \n";
	}
	else
	{
		for(j=3;j<=k;j++)
		{
			n=j;
			for(i=2;i<=n-1;i++)
			{
				if(n%i==0)
				{
				   is_prime=false;
				   break;
				}
			}
			if(is_prime)
			{
				cout<<n<<"\n";
			}
			else
			{
				is_prime=true;
			}
		}
	}
}

/* Test output for the function print_a_sentence:
 * A fool thinks himself to be wise, but a wise man knows himself to be a fool.
 *
 *
 * Test output for the function square_of_integer:
 * enter an integer number to square
 * 625
 * 390625
 *
 *
 * Test output for function addition : (case 1.Add integers) :
 * 1. add two integers
 * 2. add two double
 * 3. add two character arrays
 * enter the option (1/2/3)
 * 1
 * Enter two integer numbers
 * 245
 * -4
 * 241
 *
 *
 * Test output for function addition : (case 2.Add double numbers) :
 * 1. add two integers
 * 2. add two double
 * 3. add two character arrays
 * enter the option (1/2/3)
 * 2
 * Enter two floating point numbers
 * 12.045
 * 9876.2
 * 9888.25
 *
 *
 * Test output for function addition : (case 3.Add char arrays) :
 * 1. add two integers
 * 2. add two double
 * 3. add two character arrays
 * enter the option (1/2/3)
 * 3
 * Enter the size of the array1 less than 100
 * 5
 * Enter the elements of 1st character array
 * 2
 * 5
 * 8
 * 0
 * 3
 * Enter the size of the array2 less than 100
 * 8
 * Enter the elements of 2nd character array
 * 1
 * 3
 * 6
 * 3
 * 8
 * 6
 * 1
 * 4
 * 2 5 8 0 3 1 3 6 3 8 6 1 4
 *
 *
 * Test output for function prime:
 * enter an integer number
 * 25
 * 3
 * 5
 * 7
 * 11
 * 13
 * 17
 * 19
 * 23
 */




