#include <iostream>

using namespace std;

int set[5000];

void unionSet(int x, int y);
int findSet(int x);

int main(int argc, char const *argv[])
{
	int m, n, p;
	cin >> n >> m >> p;

	//n个人，默认每个都是自己的家族老大
 	for (int i = 1; i <= n; i++) //n people
	{
		set[i] = i;
	}

	//输入m组关系，构造一个关系对应的数组
	int a, b;
	for (int i = 1; i <= m; i++) //m relation
	{
		cin >> a >> b;//a和b之间有关系
		unionSet(a, b);//调用函数设置关系
	}

	for (int i = 0; i < p; i++) //p visit
	{
		cin >> a >> b;//输出两个人，查询是否有关系
		if (findSet(a) == findSet(b))//findSet用来查找根节点，如果这两个人有公共的节点，即有共同根节点，来自一个家族
			cout << "Yes" << endl;
		else 
			cout << "No" << endl;
	}
	return 0;
}

void unionSet(int x, int y)
{
	//接收一对新的关系
	int p = findSet(x);
	int q = findSet(y);
	//判断是否属于同一家人
	if (p != q)
	{
		set[q] = p;//不是的话就设置父子对应关系
	}
}

int findSet(int x)//递归查找这个元素所属的跟节点，如果没查找到其他的就设自己为跟节点
{
	if (set[x] == x) //如果跟节点是自己，返回自己，
		return x;
	else //否则通过递归查找他的跟节点
	{
		set[x] = findSet(set[x]);
		return set[x];//注意，数组的值表示的是跟节点
	}
}