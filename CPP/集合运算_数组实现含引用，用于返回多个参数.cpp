#include <iostream>
using namespace std;

///////////////////��Ҫ��������/////////////////
void show(int a[], int);
bool _find(int a[], int lena, int obj);
int * jiao(int a[], int lena, int b[], int lenb, int &len);
int * bing(int a[], int lena, int b[], int lenb, int &len);
int * cha(int a[], int lena, int b[], int lenb, int &len);

int main(int argc, char const *argv[])
{
	int m, n;
	cout << "��ֱ������������ϵ�Ԫ�ظ���" << endl;
	cin >> m >> n;//m,m��ʾ��������Ԫ�طֱ���m,n��

	int *a = new int[m];//����a
	int *b = new int[n];//����b

	///ע�⣺�����뼯��Ԫ�ص�ʱ��Ҫ��֤������û����ͬ��Ԫ�أ���Ϊû��дɸѡ����
	cout << "�����뼯��a" << endl;
	for (int i = 0; i < m; ++i)
	{
		cin >> a[i];//��伯��a
	}

	cout << "�����뼯��b" << endl;
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];//��伯��b
	}

	int * result;
	int tmp;

	cout << "����:";
	result = jiao(a, m, b, n, tmp);//�󽻼�
	if (tmp == 0)
		cout << "Empty" << endl;
	else
		show(result, tmp);

	cout << "����:";
	result = bing(a, m, b, n, tmp);//�󲢼�
	if (tmp == 0)
		cout << "Empty" << endl;
	else
		show(result, tmp);

	cout << "�:";
	result = cha(a, m, b, n, tmp);//��
	if (tmp == 0)
		cout << "Empty" << endl;
	else
		show(result, tmp);

	return 0;
}

void show(int a[], int len)//����show�����������Ԫ��
{
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";//�������飬ÿ���������á� ������
	}
	cout << endl;//����
}

bool _find(int a[], int lena, int obj)//_find����һ�������Ƿ���һ�������У�����1��Ҫ���������飬2������ĳ��ȣ�3��Ҫ����������
{
	for (int i = 0; i < lena; i++)//��������
	{
		if (a[i] == obj)
			return true;//����ҵ������������true�����˳�����
	}
	return false;//û��������ֵĻ�������false
}

int * jiao(int a[], int lena, int b[], int lenb, int &len)//�󽻼��������ֱ�������1������1�ĳ��ȣ�����2������2�ĳ���
{
	int *r = new int[lenb];//��������ĳ��ȿ϶�С�ڵ��ڴ��ݹ��˵�������������ĳ��ȣ����ȡlenb
	int k = 0;//����kΪ��������±�
	for (int i = 0; i < lena; i++)//��������a
	{
		for (int j = 0; j < lenb; j++)//��������b
		{
			if (a[i] == b[j])
				r[k++] = a[i];//������������ж���ͬһ��Ԫ�أ���ô��Ӧ�������ڽ�����Ԫ��
		}
	}
	len = k;
	return r;
}

int * bing(int a[], int lena, int b[], int lenb, int &len)//����ͬ��
{
	int k = 0;//kͬ��
	int *r = new int[lenb + lena];//���岢�����飬Ԫ�ص����ʱ����������Ԫ�ظ������
	for (int i = 0; i < lena; ++i)
	{
		r[k++] = a[i];//�����϶�����a���ϵ�����Ԫ��
	}

	for (int i = 0; i < lenb; ++i)
	{
		if(!_find(a, lena, b[i]))//����b���ϣ�������Ԫ��a������û��
			r[k++] = b[i];//��ô����д������������
	}
	len = k;
	return r;
}

int * cha(int a[], int lena, int b[], int lenb, int &len)//ͬ��
{
	int length, k = 0;//ͬ��
	length = (lenb > lena) ? lenb: lena;//�Ԫ�ظ���ȡ���������ϸ������ģ�������ռ��Ĳ��ʱ��
	int *r = new int[length];//��������洢�Ԫ��
	for (int i = 0; i < lena; i++)//��������a
	{
		if(!_find(b, lenb, a[i]))
			r[k++] = a[i];//�ڼ���b��ȥ����a�����е�ÿһ��Ԫ�أ����û�в��ҵ�����ô���Ԫ��Ӧ�����ڲ
	}

	len = k;
	return r;
}
