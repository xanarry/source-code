#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
	/*	创建客户端套接字,
		AF_INET表示使用ipv4类型的地址,
		SOCK_STREAM 表示使用面向连接的数据传输方式
	*/
	//参数=分别为地址族, 传输方式, 传输协议
	int client_socket = socket(AF_INET, SOCK_STREAM, 0);

	/*构建客户端的地址, IP地址和端口都保存在 sockaddr_in 结构体中*/
	struct sockaddr_in server_addr;
	//将结构体中没使用的空间使用0补充
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;//指定地址使用ipv4
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");//设置ip地址
	server_addr.sin_port = htons(8888);//设置请求端口

	//请求与服务端的连接
	connect(client_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));

	char buf[100];//申请缓冲区保存数据
	int len = 0;
	char str[100];

	/*printf("input your name:");
	scanf("%s", str);
	for (int i = 0; i < 30; i++)
		write(client_socket, "12345", 5);

	write(client_socket, str, sizeof(str));
*/
	//从服务端中读取数据
	len = read(client_socket, buf, sizeof(buf) - 1);
	buf[len] = '\0';
	printf("server reply: %s\n", buf);

	//关闭套接字
	close(client_socket);
	return 0;
}
