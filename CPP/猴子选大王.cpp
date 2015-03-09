#include <iostream>
using namespace std;

struct Node//����ڵ�ṹ��
{
	int n;//�ڵ�����
	Node *next;//һ���ṹ��ָ��
};

Node * Create(const int);//������������ĺ���
void Conduct(Node *, const int ,const int);//����ɸѡ����ĺ���
void free(Node *);//�����ͷ��ڴ�ĺ���

int main(int argc, char const *argv[])
{
	int m, n;//����m��ʾ�ڵ�������n��ʾ�����Ǳ������������
	Node *p = NULL;//����սṹָ��
	while (1)
	{
		cout << "��������Ӹ������������������" << endl;
		cin >> m >> n;//��������

		if (m == 0)
			return 0;

		p = Create(m);//���ú�������ѭ������

		Conduct(p, m, n);//���ú���ɸѡ����
	}

	free(p);
	return 0;
}

Node * Create(const int n)
{
	int i = 1;//����i����
	Node *head = NULL;//����headͷָ��Ĭ��ָ��null
	Node *previous;//�����ʾ��һ���ڵ��ָ��
	Node *current;//�����ʾ��ǰ�ڵ��ָ��
	while (i <= n)//ѭ��n�Σ�Ϊÿ�����Ӵ����ڵ�
	{
		current = new Node();//�����µĽڵ��ڴ�ռ�
		current->n = i;//��ÿ���ڵ㸳ֵ
		if (head == NULL)
			head = current;//���ͷ�ڵ�Ϊ�գ���Ӧ����ͷ���ָ���¿��ٵĽڵ��ַ
		else
			previous->next = current;//����Ѿ����ǵ�һ���ڵ㣬������һ���ڵ�ġ�next��ָ���µĽڵ㣬���ܴ���һ��

		previous = current;//�ٽ���һ��λ�õ�ָ�������һλ����Ϊ����Ĳ���ʹ��������һ���ڵ�
		i++;
	}
	current->next = head;//�����һ���ڵ�ġ�next��ָ��ͷ�ڵ㣬ʵ�������ѭ��
	return head;//��������ͷָ���������
}

void Conduct(Node *head, const int i, const int x)
{
	Node *p = NULL;//������ʱָ��
	Node *previous;//�����ʾ��һ���ڵ��ָ��
	p = head;//��ȡ�������
	int t = 1;//����tģ����ӱ���
	int count = i;//����count��ʾ�����е���Ч�ڵ�����
	while(p != NULL)//�������Ϊ�գ���ִ�����²���
	{
		if(t%x == 0)//��ʾ�������������ñ���β����t��ʾ���ñ�������x��ʾ���������ֵ
		{
			previous->next = p->next;//ɾ����ʾ������ӵĽڵ�
			count--;//�����е���Ч�ڵ��һ
		}

		previous = p;//��¼��ǰ�ڵ�
		p = p->next;//�ڵ��������ƶ�

		t++;//���������ӣ���һֱ�����ӵģ�������ȥʵ�ֱ�����ѭ��

		if(count == 1)//������ֻʣ��һ����Ч�ڵ�
			break;//��ֹ�����ų��ڵ�
	}
	cout << "������" << p->n << "��\n" << endl;//���������µĽڵ��ʾ����
}

void free(Node *t)
{
	Node *p = t;
	while (p != NULL)
	{
		delete(p);//�ͷŽڵ�
		p = p->next;
	}
}
