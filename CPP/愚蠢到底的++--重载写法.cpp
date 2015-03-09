#include <iostream>
using namespace std;

class ADD
{ 
	friend ADD operator++(ADD op);//前置++运算符声明
    friend ADD operator++(ADD &op, int n);//后置++运算符声明

public:
	ADD(int i = 0, int j = 0) {a = i; b = j;}
	void Show() const 
	{
		cout << "a=" << a << ",b=" << b << endl;
	}
private:
	int a, b;
};

ADD operator++(ADD op)//未使用引用时将返回自加后的临时变量，但但不会改变原有值，如果加上引用，则两个函数的作用一样
{	
	++op.a; 	
	++op.b;	
	return op;
}

ADD operator++(ADD &op, int n)//后置++运算符声明
{	
	++op.a;	
	++op.b;	
	return op;
}

int main()
{	
	//注意细分析输出结果
	cout << "original obj" << endl;
	ADD obj(1, 2);
	obj.Show();	
	cout << "-----------" << endl;

	cout << "using obj++" << endl;
	(obj++).Show();	
	cout << "after using " << endl;
	obj.Show();
	cout << "-----------" << endl;

	cout << "using ++obj" << endl;
	(++obj).Show();
	cout << "after using" << endl;
    obj.Show();
}
