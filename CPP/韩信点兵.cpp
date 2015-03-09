#include <iostream>
using namespace std;
/*
	三个人一排剩下2个人，5个人一排剩下1个人，7个人一排剩下6个人，则一共有41个人，
	现在输入每次余下的人求出总人数，人数为10-100；
*/
int main(int argc, char const *argv[])
{
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 10; i < 100; i++)
	{
		if (i % 3 == a && i % 5 == b && i % 7 == c)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << "No answer" << endl;
	return 0;
}