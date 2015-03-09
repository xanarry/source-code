#include <iostream>
using namespace std;

class Time
{
private:
	int hour;
	int min;
	int sec;
public:
	Time(int h = 0, int m = 0, int s = 0);//��һ�����ж�����ȫ����Ĭ�ϲ����Ĺ��캯���󣬲����ٶ������ع���ĺ���
	void show_time();
};

int main(int argc, char const *argv[])
{
	Time t;
	cout << "ֱ�Ӵ�������ʹ��Ĭ�ϲ�����";
	t.show_time();

	Time t1(12);
	cout << "ֱ�Ӷ�������һ��������";
	t1.show_time();

	Time t2(11,06,58);
	cout << "ֱ�Ӷ�������3��������";
	t2.show_time();
	return 0;
}

void Time::show_time()
{
	cout << hour << ":" << min << ":" << sec << endl;
}

Time::Time(int h, int m, int s)
{
	hour = h;
	min = m;
	sec = s;
}
