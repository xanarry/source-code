#include <iostream>
#include <cmath>
using namespace std;

int isPrime(int n)//�����ж��Ƿ�Ϊ�����ĺ��� 
{
	int i;
	if (n < 2)
		return 0;//С��2�������� 
	for(int i = 2; i <= sqrt(n); i++)
	{
		if(n%i == 0)//����ܱ�2��������n֮�����������Ҳ�������� 
			return 0;
	}
	return 1;//Ĭ�������� 
}

int huiwen(int n)
{
	if(n%10 == n/100)//�����ж� 
		return 1;
	else 
		return 0;
}

int main()
{
	int begin = 100, end, count = 0;
	cin >> end;
	for(int i = begin; i <= end; i++)//11��100֮��ֻ��һ��ͬʱ���������ģ�����1 
	{
		if(isPrime(i) && huiwen(i))
			count++;//����ҵ�һ������������������count�Լ�1	
	}
	cout << count + 1 << endl;//����11��100֮���һ���� 
	return 0;
}
