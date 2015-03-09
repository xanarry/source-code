#include <iostream>
#include <vector>

using namespace std;
using std::vector;

int main(int argc, char const *argv[])
{
	int a[20];//define a integer array has 20 elements;
	cout << "The elements of a[20] is as follows" << endl;
	for (int i = 0; i < 20; i++)
	{
		a[i] = 2 * i + 1;//assian
		cout << a[i] << " ";//output the original elements 
	}
	cout << "\nnow put them to a vector" << endl;

//I use the first way//
	vector<int> v(a, a + 20);//first method to import elements to a vector object 'v'

//	vector<int> v;

//	v.assign(a, a+20);//second method
//	copy(a, a+20, back_inserter(v));//third method

	vector<int>::iterator iter;//define a iterator
	for (iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter << " ";//traversal elements
	}

	cout << endl;
	vector<int>::iterator iter1 = v.begin() + v.size()/2;//get the mid location of the vector object;

//can't use this way to get the min location, because "v.end()" is unknown
//	vector<int>::iterator iter1 = (v.begin() + v.end())/2;
	cout << "the rest half of the elements" << endl;
	for (; iter1 != v.end(); iter1++)
	{
		cout << *iter1 << " ";
	}
	cout << endl;
	return 0;
}
