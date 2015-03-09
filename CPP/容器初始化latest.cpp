#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

void display(std::vector<int> v)
{
	std::vector<int>::iterator iter = v.begin();
	while (iter != v.end())
	{
		cout << *iter << " ";
		iter++;
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	std::vector<int> v;
	int count = 5;
	int tmp;
	cout << "first way, single input" << endl;
	for (int i = 0; i < count; ++i)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	display(v);

	cout << "second way, a copy of a array" << endl;
	int n[5];
	for (int i = 0; i < count; ++i)
	{
		cin >> n[i];	
	}
	std::vector<int> v1(n, n + 5);//指针位置只能从小到大
	display(v1);

	cout << "third way, uss assign() to copy a array" << endl;
	std::vector<int> v3;
	v3.assign(n, n + 5);
	display(v3);

	cout << "forth way, use assign() to copy a container" << endl;
	std::vector<int> v4;
	v4.assign(v1.begin(), v1.end());
	display(v4);

	return 0;
}
