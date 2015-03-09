#include <iostream>
#include <windows.h>
#include <cstdio>
#include <conio.h>

using namespace std;

void show(int);

int main(int argc, char const *argv[])
{
	char c;
	int t;
	int state = 1;
	show(state);
	while(1)
	{
		c = getch();
		t = (int)c;
		switch(t)
		{	
			case 72:
				if (state > 1)
				{
					state--;
					system("cls");
					show(state);
				}
				break;
			case 80:
				if (state < 7)
				{
					state++;
					system("cls");
					show(state);
				}
				break;
			case 13:
				system("cls");
				cout << "you choose " << state << state << state << endl;
				show(state);
				break;
		}
	}
	
	return 0;
}

void show(int n)
{
	if (n == 1)
		printf("\t[*]:11111111\n");
	else
		printf("\t[ ]:11111111\n");
		
	if (n == 2)
		printf("\t[*]:22222222\n");
	else
		printf("\t[ ]:22222222\n");
		
	if (n == 3)
		printf("\t[*]:33333333\n");
	else
		printf("\t[ ]:33333333\n");
		
	if (n == 4)
		printf("\t[*]:44444444\n");
	else
		printf("\t[ ]:44444444\n");
		
	if (n == 5)
		printf("\t[*]:55555555\n");
	else
		printf("\t[ ]:55555555\n");
		
	if (n == 6)
		printf("\t[*]:66666666\n");
	else
		printf("\t[ ]:66666666\n");
		
	if (n == 7)
		printf("\t[*]:77777777\n");
	else
		printf("\t[ ]:77777777\n");
}
