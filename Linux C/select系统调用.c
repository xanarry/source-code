#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/select.h>

int main(int argc, char const* argv[])
{
	/*
	this program use select system call to trace the STDIN
	for each check, the select will wait 2.5sec for STDIN state change
	if get state change at any time, select will stop to wait
	*/
	int fd = 0;
	char buf[128];

	fd_set input;

	FD_ZERO(&input);
	FD_SET(0, &input);

	struct timeval time;

	while (1)
	{
		time.tv_sec = 2;
		time.tv_usec = 500000;
		fd_set test = input;
		int result = select(fd + 1, &test, (fd_set *) NULL, (fd_set *) NULL, &time);
		if (result == 0)
		{
			printf("time out\n");
		}
		else if (result == -1)
		{
			printf("error\n");
			exit(-1);
		}
		else
		{
			if (FD_ISSET(fd, &input))
			{
				int nread;
				ioctl(0, FIONREAD, &nread);
				if (nread == 0)
				{
					printf("control key dowb\n");
					exit(0);
				}
				nread= read(fd, buf, nread);
				nread--;
				buf[nread] = 0;
				printf("input %s len: %d\n", buf, nread);
			}
		}
	}

	return 0;
}
