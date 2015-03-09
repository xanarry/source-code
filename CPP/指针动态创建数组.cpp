#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	const int len = 100;

	int *p = new int[len];

	const int *p1 = p;// visit the array

	int n;
	for (int i = 0; i < len; i++)
	{
		*(p + i) = (rand()%500 + 1);
	}

	for (int i = 0; i < len; i++)
	{
		cout << *(p1 + i) << " " << endl;
	}
	delete [] p1;
	return 0;
}
