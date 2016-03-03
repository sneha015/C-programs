#include<iostream>
#include"binarysearchTree.h"

using namespace std;

int main()
{
	bSearchTreeType<int> bt;

	bt.insert(5);
	bt.insert(10);
	bt.insert(9);
	bt.insert(4);
	bt.insert(6);
	bt.insert(2);
	bt.insert(12);
	bt.insert(25);
	bt.insert(1);

	bt.inorderTraversal();
	cout<<endl;
	bt.preorderTraversal();
	cout<<endl;
	cout<<bt.treeNodeCount();
	cout<<endl;
	cout<<bt.treeLeavesCount();
	cout<<endl;


	return 0;
}




