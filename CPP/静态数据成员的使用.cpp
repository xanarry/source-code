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
	School(string SN = "�����", int SH = 70, int SC = 100):School_Name(SN), School_History(SH), School_Code(SC){} 
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
	School s1;//ֻ��һ��ѧУ���󣬷�УĬ�ϸ�����0��
	s1.show_info();
	cout << "\n���һ���µķ�У֮��\n";
	School s2;//���½�һ��ѧУ����Ϊ��У
	School::Branch_School_Num += 1;//��ô��У������1
	s2.show_info();//������µ���Ϣ
	return 0;
}
