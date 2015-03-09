#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	std::vector<int> v;
	while (cin >> n)
	{
		v.push_back(n);
	}

	cout << "the data you input as fallowing" << endl;
	std::vector<int>::iterator iter = v.begin(), iter1;
	for (; iter != v.end(); iter++)
	{
		cout << *iter << " ";
	}

	cout << "\nthis is the result of tail plus head" << endl;

	iter = v.begin();//元素起点
	iter1 = --v.end();//元素终点
	
	while (iter <= iter1)//当头尾没有相遇时
	{
		cout << *iter << "+" << *iter1 << "=" << *iter + *iter1 << endl;
		iter++;//头迭代器后移
		iter1--;//尾迭代器前移
	}
	return 0;
}
