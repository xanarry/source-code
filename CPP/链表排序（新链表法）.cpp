#include<iostream>
using namespace std;

struct List
{
	int num;
	List *next;
};

List* creat()//��������ķ�ʽ�е���֣����ǲ�����ˣ��Ǻ�
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
	
	//������� 
	List *temp=head->next;
	while(temp!=NULL)
	{
		cout<<temp->num<<' ';
		temp=temp->next;
	}

	return head;
}

//����������ԭ�������ҳ���С�Ľڵ㲢������һ���������У�ͷ�ڵ�Ϊhead_2)
//�����ظ����������ֱ��ԭ����ֻʣ��һ���ڵ�Ϊֹ
//��ԭ�����еĽڵ�ȫ�����벢������ϳ���һ��������

List*sort(List*head)
{
	List*head_2=new List;

	List*p3=head,*p1,*p2,*p4,*p5,*p6;
	p6=head_2;
	while(p3->next->next!=NULL)//ע�����ѭ����ֹ������
	{
		p3=head;

		p2=p3->next;
		p1=p2;
		p5=p1;

		bool flag=false;
		while(p1->next!=NULL)//�ڴ�ѭ����ֹ������
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
		else//�������Ϊͷ�ڵ�����һ���ڵ�<=���������нڵ��ֵ����num��ֵ����Ҫ���ؿ���
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
