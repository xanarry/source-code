#include <iostream>
#include <vector>

using namespace std;

void display(std::vector<int> v)
{
	std::vector<int>::iterator iter = v.begin();
	while (iter != v.end())
	{
		cout << *iter << " ";
		iter++;
	}
}

//将数字串中的偶数替换为奇数
int main(int argc, char const *argv[])
{
	std::vector<int> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	display(v);
	cout << endl;
	
	// 0 1 2 3 4 5 6 7 8 9
	// 1 1 3 3 5 5 7 7 9 9
	std::vector<int>::iterator iter = v.begin();
	while (iter != v.end())
	{
		if (*iter % 2 == 1)
		{
			iter = v.insert(iter, *iter);//返回之前的迭代器
			iter += 2;
		}
		else
			iter = v.erase(iter);//返回之后的迭代器
	}
	display(v);
	return 0;
}
