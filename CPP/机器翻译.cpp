//题目来源：https://www.smartoj.com/p/1555 
#include<iostream>
#include<list>
using namespace std;
int main()
{
	int n,m,count=0; 
	cin >> m >> n;
	list<int> l;
	list<int>::iterator i;
	for(int j=0;j<n;j++)
	{
		int t;
		bool find = false;
		cin >> t;
		for(i = l.begin();i!=l.end();i++)
		{
			if(*i == t)
			{
				find = true;
				break;
			}
		}
		if(find == false)
		{
			if(l.size() == m)
				l.pop_front();
			l.push_back(t);
			count++;
		}
	}
	cout << count;
}
