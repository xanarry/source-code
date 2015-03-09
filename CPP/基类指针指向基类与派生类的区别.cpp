#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
	string name;
	char sex;
	int age;
public:
	Person(string n, char s, int a)
	{
		name = n;
		sex = s;
		age = a;
	}
	~Person(){}
	void show()
	{
		cout << "name = " << name << endl;
		cout << "sex = " << sex << endl;
		cout << "age = " << age << endl;
	} 
};

class Teacher: public Person
{
private:
	int TeachNum;
	string major;
public:
	Teacher(string n, char s, int a, int t, string m):Person(n, s, a)
	{
		TeachNum = t;
		major = m;
	}
	~Teacher(){}
	void Teacher::show()////
	{					////
		Person::show();	////���������������������ͬ����������������Ӧ��ʹ��������ʾ����
		cout << "TeachNum = " << TeachNum << endl;
		cout << "major = " << major << endl;
	}
};

int main(int argc, char const *argv[])
{
	cout << "----------------����--------------------" << endl;
	Person p1("xiongyang", 'F', 21);
	p1.show();

	cout << "----------------������------------------" << endl;
	Teacher t1("Zhang", 'M', 12, 234123, "CS");
	t1.show();

	cout << "-------------����ָ��ָ�����-----------" << endl;
	Person *p2;
	p2 = &p1;
	p2->show();

	cout << "------------����ָ��ָ��������-----------" << endl;
	p2 = &t1;
	p2->show();
	////////////////////////////////////////////////////////////////////////////
	//ָ������ָ������ָ����໹�ǻ���������඼ֻ����ʾ�����ڻ��ಿ�ֵ�����//
	////////////////////////////////////////////////////////////////////////////
	return 0;
}
