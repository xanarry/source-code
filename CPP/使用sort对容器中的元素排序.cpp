#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	std::vector<int> v;
	ostream_iterator<int> output(cout, " ");

	for (int i = 0; i < 15; i++)
	{
		v.push_back(rand()%150);//generate 15 random numbers
	}

	cout << "the following is 15 random numvers" << endl;
	copy(v.begin(), v.end(), output);
/*
	for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter << " ";
	}*/
	cout << endl;

	
	cout << "use sort() to sort the numbers of the container" << endl;
	sort(v.begin(), v.end());//use sort() which is included in "algorithm" to sort them
/*
	for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter;
	}
	cout << endl;*/
	copy(v.begin(), v.end(), output);
	return 0;
}
