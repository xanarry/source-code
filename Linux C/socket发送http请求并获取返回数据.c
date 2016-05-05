#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
#include <assert.h>

void get_host_domain(const char *url, char *domain)
{
    int j = 0, start = 0;
    char *patterns[] = {"http://", "https://", NULL};

    for (int i = 0; patterns[i]; i++)
        if (strncmp(url, patterns[i], strlen(patterns[i])) == 0)
            start = strlen(patterns[i]);

    for (int i = start; url[i] != '/' && url[i] != '\0'; i++, j++)
        domain[j] = url[i];
    domain[j] = '\0';
}

void get_ip_addr(char *domain, char *ip_addr)
{
    struct hostent *host = gethostbyname(domain);
    if (!host)
        ip_addr = NULL;
    for (int i = 0; host->h_addr_list[i]; i++)
    {
        strcpy(ip_addr, inet_ntoa( * (struct in_addr*) host->h_addr_list[i]));
        break;
    }
}

int main(int argc, char const *argv[])
{
    char header[2048];
    char domain[64];
    char ip_addr[16];

    const char *url = "http://www.baidu.com";

    get_host_domain(url, domain);
    get_ip_addr(domain, ip_addr);
    uint16_t port = 80;

    printf("%s : %s\n", domain, ip_addr);

    sprintf(header, \
            "GET %s HTTP/1.1\r\n"\
            "Accept:text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\n"\
            "User-Agent:Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/47.0.2526.73 Safari/537.36\r\n"\
            "Host:%s\r\n"\
            "Connection:close\r\n"\
            "\r\n\r\n"\
        ,url, domain);
    //printf("%s\n%d", header, (int) strlen(header));

    int client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (client_socket < 0)
    {
        printf("invalid socket descriptor: %d\n", client_socket);
        exit(-1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_addr);
    addr.sin_port = htons(port);


    puts("connect server");
    int res = connect(client_socket, (struct sockaddr *) &addr, sizeof(addr));
    if (res == -1)
    {
        printf("connect failed, return: %d\n", res);
        exit(-1);
    }

    puts("send request");
    write(client_socket, header, strlen(header));

    int buf_len = 2;
    char *buf = (char *) malloc(buf_len * sizeof(char));
    int mem_size = buf_len;

    int length = 0;
    char *response = (char *) malloc(buf_len * sizeof(char));
    int len;

    while ((len = read(client_socket, buf, buf_len)) != 0)
    {
        if (length + len > mem_size)
        {
            mem_size *= 2;
            char * temp = (char *) realloc(response, sizeof(char) * mem_size);
            if (temp == NULL)
            {
                printf("realloc failed\n");
                exit(-1);
            }
            response = temp;
        }
        buf[len] = '\0';
        strcat(response, buf);
        length += len;
    }
    printf("get content:\n-----------------------------------------------\n");
    printf("%s\n", response);
    printf("\n-----------------------------------------------\n");
    return 0;
}
