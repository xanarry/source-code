#include <iostream>

using namespace std;

struct Node//��ʾ����ڵ�Ľṹ��
{
	int num;
	Node *next;
};


void show(Node *);//���������������
bool _find(Node *, int);//�������Һ���
Node * create_linklist(int);//����������������
Node * Jiao(Node *, Node *);//���������󽻼�
Node * Bing(Node *, Node *);//���������󲢼�
Node * Cha(Node *, Node *);//����������


int main(int argc, char const *argv[])
{
	int m, n;
	Node *a = NULL, *b = NULL;//ԭʼ����
	Node *jiao = NULL, *bing = NULL, *cha = NULL;//�ֱ��¼���صĽ������������

	cout << "��ֱ������������ϵ�Ԫ�ظ���" << endl;
	cin >> m >> n;//m,m��ʾ��������Ԫ�طֱ���m,n��

	///ע�⣺�����뼯��Ԫ�ص�ʱ��Ҫ��֤������û����ͬ��Ԫ�أ���Ϊû��дɸѡ����
	a = create_linklist(m);//
	b = create_linklist(n);//

	jiao = Jiao(a, b);//�󽻼�
	show(jiao);//

	bing = Bing(a, b);//�󲢼�
	show(bing);//

	cha = Cha(a, b);//��
	show(cha);//
	
	return 0;
}


void show(Node *h)//�������������
{
	Node *cur = h;
	if(cur == NULL)
		cout << "Empty";//�������Ϊ��,������Ϊ�ռ�������empty
	else
	{
		while (cur != NULL)
		{
			cout << cur->num << " ";//��������ڵ�
			cur = cur->next;
		}
	}
	cout << endl;//�������
}


bool _find(Node *h, int n)//������Һ���
{
	Node *head = h;
	while (head)
	{
		if (n == head->num)
			return true;//�����ָ�������в��ҵ���Ŀ��Ԫ�أ�����TRUE
		head = head->next;
	} 
	return false;//û���в��ҵ�����FALSE
}


Node * create_linklist(int len)//���崴�����Ϻ���
{
	Node *head = NULL;//�����µ�ͷ�ڵ����ڷ��ر�ʾ���ϵ�����
	Node *cur, *pre;//������ָ��һ���ڵ�͵�ǰ�ڵ��ָ��
	for (int i = 0; i < len; i++)//ѭ������len���ڵ㳤��������
	{
		Node *cur = new Node;//�����µĽڵ�
		cin >> cur->num;//�����½ڵ������
		cur->next = NULL;//�ڵ�ĩ��ָ��NULL��Ĭ����Ϊ�յ�ڵ�

		if (head == NULL)
			head = cur;//���ͷ�ڵ�Ϊ�գ���ôӦ����ͷ���ָ���½ڵ�
		else
			pre->next = cur;//��������һ���ڵ��nextָ���½ڵ�
		pre = cur;//��һ���ڵ�ָ���ƶ�����ǰλ��
	}
	return head;//���ر�ʾ���ϵ�����
}


Node * Jiao(Node *a, Node *b)//���彻�����㺯��
{
	Node *r = NULL, *y = b;//rΪ���ص�����ͷָ�룬y��������ѭ���е����
	Node *pre, cur;//������ָ��һ���ڵ�͵�ǰ�ڵ��ָ��
	while (a)//ѭ��a����
	{
		y = b;//�ڲ�ѭ�����Ҫ�����ڲ�ѭ�������
		while(y)//ѭ��b����
		{
			if (a->num == y->num)//������Ԫ����������
			{
				Node * _new = new Node;//�����µĽڵ�
				_new->num = a->num;//����½ڵ������
				_new->next = NULL;//�ڵ�ĩ��ָ��NULL��Ĭ����Ϊ�յ�ڵ�

				if(r == NULL)
					r = _new;//ͬ��
				else
					pre->next = _new;//ͬ��
				pre = _new;//ͬ��
			}
			y = y->next;//�ƶ�b����ָ�뵽һ��һ���ڵ㣬ʵ��ѭ��
		}
		a = a->next;//�ƶ�a����ָ��
	}
	return r;//���ؽ���
}


Node * Bing(Node *a, Node *b)//���岢�����㺯��
{
	Node *r = NULL, *tmp = a;//rΪ���ص�����ͷָ�룬tmp����ѭ��ʹ��
	Node *cur, *pre;//������ָ��һ���ڵ�͵�ǰ�ڵ��ָ��
	while (a)//��������a
	{
		Node * _new = new Node;//�����µĽڵ�
		_new->num = a->num;//����½ڵ������
		_new->next = NULL;//�ڵ�ĩ��ָ��NULL��Ĭ����Ϊ�յ�ڵ�

		if(r == NULL)
			r = _new;//ͬ��
		else
			pre->next = _new;//ͬ��
		pre = _new;//ͬ��

		a = a->next;//�ƶ�ָ�뵽��һ���ڵ�
	}
	/////���ϲ��ֽ�����a�е�����Ԫ���ƶ�������������
	while (b)//��������b
	{
		Node *_new = new Node;//�����µĽڵ�
		_new->num = b->num;//����½ڵ������
		_new->next = NULL;//�ڵ�ĩ��ָ��NULL��Ĭ����Ϊ�յ�ڵ�

		if (!_find(tmp, b->num))//����ֻ�ü���b���е�Ԫ��
		{
			pre->next = _new;//ͬ��
			pre = _new;//ͬ�ϣ����Ǵ�����������131�д�����
		}

		b = b->next;//�ƶ�ָ�뵽��һ���ڵ�
	}
	return r;//���ر�ʾ����������
}


Node * Cha(Node *a, Node *b)//�������㺯��
{
	Node *r = NULL;//rΪ���ص�����ͷָ��
	Node *cur, *pre;//������ָ��һ���ڵ�͵�ǰ�ڵ��ָ��
	while (a)//��������a
	{
		if (!_find(b, a->num))//���a�е�һ��Ԫ�ز�ͬ��b�е��κ�һ��Ԫ�أ���ô���϶������ڲ��
		{
			Node *_new = new Node;//�����µĽڵ�
			_new->num = a->num;//����½ڵ������
			_new->next = NULL;//�ڵ�ĩ��ָ��NULL��Ĭ����Ϊ�յ�ڵ�

			if (r == NULL)
				r = _new;//ͬ��
			else
				pre->next = _new;//ͬ��
			pre = _new;//ͬ��
		}

		a = a->next;//�ƶ�ָ������һ���ڵ�
	}
	return r;//���ز����
}
