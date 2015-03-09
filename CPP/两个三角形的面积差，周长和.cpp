#include <iostream>
#include <cmath>

using namespace std;

class Triangle//define the class of triangle
{
public:
	Triangle();//declare the default construct function
	Triangle(double x, double y):a(x), b(y){}//declare the general construct function
	double Circumference();//dalare the function to calculating circumference
	double Area();//dalare the function to calculating area
private:
	double a;//side a
	double b;//side b
};

Triangle::Triangle()
{
	a = b = 1;//set defualt a = b = 1
}

double Triangle::Circumference()
{
	return a + b + sqrt(a*a + b*b);//return circumference
}

double Triangle::Area()
{
	return a*b/2;//return area
}

int main(int argc, char const *argv[])
{
	Triangle t1(3, 4);//create a triangle, and a = 3, b = 4
	Triangle t2(5, 12);//ditto

	//print all info~
	cout << "t1的面积是" << t1.Area() << "\n周长是" << t1.Circumference() << endl;
	cout << "\nt2的面积是" << t2.Area() << "\n周长是" << t2.Circumference() << endl;
	cout << "\n面积差是：" << abs(t1.Area() - t2.Area()) << endl;
	cout << "周长和是：" << t1.Circumference() + t2.Circumference() << endl;
	return 0;
}
