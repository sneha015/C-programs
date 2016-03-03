/*
 * chattest.cpp
 *
 *  Created on: Jul 6, 2015
 *      Author: lokisneha
 */
#include<string>
#include<iostream>
#include<iterator>
#include<ctype.h>
#include<algorithm>
 using namespace std;

 int main()
 {
	 string s("Hello world");

	 for (string::iterator it = s.begin(), end = s.end(); it != end; ++it)
	 {
	     cout << "One character: " << *it << "\n";
	     *it = '*';
	 }

	// for (char & c : s)
	// {
	 //    cout << "One character: " << c << "\n";
	  //   c = '*';
	// }

	 cout<<endl;

	 return 0;

 }



