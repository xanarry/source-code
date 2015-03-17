#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int a, b, c;
	while (cin >> a >> b >> c && a != 0 && b != 0 && c != 0)
	{
		double temp = (double) a / (double) b;

		stringstream ss;
		ss << temp;
		string str_r = ss.str();

		int i = 0;
		int pos = 0;
		int flag = 0;
		cout << str_r << endl;
		while (i != str_r.length())
		{
			if (str_r[i] == '.')
				flag = 1;
			if (flag == 1)
				pos++;
			if (pos == c + 1)
				break;
			i++;
		}
		if (str_r[i + 1] >= '5')
			str_r[i]++;

		cout << str_r.substr(0, i + 1) << endl;

		
		long long loc = pow(10, c);
		double t2 = temp * loc;
		cout << floor(t2 + 0.5) / loc << endl;
		
	}
	return 0;
}