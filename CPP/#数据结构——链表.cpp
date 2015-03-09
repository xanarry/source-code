#include<list>
#include<stdio.h>
using namespace std;
int main()
{
	list <int> a;
	a.push_front(1);
	a.push_front(2);
	a.push_front(3);
	a.push_front(4);
	a.push_front(5);
	a.push_front(6);
	a.push_front(7);
	a.push_front(8);
	a.push_back(9);
	a.push_back(10);
	a.sort();
	list<int>::iterator i;
	for(i=a.begin(); i != a.end(); i++)
	printf("%d ",*i);
	return 0;
}
