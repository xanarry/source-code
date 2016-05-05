#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const* argv[])
{
	int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	struct sockaddr_in server_addr;
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(8888);

	bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));

	listen(server_socket, 20);

	struct sockaddr_in client_addr;
	socklen_t addr_len = sizeof(client_addr);

	puts("waiting");
	int client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &addr_len);
	puts("get connect");

	int fd = open("/home/xanarry/downloads/myeclipse-2015-stable-2.0-offline-installer-linux.run", O_RDONLY);
	puts("start send");

	char buf[1024] = {0};
	int len = 1024;

	while ((len = read(fd, buf, 1024)) != 0)
	{
		write(client_socket, buf, len);
	}

	puts("finish send");

	close(fd);
	shutdown(client_socket, SHUT_WR);

	memset(buf, 0, sizeof(buf));

	puts("get msg from client");
	read(client_socket, buf, sizeof(buf));
	puts(buf);

	puts("send msg to client");
	write(client_socket, "56789", 6);

	close(client_socket);
	close(server_socket);
	return 0;
}
