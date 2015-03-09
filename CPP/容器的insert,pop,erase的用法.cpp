#include <vector>
#include <iostream>

using namespace std;

void display(std::vector<int> v)
{
	std::vector<int>::iterator iter = v.begin();
	while (iter != v.end())
	{
		cout << *iter << " ";
		iter++;
	}
}

int main(int argc, char const *argv[])
{
	std::vector<int> v;
	const int count = 10;
	for (int i = 0; i < count; ++i)
	{
		v.push_back(i + 1);
	}
	display(v);

	cout << "\ninsert(v.end(), 11)" << endl;
	v.insert(v.end(), 11);//尾部
	display(v);

	cout << "\ninsert(v.begin(), 0)" << endl;
	v.insert(v.begin(), 0);//头部
	display(v);

	cout << "\ninsert(v.begin() + 3, 3)" << endl;
	v.insert(v.begin() + 3, 3);//中间
	display(v);

	cout << "\ninsert(v.end(), 3, 12)" << endl;
	v.insert(v.end(), 3, 12);//一段相同的数
	display(v);

	int a[5] = {-1, -2, -3, -4, -5};
	cout << "\na[5] = {-1, -2, -3, -4, -5}, insert(v.begin(), a, a + 5))" << endl;
	v.insert(v.begin(), a, a + 5);//插入一对迭代器范围内的数
	display(v);

	cout << "\nv.erase(v.begin(), begin + 5)" << endl;
	v.erase(v.begin(), v.begin() + 5);//删除一对迭代器范围内的数
	display(v);

	cout << "\ni = 0; while(i < 3) {iter = v.erase(v.end() - 1); i++}" << endl;
	int i = 0;
	std::vector<int>::iterator iter;
	while (i < 3)
	{
		iter = v.erase(v.end() - 1);//删除对迭代器指向的数，返回前一个迭代器
		i++;
	}
	display(v);

	cout << "\nv.pop_back()" << endl;
	v.pop_back();//删除尾部，vector不能使用pop_front()函数，同样不能push_front
	display(v);

	cout << "\nv.erase(v.begin())" << endl;
	v.erase(v.begin());
	display(v);
	return 0;
}

