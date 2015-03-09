#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct input
{
	char f_name[35];
	int  f_score;
	struct input *next;
};

int main()
{
	struct input *current;
	struct input *prev;
	struct input *head;
	int n; 
	int i=1;
	printf ("请输入有多少个学生>=1:");
	scanf ("%d", &n);
	head = NULL;
	for (i = 1; i <= n; i++)
	{
		current = (struct input *)malloc(sizeof(struct input));
		printf ("请输入第%d个学生的姓名和分数:\n",i);
		scanf ("%s %d",current->f_name,&current->f_score);
		if (head == NULL)
			head = current;
		else 
			prev->next = current;
		current->next = NULL;
		prev = current;
	}
	if (head == NULL)
		printf ("No data input\n");
	else
		current = head;
	printf ("下列是%d个学生信息:\n",n);
	while (current != NULL)  //如果为current->next会少输出一个元素
	 
	{
		printf ("姓名:%s 分数:%d\n",current->f_name,current->f_score);
		current = current->next;
	}
	current = head;
	while (current->next != NULL)
 	{
 		free (current);
 		current = current->next;
 	}
	return 0;
}
