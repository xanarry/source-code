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
	printf("�������1��ѧ������\n");
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
		printf("�������%d��ѧ������:\n",++i);
	}
	if (head == NULL)
		printf ("No data input\n");
	else
		current = head;
	printf ("�����������ѧ����Ϣ:\n");
	while (current != NULL)  //���Ϊcurrent->next�������һ��Ԫ��
	 
	{
		printf ("ѧ��%d����:%s\n",k++,current->f_name);
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
