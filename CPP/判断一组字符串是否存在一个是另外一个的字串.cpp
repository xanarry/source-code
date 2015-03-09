/*
We know that if a phone number A is another phone number B��s prefix, 
B is not able to be called. For an example, A is 123 while B is 12345, 
after pressing 123, we call A, and not able to call B.
������һ���ַ������Ƿ����һ���ַ�������������һ���ַ����Ĵ���㿪ʼ���Ӵ�
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int len;
	cin >> len;
	string str[len];

	for (int i = 0; i < len; i++)
	{
		cin >> str[i];
	}

	bool flag = false;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)//����˫��ѭ�򣬱��������������ȽϵĽ��
		{
			if (str[i].length() < str[j].length())//ֻ�ж̴����п���Ϊ�������ִ�
			{
				if (str[j].substr(0, str[i].length()) == str[i])
				{
					flag = true;
					break;
				}
			}
			else
			{
				if (str[i].substr(0, str[j].length()) == str[j])
				{
					flag = true;
					break;
				}
			}
		}
	}
	
	if (!flag)
		cout << "YES" << endl;
	else 
		cout << "NO" << endl;
    return 0;
}
