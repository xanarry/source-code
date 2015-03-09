/*
要对某个类实例化出来的所有对象按照类中的某一属性排序时，只要在类中定义相关的比较函数，
然后就能调用sort函数就能对这一属性实行快速排序，因为使用sort时，sort就会到类中去查找
是否有相关的比较函数，默认的类中没有，所有需要额外定义-
*/
#include <iostream>
#include <algorithm>

using namespace std;

class Score
{
public:
	Score():math_score(0), cpp_score(0){}
	~Score(){};
	Score(int ms, int cs): math_score(ms), cpp_score(cs), total_score(cs + ms){}

	void set_math_score(int n)
	{
		math_score = n;
	}
	void set_cpp_score(int n)
	{
		cpp_score = n;
	}

	void cal_total_score(int n)
	{
		total_score = n;
	}

	void display()
	{
		cout << "math = " << math_score << " cpp = " << cpp_score << " total_score = " << total_score << endl;
	}

	bool operator < (const class Score a) const//定义类中的比较函数
	{
		return total_score > a.total_score;//返回总分的比较结果给sort函数
	}

private:
	int math_score;
	int cpp_score;
	int total_score;
};

int main(int argc, char const *argv[])
{
	int count, ms, cs;
	cout << "please input student's count" << endl;
	cin >> count;
	Score *s = new Score[count];
	for (int i = 0; i < count; ++i)
	{
		cin >> ms >> cs;
		s[i].set_math_score(ms);
		s[i].set_cpp_score(cs);
		s[i].cal_total_score(ms + cs);
	}

	sort(s, s + count);
	cout << "ordered by total_score" << endl;
	for (int i = 0; i < count; ++i)
	{
		s[i].display();
	}
	return 0;
}

/* test data
10
12 23
43 15
64 36
89 68
67 43
89 68
90 67
99 78
88 64
43 69
*/
