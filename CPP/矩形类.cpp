#include <iostream>
using namespace std;

////////////////头文件的开始////////////////
class Rectangle
{
private:
	int width,height; 
public:
	int static count;
	Rectangle();
	Rectangle(int, int);
	~Rectangle(){}
	int Area();
	int Perimeter();	
};

Rectangle::Rectangle()
{
	width = 0;
	height = 0;
}

Rectangle::Rectangle(int w, int h)
{
	width = w;
	height = h;
	count++;
}

int Rectangle::Area()
{
	return width * height;
}

int Rectangle::Perimeter()
{
	return 2 * ( width + height);  
}
int Rectangle::count = 0;
////////////////头文件的结束////////////////

int main(int argc, char const *argv[])
{
	int p1, p2;
	cin >> p1 >> p2;
	Rectangle t(p1, p2);

	cout << "Area is " << t.Area() << endl;
	cout << "Perimeter is " << t.Perimeter() << endl << endl;

	//使用指针
	Rectangle *p = &t;
	cout << "Area is " << p->Area() << endl;
	cout << "Perimeter is " << p->Perimeter() << endl;

	cout << endl << "you have create " << Rectangle::count << " object" << endl;
	return 0;
}
