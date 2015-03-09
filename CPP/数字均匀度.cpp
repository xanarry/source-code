#include <iostream>

 using namespace std;

 int main(int argc, char const *argv[])
 {
 	int n;
 	cin >> n;
 	int *a = new int[n - 1];
 	int t = 0;
 	int temp;
 	int input;
 	int count = 0;
 	bool flag = false;
 	cin >> temp;
 	//计算一串数字之间两两不同差值的个数
 	for (int i = 1; i < n; i++)
 	{
 		cin >> input;
 		a[t] = input - temp;
 		for (int j = 0; j < t; j++)
 		{	
 			if (a[t] == a[j])
 			{
 				flag = true;
 				break;
 			}
 		}
 		if (!flag)
 			count++;

 		temp = input;
 		t++;
 	}
 	cout << count << endl;
 	return 0;
 }
