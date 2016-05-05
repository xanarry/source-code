#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
	int server_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(8888);

	//a udp server also need to bind with a address
	bind(server_socket, (struct sockaddr *) &addr, sizeof(addr));

	/*
		the difference between udp and tcp is tcp connection need 
		listen() and accept() while upd connection do not need 
		neither of these two function

		and there are two specific io function for udp connection
		is recvfrom() and sendto(), equal to read() and write()
	*/
	int len;
	char buf[200];

	struct sockaddr_in in_addr;
	socklen_t in_addr_len = sizeof(in_addr);

	while (1)
	{
		puts("\nwaiting for data...");
		//recieve data
		len = recvfrom(server_socket, buf, 200, 0, (struct sockaddr *) &in_addr, &in_addr_len);

		buf[len] = 0;
		printf("recieve data \"%s\" from %s:%d\n", buf, inet_ntoa(in_addr.sin_addr), ntohs(in_addr.sin_port));

		//reply data
		sendto(server_socket, buf, strlen(buf), 0, (struct sockaddr *) &in_addr, in_addr_len);
	}

	return 0;
}

ACCEPTED
WRONG_ANSWER
PRESENTATION_ERROR 3
TIME_LIMIT_EXCEEDED 4
MEMORY_LIMIT_EXCEEDED 5
OUTPUT_LIMIT_EXCEEDED 6
SEGMENTATION_FAULT 7
FLOATING_POINT_EXCEPTION 8
COMPILATION_ERROR 9
RUNTIME_ERROR 10
SYSTEM_ERROR 11