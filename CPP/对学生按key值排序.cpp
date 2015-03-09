#include <iostream>
using namespace std;

class student;
ostream & operator<<(ostream & s, const student & k);
istream & operator>>(istream & s, student k);

class student
{
	int key;
	string name;
public:
	student(string n, int k):key(k), name(n){}
	student(){}
	~student(){}
	student(const student &s)
	{
		name = s.name;
		key = s.key;
	}
	bool operator<(student);
	bool operator>(student);
	friend ostream & operator<<(ostream & s,const student & k);
	friend istream & operator>>(istream & s,student & k);
};

ostream & operator<<(ostream & s, const student &k)  
{   
	   s << k.name << "   " << k.key;
	   return s;
}

istream & operator>>(istream &s, student &k)
{
	s >> k.name >> k.key;
	return s;
}

bool student::operator<(student st)
{
    return  key < st.key;
}


template <typename T>
void BublleSort(T *a, int Len);

int main(int argc, char const *argv[])
{
	int count;
	int key;
	string name;
	
	cout << "input students' count: ";
	cin >> count;

	student *s = new student[count];
	for (int i = 0; i < count; ++i)
	{
		cout << "student" << i + 1 << " \'s info: ";
		cin >> name >> key;
		s[i] = student(name, key);
	}

	cout << "oringinal data" << endl;
	for (int i = 0; i < count; ++i)
	{
		cout << s[i] << endl;
	}

	BublleSort(s, count);

	cout << "\nbubble sorted by key" << endl;
	for (int i = 0; i < count; ++i)
	{
		cout << s[i] << endl;
	}
	
	return 0;
}

template <typename T>
void BublleSort(T *a, int Len)
{
	T tmp;
	for (int i = 0; i < Len - 1; i++)
	{
		for (int j = 0; j < Len - 1 - i; j++)
		{
			if (a[j] < a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

/*test data
4
xiong 4
zhang 3
yang 1
wang 2
*/
