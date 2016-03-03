
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iterator>
#include<fstream>

using namespace std;

const int SYMBOL = 0;
const int GAIN = 1;

// class stockType declares and initializes stock elements
class stockType
{
public:
	friend void operator <<(ostream& out,stockType& stk);
	// friend function overloads operator << using ostream and prints stock elements on the screen in the given format

	stockType(string symbol=" ",double open= 0.0, double close=0.0, double high=0.0,
				double low=0.0, double prevClose=0.0, int shares=0);
	//construstor assigns default values to the stock elements if no input values are given

	string getSymbol();
	double getOpenPrice();
	double getClosePrice();
	double getHighPrice();
	double getLowPrice();
	double getPrevPrice();
	double getPercentGain();
	int getNoOfShares();
	// get functions to access private member variable outside class

private:
	string stockSymbol;
	double todayOpeningPrice;
	double todayClosingPrice;
	double todayHighPrice;
	double todayLowPrice;
	double previousClosingPrice;
	double percentGain;
	int numberOfShares;
};


void operator<<(ostream& out,stockType& stk)
{
	out.setf(ios::fixed);
	out.setf(ios::showpoint);
	out.precision(2);
	out<< stk.stockSymbol << "\t" << stk.todayOpeningPrice << "\t" << stk.todayClosingPrice << "\t" << stk.todayHighPrice<< "\t"<< stk.todayLowPrice << "\t" << stk.previousClosingPrice<< "\t" <<stk.percentGain << "%\t" << stk.numberOfShares << "\n";
}

stockType::stockType(string symbol,double open, double close, double high,
			double low, double prevClose, int shares)
{
	stockSymbol = symbol;
		todayOpeningPrice = open;
		todayClosingPrice = close;
		todayHighPrice = high;
		todayLowPrice = low;
		previousClosingPrice = prevClose;
		numberOfShares = shares;
		percentGain = ((todayClosingPrice - previousClosingPrice) / previousClosingPrice) * 100;
}

string stockType::getSymbol()
{
	return stockSymbol ;
}

double stockType::getPercentGain()
{
	percentGain = ((todayClosingPrice - previousClosingPrice) / previousClosingPrice) * 100;
	return percentGain;
}
double stockType::getOpenPrice()
{
	return todayOpeningPrice;
}
double stockType::getClosePrice()
{
	return todayClosingPrice;
}
double stockType::getHighPrice()
{
	return todayHighPrice;
}
double stockType::getLowPrice()
{
	return todayLowPrice;
}
double stockType::getPrevPrice()
{
	return previousClosingPrice;
}
int stockType::getNoOfShares()
{
	return numberOfShares;
}

/* structure EntityComp is used to send the entity of the stock elements array,
 on basis of which entity the stocks should be sorted */
struct EntityComp {
  int pergain;
  (EntityComp(int pergain))
  {
	  this->pergain = pergain;
  }
  //operator () is overloaded to read the entity and over load < operator for the stock sort
  bool operator()(stockType& s1, stockType& s2) const
  {
      if(pergain == GAIN)
          return (s1.getPercentGain() > s2.getPercentGain());
      else
          return (s1.getSymbol() < s2.getSymbol());
  }
};

//Class "stockListType" declares a private member vector object of type stockType  which holds the stockType members
class stockListType
{
public:
	void sortBySymbol(); // sorts stocks and orders it on basis of stock symbols
	void sortByPercentGain();// sorts stocks and orders it on basis of percent gain/loss
	vector<stockType> getstockList(); // get function to access stocklist outside class
	void setStockList(vector<stockType> stockList);
	void printStocks(ostream& outp); //prints the vector array on the screen
	void printClosingAssets();// calculates and prints closing assest

private:
	vector<stockType> stockList;
};

void stockListType::sortBySymbol()
{
	sort(stockList.begin(),stockList.end(),EntityComp(SYMBOL));
}

void stockListType::sortByPercentGain()
{
	sort(stockList.begin(),stockList.end(),EntityComp(GAIN));
}

void stockListType::setStockList(vector<stockType> stockLis){
	this->stockList = stockLis;
}

vector<stockType> stockListType::getstockList()
{
	return stockList;
}
void stockListType::printStocks(ostream& out)
{
	for(int i=0; i<5; i++)
	{
		out<<stockList[i];

	}
}
void stockListType::printClosingAssets()
{
	double closingAssets=0.0;
	for(int i=0; i<5; i++)
		{
		closingAssets = closingAssets + (stockList[i].getClosePrice() * stockList[i].getNoOfShares())	;
		}
	cout<<"Closing Assets: "<<closingAssets<<"$\n";
	cout<< "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
	cout<<"\n\n\n";
}

// input function reads the input file and copies the stock data in to stockList vector array
void input(ifstream& infile,stockListType& mylist)
{
stockType myStock;
string symbol;
double open, close, high,low, prevClose;
int shares;
vector<stockType> stkLst;

		if(infile.is_open())
		{
			while(!infile.eof())
			{
				infile>>symbol>>open>>close>>high>>low>>prevClose>>shares;

				myStock= stockType(symbol, open,  close,  high, low, prevClose, shares);
				stkLst.push_back(myStock);
			}
			mylist.setStockList(stkLst);
			infile.close();
		}
		else cout<< "No such file found!!";
}

// common heading to print before stocks
void output(ostream& outs)
{
	outs << "******************  First Investor's Heaven  *****************" << endl;
	outs << "******************      Financial Report     *****************" << endl;
    outs << "Stock"<<"\t"<<"Today"<<"\t\t\t\t"<< "Previous "<<"Percent" << "\t \t \n";
	outs << "Symbol"<<"\t"<<"Open"<<"\t"<<"Close"<<"\t"<<"High"<<"\t"<<"Low"<<"\t"<<"Close "<<"\t"<<" Gain"<<"\t"<< "Volume" << endl;
	outs << "------"<<"\t"<<"----"<<"\t"<<"-----"<<"\t"<<"----"<<"\t"<<"---"<<"\t"<<"-----"<<"\t"<<"----"<<"\t"<<"------" << "\n";
}

//main function which automates companies stock data using the classes stockType and stockListType
int main()
{
   stockListType stockLst;

   ifstream infile("input.txt"); // the input stock lists are in the fine input.txt
   input(infile,stockLst);

   //outputs the stock data as read from the input file on screen along with closing assets
   cout<<"Financial report read from the input file:\n\n";
   output(cout);
   stockLst.printStocks(cout);
   stockLst.printClosingAssets();

   //sorts the sortList and orders them on basis of symbol and prints them on screen with given format along with closing assets
   stockLst.sortBySymbol();
   cout<<"Financial report ordered with respect to Symbol:\n\n";
   output(cout);
   stockLst.printStocks(cout);
   stockLst.printClosingAssets();

   //sorts the sortList and orders them on basis of percent gain/loss and prints them on screen with given format along with closing assets
   stockLst.sortByPercentGain();
   cout<<"Financial report ordered with respect to Percent Gain/Loss:\n\n";
   output(cout);
   stockLst.printStocks(cout);
   stockLst.printClosingAssets();

   return 0;
}

/* Output:

 Financial report read from the input file:

******************  First Investor's Heaven  *****************
******************      Financial Report     *****************
Stock	Today				Previous Percent
Symbol	Open	Close	High	Low	Close 	 Gain	Volume
------	----	-----	----	---	-----	----	------
IBD	68.00	71.00	72.00	67.00	75.00	-5.33%	15000
MSET	120.00	140.00	145.00	140.00	115.00	21.74%	30920
AOLK	80.00	75.00	82.00	74.00	83.00	-9.64%	5000
CSCO	100.00	102.00	105.00	98.00	101.00	0.99%	25000
ABC	123.45	130.95	132.00	125.00	120.50	8.67%	10000
Closing Assets: 9628300.00$
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


Financial report ordered with respect to Symbol:

******************  First Investor's Heaven  *****************
******************      Financial Report     *****************
Stock	Today				Previous Percent
Symbol	Open	Close	High	Low	Close 	 Gain	Volume
------	----	-----	----	---	-----	----	------
ABC	123.45	130.95	132.00	125.00	120.50	8.67%	10000
AOLK	80.00	75.00	82.00	74.00	83.00	-9.64%	5000
CSCO	100.00	102.00	105.00	98.00	101.00	0.99%	25000
IBD	68.00	71.00	72.00	67.00	75.00	-5.33%	15000
MSET	120.00	140.00	145.00	140.00	115.00	21.74%	30920
Closing Assets: 9628300.00$
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


Financial report ordered with respect to Percent Gain/Loss:

******************  First Investor's Heaven  *****************
******************      Financial Report     *****************
Stock	Today				Previous Percent
Symbol	Open	Close	High	Low	Close 	 Gain	Volume
------	----	-----	----	---	-----	----	------
MSET	120.00	140.00	145.00	140.00	115.00	21.74%	30920
ABC	123.45	130.95	132.00	125.00	120.50	8.67%	10000
CSCO	100.00	102.00	105.00	98.00	101.00	0.99%	25000
IBD	68.00	71.00	72.00	67.00	75.00	-5.33%	15000
AOLK	80.00	75.00	82.00	74.00	83.00	-9.64%	5000
Closing Assets: 9628300.00$
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

 */





