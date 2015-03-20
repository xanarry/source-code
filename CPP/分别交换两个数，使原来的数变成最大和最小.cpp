#include <iostream>
#include <string>

using namespace std;
string doitmax(string num);
string doitmin(string num);
string exchange(string num, int a, int b);

int main(int argc, char const *argv[])
{
	int n;
	string inum;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> inum;
		cout << "Case#" << i + 1 << ": " << doitmax(inum) << " : " << doitmin(inum) << endl;
	}
	return 0;
}

string doitmax(string num)
{
	int index = 0, sp = 0;
	char max = num[index];
	while (index == sp)
	{
		for (int j = sp; j < num.length(); j++)
		{
			if (num[j] >= max)
			{
				max = num[j];
				index = j;
			}
		}
		if (sp == index && sp < num.length()-1)
		{
			index++;
			sp++;
			max = num[sp];
		}
		else
			break;
	}

	int s = sp;
	for (int i = sp; i < index; i++)
	{
		if (num[i] < num[index])
		{
			s = i;
			break;
		}
	}
	exchange(num, s, index);
	return "max: " + exchange(num, s, index);
}

string doitmin(string num)
{
	int index = 0, sp = 0;
	char min = num[index];
	while (index == sp)
	{
		for (int j = sp; j < num.length(); j++)
		{
			if (num[j] <= min)
			{
				min = num[j];
				index = j;
			}
		}
		if (sp == index && sp < num.length()-1)
		{
			index++;
			sp++;
			min = num[sp];
		}
		else
			break;
	}

	int s = sp;
	for (int i = sp; i < index; i++)
	{
		if (num[i] > num[index])
		{
			s = i;
			break;
		}
	}
	exchange(num, s, index);
	return "min: " + exchange(num, s, index);
}

string exchange(string num, int a, int b)
{
	char temp = num[a];
	num[a] = num[b];
	num[b] = temp;
	return num;
}

/*
10354
14305
93252
9807016
54398
54376989832
1001
120
510
*/
