#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BC 1

int main(int argc, char const *argv[])
{
    int server_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    char ip[16];
    if (!BC)
        strcpy(ip, "127.0.0.1");
    else
        strcpy(ip, "255.255.255.255");


    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(8888);
    socklen_t a_len = sizeof(addr);

    //set broadcast
    if (BC)
    {
        int flags = 1;
        socklen_t flags_len = sizeof(flags);
        setsockopt(server_socket, SOL_SOCKET, SO_BROADCAST, &flags, flags_len);
    }

    int buf_len = 1024;
    char buf[1024];
    printf("%s\n", ip);

    while (1)
    {
        printf("input a msg:");
        scanf("%s", buf);

        //reply client a message
        sendto(server_socket, buf, strlen(buf), 0, (struct sockaddr *) &addr, a_len);

        //read message from socket
        int len = recvfrom(server_socket, buf, buf_len, 0, (struct sockaddr *) &addr, &a_len);
        buf[len] = 0;
        printf("get msg \"%s\" from %s : %d\n", buf, inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));

    }
    return 0;
}
