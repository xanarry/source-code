#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct input
{
	char f_name[35];
	struct input *next;
};

int main()
{
	struct input *current;
	struct input *prev;
	struct input *head;
	char a[35];
	int i=1;
	int k=1;
	head = NULL;
	printf("请输入第1个学生姓名\n");
	while (gets(a)!= NULL)
	{
		current = (struct input *)malloc(sizeof(struct input));
		strcpy (current->f_name,a);
		if (head == NULL)
			head = current;
		else 
			prev->next = current;
		current->next = NULL;
		prev = current;
		printf("请输入第%d个学生姓名:\n",++i);
	}
	if (head == NULL)
		printf ("No data input\n");
	else
		current = head;
	printf ("下列是输入的学生信息:\n");
	while (current != NULL)  //如果为current->next会少输出一个元素
	 
	{
		printf ("学生%d姓名:%s\n",k++,current->f_name);
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
