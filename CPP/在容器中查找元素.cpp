#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
using std::vector;

const int N = 1000;

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int a[N] = {0};
	for (int i = 0; i < N; i++)
	{
		if (i % 15 == 0)
			cout << endl;

		a[i] = rand()%500;
		cout << setw(3) << a[i] << " ";
	}

	cout << "\nwhich number you wanna find in this vector" << endl;
	int _find;
	cin >> _find;

	bool state = false;
	int location;
	vector<int> v(a, a + N);

	vector<int>::iterator iter = v.begin();
	for (; iter != v.end(); iter++)
	{
		if (_find == *iter)
		{
			state = true;
			location = iter - v.begin();
			break;
		}
	}

	cout << "\n-------------------------------------" << endl;
	if (state == true)
	{
		cout << "congratulate, finded " << _find << " in this vector" << endl;
		cout << "and it's location is " << location << endl;
	}
	if (state == false)
		cout << _find << "is not in this vector" << endl;
	return 0;
}
