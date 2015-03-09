/*
	Name: c++,数据结构，队列 (先进先出） 
	Copyright: 
	Author: 
	Date: 16/11/13 18:38
	Description: 
*/
#include<queue>  //队列 
#include<stack> //栈 
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	queue<int> q; //定义q 
	q.push(2);   //接收第一个 
	q.push(3);  //接收第二个
	q.push(4); //接收第三个fprintf(stderr, "%s\n", );
	q.pop();  //删除头部 
	printf("%d\n",q.front());//输入头部 
	cout << q.back();       //c++方式输出尾部 
}
