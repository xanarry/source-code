#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <netdb.h>


/*
struct hostent *gethostbyname(const char *name);

struct hostent{
    char *h_name;  //official name
    char **h_aliases;  //alias list
    int  h_addrtype;  //host address type
    int  h_length;  //address lenght
    char **h_addr_list;  //address list
}
*/

int main(int argc, char const* argv[])
{
	//https://dl.google.com/dl/android/studio/ide-zips/1.5.0.4/android-studio-ide-141.2422023-linux.zip
	//struct hostent *host = gethostbyname("dl.google.com");
	struct hostent *host = gethostbyname("blog.csdn.net");

	if(!host){
        puts("Get IP address error!");
        exit(0);
    }

	printf("name: %s\n", host->h_name);

	for(int i=0; host->h_aliases[i]; i++)
		printf("alias: %s\n", host->h_aliases[i]);


	printf("type: %s\n", (host->h_addrtype == AF_INET) ? "AF_INET" : "AF_INET6");
	printf("lentgh: %d\n", host->h_length);

	for(int i=0; host->h_addr_list[i]; i++)
		printf("addr: %s\n", inet_ntoa( *(struct in_addr*) host->h_addr_list[i]));


}
