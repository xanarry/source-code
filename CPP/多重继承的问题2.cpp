#include <iostream>
using namespace std;

class N
{
public:
	int a;
	void display()
	{
		cout << "A::a = " << a << endl;
	}
};

class A: public N
{
	int a1;
};

class B: public N
{
public:
	int a2;
};

class C: public A, public B
{
public:
	int a3;
	void show()
	{
		cout << "a3 = " << a3 << endl;
	}
};

int main(int argc, char const *argv[])
{
	C t;
	t.a3 = 0;
	t.show();
	t.A::a = 1111;
	t.A::display();
	t.B::a = 2222;
	t.B::display();
	return 0;
}
