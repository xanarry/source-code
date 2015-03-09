#include <iostream>
#define elmtpe char//在此修改要处理的数据类型

using namespace std;

/*///////////引用的函数原型//////////////
class Compare
{
private:
	int x, y;
public:
	Compare(int a = 0, int b = 0):x(a), y(b){}
	int Max();
	int Min();
};

int Compare::Max()
{
	return ((x > y)? x:y);
}

int Compare::Min()
{
	return ((x < y)? x:y);
}
*/////////////////////////////////////////

template <class elemtype>//声明一个模板，虚拟类型为elemtype
class Compare
{
private:
	elemtype x, y;
public:
	Compare(elemtype a = 0, elemtype b = 0):x(a), y(b){}//创建构造函数，默认值为0
	elemtype Max();
	elemtype Min();
};

template <class elemtype>//由于方法在类外定义，需要指定以下函数也使用的虚拟数据类型
elemtype Compare<elemtype>::Max()//返回类型为elemtype类型，"Compare<elemtype>"是一个整体，表示带参数的类，
{
	return ((x > y)? x:y);
}

template <class elemtype>//同上
elemtype Compare<elemtype>::Min()//同上
{
	return ((x < y)? x:y);
}

int main(int argc, char const *argv[])
{
	elmtpe a,b;
	cout << "input 2 numbers:" << endl;
	cin >> a >> b;
	Compare<elmtpe> cmp(a,b);//使用类模板定义对象
	cout << "min = " << cmp.Min() << endl << "max = " << cmp.Max() << endl;
	return 0;
}
