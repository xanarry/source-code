#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

string Toupper(string a)
{
	for (int i = 0; i < a.size(); ++i)//遍历string串
	{
		if (islower(a[i]))
			a[i] = a[i] - 32;//将小写变为大写
	}
	return a;
}
int main(int argc, char const *argv[])
{
	string tmp;
	std::vector<string> v;
	while (cin >> tmp)
	{
		v.push_back(tmp);//输入string到容器
	}

	std::vector<string>::iterator iter = v.begin();
	while (iter != v.end())
	{
		cout << Toupper(*iter) << endl;//调用函数并输出大写结果
		iter++;
	}
	return 0;
}
