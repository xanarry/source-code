#include <iostream>
#define elmtpe char//�ڴ��޸�Ҫ�������������

using namespace std;

/*///////////���õĺ���ԭ��//////////////
class Compare
{
private:
	int x, y;
public:
	Compare(int a = 0, int b = 0):x(a), y(b){}
	int Max();
	int Min();
};

int Compare::Max()
{
	return ((x > y)? x:y);
}

int Compare::Min()
{
	return ((x < y)? x:y);
}
*/////////////////////////////////////////

template <class elemtype>//����һ��ģ�壬��������Ϊelemtype
class Compare
{
private:
	elemtype x, y;
public:
	Compare(elemtype a = 0, elemtype b = 0):x(a), y(b){}//�������캯����Ĭ��ֵΪ0
	elemtype Max();
	elemtype Min();
};

template <class elemtype>//���ڷ��������ⶨ�壬��Ҫָ�����º���Ҳʹ�õ�������������
elemtype Compare<elemtype>::Max()//��������Ϊelemtype���ͣ�"Compare<elemtype>"��һ�����壬��ʾ���������࣬
{
	return ((x > y)? x:y);
}

template <class elemtype>//ͬ��
elemtype Compare<elemtype>::Min()//ͬ��
{
	return ((x < y)? x:y);
}

int main(int argc, char const *argv[])
{
	elmtpe a,b;
	cout << "input 2 numbers:" << endl;
	cin >> a >> b;
	Compare<elmtpe> cmp(a,b);//ʹ����ģ�嶨�����
	cout << "min = " << cmp.Min() << endl << "max = " << cmp.Max() << endl;
	return 0;
}
