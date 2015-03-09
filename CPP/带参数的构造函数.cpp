#include <iostream>
using namespace std;

class triangle
{
private:
	float height;
	float width;
	float length;
public:
	float total_length();
	triangle(float h, float w, float l);
};

triangle::triangle(float h, float w, float l)
{
	height = h;
	width = w;
	length = l;
}

float triangle::total_length()
{
	return height + width + length;
}

int main(int argc, char const *argv[])
{
	triangle tr1(3,4,5);
	cout << tr1.total_length();
	return 0;
}

