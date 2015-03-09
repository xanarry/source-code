#include <iostream>
#include <vector>
#include <list>

using namespace std;
using std::vector;

int main(int argc, char const *argv[])
{
	/*1*/
	vector<int> v1(10, 3);
	vector<int>::iterator b = v1.begin();
	while (b != v1.end())
	{
		cout << *b << " ";
		b++;
	}
	cout << endl;

	/*2*/
	vector<int> v2 = v1;
	vector<int>::iterator i = v2.begin();
	while (i != v2.end())
	{
		cout << *i << " ";
		i++;
	}
	cout << endl;

	/*2*/
	vector<int> v3 = v2;
	vector<int>::iterator i1 = v3.begin();
	while (i1 != v3.end())
	{
		cout << *i1 << " ";
		i1++;
	}
	cout << endl;

	/*3*/
	vector<int> v4(10);
	vector<int>::iterator i2 = v4.begin();
	while (i2 != v4.end())
	{
		cout << *i2 << " ";
		i2++;
	}
	cout << endl;


	/********************************************
		c++11的新的定义标准，现编译器无法通过
	//5//
	vector<int> v5 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int>::iterator iter = v4.begin();
	while (iter != v4.end())
	{
		cout << *iter << " ";
		iter++;
	}
	cout << endl;
	
	//6//
	vector<int> v6 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	*********************************************/
	return 0;
}
