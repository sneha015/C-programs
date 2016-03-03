#include<iostream>
#include"unorderedLinkedList.h"
using namespace std;

void selectionSortArray(int arr[])
{

	for(int k=0; k<10; k++)
		{
			cout<<arr[k]<<" ";
		}
		cout<<"\n";

		for(int i=0; i<10; i++)
		{
			int small = i;
			for(int j=i; j<10; j++)
			{
				if(arr[j]< arr[small])
					small = j;
			}

			if(small != i)
			{
				int temp =arr[i];
				arr[i]= arr[small];
				arr[small]=temp;
			}
		}

		for(int l=0; l<10; l++)
			{
				cout<<arr[l]<<" ";
			}
			cout<<"\n";

}

int sequentialSearch(int arr[],int length,int item)
{
	for(int i=0; i<length;i++)
	{
		if(arr[i]==item)
		return i;
	}
	return -1;
}


int main()
{
	int arr[10]={ 5, 24,-1,9,72,2,-4,6,10,36};
	int length=10;
	int item=2;
	/*unorderedLinkedList<int> list1;
	    int num;

	    cout << "Enter the elements for list1, numbers ending with -999. \n";
	    cin >> num;
	    while (num != -999)
	    {
	        list1.insertLast(num);
	        cin >> num;
	    }

	    list1.print();

	    list1.selectionSort();

	    cout<<endl;
	    list1.print();

	    cout<<endl;
	    cout<<"selection sort using arrays \n";
	    selectionSortArray(arr);*/

	    int result = sequentialSearch(arr,length,item);
	    cout<<result;

cout<<endl;

return 0;

}



