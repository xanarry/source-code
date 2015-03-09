#include <iostream>
#include <string>
using namespace std;

class School
{
private:
	string School_Name;
	int School_History;
	int School_Code;
public:
	School(string SN = "万二中", int SH = 70, int SC = 100):School_Name(SN), School_History(SH), School_Code(SC){} 
	void show_info()
	{
		cout << "School_Name: " << School_Name << endl;
		cout << "School_History: " << School_History << endl;
		cout << "School_Code: " << School_Code << endl;
		cout << "Branch_School_Num: " << Branch_School_Num << endl;
	}
	static int Branch_School_Num;
};

int School::Branch_School_Num = 0;

int main(int argc, char const *argv[])
{
	School s1;//只有一个学校对象，分校默认个数是0；
	s1.show_info();
	cout << "\n添加一个新的分校之后\n";
	School s2;//有新建一个学校对象为分校
	School::Branch_School_Num += 1;//那么分校数量加1
	s2.show_info();//输出最新的信息
	return 0;
}
