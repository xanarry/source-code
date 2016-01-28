#include <WINSOCK2.H>
#include <STDIO.H>
#pragma  comment(lib,"ws2_32.lib")

int main(int argc, char* argv[])
{
	WORD sockVersion = MAKEWORD(2,2);
	WSADATA data;
	if(WSAStartup(sockVersion, &data) != 0)
		return 0;

	struct sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;
	serAddr.sin_addr.S_un.S_addr = inet_addr("192.168.1.103");
    serAddr.sin_port = htons(8888);

    char  sendData[100];
    char recData[255];

	while (1)
    {
        SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if(sclient == INVALID_SOCKET)
        {
            printf("invalid socket !\n");
            return 0;
        }

        if (connect(sclient, (struct sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
        {
            printf("connect faild!\n");
            closesocket(sclient);
            return 0;
        }
        printf("input a message:");
        gets(sendData);
        send(sclient, sendData, strlen(sendData), 0);

        int ret = recv(sclient, recData, 255, 0);
        recData[ret] = '\0';
        printf("server reply: %s\n", recData);

        closesocket(sclient);
        memset(recData, 0, sizeof(recData));
        memset(sendData, 0, sizeof(sendData));
    }
	WSACleanup();
	return 0;
}
