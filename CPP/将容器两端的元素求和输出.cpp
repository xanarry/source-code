#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	std::vector<int> v;
	while (cin >> n)
	{
		v.push_back(n);
	}

	cout << "the data you input as fallowing" << endl;
	std::vector<int>::iterator iter = v.begin(), iter1;
	for (; iter != v.end(); iter++)
	{
		cout << *iter << " ";
	}

	cout << "\nthis is the result of tail plus head" << endl;

	iter = v.begin();//Ԫ�����
	iter1 = --v.end();//Ԫ���յ�
	
	while (iter <= iter1)//��ͷβû������ʱ
	{
		cout << *iter << "+" << *iter1 << "=" << *iter + *iter1 << endl;
		iter++;//ͷ����������
		iter1--;//β������ǰ��
	}
	return 0;
}
