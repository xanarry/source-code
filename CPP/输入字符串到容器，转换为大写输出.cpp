#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

string Toupper(string a)
{
	for (int i = 0; i < a.size(); ++i)//����string��
	{
		if (islower(a[i]))
			a[i] = a[i] - 32;//��Сд��Ϊ��д
	}
	return a;
}
int main(int argc, char const *argv[])
{
	string tmp;
	std::vector<string> v;
	while (cin >> tmp)
	{
		v.push_back(tmp);//����string������
	}

	std::vector<string>::iterator iter = v.begin();
	while (iter != v.end())
	{
		cout << Toupper(*iter) << endl;//���ú����������д���
		iter++;
	}
	return 0;
}
