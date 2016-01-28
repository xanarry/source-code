#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

int main(int argc, char* argv[])
{
    //初始化WSA
    WORD sockVersion = MAKEWORD(2,2);
    WSADATA wsaData;
    if(WSAStartup(sockVersion, &wsaData)!=0)
        return 0;

    //创建套接字
    SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(slisten == INVALID_SOCKET)
    {
        printf("socket error !");
        return 0;
    }

    //绑定IP和端口
    /*
    struct sockaddr_in sockAddr;
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_port = htons(8888);
    sockAddr.sin_addr.S_un.S_addr = INADDR_ANY;*/

    struct sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));  //每个字节都用0填充
    sockAddr.sin_family = AF_INET;  //使用IPv4地址
    sockAddr.sin_addr.s_addr = inet_addr("192.168.1.103");  //具体的IP地址
    sockAddr.sin_port = htons(8888);  //端口

    if(bind(slisten, (LPSOCKADDR )&sockAddr, sizeof(sockAddr)) == SOCKET_ERROR)
    {
        printf("bind error !");
    }

    //开始监听
    if(listen(slisten, 20) == SOCKET_ERROR)
    {
        printf("listen error !");
        return 0;
    }

    //循环接收数据
    SOCKET sClient;
    struct sockaddr_in remoteAddr;
    int nAddrlen = sizeof(remoteAddr);
    char revData[255];
    char sendData[255] = "hello ";
    int len = strlen(sendData);

    while (1)
    {
        printf("\nwaiting...\n");
        sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);
        if(sClient == INVALID_SOCKET)
        {
            printf("accept error !\n");
            continue;
        }
        printf("get a connetion: %s\n", inet_ntoa(remoteAddr.sin_addr));

        //接收数据
        int ret = recv(sClient, revData, 255, 0);
        revData[ret] = '\0';
        printf("get message from client: %s\n", revData);

        //发送数据
        //strcat(sendData, revData);
        printf("inpud msg: ");
        scanf("%s", sendData);
        send(sClient, sendData, 255, 0);

        closesocket(sClient);
        memset(revData, 0, sizeof(revData));
        //sendData[len] = '\0';
        memset(sendData, 0, sizeof(sendData));
    }

    closesocket(slisten);
    WSACleanup();
    return 0;
}


/*
42849360
256 46s
512 42s


256    39126ms
512    30359ms
1024   33432ms
2048   35553ms
4096   30124ms
8192   30765ms
16384  13199ms
32768  25819ms
49152  21357ms
1048576 18659ms
*/