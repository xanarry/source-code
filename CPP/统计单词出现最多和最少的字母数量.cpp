#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int isPrime(int n)//�ж��Ƿ�Ϊ�����ĺ��� 
{
	if (n < 2)
		return 0;
	for(int i = 2; i <= sqrt(n); i++) 
	{
		if(n%i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	char in[100];
	int max = 0, min = 100, len, count[26];//��ĸ��26�������Զ����СΪ26�������¼ÿ���ַ����ֵĴ��� 
	memset(count, 0, sizeof(count));//��ʼ�������е�ÿ��Ԫ�ص�ֵΪ0 
	cin >> in;
	len = strlen(in);//��ȡ�ַ������� 
	
	for(int i = 0; i < len; i++)//���������е�ÿ����ĸ
	{
		count[in[i] - 'a']++;//in[i]��һ����ĸ��������'a'���������¼����ĸ���ִ����������±�
	}

	for(int i = 0; i < 26; i++)
	{
		if(count[i] != 0)//�ų�û�г��ֵ���ĸ
		{
			if(count[i] > max)//�ҳ��������Ĵ���
				max = count[i];
			if(count[i] < min)//�ҵ�������С�Ĵ���
				min = count[i];
		}
		
	}

	if(isPrime(max - min))
		cout << "Lucky Word" << endl << max - min << endl;
	else 
		cout << "No Answer" << endl << max - min << endl;
	return 0;
}
