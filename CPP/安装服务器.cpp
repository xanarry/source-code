/**************************************
url: https://www.smartoj.com/p/1076
**************************************/
#include <iostream>
#include <cmath>

using namespace std;

class CityInfo

{
public:
	CityInfo(){}
	~CityInfo(){}
	CityInfo(int a, int b, int c, int d)
	{
		x = a;
		y = b;
		demand = d * c;
		if (x > xmax)
			xmax = x;
		if (y > ymax)
			ymax = y;
	}
	friend int cost(CityInfo *a, int count);
	int static xmax;
	int static ymax;
private:
	int x, y;
	int demand;
};

int CityInfo::xmax = 0;
int CityInfo::ymax = 0;

int costx(CityInfo *a, int count)
{
	int FeeL = 0;
	int FeeR = ;
	for (int k = 0; k < count; k++)
	{
		
	}
	cout << rx << " " << ry << endl;
}

int main(int argc, char const *argv[])
{
	int count;
	int x, y;
	int population, demand;
	CityInfo c[100];
	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		cin >> x >> y >> population >> demand;
		c[i] = CityInfo(x, y, population, demand);
	}
	cost(c, count);
	return 0;
}
