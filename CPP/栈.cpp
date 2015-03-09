#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Stack
{
	int size;//stack's max size
	int *base;
	int *top;
};

bool init_stack(Stack &s)
{
	cout << "input the size of the stack: ";
	cin >> s.size;
	s.base = new int[s.size];//aplay sizof(int) * size space;
	if(s.base == NULL)
		return false;//if aplay failed;
	s.top = s.base;//s.top and s.base should point to the same location
}

int get_top(Stack &s)
{
	if (s.base == s.top)
		exit(1);
	int value = *(s.top - 1);//get too element
	return value;
}

bool push(Stack &s, int n)
{
	if (s.top - s.base > s.size - 1)
	{
		cout << "Error! overstack" << endl;
		return false;
	}
	*s.top = n;//get new element
	s.top++;//top pointer move up
	cout << n << " has been pushed into" << endl;
	return true;//return tatus
}

int pop(Stack &s)
{
	if (s.base == s.top)
	{
		cout << "this stack has no elements to pop" << endl;
		return false;
	}
	s.top--;
	cout << *s.top << " has been poped" << endl;
	return *s.top;
}

void traversal(Stack &s)
{
	if (s.base == s.top)
	{
		cout << "this stack has no elements to show" << endl;
		exit(1);
	}
	int *tmp = s.top;//in case operator '--' to change the pionter s.top;

	while (tmp != s.base)
	{
		cout << *(--tmp) << endl;
	}
}

int main(int argc, char const *argv[])
{
	Stack s;
	init_stack(s);
	string operation;
	int value;
	cout << "input your operation" << endl;
	while (cin >> operation)
	{	
		if (operation == "push")
		{
			cin >> value;
			push(s, value);
		}
		if (operation == "pop")
			pop(s);
		if (operation == "get_top")
			cout << get_top(s) << endl;
		if (operation == "traversal")
			traversal(s);
	}
	return 0;
}
