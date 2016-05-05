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
#include <sys/time.h>


int main(int argc, char const *argv[])
{
    int master_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (master_socket < 0)
    {
        printf("create socket failed\n");
        exit(-1);
    }

    //set non-blocking IO
    int flags = fcntl(master_socket, F_GETFL, 0);
    fcntl(master_socket, F_SETFL, flags | O_NONBLOCK);

/*
    //set master socket to allow multiple connections , this is just a good habit, it will work without this
    int opt = 1;
    if( setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0 )
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
*/

    //set address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;//inet_addr("127.0.0.1");//or INADDR_ANY; /* auto-fill with my IP */
    server_addr.sin_port = htons(8888);

    //bind address for socket
    bind(master_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));

    //listen port
    listen(master_socket, 5);

    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    int new_socket;

    //prepare for select system call
    fd_set socket_fds;
    struct timeval timeout;

    puts("waiting...");

    int max_conn_capacity = 20;
    int max_socket;
    int client_sockets[20] = {0};


    while (1)
    {
        //all the socket file descriptor need to reset each loop
        FD_ZERO(&socket_fds);
        FD_SET(master_socket, &socket_fds);
        max_socket = master_socket;
        timeout.tv_sec = 2;
        timeout.tv_usec = 0;

        //reset all file desecriptor has been use before
        for (int i = 0; i < max_conn_capacity; i++)
        {
            //socket descripters greater than 0 are valid, add valid socket to set
            if (client_sockets[i] > 0)
                FD_SET(client_sockets[i], &socket_fds);

             /*socket descripter is a in numer it will increase as create new connect socket
              so, update the max socket descriptor to decrease the loop time from select
            */
            if (client_sockets[i] > max_socket)
                max_socket = client_sockets[i];
        }

        //wait for an activity on one of the sockets , wait 2.5s
        int result = select(max_socket + 1, &socket_fds, NULL, NULL, NULL);
        if (result == -1 && errno != EINTR)
        {
            printf("select error");
        }
        else if (result == 0)
		{
			puts("timeout");
		}

        //is state changing happened on master socket, it must get new connect request
        if (FD_ISSET(master_socket, &socket_fds))
        {
            new_socket = accept(master_socket, (struct sockaddr *) &client_addr, &client_addr_len);
            if (new_socket == -1)
            {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            //inform new connection
            printf("New connection, socket fd is %d, ip is: %s , port: %d\n", new_socket, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

            //send reply msg
            char hello[] = "Hello, connection constructed";
            int len = write(new_socket, hello, strlen(hello));
            if (len != strlen(hello))
                perror("write");

            //add new client socket to array and fd_set
            for (int i = 0; i < max_conn_capacity; i++)
            {
                if (client_sockets[i] == 0)
                {
                    client_sockets[i] = new_socket;
                    printf("Adding to list of sockets as %d\n" , i);
                    break;
                }
            }
        }

        for (int i = 0; i < max_socket; i++)
        {
            int sd = client_sockets[i];
            if (FD_ISSET(sd, &socket_fds))
            {
                char msg[100];
                int len = read(sd, msg, 100);
                if (len == 0)
                {
                    //Somebody disconnected , get his details and print
                    getpeername(sd , (struct sockaddr*)&client_addr , (socklen_t*)&client_addr);
                    printf("Host disconnected , ip %s , port %d \n" , inet_ntoa(client_addr.sin_addr) , ntohs(client_addr.sin_port));

                    //Close the socket and mark as 0 in list for reuse
                    close(sd);
                    client_sockets[i] = 0;
                }
                else
                {
                    msg[len] = '\0';
                    write(sd, msg, strlen(msg));
                }
                //FD_CLR(client_sockets[i], &socket_fds);
            }
        }
    }
    return 0;
}
