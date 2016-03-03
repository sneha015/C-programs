
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iterator>
#include<fstream>

using namespace std;

const int SYMBOL = 0;
const int GAIN = 1;

class stockType
{
public:
	friend void operator <<(ostream& out,stockType& stk);

	stockType(string symbol=" ",double open= 0.0, double close=0.0, double high=0.0,
				double low=0.0, double prevClose=0.0, int shares=0);

	string getSymbol();
	double getOpenPrice();
	double getClosePrice();
	double getHighPrice();
	double getLowPrice();
	double getPrevPrice();
	double getPercentGain();
	int getNoOfShares();

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


void operator<<(ostream& out,stockType& stk) // operator << overloaded with ostream
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



  bool operator()(stockType& s1, stockType& s2) const
  {
      if(this == GAIN)
          return (s1.getPercentGain() > s2.getPercentGain());
      else
          return (s1.getSymbol() < s2.getSymbol());
  }


class stockListType
{
public:
	void sortBySymbol();
	void sortByPercentGain();
	vector<stockType> getstockList();
	void setStockList(vector<stockType> stockList);
	void printStocks(ostream& outp);
	void printClosingAssets();

private:
	vector<int> indexByGain;
	vector<stockType> stockList;
};

void stockListType::sortBySymbol()
{
	sort(stockList.begin(),stockList.end(),SYMBOL);
}

void stockListType::sortByPercentGain()
{
	sort(stockList.begin(),stockList.end(),GAIN);
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

void output(ostream& outs)
{
	outs << "******************  First Investor's Heaven  *****************" << endl;
	outs << "******************      Financial Report     *****************" << endl;
    outs << "Stock"<<"\t"<<"Today"<<"\t\t\t\t"<< "Previous "<<"Percent" << "\t \t \n";
	outs << "Symbol"<<"\t"<<"Open"<<"\t"<<"Close"<<"\t"<<"High"<<"\t"<<"Low"<<"\t"<<"Close "<<"\t"<<" Gain"<<"\t"<< "Volume" << endl;
	outs << "------"<<"\t"<<"----"<<"\t"<<"-----"<<"\t"<<"----"<<"\t"<<"---"<<"\t"<<"-----"<<"\t"<<"----"<<"\t"<<"------" << "\n";

}


int main()
{
   stockListType stockLst;

   ifstream infile("input.txt");
   input(infile,stockLst);

   cout<<"Financial report read from the input file:\n\n";
   output(cout);
   stockLst.printStocks(cout);
   stockLst.printClosingAssets();

   stockLst.sortBySymbol();
   cout<<"Financial report ordered with respect to Symbol:\n\n";
   output(cout);
   stockLst.printStocks(cout);
   stockLst.printClosingAssets();

   stockLst.sortByPercentGain();
   cout<<"Financial report ordered with respect to Percent Gain/Loss:\n\n";
   output(cout);
   stockLst.printStocks(cout);
   stockLst.printClosingAssets();

   return 0;
}





