#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int show_mem(char *status_path)
{
	const int buf_len = 4096;
	char buf[buf_len];
	int data = 0;
	int stack = 0;
	int fd;
	if ((fd = open(status_path, O_RDONLY)) < 0)
	{
		printf("precess has not been existed\n");
		return -1;
	}

	read(fd, buf, buf_len);
	close(fd);
	char *vm = strstr(buf, "VmData:");
	if (vm)
    	sscanf(vm, "%*s %d", &data);

    vm = strstr(buf, "VmStk:");
    if (vm)
    	sscanf(vm, "%*s %d", &stack);
    
    return data + stack;    
}

int main(int argc, char const *argv[])
{
	int pid;
	if (argc != 2)
	{
		printf("input a process pid:");
		scanf("%d", &pid);
	}
	else
		pid = atoi(argv[1]);
	char status_path[64];
	sprintf(status_path, "/proc/%d/status", pid);
	int size;
	while ((size = show_mem(status_path)) != -1)
	{
		printf("current memsize: %d\n", size);
		sleep(1);
	}
	printf("process finished\n");
	return 0;
}