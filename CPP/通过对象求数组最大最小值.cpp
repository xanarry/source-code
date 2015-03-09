#include <iostream>
using namespace std;

class array
{
private:
	int a[100];
public:
	int N;
	void input()
	{
		for(int i = 0; i < N; i++)
		{
			cin >> a[i];
		}
	}

	int find()
	{
		int max = a[0];
		for(int i = 1; i < N; i++)
		{
			if(a[i] > max)
				max = a[i];
		}
		return max;
	}

};

int main(int argc, char *argv[])
{
	cout << "input numbers count:";
	int n;
	cin >> n;
	array ary;
	ary.N = n;
	ary.input();
	cout << "the max number you've input is: " << ary.find() << endl;
	return 0;
}
