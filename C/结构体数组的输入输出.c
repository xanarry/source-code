#include<stdio.h>
#define N 10
int main(void)
{ 
    int i;
	struct student
	{
		char name[20];
		int age;
		char sex;
		int score;
	};
	struct student a[N];
	
	for(i = 0; i < N; i++)
	{ 
		scanf("%s %d %c %d",a[i].name, &a[i].age, &a[i].sex, &a[i].score);
	} 
	for(i = 0; i < N; i++)
	{
		printf("%s %d %c %d",a[i].name, a[i].age, a[i].sex, a[i].score);
		printf("\n");
    }
    return 0; 
}

