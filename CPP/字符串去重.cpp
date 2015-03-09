#include <iostream>
#include <cstring>

using namespace std;

char *deal(char *, char *);
int main(int argc, char const *argv[])
{
	char str[1000];
	char c_str[1000];
	cin >> str;
	cout << "original string is: " << str << endl;
	deal(c_str, str);
	cout << "after conduct: " << c_str << endl;
	return 0;
}

char *deal(char _new[], char *t)
{
	int k = 1;//record the new char array's length
	int state = 0;//mark if the new char has been insert into the array whitch we wanne return
	_new[0] = t[0];//fitrst charactor must be inserted
	for (int i = 1; i < strlen(t); i++)//traverse the original array
	{
		state = 0;//state
		for (int j = 0; j < k; j++)//travers the new array
		{
			if (t[i] == _new[j])//judge if the new charactor has been instered
			{
				state = 1;
				break;
			}
		}
		if (state != 1)//if the charactor that is going to insert has not been the new array
		{
			_new[k] = t[i];//then insert it in the new array
			k++;//length auto increase 1
		}
	}
	_new[k] = '\0';//to end the char array;
	return _new;//return it, and each word of this array is different;
}
