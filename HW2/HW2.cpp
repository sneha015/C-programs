#include<iostream>
#include<fstream>

using namespace std;

void exercise1();
void exercise2();
void exercise3();

int main(){

	exercise1();
	exercise2();
	exercise3();
	return 0;
}

void exercise1()
{
	char ch,array1[10];
	int size=1,i;
	cout<<"Enter the character string to print in reverse order, end it with \".\" :\n";
	cin>>ch;
	while(ch!='.' && size<10)
	{
		array1[size]=ch;
		size++;
		cin>>ch;
	}
	if(size>=10)
	{
		array1[size]=ch;
		cout<<"string length exceeded array size, only 1st 10 characters \"";
		for(i=0;i<=size;i++)
		{
			cout<<array1[i];
		}
		cout<<"\" will be reversed !!\n";
	}
	if(size>1)
	{
		cout<<"The reverse of the input string is: ";
		for(i=size;i>=0;i--)
		{
			cout<<array1[i];
		}
		cout<<"\n";
	}
	else
	{
		cout<<"No string to print!! \n";
	}
}

void exercise2()
{
	double value[2][8], overall;
	int i,j;
	string filename;

	//take the HW Assignment and Lab exam scores of the student:
	cout <<"Please enter five HW Assignments scores [0 – 100]: \n";
	for(i=0;i<5;i++)
	{
		cin>>value[0][i];
	}
	cout <<"Please enter five Lab Exam scores [0 – 100]: \n";
	for(i=0;i<5;i++)
	{
		cin>>value[1][i];
	}


	//best score value[x][5], worst score value[x][6] and average score value[x][7] calculation:
	//let us assume 1st score of HW and exam to be the best, worst and average score,and compare it with other scores and swap accordingly.
	value[0][5]=value[0][0];  //best score HW
	value[0][6]=value[0][0];  //worst score HW
	value[0][7]=value[0][0];  //average score HW
	value[1][5]=value[1][0];  //best score exam
	value[1][6]=value[1][0];  //worst score exam
	value[1][7]=value[1][0];  //average score exam
	for(i=0;i<2;i++)
	{
		for(j=1;j<5;j++)
		{
			if(value[i][5]<value[i][j]) //best score
			{
				value[i][5]=value[i][j];
			}
			if(value[i][6]>value[i][j]) //worst score
			{
				value[i][6]=value[i][j];
			}
			value[i][7]+=value[i][j]; //total score
		}
		value[i][7]=value[i][7]/5; //average score

	}
	overall=(value[0][7]+value[1][7])/2; // overall average of HW and exam scores


	cout<<"  \t1\t2\t3\t4\t5 \n";
	cout<<"\t************************************\n";
	cout<<"HW\t"<<value[0][0]<<"\t"<<value[0][1]<<"\t"<<value[0][2]<<"\t"<<value[0][3]<<"\t"<<value[0][4]<<"\t"<<"BEST HW: "<<value[0][5]<<"  WORST HW: "<<value[0][6]<<"  average HW: "<<value[0][7]<<"\n";
	cout<<"LAB\t"<<value[1][0]<<"\t"<<value[1][1]<<"\t"<<value[1][2]<<"\t"<<value[1][3]<<"\t"<<value[1][4]<<"\t"<<"BEST HW: "<<value[1][5]<<"  WORST HW: "<<value[1][6]<<"  average HW: "<<value[1][7]<<"\n\n";
	cout<<"AVG\t"<<(value[0][0]+value[1][0])/2<<"\t"<<(value[0][1]+value[1][1])/2<<"\t"<<(value[0][2]+value[1][2])/2<<"\t"<<(value[0][3]+value[1][3])/2<<"\t"<<(value[0][4]+value[1][4])/2<<"\t"<<"Overall: "<<overall<<"\n\n";

	if(value[0][7]>50 && value[1][7]>50)
	{
	cout<<" Congratulations! You passed the class! \n\n";
	}
	else if(value[0][7]<50)
	{
	cout<<"I’m sorry to inform you that you failed the class, because your performance in HW Assignment was <50%. Try again next semester. \n\n";
	}
	else
	{
	cout<<"I’m sorry to inform you that you failed the class, because your performance in the Lab Exam was <50%. Try again next semester. \n\n";
	}

	//write the output to the file :
	cout<<"Enter the file name to write the output in to file: \n";
	cin>>filename;
	ofstream myfile(filename);
	  if (myfile.is_open())
	  {
	    myfile<<"  \t1\t2\t3\t4\t5 \n";
	    myfile<<"\t************************************\n";
	    myfile<<"HW\t"<<value[0][0]<<"\t"<<value[0][1]<<"\t"<<value[0][2]<<"\t"<<value[0][3]<<"\t"<<value[0][4]<<"\t"<<"BEST HW: "<<value[0][5]<<"  WORST HW: "<<value[0][6]<<"  average HW: "<<value[0][7]<<"\n";
	    myfile<<"LAB\t"<<value[1][0]<<"\t"<<value[1][1]<<"\t"<<value[1][2]<<"\t"<<value[1][3]<<"\t"<<value[1][4]<<"\t"<<"BEST HW: "<<value[1][5]<<"  WORST HW: "<<value[1][6]<<"  average HW: "<<value[1][7]<<"\n\n";
	    myfile<<"AVG\t"<<(value[0][0]+value[1][0])/2<<"\t"<<(value[0][1]+value[1][1])/2<<"\t"<<(value[0][2]+value[1][2])/2<<"\t"<<(value[0][3]+value[1][3])/2<<"\t"<<(value[0][4]+value[1][4])/2<<"\t"<<"Overall: "<<overall<<"\n\n";
	    if(value[0][7]>50 && value[1][7]>50)
	    	{
	    	myfile<<" Congratulations! You passed the class! \n";
	    	}
	    	else if(value[0][7]<50)
	    	{
	    	myfile<<"I’m sorry to inform you that you failed the class, because your performance in HW Assignment was <50%. Try again next semester. \n";
	    	}
	    	else
	    	{
	    	myfile<<"I’m sorry to inform you that you failed the class, because your performance in the Lab Exam was <50%. Try again next semester. \n";
	    	}
	    cout<<"Output Successfully written to the file! \n";
	    myfile.close();
	  }
	  else cout<< "Unable to open file";

}


void exercise3()
{
	int array[50],option,size=0,i,j,n=0,max,temp,count=1;
	string filename;

	cout<<"To enter the elements of array from console select 1/ from file select 2 \n";
	cin>>option;
	if(option==1) // reads integers from console in to the array
	{
		cout<<"enter the size of an array less than 50 \n";
		cin>>size;
		cout<<"enter the elements of array \n";
		for(i=0;i<size;i++)
		{
			cin>>array[i];
		}
	}
	else // reads integers from file in to array.
	{
		cout<<"enter the file name to read integers in to an array \n";
		cin>>filename;
		ifstream inputfile;
		inputfile.open(filename);
		if(inputfile.is_open())
		{
			while(!inputfile.eof())
			{
				inputfile>>array[n];
				n++;
			}
			size=n;
			inputfile.close();
			cout<<"The array elements read from file are : ";
			for(i=0;i<size;i++)
			{
				cout<<array[i]<<"  ";
			}
			cout<<"\n\n";
		}
		else cout<< "No such file found!!";
	}

	//sort the array in the descending order
	for(i=0;i<size;i++)
	{
		max=i;
		for(j=i+1;j<size;j++)
		{
			if(array[j]>array[max])
				max=j;
		}
		if(max!=i)
		{
		temp=array[i];
		array[i]=array[max];
		array[max]=temp;
		}
	}


	//printing output to the console
	if(size!=0)
	{
	cout<<"  \tN\tCount\n";
	for(i=0;i<size;i++)
	{
		if(array[i]==array[i+1])
		{
			count++;
		}
		else
		{
			cout<<"  \t"<<array[i]<<"\t "<<count<<"\n";
			count=1;
		}
	}

	cout<<"Enter the file name to write the output in to file: \n";
	cin>>filename;
	ofstream myfile(filename);
	if (myfile.is_open())
	{
		myfile<<"  \tN\tCount\n";
			for(i=0;i<size;i++)
			{
				if(array[i]==array[i+1])
				{
					count++;
				}
				else
				{
					myfile<<"  \t"<<array[i]<<"\t "<<count<<"\n";
					count=1;
				}
			}
		cout<<"Output Successfully written to the file! \n";
		myfile.close();
    }
    else cout<< "Unable to open file";
	}

}

/*
 Exercise1 output:

 case 1: (when string ended with ".")
 Enter the character string to print in reverse order, end it with "." :
 abcdef.
 The reverse of the input string is:  fedcba 

 case 2: (when string length exceeds array size)
 Enter the character string to print in reverse order, end it with "." :
 abcdhgjkdsjdhfhfhdjshfjsh
 string length exceeded array size, only 1st 10 characters " abcdhgjkds" will be reversed !!
 The reverse of the input string is: sdkjghdcba 

 case 3: (when invalid input is given say jus "." is given)
 Enter the character string to print in reverse order, end it with "." :
 .
 No string to print!!
 */

/*
 Exercise2 output:

 case1: (student passed the class )
 Please enter five HW Assignments scores [0 – 100]:
100
90
70
40
68
Please enter five Lab Exam scores [0 – 100]:
35
90
70
85
55
  	1	2	3	4	5
	************************************
HW	100	90	70	40	68	BEST HW: 100  WORST HW: 40  average HW: 73.6
LAB	35	90	70	85	55	BEST HW: 90  WORST HW: 35  average HW: 67

AVG	67.5	90	70	62.5	61.5	Overall: 70.3

 Congratulations! You passed the class!

Enter the file name to write the output in to file:
case1.txt
Output Successfully written to the file!

case2:( student failed the class)
Please enter five HW Assignments scores [0 – 100]:
35
25
50
30
40
Please enter five Lab Exam scores [0 – 100]:
80
60
70
55
65
  	1	2	3	4	5
	************************************
HW	35	25	50	30	40	BEST HW: 50  WORST HW: 25  average HW: 36
LAB	80	60	70	55	65	BEST HW: 80  WORST HW: 55  average HW: 66

AVG	57.5	42.5	60	42.5	52.5	Overall: 51

I’m sorry to inform you that you failed the class, because your performance in HW Assignment was <50%. Try again next semester.

Enter the file name to write the output in to file:
case2.txt
Output Successfully written to the file!
*/

/*
 Exercise3 output:
 case 1: (input from keyboard/console)
 To enter the elements of array from console select 1/ from file select 2
 1
 enter the size of an array less than 50
 8
 enter the elements of array
 2
 -1
 3
 -1
 -1
 4
 2
 -1
   	N	Count
   	4 	 1
  	3	 1
  	2	 2
  	-1	 4
Enter the file name to write the output in to file:
output.txt
Output Successfully written to the file!

 case 2: (read array elements file, and file name is invalid)
 To enter the elements of array from console select 1/ from file select 2
 2
 enter the file name to read integers in to an array
 example.txt
 No such file found!!

 case 3: (reads array elements from file)
 To enter the elements of array from console select 1/ from file select 2
 2
 enter the file name to read integers in to an array
 input.txt
 The array elements read from file are : 4  8  8  6  7  4  4  -4  4  0

  	N	Count
  	8	 2
  	7	 1
  	6	 1
  	4	 4
  	0	 1
  	-4	 1
Enter the file name to write the output in to file:
output.txt
Output Successfully written to the file!

 */


/*Algorithm for Exercise1:

1. Declare a char array
2. Enter a loop to read a char from the console at a time,copy the char to the array and increment array size.
Check if the char is ‘.’ or if the char count exceeds array size, if so exit the loop.
3. If char input count exceeds array size, then display the warning message to user, display 1st 10 chars that will be reversed and go to step 4,
else if loop exits because of '.' then directly go to step4.
4. Iterate I from the array size down to 0 and print the array element to the console.

Pseudo-code for Exercise 1:

1. char ch, array[10]
2. int size = 1;
3. cin >> ch;
4. while (ch != ‘.’ & size<10)
   {
   array[size] = ch;
   size ++;
   cin >> ch;
   }
5.  if(size>=10)
	{
		array[size]=ch;
	}
6. for (int i = size; i >= 0; i--)
   {
   cout << array[i];
   }
*/

/*Algorithm for Exercise 2:
1. Declare a two dimensional double array val[2][8]. Val[0][] is used to store
   HW assignments and val[1][] is used to store exams.
   val[][5], val[][6], val[][7] are used to store the best, worst, and average scores of HW and exams each component respectively.
2. Loop for five times and input the HW assignment to the val[0][i].
3. Loop for five times and input the exams to the val[1][i].
4. Find the best, worst, and averages of HW and Exams.
   a. Find the best: iterate the five scores by comparing each with the variable best. If greater than the best, update best to be the current
     HW assignment.
     b. Find the worst: similar but change “greater” to be “smaller”
     c. Find the average: add the five scores and divide the sum by five.
6. Declare a double variable for overall grade. Calculate the overall grade by averaging the two averages of the two sets of the scores.
7. Output the scores in the format specified.
8. If both averages (HWs and Exams) are equal or above 50, then print "student passed the class" else print he failed.

Pseudo-code for Exercise 2:
1. double val[2][8];
2. Input the HW assignments:
cout << “Please enter five HW scores [0 – 100]: “;
for (int i = 0; i < 5; i++)
{
cin >> val[0][i];
}
4.Input the Lab exam scores:
cout << “Please enter five exam scores [0 – 100]: “;
for (int i = 0; i < 5; i++)
{
cin >> val[1][i];
}
3. Find the best,worst and average of HW and exam scores:
let us assume 1st score of HW and exam to be the best worst and average score,and compare it with other scores and replace.
 value[0][5]=value[0][6]=value[0][7]=value[0][0];
 value[1][5]=value[1][6]=value[1][7]=value[1][0];
4. i=0 for HW and i=1 for exam case:
	for(i=0;i<2;i++)
	{
		for(j=1;j<5;j++)
		{
		    best score:
			if(value[i][5]<value[i][j])
			{
				value[i][5]=value[i][j];
			}
			worst score:
			if(value[i][6]>value[i][j])
			{
				value[i][6]=value[i][j];
			}
			value[i][7]+=value[i][j];
		}
		average score, sum of 5 scores divided by 5:
		value[i][7]=value[i][7]/5;

	}
	overall average:
	overall=(value[0][7]+value[1][7])/2;
5.output to the console in the given output format using cout and write same output to the file:
	cin>>filename;
	ofstream myfile(filename);
	  if (myfile.is_open())
	  {
	    myfile<<"  \t1\t2\t3\t4\t5 \n";
	    myfile<<"\t************************************\n";
	    myfile<<"HW\t"<<value[0][0]<<"\t"<<value[0][1]<<"\t"<<value[0][2]<<"\t"<<value[0][3]<<"\t"<<value[0][4]<<"\t"<<"BEST HW: "<<value[0][5]<<"  WORST HW: "<<value[0][6]<<"  average HW: "<<value[0][7]<<"\n";
	    myfile<<"LAB\t"<<value[1][0]<<"\t"<<value[1][1]<<"\t"<<value[1][2]<<"\t"<<value[1][3]<<"\t"<<value[1][4]<<"\t"<<"BEST HW: "<<value[1][5]<<"  WORST HW: "<<value[1][6]<<"  average HW: "<<value[1][7]<<"\n\n";
	    myfile<<"AVG\t"<<(value[0][0]+value[1][0])/2<<"\t"<<(value[0][1]+value[1][1])/2<<"\t"<<(value[0][2]+value[1][2])/2<<"\t"<<(value[0][3]+value[1][3])/2<<"\t"<<(value[0][4]+value[1][4])/2<<"\t"<<"Overall: "<<overall<<"\n\n";
6.check if student has HW and Exam scores above 50%, if so print pass else print fail:
	    if(value[0][7]>50 && value[1][7]>50)
	    	{
	    	myfile<<" Congratulations! You passed the class! \n";
	    	}
	    	else if(value[0][7]<50)
	    	{
	    	myfile<<"I’m sorry to inform you that you failed the class, because your performance in HW Assignment was <50%. Try again next semester. \n";
	    	}
	    	else
	    	{
	    	myfile<<"I’m sorry to inform you that you failed the class, because your performance in the Lab Exam was <50%. Try again next semester. \n";
	    	}
	    myfile.close();
	  }
 */


/*Algorithm for Exercise 3:
1. Declare an one dimensional array
2. Ask user to choose between Input from the keyboard vs. reading from a file
3. If user choose keyboard input,ask for the size and input arrays using loop.
4. When reading from file, ask the user for input (file name) and read from the file
5. sort the array in descending order
6.count the occurrences of each element and print it along with the element in two columns, using given format.


Pseudo-code for Exercise 3:
1.Declare an array:
  int array[50];
2.to read array elements from console:
  cin>>size;
  enter elements:
  for(i=0;i<size;i++)
    {
	cin>>array[i];
	}
3.reads integers from file in to array.,user enters file name:
	cin>>filename;
	ifstream myfile;
	myfile.open(filename);
	while(!myfile.eof())
	{
	myfile>>array[n];
	n++;
	}
	size=n;
4.sort the array in the descending order
	for(i=0;i<size;i++)
	{
		max=i;
		for(j=i+1;j<size;j++)
		{
			if(array[j]>array[max])
				max=j;
		}
		if(max!=i)
		{
		temp=array[i];
		array[i]=array[max];
		array[max]=temp;
		}
	}
5.printing output to the console in the given format:
	cout<<"  \tN\tCount\n";
	for(i=0;i<size;i++)
	{
		if(array[i]==array[i+1])
		{
			count++;
		}
		else
		{
			cout<<"  "<<array[i]<<"\t"<<count<<"\n";
			count=1;
		}
	}
*/




