#include <iostream>
using namespace std;

class Sample 
{
private:
	int n;
public:
	Sample(int i):n(i){}
	~Sample(){}
	Sample operator--()
	{
		return Sample(--n);
	}

	Sample operator++()
	{
		return Sample(++n);
	}

	Sample operator++(int)
	{
		Sample tmp = *this;
		this->n += 1;
		return tmp;
	}

	Sample operator--(int)
	{
		Sample tmp = *this;
		this->n -= 1;
		return tmp;
	}

	friend ostream & operator<<(ostream & a, const Sample b)
	{
		a << b.n;
		return a;
	}
};

int main()
{
	Sample s(5);
	cout << "original number is: " << s << endl;
	cout << "used --s operation: " << --s << endl;
	cout << "used ++s operation: " << ++s << endl;
	cout << "---------------------" << endl;
	cout << "just output s is  : " << s << endl;
	cout << "used s++ operation: " << s++ << endl;
	cout << "and then output s : " << s << endl;
	cout << "used s-- operation: " << s-- << endl;
	cout << "value has changled: " << s << endl;
	return 0;
}
