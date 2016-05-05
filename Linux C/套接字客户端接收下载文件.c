#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const* argv[])
{
	int client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	struct sockaddr_in client_addr;
	memset(&client_addr, 0, sizeof(client_addr));
	client_addr.sin_family = AF_INET;
	client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	client_addr.sin_port = htons(8888);

	socklen_t addr_len = sizeof(client_addr);

	puts("connecting");
	connect(client_socket, (struct sockaddr *) &client_addr, addr_len);

	int fd = open("/home/xanarry/myeclipse.run", O_CREAT | O_WRONLY);
	char buf[1024];
	int len = 1024;

	puts("downloading");
	while ((len = read(client_socket, buf, 1024)) != 0)
	{
		write(fd, buf, len);
	}

	close(fd);
	shutdown(client_socket, SHUT_RD);

	puts("sending msg");
	write(client_socket, "12345", 6);

	memset(buf, 0, sizeof(buf));

	puts("get msg reply");
	len = read(client_socket, buf, 1024);
	buf[len] = '\0';
	printf("get reply: %s\n", buf);

	close(client_socket);
}
