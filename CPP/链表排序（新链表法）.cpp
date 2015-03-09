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

//方案二：在原链表中找出最小的节点并并入另一个新链表中（头节点为head_2)
//反复重复这个操作，直到原链表只剩下一个节点为止
//则原链表中的节点全部并入并重新组合成了一个新链表

List*sort(List*head)
{
	List*head_2=new List;

	List*p3=head,*p1,*p2,*p4,*p5,*p6;
	p6=head_2;
	while(p3->next->next!=NULL)//注意外层循环终止的条件
	{
		p3=head;

		p2=p3->next;
		p1=p2;
		p5=p1;

		bool flag=false;
		while(p1->next!=NULL)//内存循环终止的条件
		{
			if(p5->num>p1->next->num)
			{
				p5=p1->next;
				
				p4=p1;
				flag=true;
			}
			p1=p1->next;
		}
		if(flag)
		{
			p4->next=p5->next;
		}
		else//此种情况为头节点后面第一个节点<=它后面所有节点的值（即num的值），要慎重考虑
		{
			p3->next=p3->next->next;
		}
		p6->next=p5;
		p6=p6->next;
	}

	p6->next=p3->next;
	p6=p6->next;

	return head_2;
}

int main()
{
	List*head=creat();

	head=sort(head);
	cout<<endl<<endl;
	head=head->next;
	while(head!=NULL)
	{
		cout<<head->num<<' ';
		head=head->next;
	}
	cout<<endl<<endl;

	return 0;
}
