
#include<iostream>
#include<ctype.h>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>


using namespace std;

void exercise1(); //replaces all occurrences of masculine pronouns with gender-neutral pronouns.
void exercise2(); //Tests Rational class
void exercise3(); //splits string based on given delimiter.
vector<string> split(string target, string delimiter);


int main()
{
	exercise1();
	exercise2();
	exercise3();
	return 0;
}


void exercise1()
{
	string input;
    string word; // buffer to extract word from string stream
    int option=1;

    while(true)
    {
    	if(option==2){
    		break;
    	}
    cout<<"Enter a sentence to modify !! \n";

    getline(cin,input); // reads a string from keyboard
    stringstream ss(input); //string streams to extract word

    while (ss>>word)
    {
        if(word=="He" || word=="She")
        {
        	cout<<"She or he";
        }
        else if(word=="he" || word=="she")
        	{
        	cout<<"she or he";
        	}
        else if(word=="his" || word=="her")
            {
            	cout<<"her(s) or his";
            }
        else if(word=="His" || word=="Her")
            {
                cout<<"Her(s) or his";
            }
        else if(word=="him" || word=="her")
            {
                cout<<"her or him";
            }
        else if(word=="Him" || word=="Her")
            {
                cout<<"Her or him";
            }
        else
        {
        	cout<<word; //any other word including special symbols and numbers are printed
        }
        cout<<" ";
    }

    input.clear();
    cout<<"\nDo u want to enter one more sentence ? type \"1\" for yes and \"2\" for no \n";
    cin>>option;
    cin.ignore();
    }
}


// class defines numbers numerator and denominator of a rational number
class Rational
{
public:
	friend Rational add(Rational& number1, Rational& number2); //Adds 2 rational numbers
	friend Rational subtract(Rational& number1, Rational& number2);//returns difference 2 rational numbers
	friend Rational multiply(Rational& number1, Rational& number2);//finds product of 2 rational numbers
	friend Rational division(Rational& number1, Rational& number2);//divides 2 rational numbers
	friend bool equal(const Rational& number1, const Rational& number2);//checks 2 rational numbers are equal
	friend bool less_than(const Rational& number1, const Rational& number2);//check if 1st number is less than second rational number

	int gcd();//Helper function to normalize the rational number

	Rational(int numerator,int denominator); //constructor, checks if the numbers are in valid format and assigns it to rational number

	Rational();

	void input(istream& ins);
	//Precondition: If ins is a file input stream, then ins has already been connected to a file.
	//value of numerator and denominator, has been entered in the input stream ins.
	//Postcondition: The value of the calling object has been set to the numerator and denominator values read from the input stream ins.

	void output(ostream& outs);
	//Precondition: If outs is a file output stream, then outs has already been connected to a file.
	//Postcondition: numerator and denominator of a rational number in the calling object have been sent to the output stream outs.

private:
	int numerator;
	int denominator;
};


Rational::Rational(int number1,int number2)
{
if(number2==0) //If denominator is zero then its illegal
 {
 cout << "Error illegal form for denominator input, division by zero is not possible.\n";
 exit(1);
 }
 numerator=number1;
 denominator=number2;
}

Rational::Rational()
{
	numerator=1;
	denominator=1;
}

int Rational::gcd()
 {
	 int temp,num,deno;
	 num=numerator;
	 deno=denominator;

	 	while(deno!=0)
	 	{
	 		temp = num;
	 		num = deno;
	 		deno = temp % deno;
	 	}

	 	return abs(num);
 }


void Rational::input(istream& ins)
{
int digit1, digit2;
ins >> digit1 >> digit2;
if(digit2==0)
 {
 cout << "Error illegal form for denominator input, division by zero is not possible.\n";
 exit(1);
 }
numerator=digit1;
denominator=digit2;
}

void Rational::output(ostream& outs)
{
	Rational temp;
	int divisor;
	if(denominator==0)
	{
	cout << "Error illegal form for denominator input, division by zero is not possible.\n";
	exit(1);
	}
	if(numerator==0)
	{
	cout << "0 \n";
	}
	else
	{
	temp.numerator=numerator;
	temp.denominator=denominator;
	divisor=temp.gcd();
	temp.numerator = abs(numerator)/divisor;
	temp.denominator = abs(denominator)/divisor;

    if((numerator<0 && denominator<0) || (numerator>0 && denominator>0) )
           outs << temp.numerator << "/" << temp.denominator<<"\n";
    else if((numerator<0 && denominator>0) || (numerator>0 && denominator<0) )
           outs << "-" << temp.numerator << "/" << temp.denominator<<"\n";
	}
 }

 Rational add(Rational& number1, Rational& number2)
 {
	Rational temp_add;
	int divisor;
	temp_add.numerator=(number1.numerator*number2.denominator)+(number2.numerator*number1.denominator);
	temp_add.denominator=(number1.denominator)*(number2.denominator);
	divisor=temp_add.gcd();
	temp_add.numerator=(temp_add.numerator) / divisor;
	temp_add.denominator=(temp_add.denominator) / divisor;

	return temp_add;
 }
 Rational subtract(Rational& number1, Rational& number2)
  {
 	Rational temp;
 	int divisor;
 	temp.numerator=(number1.numerator*number2.denominator)-(number2.numerator*number1.denominator);
 	temp.denominator=number1.denominator*number2.denominator;
 	divisor=temp.gcd();
 	temp.numerator=temp.numerator/divisor;
 	temp.denominator=temp.denominator/divisor;

 	return temp;
  }

 Rational multiply(Rational& number1, Rational& number2)
  {
 	Rational temp;
 	int divisor;
 	temp.numerator=number1.numerator*number2.numerator;
 	temp.denominator=number1.denominator*number2.denominator;
 	divisor=temp.gcd();
 	temp.numerator=temp.numerator/divisor;
 	temp.denominator=temp.denominator/divisor;

 	return temp;
  }

 Rational division(Rational& number1, Rational& number2)
  {
 	Rational temp;
 	int divisor;
 	temp.numerator=number1.numerator*number2.denominator;
 	temp.denominator=number2.numerator*number1.denominator;
 	divisor=temp.gcd();
 	temp.numerator=temp.numerator/divisor;
 	temp.denominator=temp.denominator/divisor;

 	return temp;
  }

bool equal(const Rational& number1, const Rational& number2)
{
	Rational num1,num2;
	int div1,div2;
	num1.numerator=number1.numerator;
	num2.numerator=number2.numerator;
	num1.denominator=number1.denominator;
	num2.denominator=number2.denominator;
	div1=num1.gcd();
	div2=num2.gcd();

	if((num1.numerator*num1.denominator)<0)
	num1.numerator=-1*abs(num1.numerator/div1);
	else
	num1.numerator=num1.numerator/div1;
	num1.denominator=abs(num1.denominator/div1);

	if((num2.numerator*num2.denominator)<0)
	num2.numerator=-1*abs(num2.numerator/div2);
	else
	num2.numerator=num2.numerator/div2;
	num2.denominator=abs(num2.denominator/div2);


	if((num1.numerator==num2.numerator) && (num1.denominator==num2.denominator))
		return true;
	else
		return false;
}

bool less_than(const Rational& number1, const Rational& number2)
{
	Rational num1,num2;
		int div1,div2;
		num1.numerator=number1.numerator;
		num2.numerator=number2.numerator;
		num1.denominator=number1.denominator;
		num2.denominator=number2.denominator;
		div1=num1.gcd();
		div2=num2.gcd();

		if((num1.numerator*num1.denominator)<0)
		num1.numerator=-1*abs(num1.numerator/div1);
		else
		num1.numerator=num1.numerator/div1;
		num1.denominator=abs(num1.denominator/div1);

		if((num2.numerator*num2.denominator)<0)
		num2.numerator=-1*abs(num2.numerator/div2);
		else
		num2.numerator=num2.numerator/div2;
		num2.denominator=abs(num2.denominator/div2);


		if((num1.numerator*num2.denominator) < (num1.denominator*num2.numerator))
			return true;
		else
			return false;
}

void exercise2()
{
       Rational number1, number2(1,4),sum,difference,product,divide;

       cout << "Enter value of numerator and denominator for rational number1 : \n";
       number1.input(cin);
       cout << "The rational number1 is: ";
       number1.output(cout);
       cout << "\n";
       cout << "The rational number2 is: ";
       number2.output(cout);
       cout << "\n";
       cout<<"sum of rational number1 and rational number2 = ";
       sum=add(number1,number2);
       sum.output(cout);
       cout<<"Difference of rational number1 and rational number2 = ";
       difference=subtract(number1,number2);
       difference.output(cout);
       cout<<"product of rational number1 and rational number2 = ";
       product=multiply(number1,number2);
       product.output(cout);
       cout<<"division of rational number1 by rational number2 = ";
       divide=division(number1,number2);
       divide.output(cout);
       if(equal(number1,number2))
    	  cout<<"rational number1 and rational number2 are equal \n";
       else
    	  cout<<"rational number1 and rational number2 are not equal \n";

       if(less_than(number1,number2))
          cout<<"rational number1 is less than rational number2 \n";
       else
          cout<<"rational number1 is not less than rational number2 \n";
}

void exercise3()
{
  string str,dltr;
  cout<<"Enter the string: ";
  getline(cin,str);
  cout<<"Enter the delimiter: ";
  getline(cin,dltr);
  cout<<"\nOutput string : ";
  vector<string> sep = split(str,dltr);

  for(int i = 0; i < sep.size(); ++i)
  {
    cout <<" \""<< sep[i] <<"\"";
  if(i < (sep.size())-1)
	  cout<<",";
  else
	  cout<<".";
  }
}

vector<string> split(string target, string delimiter) {
	std::vector<string> word;
	    size_t start = 0;

	    for(;;)
	    {
	        size_t loc = target.find(delimiter, start);

	        if(loc == string::npos)
	        {
	            word.push_back(&target[start]);
	            break;
	        }

	        word.push_back(target.substr(start, loc - start));
	        start += (loc - start) + delimiter.size();
	    }

	    return (word);
}


/*
 Output for Exercise1:
Enter a sentence to modify !!

He is smart and Intelligent !! His work shows his hardwork and dedication.People appreciate him because of his honesty ..

She or he is smart and Intelligent !! Her(s) or his work shows her(s) or his hardwork and dedication.People appreciate her or him because of her(s) or his honesty ..

Do u want to enter one more sentence ? type "1" for yes and "2" for no

1

Enter a sentence to modify !!

She earns $100,000/anum.

She or he earns $100,000/anum.

Do u want to enter one more sentence ? type "1" for yes and "2" for no

2
 */

/*
 Output for Exercise2:

case1: (with valid inputs)

Enter value of numerator and denominator for rational number1 :
-4
16
The rational number1 is: -1/4

The rational number2 is: -1/4

sum of rational number1 and rational number2 = -1/2
Difference of rational number1 and rational number2 = 0
product of rational number1 and rational number2 = 1/16
division of rational number1 by rational number2 = 1/1
rational number1 and rational number2 are equal
rational number1 is not less than rational number2

case2: (with denominator=0)

Enter value of numerator and denominator for rational number1 :
5
0
Error illegal form for denominator input, division by zero is not possible.
*/

/*
 Output for Exercise3:

 case1:(delimiter space)
 Enter the string: one two three four
 Enter the delimiter:

 Output string :  "one", "two", "three", "four".

 case2: (delimiter ",")
 Enter the string: A,B,C,D,E
 Enter the delimiter: ,

 Output string :  "A", "B", "C", "D", "E".
 */


/*
 Algorithm for Exercise1 :
1.reads a sentence in to a string 'input'.
2.using string stream, the string is read word by word and copied in to a buffer 'word'.
3.it is then compared with he/she/him/his/her and replaced with gender-neutral pronouns as follows:
he/she -> she or he
him/her -> her or him
his/her(s) -> her(s) or his
4.capital letter is taken care of when 1st letter of the sentence is replaced.
He/She -> She or he
Him/Her -> Her or him
His/her(s) -> Her(s) or his
5.all other words including special symbols and numbers are printed as it is without altering.

 Pseudocode for Exercise1:
1.Input a line
2.While (extract a word from the line)
If (word == “he”)
	Output “she or he”
Else if (word == “him” or “his”)
	Output “her or him”
Else
	Output word
…

Algorithm for Exercise2:
1.class Rational for rational numbers is defined with 2 private member variables  numerator and the denominator.
2.constructor with two arguments created to initialize the member variables of an object .
3.public function “input()” takes an argument of type of stream and reads it in to the numerator and denominator member variables.
4.public function “output()”, having an argument of type ostream, will output the simplified rational number with sign in a form 1/2, 15/32, -300/401, and so forth to the output stream.
5.Friend functions add, subtract, multiply, and division returns a Rational object (addition, subtraction,multiplication and division of two rational numbers respectively)
6.Friend functions equal and less_than, with return a bool value, take two const arguments of type Rational& and compares them.
7.Exercise2 is a test function wich checks the correctivity of the class

Pseudocode for Exercise2:
1.input 2 numbers
2.if denominator==0
 illegal operation and exit;
 else
 ins>>numerator>>denominator;
3.output function:
siplified_numerator= numerator/GCD;
siplified_denominator= denominator/GCD;
outs<<siplified_numerator<<siplified_denominator;

Algorithm for Exercise3:
1.function split is implemented which reads a input string ‘target’ returns a vector of the strings in target that are separated by the string delimiter.
2.vector<string> split(string target, string delimiter);
3.example split(“10,20”,30”, “,”) returns a vector with the strings “10”, “20”, “30”.
4.the delimiter can be space or , or any special symbol.

Pseudocode for Exercise3:
1.read input string and delimiter in to string variables
2.location of delimiter:
loc = target.find(delimiter, start);
3.push_back the extracted word to word:
word.push_back(target.substr(start, loc - start));
start += (loc - start) + delimiter.size();
4.increment the starting point for search and go to step 1 till the end of string is reached.

 */

