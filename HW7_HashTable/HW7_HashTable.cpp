#include<iostream>
#include "hashT.h"

using namespace std;

int main()
{
	hashT<int> ht(19); //hash table of size 19 is declared
	int k[6]={115, 153, 586, 208, 985, 111};
	int retrieveItem;
	bool found;
	int loc = k[2] % 19; //hash function to calculate index

	for(int i=0; i< 6 ; i++) //adds element to hash table
	{
		ht.insert(k[i] % 19 , k[i]); //sends the location and element to be saved in that index location to insert function
	}

	cout<<"Hash Table Elements: \n";
	ht.print(); // prints all the elements in hash table
	cout<<"\n";

	cout<<"Search element 586 in the Hash Table:\n";
	ht.search(loc,k[2],found); //search for a element starting from given location index and make found true if found
	cout<<"\n";

	cout<<"Remove element 586 from the Hash Table if found:\n";
	ht.remove(loc,k[2]); // searches for element in given location, if found it is deleted,else prints error message

	cout<<"HashTable after removing an element :\n";
	ht.print(); // print hash table after removing element
	cout<<"\n";

	retrieveItem = k[5];
	cout<<"Retrieve element 111 (giving correct index): \n";
	ht.retrieve(k[5] % 19 , retrieveItem);
	if(retrieveItem != -1)
	    cout<<"After Retrieve operation the item retrieved is : "<<retrieveItem<<"\n";
	else
		cout<<"Retrieve Item not found in the hash table \n";
    cout<<endl;

    cout<<"isItemAtEqual operation is performed on element 115 at initial array index 0 : \n";
    if(ht.isItemAtEqual(k[0] % 19 , k[0]))
    	cout<<"Item matches element in given index in hash table \n";
    else
    	cout<<"Item do not match element in given index in hash table \n";

        cout<<endl;
	return 0;
}


/* output:
Hash Table Elements:
H[1] <- 115	H[2] <- 153	H[6] <- 111	H[16] <- 586	H[17] <- 985	H[18] <- 208

Search element 586 in the Hash Table:
Element 586 found at Hash Index : 16

Remove element 586 from the Hash Table if found:
Element 586 at Hash Index 16 removed successfully!!
HashTable after removing an element :
H[1] <- 115	H[2] <- 153	H[6] <- 111	H[17] <- 985	H[18] <- 208

Retrieve element 111 (giving correct index):
After Retrieve operation the item retrieved is : 111

isItemAtEqual operation is performed on element 115 at initial array index 0 :
Item matches element in given index in hash table
 */



