#include <iostream>
using namespace std;

class a
{
public:
	a(){cout << "aaaaaaa" << endl;}
	~a(){cout << "~~~~aaa" << endl;}
};

class b: public a
{
public:
	b(){cout << "bbbbbbb" << endl;}
	~b(){cout << "~~~~bbbb" << endl;}
};

class c: public b
{
public:
	c(){cout << "cccccc" << endl;}
	~c(){cout << "~~~ccc" << endl;}
};

int main(int argc, char const *argv[])
{
 	c c1;
	return 0; 
}
