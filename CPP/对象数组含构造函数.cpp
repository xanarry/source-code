#include <iostream>
#include <cstring>

using namespace std;

class student
{
private:
	char name[10];
	char sex;
	int num;
public:
	student(char n[], char s = 'F', int nu = 0)
	{
		strcpy(name, n);
		sex = s;
		num = nu;
	}

	void show_info()
	{
		cout << "name = " << name << endl;
		cout << "sex = " << sex << endl;
		cout << "number = " << num << endl;
	}
};

int main(int argc, char const *argv[])
{
	student stu1[3] = {"zhang", "wang", "li"};//*如果仅仅扣提供数组元素个数的参数，那么将会给每个数组的第一个属性赋值
	for(int i = 0; i < 3; i++)
	{
		stu1[i].show_info();
		cout << endl;
	}
	cout << endl;

	student stu2[3] = {
		student("zhang", 'F', 1),
		student("wang", 'M', 2),
		student("zhao", 'F', 3)
	};//**如果要同时初始化多个数组元素，应该在定义对象数组时使用多个构造函数
	for(int i = 0; i < 3; i++)
	{
		stu2[i].show_info();
		cout << endl;
	}
	cout << endl;
	return 0;
}
