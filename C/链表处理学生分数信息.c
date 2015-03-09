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
	printf ("�������ж��ٸ�ѧ��>=1:");
	scanf ("%d", &n);
	head = NULL;
	for (i = 1; i <= n; i++)
	{
		current = (struct input *)malloc(sizeof(struct input));
		printf ("�������%d��ѧ���������ͷ���:\n",i);
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
	printf ("������%d��ѧ����Ϣ:\n",n);
	while (current != NULL)  //���Ϊcurrent->next�������һ��Ԫ��
	 
	{
		printf ("����:%s ����:%d\n",current->f_name,current->f_score);
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
