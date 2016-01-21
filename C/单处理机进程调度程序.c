#include <stdio.h>
#include <stdlib.h>

struct pcb
{
	char name[10];
	char state;
	int priority;
	int ntime;
	int rtime;
	struct pcb *next;
};

struct pcb * put_process_into_queue(struct pcb *process_queue, struct pcb *process)
{
	if (process_queue->next == NULL)
		process_queue->next = process;
	else
	{
		struct pcb *cur = process_queue->next;
		struct pcb *pre = process_queue;
		while (cur && process->priority < cur->priority)
		{
			pre = cur;
			cur = cur->next;
		}
		pre->next = process;
		process->next = cur;
	}
	return process_queue;
}

struct pcb * load_process()
{
	puts("input number of process");
	int n;
	scanf("%d", &n);
	struct pcb *process_queue = (struct pcb *) malloc(sizeof(struct pcb));
	for (int i = 1; i <= n; i++)
	{
		struct pcb *new_process = (struct pcb *) malloc(sizeof(struct pcb));
		printf("input %d process's info: \n", i);
		printf("name: ");
		scanf("%s", new_process->name);
		printf("priority:");
		scanf("%d", &new_process->priority);
		printf("limit time:");
		scanf("%d", &new_process->ntime);
		new_process->rtime = 0;
		put_process_into_queue(process_queue, new_process);
	}
	return process_queue;
}


void show_process_list(struct pcb *process_queue)
{
	puts("----------------------");
	while (process_queue->next)
	{
		printf("[%s, %d, %d, %d] ", process_queue->next->name, process_queue->next->priority, process_queue->next->rtime, process_queue->next->ntime);
		process_queue = process_queue->next;
	}
	puts("\n----------------------");
}

void run_process(struct pcb * process_queue)
{
	struct pcb *cur_run;
	while (process_queue->next)
	{
		show_process_list(process_queue);
		printf("\n");
		cur_run = process_queue->next;
		cur_run->priority--;
		cur_run->rtime++;

		process_queue->next = cur_run->next;
		if (cur_run->rtime == cur_run->ntime)
		{
			printf("process [%s, %d, %d] has finished\n", cur_run->name, cur_run->priority, cur_run->ntime);
			free(cur_run);
		}
		else
			process_queue = put_process_into_queue(process_queue, cur_run);
	}
}

int main()
{
	struct pcb *process_queue;
	process_queue = load_process();
	show_process_list(process_queue);
	run_process(process_queue);
	return 0;
}

/*
3
a
3
4
b
2
4
c
1
4
*/