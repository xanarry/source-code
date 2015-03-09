#include <iostream>
#include <string>
using namespace std;

class A
{
private:
	string k;
protected:
	void f2()
	{
		cout << "this is protected f2() in A" << endl;
	}
	string j;
public:
	string i;
};

class B: public A
{
private:
	string m;
protected:
	void f4()
	{
		cout << "this is protected f4() in B" << endl;
	}
public:
	void f3()
	{
		cout << "this is public f3() in B" << endl;
	}
};

class C: protected B
{
private:
	string n;
public:
	void f5()
	{
		cout << "this is public f5() in C" << endl;
	}
	void use_f4()
	{
		cout << "this is protected f4() in C used by class C" << endl;//f4()是保护函数，可以通过派生类访问
	}
	void use_f2()
	{
		cout << "this is protected f2() in A used by class C" << endl;//f2()是保护函数，可以通过派生类访问，包括多级派生
	}
	void use_f3()
	{
		cout << "this is protected f3() in B used by class C" << endl;//f3()是保护函数，可以通过派生类访问，包括多级派生
	}
	void set_values(string t)
	{
		n = (t + " --->n in class C");
	//	m = (t + " --->m in class B");
	//	k = (t + " --->k in class A");
		i = (t + " --->i in class A");
		j = (t + " --->j in class A");
	}
	void get_values()
	{
		cout << "n = " << n << endl;
	//	cout << "m = " << m << endl;
	//	cout << "k = " << k << endl;
		cout << "j = " << j << endl;
		cout << "i = " << i << endl;
		
	}
};

int main(int argc, char const *argv[])
{
	C test;
	test.f5();
//	test.f4();//f4是B中的保护函数，只能在其派生类中使用函数访问
//	test.f3();//f3是B中的保护函数，由于是保护继承，只能在其派生类中使用函数访问，改为公共继承则可以直接访问
//	test.f2();//f4是A中的保护函数，只能在其派生类中使用函数访问
	test.use_f4();
	test.use_f3();
	test.use_f2();
	cout << endl << "varable test" << endl;
	test.set_values("my name is xiongyang HaHa! ");
	test.get_values();
	return 0;
}
