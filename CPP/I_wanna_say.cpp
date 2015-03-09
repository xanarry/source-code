#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	float y;
	float x = 4;
	y = ((x + 52.8) * 5 - 3.9343) / 0.5 - x * 10;
	printf("%.4f\n", y);
	return 0;
}
