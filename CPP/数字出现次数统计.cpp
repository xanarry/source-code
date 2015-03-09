#include <iostream>
#include <algorithm>

using namespace std;

class InputNumber
{
public:
	InputNumber(){}
	~InputNumber(){}
	int static ShowTime;
	bool operator < (const InputNumber t) const//为sort函数提供比较基础
	{
		return num < t.num;//升序排序
	}
	void set(int n){num = n; ShowTime++;}
	int get(){return num;}
private:
	int num;
};

int InputNumber::ShowTime = 0;

int main(int argc, char const *argv[])
{
	int n, i = 0;
	InputNumber num[1000];
	while (cin >> n)
	{
		num[i].set(n);//输入数字
		i++;//下标处理
	}

	sort(num, num + InputNumber::ShowTime);//排序

	int  times = 1;//默认一个数的出现次数是1
	int tmp = num[0].get();//单独处理第一个数字

	for (int i = 1; i < InputNumber::ShowTime; i++)//第一个之后的数子
	{
		if (tmp == num[i].get())
		{
			times++;//如果发现后面的数字与前面的相同，那么次数自加
		}
		else//发现不同的数字
		{
			cout << tmp << " " << times << endl;//输入上个数的结果
			times = 1;//重置次数
			tmp = num[i].get();//重置比较对象
		}
	}
	cout << tmp << " " << times << endl;//输出最后一个数字的结果
	return 0;
}

/*test data
1
1
1
1
1
2
2
2
2
3
3
3
4
4
5
*/
