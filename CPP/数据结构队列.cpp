/*
	Name: c++,���ݽṹ������ (�Ƚ��ȳ��� 
	Copyright: 
	Author: 
	Date: 16/11/13 18:38
	Description: 
*/
#include<queue>  //���� 
#include<stack> //ջ 
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	queue<int> q; //����q 
	q.push(2);   //���յ�һ�� 
	q.push(3);  //���յڶ���
	q.push(4); //���յ�����fprintf(stderr, "%s\n", );
	q.pop();  //ɾ��ͷ�� 
	printf("%d\n",q.front());//����ͷ�� 
	cout << q.back();       //c++��ʽ���β�� 
}
