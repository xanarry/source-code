#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
 
int main(int argc, char const *argv[])
{
    /*this is client*/
    int client_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    struct sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    client_addr.sin_port = htons(8888);

    int len;
    socklen_t a_len = sizeof(client_addr);
    char buf[200];

    while (1)
    {
        printf("input a msg:");
        scanf("%s", buf);
        sendto(client_socket, buf, strlen(buf), 0, (struct sockaddr *) &client_addr, a_len);

        len = recvfrom(client_socket, buf, 200, 0, (struct sockaddr *) &client_addr, &a_len);
        buf[len] = 0;
        printf("server reply: %s\n", buf);
    }
    return 0;
}