//��������ʾ������������򷽷�
//��Ȼ������������һЩ���򷽷�
//����ѡ��
//����ֻҪ�㶮����������ӣ����뷽��
//�������򷽷����׶�

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


//����һ��ð�ݷ������������������ƣ�,�ڱ���������ֵ��num�����Ӵ�С����
//�����˼��Ϊ��ָ��p3ʼ��ָ��p2��ǰһ���ڵ㣬
//p2ʼ��ȡ������p2�Ժ�ڵ����Сֵ
//ָ��p5����p2�Ժ�ڵ�����Сֵ�Ǹ��ڵ㣬��p4ʼ��ָ��p5��ǰһ���ڵ�
//����Сֵ�ڵ�ķ�ʽ���һ�ַ���ð�ݷ���������
//�о������������ر��ӣ�ָ��ָȥ���ͷ�����ǵ�
//����ͨ����һЩ�򵥵�ͼ���������
//�����׳���

List * sort(List*head)
{
	List *p3=head;

	List *p2,*p1,*p4,*p5;
	while(p3->next->next!=NULL)//ע��������ǰ�ƽ��ķ�ʽ(�ܱ�ʾֻ��һ���ڵ�) 
	{
		p2=p3->next;
		p5=p2;

		p1=p2;

		bool flag=false;

		while(p1->next!=NULL)//�ڴ�ѭ����ֹ������
		{
			if(p5->num>p1->next->num)//�ҳ�ԭ������ʣ��ڵ���ֵ��С���Ǹ��ڵ�
			{
				p5=p1->next;//p5��¼����ֵ��С�Ľڵ� 
				
				p4=p1;
				flag=true;
			}

			p1=p1->next;
		}
				
		if(flag)//���������ڵ��˳��ֵС�Ľڵ���ǰ��
		{
			if(p2==p4)//�������ΪҪ����˳��������ڵ�����
			{
				p2->next=p5->next;
				p5->next=p2;
				p3->next=p5;
			}
			else//�������ΪҪ�����������ڵ㲻����
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

//�о������������ر��ӣ�ָ��ָȥ���ͷ�����ǵ�
//����ͨ����һЩ�򵥵�ͼ���������
//�����׳���
