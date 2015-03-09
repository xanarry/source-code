#include <iostream>
#include <cstdio>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <pthread.h>
#include <conio.h>

using namespace std;

int value = 100;
int i = 0;

void *change_value(void *args)
{
    int input;
    while (1)
    {
        input  = (int)getch();
        if (input == 75)
            cout << input << endl;
    }
}

int main(int argc, char const *argv[])
{
	pthread_t id;
	int ret = pthread_create(&id, NULL, change_value, NULL);
	if (ret != 0)
	{
		cout << "create thread failed" << endl;
		exit(0);
	}
	while (1)
	{
		cout << "value is " << value << endl;
		Sleep(1000);
	}
	return 0;
}
