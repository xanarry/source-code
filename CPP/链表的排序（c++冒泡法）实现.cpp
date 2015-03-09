//本程序演示链表的两种排序方法
//当然还可以其他的一些排序方法
//比如选择法
//但是只要搞懂了链表的连接，插入方法
//其他排序方法都易懂

#include<iostream>
using namespace std;

struct List
{
	int num;
	List *next;
};

List* creat()//创建链表的方式有点奇怪，可是不想改了，呵呵
{
	List *p1,*p2,*head;
	head=new List;
	p1=new List;
	 
	p1->num=8;
	head->next=p1;
	p2=p1;

	for(int i=0;i<10;++i)
	{
		p1=new List;
		cin>>p1->num;

		p2->next=p1;
		p2=p1;
	}

	p1->next=NULL;
	
	//输出链表 
	List *temp=head->next;
	while(temp!=NULL)
	{
		cout<<temp->num<<' ';
		temp=temp->next;
	}

	return head;
}


//方案一：冒泡法（与数组中排序类似）,在本程序中数值（num）按从大到小排列
//其基本思想为：指针p3始终指向p2的前一个节点，
//p2始终取链表中p2以后节点的最小值
//指针p5代表p2以后节点中最小值那个节点，而p4始终指向p5的前一个节点
//找最小值节点的方式与第一种方案冒泡法排序类似
//感觉链表处理起来特别复杂，指来指去搞得头昏脑涨的
//可以通过画一些简单的图来帮助理解
//很容易出错

List * sort(List*head)
{
	List *p3=head;

	List *p2,*p1,*p4,*p5;
	while(p3->next->next!=NULL)//注意链表向前推进的方式(能表示只有一个节点) 
	{
		p2=p3->next;
		p5=p2;

		p1=p2;

		bool flag=false;

		while(p1->next!=NULL)//内存循环终止的条件
		{
			if(p5->num>p1->next->num)//找出原链表中剩余节点中值最小的那个节点
			{
				p5=p1->next;//p5记录的是值最小的节点 
				
				p4=p1;
				flag=true;
			}

			p1=p1->next;
		}
				
		if(flag)//交换两个节点的顺序，值小的节点往前调
		{
			if(p2==p4)//此种情况为要交换顺序的两个节点相邻
			{
				p2->next=p5->next;
				p5->next=p2;
				p3->next=p5;
			}
			else//这种情况为要交换的两个节点不相邻
			{
				List*temp=p5->next;
				p5->next=p2->next;
				p3->next=p5;
				p4->next=p2;
				p2->next=temp;
			}
		}
		p3=p3->next;
	}

	cout<<endl<<"After sort the result is: "<<endl;

	List*temp=head;
	temp=temp->next;

	while(temp!=NULL)
	{
		cout<<temp->num<<' ';
		temp=temp->next;
	}
	cout<<endl<<endl;

	return head;
}

int main()
{
	List*head=creat();

	head=sort(head);

	return 0;
}

//感觉链表处理起来特别复杂，指来指去搞得头昏脑涨的
//可以通过画一些简单的图来帮助理解
//很容易出错
