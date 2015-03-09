#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using std::vector;

struct Times
{
	int number;
	int count;
};

int main(int argc, char const *argv[])
{
	int n, tmp;
	Times cd[10000];
	vector<int> lst;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		lst.push_back(tmp);
	}
	sort(lst.begin(), lst.end());
	lst.push_back(0);//抽取数字是总是少抽去了一个，所以在排序后才插入以无效数字填充数目
	vector<int>::iterator iter = lst.begin();
	tmp = *iter;
	int j = 0;
	while (iter + 1 != lst.end())
	{
		cd[j].number = tmp;
		if (tmp == *iter)
			cd[j].count++;
		else
		{
			tmp = *iter;
			j++;
			cd[j].number = *iter;
			cd[j].count = 1;
		}
		iter++;
	}
	for (int i = 0; i <= j; ++i)
	{
		cout << cd[i].number << " " << cd[i].count << endl;
	}

	return 0;
}
