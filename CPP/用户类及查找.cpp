#include <iostream>
#include <string>
using namespace std;

class User
{
private:
	string username;
	string userpass;
public:
	User();
	User(string, string);
	~User(){}
	string get_username();
	string get_userpass();
	void set_username(string);
	void set_userpass(string);
};

User::User()
{
	username = "null";
	userpass = "null";
}

User::User(string n, string p)
{
	username = n;
	userpass = p;
}

string User::get_username()
{
	return username;
}

string User::get_userpass()
{
	return userpass;
}

void User::set_username(string n)
{
	username = n;
}
void User::set_userpass(string p)
{
	userpass = p;
}

void find(User a[], int len, string name)
{
	int index;
	bool state = false;
	for (int i = 0; i < len; ++i)
	{
		if (name == a[i].get_username())
		{
			state = true;
			index = i;
			break;
		}
	}
	if (state)
		cout << name << ":" << a[index].get_userpass() << endl;
	else
		cout << "不存在该用户!" << endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	User *u = new User[n];

	string name, pass;
	for (int i = 0; i < n; ++i)
	{
		cin >> name >> pass;
		u[i].set_username(name);
		u[i].set_userpass(pass);
	}
	string find_name;

	while (cin >> find_name)
	{
		find(u, n, find_name);
	}
	return 0;
}
