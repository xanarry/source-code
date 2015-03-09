#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int input;
	cin >> n;
	cin >> input;

	bool special;
	if (input%2 == 0)
		special = true;
	else
		special = false;

	int i = 1;
	for (i = 1; i < n; )
	{
		cin >> input;
		if ( (input%2 == 0 && special) || (input%2 != 0 && !special) )//没有突然遇到非偶数或者非奇数
			i++;
		else
			break;//数字类型突变后终止计数
	}
	if (i != 1)
		cout << i + 1;
	else cout << i;
	return 0;
}