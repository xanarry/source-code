#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char const* argv[])
{
	struct sockaddr_in client_addr;
	memset(&client_addr, 0, sizeof(client_addr));
	client_addr.sin_family = AF_INET;
	client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	client_addr.sin_port = htons(8888);

	char buf[100];
	while (1)
	{
		int client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		connect(client_socket, (struct sockaddr *) & client_addr, sizeof(client_addr));

		printf("input a string:");
		scanf("%s", buf);
		write(client_socket, buf, sizeof(buf));

		read(client_socket, buf, sizeof(buf) - 1);
		printf("Server reply: %s\n", buf);

		memset(buf, 0, sizeof(buf));
		close(client_socket);
	}
}
