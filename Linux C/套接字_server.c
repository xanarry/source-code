#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>//include IPPOTO_TCP, struct sockaddr_in,

int main(int argc, char const* argv[])
{
	/*	创建服务端套接字,
		AF_INET表示使用ipv4类型的地址,
		SOCK_STREAM 表示使用面向连接的数据传输方式
		IPPROTO_TCP 表示使用 TCP 协议
	*/
	int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	/*构建服务端的地址, IP地址和端口都保存在 sockaddr_in 结构体中*/
	struct sockaddr_in server_addr;
	memset(&server_addr, 0, sizeof(server_addr));//空位的内存用0补充
	server_addr.sin_family = AF_INET;//设置地址类型为ipv4
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");//设置ip
	server_addr.sin_port = htons(8888);//设置端口

	//bind() 函数将套接字 serv_sock 与特定的IP地址和端口绑定, 此后通过ip+port的连接相当与直接此套接字
	bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));

	//让套接字处于被动监听状态。指套接字一直处于“睡眠”中，直到客户端发起请求才会被“唤醒”。
	listen(server_socket, 20);

	struct sockaddr_in client_addr;
	socklen_t client_addr_size = sizeof(client_addr);

	char in[100];
	char str[100] = "hello ";
	int len = strlen(str);
	//while (1)
	{
		printf("\nwaiting...\n");
		//accept() 函数用来接收客户端的请求。程序一旦执行到 accept() 就会被阻塞（暂停运行），直到客户端发起请求。
		int client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_size);

		printf("=>get a connect request\n");
		read(client_socket, in, sizeof(in));
		printf("=>get data from client: %s\n", in);

		strcat(str, in);

		write(client_socket, str, sizeof(str));
		close(client_socket);
		memset(in, 0, sizeof(in));
		str[len] = '\0';
	}
	close(server_socket);
	return 0;
}
