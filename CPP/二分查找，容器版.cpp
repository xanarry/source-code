#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int binary_search(std::vector<int> v, int n)
{
	int location;
	std::vector<int>::iterator left = v.begin();
	std::vector<int>::iterator right = v.end();
	std::vector<int>::iterator mid = v.begin() + v.size()/2;

	while (n != *mid)
	{
		if (n > *mid)
			left = mid + 1;
		if (n < *mid)
			right = mid - 1;
		mid = left + (right - left)/2;
	}

	location = mid - v.begin();
	return location + 1;
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	std::vector<int> v;
	const int count = 20;
	
	for (int i = 0; i < count; ++i)
	{
		v.push_back(rand() % 50);
	}

	sort(v.begin(), v.end());

	cout << "the following is a sorted random number" << endl;
	std::vector<int>::iterator iter = v.begin();
	while (iter != v.end())
	{
		cout << *iter << " ";
		iter++;
	}

	int n; 
	cout << "\ninput which number's location you wanna find" << endl;
	cin >> n;
	int location = binary_search(v, n);
	cout << "location is " << location << endl;
	return 0;
}
