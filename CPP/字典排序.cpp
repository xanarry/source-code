#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int i;
	int n;
	string a[1000];			//����a���ַ������� 
	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> a[i];		//��ȡԪ�� 
	}
	
	sort(a,a+n);			//���ú������� 
	
	for(i = 0; i < n; i++)
	{ 
		cout <<a[i]<<endl;
	}						//����������� 
	return 0;
}
