#include <iostream>
using namespace std;

///////////////////主要函数声明/////////////////
void show(int a[], int);
bool _find(int a[], int lena, int obj);
void jiao(int a[], int lena, int b[], int lenb);
void bing(int a[], int lena, int b[], int lenb);
void cha(int a[], int lena, int b[], int lenb);

int main(int argc, char const *argv[])
{
	int m, n;
	cout << "请分别输入两个集合的元素个数" << endl;
	cin >> m >> n;//m,m表示两个集合元素分别有m,n个

	int *a = new int[m];//集合a
	int *b = new int[n];//集合b

	///注意：在输入集合元素的时候要保证集合中没有相同的元素，因为没有写筛选函数
	cout << "请输入集合a" << endl;
	for (int i = 0; i < m; ++i)
	{
		cin >> a[i];//填充集合a
	}

	cout << "请输入集合b" << endl;
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];//填充集合b
	}

	jiao(a, m, b, n);//求交集
	bing(a, m, b, n);//求并集
	cha(a, m, b, n);//求差集
	
	return 0;
}

void show(int a[], int len)//定义show函数输出数组元素
{
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";//遍历数组，每两个数字用‘ ’隔开
	}
	cout << endl;//换行
}

bool _find(int a[], int lena, int obj)//_find查找一个数字是否在一个数组中，参数1是要搜索的数组，2是数组的长度，3是要搜索的数字
{
	for (int i = 0; i < lena; i++)//遍历数组
	{
		if (a[i] == obj)
			return true;//如果找到这个数，返回true，并退出函数
	}
	return false;//没有这个数字的话，返回false
}

void jiao(int a[], int lena, int b[], int lenb)//求交集，参数分别是数组1，数组1的长度；数组2，数组2的长度
{
	int *r = new int[lenb];//交集数组的长度肯定小于等于传递过了的任意两个数组的长度，随便取lenb
	int k = 0;//定义k为新数组的下标
	for (int i = 0; i < lena; i++)//遍历数组a
	{
		for (int j = 0; j < lenb; j++)//遍历数组b
		{
			if (a[i] == b[j])
				r[k++] = a[i];//如果两个集合中都有同一个元素，那么他应该是属于交集的元素
		}
	}

	if (k == 0)
		cout << "Empty" << endl;//如果交集为空，输出Empty
	else
		show(r, k);//调用函数输出交集
}

void bing(int a[], int lena, int b[], int lenb)//参数同上
{
	int k = 0;//k同上
	int *r = new int[lenb + lena];//定义并集数组，元素的最多时是两个集合元素个数相加
	for (int i = 0; i < lena; ++i)
	{
		r[k++] = a[i];//并集肯定包含a集合的所有元素
	}

	for (int i = 0; i < lenb; ++i)
	{
		if(!_find(a, lena, b[i]))//遍历b集合，如果这个元素a集合中没有
			r[k++] = b[i];//那么将其写到并集集合中
	}
	if (k == 0)
		cout << "Empty" << endl;
	else
		show(r, k);//同上
}

void cha(int a[], int lena, int b[], int lenb)//同上
{
	int len, k = 0;//同上
	len = (lenb > lena) ? lenb: lena;//差集元素个数取，两个集合个数最多的，比如与空集的差集的时候
	int *r = new int[len];//开辟数组存储差集元素
	for (int i = 0; i < lena; i++)//遍历数组a
	{
		if(!_find(b, lenb, a[i]))
			r[k++] = a[i];//在集合b中去查找a集合中的每一个元素，如果没有查找到，那么这个元素应该属于差集
	}

	if (k == 0)
		cout << "Empty" << endl;
	else
		show(r, k);//同上
}
