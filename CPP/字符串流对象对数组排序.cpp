#include <strstream>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	char ary[100] = "1 23 2 34 5 56 -12 354 125 86 -324 234 782 -879 9876 0";
	cout << "array in string\n" << ary << endl;
	int num[16], t, i, j;

	istrstream strin(ary, sizeof(ary));//estabilish the string object with whole string array, because of "sizeof(ary)";

	for(i = 0; i < 16; i++)
	{
		strin >> num[i];//extract data to integer array,but this way is only viable when number is separated be space
	}
	cout << "array of int" << endl;
	for(i = 0; i < 16; i++)
	{
		cout << num[i] << ' ';//output extracted numbers;
	}
	cout << endl;
///////////////////////////////////////////
	for(i = 0; i < 15; i++)
	{
		for(j = 0; j < 15 - i; j++)
		{
			if(num[j] > num[j + 1])
			{
				t = num[j];
				num[j] = num[j + 1];
				num[j + 1] = t;
			}
		}
	}////use bubble sort to sort this array
///////////////////////////////////////////
	cout << "now array has ordered" << endl;
	for(int i = 0; i < 16; i++)
	{
		cout << num[i] << ' ';//output new array
	}
	cout << endl;

	char ary1[100];//create a new array
	cout << "write all nubers in array to string stream" << endl;

	ostrstream strout(ary1, sizeof(ary1));//create a output string stream object

	for(i = 0; i < 16; i++)
	{
		strout << num[i] << ' ';//write new data to this object
	}
	strout << ends;

	cout << ary1;//output the string
	cout << endl;
	return 0;
}
