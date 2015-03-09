#include <fstream>
#include <iostream>
#include <ctype.h>
using namespace std;

char str[90];

void in(char *str)
{
	ofstream outfile("text.txt");//out info to file
	for(int i = 0; str[i] != '\0' ; i++)//get a charactor
	{
		cout.put(str[i]);//display the charactor
		outfile << str[i];//write it to file
	}
	outfile.close();//close handle
}

void out()
{
	ifstream infile("text.txt", ios::in);//open a handle
	ofstream outfile("uptext.txt");//ditto
	int i = 0;
	char c;
	while(infile.get(c))//get charactor from the handle of infile
	{
		if(c >= 97 && c <= 122)//if the charactor is lower, then translate it to upper
		{
			c -= 32;//function part
		}
		cout.put(c);//display new charactor
		outfile << c;//write new info to new file
	}
}

int main(int argc, char const *argv[])
{
	cin.getline(str, 90);//get a string, max length is 90
	cout << endl;
	in(str);
	cout << endl;
	out();
	cout << endl;
	return 0;
}
