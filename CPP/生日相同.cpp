#include <iostream>
#include <string>
using namespace std;

struct STUDENT//����ṹ��
{
	string StuNum;//ѧ��
	int Month;//������
	int Day;//������
};

int main(int argc, char const *argv[])
{
	int n, i, count[12][31] = {0};//����count�����¼ÿ�����ճ��ֵĴ���
	STUDENT Student[1001];//
	cout << "������ѧ���ĸ���" << endl;
	cin >> n;//����ѧ������
	cout << "����������ÿ��ѧ������Ϣ" << endl;
	for (i = 0; i < n; i++)//ѭ������ÿ��ѧ������Ϣ
	{
		cin >> Student[i].StuNum >> Student[i].Month >> Student[i].Day;
	}

	for (i = 0; i < n; i++)
	{
		//ͳ��������Ϣ��ÿ�����ճ��ֵĴ��������Ҽ�¼��count������
		count[ Student[i].Month - 1 ][ Student[i].Day - 1 ]++;
		//������±�1���·�-1��ֵ���±�2����-1��ֵ
	}

	for (i = 0; i < 12; i++)//����ÿ�£�0-11),�±�ʾ��0��ʼ��
	{
		for (int j = 0; j < 31; j++)//����ÿ��(0-30)���±��Ǵ�0��ʼ��
		{
			if(count[i][j] > 1)//���������ճ��ֵĴ���������1��
			{
				cout << i + 1 << " " << j + 1 << " ";//����������
				for (int k = 0; k < n; k++)//�����ṹ������
				{
					//Ѱ��������������ڵ�����ѧ�������
					if(Student[k].Month == (i + 1) && Student[k].Day == (j + 1) )
						cout << Student[k].StuNum << " ";
				}
				cout << endl;//������У�׼����һ�����յ����
			}
		}
	}
	return 0;
}
