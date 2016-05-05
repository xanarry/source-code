#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

int cnt;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *func(void * n)
{
    int fd = (int ) n;
    char buf[20];
    sprintf(buf, "your connection socket: %d", fd);

    write(fd, buf, strlen(buf));
    sleep(4);

    close(fd);
    pthread_mutex_lock(&mutex);
    cnt--;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}


int main(int argc, char const *argv[])
{
    int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_socket < 0)
    {
        printf("create socket failed\n");
        exit(-1);
    }

    int flags = fcntl(server_socket, F_GETFL, 0);
    fcntl(server_socket, F_SETFL, flags | O_NONBLOCK);



    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");//or INADDR_ANY; /* auto-fill with my IP */
    server_addr.sin_port = htons(8888);

    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));

    listen(server_socket, 5);

    struct sockaddr_in client_addr;
    socklen_t len = sizeof(client_addr);

    int new_socket;
    puts("waiting...");

    while (1)
    {
        new_socket = accept(server_socket, (struct sockaddr *) &client_addr, &len);
        if (new_socket == -1)
        {
            if (errno==EAGAIN || errno == EWOULDBLOCK)
            {
                printf("no client connections yet\n");
                sleep(1);
            }
            else
            {
                puts("connect failed");
                exit(-1);
            }
        }
        else
        {
            pthread_mutex_lock(&mutex);
            cnt++;
            pthread_mutex_unlock(&mutex);

            while (cnt > 4)
            {
                printf("max connection execess, waiting: %d\n", cnt);
                sleep(1);
            }

            printf("start thread to deal new connection, cnt=%d\n", cnt);
            pthread_t thread;
            pthread_create(&thread, NULL, func, (void *) new_socket);

        }
    }
    return 0;
}

