#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

template <typename T>
void BublleSort(T *a, int Len)
{
	T tmp;
	for (int i = 0; i < Len - 1; i++)
	{
		for (int j = 0; j < Len - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

string CreateString(int len)//生成字符串，避免让入输入
{
	string charactors[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
	string tmp;
	
	for (int i = 0; i < len; ++i)
	{
		int index = rand()%25 + 1;
		tmp.append(charactors[index]);
	}
	return tmp;
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	const int len = 10;

	//sort a integer array//
	cout << "--original integer array" << endl;
	int *a = new int[len];
	for (int i = 0; i < len; ++i)
	{
		a[i] = rand()%10 + 1;
		cout << a[i] << " ";
	}
	cout << "\n--BublleSorted" << endl;
	BublleSort(a, len);
	for (int i = 0; i < len; ++i)
	{
		cout << a[i] << " ";
	}
	cout << "\n--int end\n" << endl;


	//sort a float array//
	float *b = new float[len];
	cout << "--original float point array" << endl;
	for (int i = 0; i < len; ++i)
	{
		b[i] = (rand()%100 + 1) + (float)(rand()%101)/100;
		cout << b[i] << " ";
	}
	cout << "\n--BublleSorted" << endl;
	BublleSort(b, len);
	for (int i = 0; i < len; ++i)
	{
		cout << b[i] << " ";
	}
	cout << "\n--float end\n" << endl;


	//sort a string array//
	string *c = new string[len];
	cout << "--original string array" << endl;
	for (int i = 0; i < len; ++i)
	{
		int len = rand()%(7 - 4) + 4;
		c[i] = CreateString(len);
		cout << c[i] << endl;
	}
	cout << "\n--BublleSorted" << endl;
	BublleSort(c, len);
	for (int i = 0; i < len; ++i)
	{
		cout << c[i] << endl;
	}
	cout << "\n--string end" << endl;
	return 0;
}
