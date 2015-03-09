#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

bool find1(std::vector<int> v, int obj)
{
	std::vector<int>::iterator iter = v.begin();
	while (iter != v.end())
	{
		if (obj == *iter)
			return true;
		iter++;
	}
	return false;
}

int find2(std::vector<int> v, int obj)
{
	std::vector<int>::iterator iter = v.begin();
	while (iter != v.end())
	{
		if (obj == *iter)
			return iter - v.begin() + 1;
		iter++;
	}
	cout << "can not find this number" << endl;
	exit(1);
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	std::vector<int> v;
	const int count = 10;
	for (int i = 0; i < count; ++i)
	{
		int tmp = rand() % 50;
		v.push_back(tmp);
		cout << tmp << " ";
	}
	cout << "\ninput a number you wanna find: " << endl;
	int n, result;
	cin >> n;
	if (find1(v, n))
		cout << "ok we find it" << endl;
	result = find2(v, n);
	cout << "location is: " << result << endl;
	return 0;
}
