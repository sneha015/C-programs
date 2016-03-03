#include<iostream>
#include<string>
#include<fstream>
#include "unorderedLinkedList.h"

using namespace std;

class videoType
{
	friend ostream& operator<< (ostream& ,const videoType&);

public:
	void setVideoInfo( string titl, string str1, string str2, string prd, string dir, string prdn, int stk)
	{
		Title=titl;
		star1=str1;
		star2=str2;
		producer=prd;
		director=dir;
		production= prdn;
		stock=stk;
	}

	int getNoOfCopiesInStock() const
	{
		return stock;
	}
	void checkout()
	{
		if(getNoOfCopiesInStock() > 0)
			stock--;
		else
			cout<<"video is out of stock \n";
	}
	void checkin()
	{
		stock++;
	}
	void printTitle()
	{
		cout<<"video Title: " <<Title <<"\n";
	}
	void printInfo()
	{
		cout<<"Video Title: "<< Title <<"\n";
		cout<<"stars: "<<star1 << " and " << star2 <<"\n";
		cout<<"producer: " << producer <<"\n";
		cout<<"director: " << director <<"\n";
		cout<<"production: " << production <<"\n";
		cout<<"Copies in Stock: "<< stock<<"\n";
	}
	bool checkTitle( string titl)
	{
		return(Title == titl);
	}
	void updateStock(int num)
	{
		stock=stock+num;
	}
	void setCopiesInStock(int num)
	{
		stock = num;
	}
	string getTitle() const
	{
		return Title;
	}

	videoType( string titl=" ", string str1=" ", string str2=" ", string prd=" ", string dir=" ", string prdn=" ", int stk=0 )
	{
		setVideoInfo( titl, str1, str2, prd, dir, prdn, stk);
	}
	bool operator== (const videoType& Vt) const
		{
		return (Title == Vt.Title);
		}
	bool operator!= (const videoType& Vt) const
			{
			return (Title != Vt.Title);
			}

private:
	string Title;
	string star1;
	string star2;
	string producer;
	string director;
	string production;
	int stock;
};

ostream& operator<<(ostream& out,const videoType& video)
{
	out<< endl;
	out<<"Video Title: "<< video.Title <<"\n";
	out<<"stars: "<<video.star1 << " and " << video.star2 <<"\n";
	out<<"producer: " << video.producer <<"\n";
	out<<"director: " << video.director <<"\n";
	out<<"production: " << video.production <<"\n";
	out<<"Copies in Stock: "<< video.stock<<"\n";
	out<<"------------------------------------------------"<<endl;
	return out;
}

class videoListType :public unorderedLinkedList<videoType>
{
public:
	bool videoSearch( string title) const
	{
		bool found=false;
		nodeType<videoType> *location;
		searchVideoList( title,found,location);
		return found;
	}
	bool isVideoAvailable(string title) const
	{
		bool found=false;
				nodeType<videoType> *location;
				searchVideoList( title,found,location);
				if(found)
					found = (location->info.getNoOfCopiesInStock() >0);
				else
					found=false;
				return found;
	}
	void videoCheckout(string title) const
	{
		bool found=false;
		nodeType<videoType> *location;
		searchVideoList(title,found,location);
		if(found)
			location->info.checkout();
		else
			cout<<"store does not carry \n";
	}
	void videoPrintTitle() const
	{
		nodeType<videoType> *current;
		current = first;
		while(current!=NULL)
		{
			cout<<current->info.Title;
			current=current->link;
		}
	}
	void videoUpdateInStock(string title, int num)
	{
		bool found =false;
		nodeType<videoType> *location;
		searchVideoList(title,found,location);
		if(found)
			location->info.updateStock(num);
		else
			cout<<"store does not carry"\n;
	}
	void setCopiesInStock(string title, int num)
	{
		bool found =false;
		nodeType<videoType> *location;
		searchVideoList(title,found,location);
		if(found)
			location->info.setCopiesInStock(num);
		else
			cout<<"store does not carry"\n;
	}
private:
	void searchVideoList( string title, bool found, nodeType<videoType>* &current) const
	{
		found=false;
		current = first;
		while(current != NULL && !found)
			if(current->info == title)
				found=true;
			else
				current=current->link;
	}
};


void createVideoList(ifstream& infile, videoListType& videoList);
void displayMenu();



int main()
{
	videoListType video;
	int choice;
	char ch;
	string title;

	ifstream infile;

	infile.open("video.txt");
	if(!infile)
	{
		cout<<"input file does not exist \n";
		return 1;
	}
	createVideoList(infile,video);
	infile.close();

	displayMenu();
	cout << "Enter your choice: ";
	cin >> choice;    //get the request
	cin.get(ch);
	cout << endl;

	return 0;
}

