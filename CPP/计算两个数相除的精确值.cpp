#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
  	int a, b, m;
  	cin >> a >> b;

    //除数大于和小于被除数是要单独处理小数点前面的数
  	if (a < b)
  	{
  		m = a * 10;
  		cout << "0.";
  	}
  	else
  	{
  		cout << a / b << ".";
  		m = (a % b)*10;
  	}

  	while (1)//计算小数位数
  	{
  		cout << m / b;
  		if (m % b == 0)
  			break;
  		m = (m % b) * 10;
  	}
    return 0;
}