/*
	Description: 数据结构 栈 
*/
#include<stack>
#include<stdio.h>
using namespace std;
int main()
{
	stack<int> q;
	q.push(2);
	q.push(3); //后进先出 
	printf("%d ",q.top());
}
