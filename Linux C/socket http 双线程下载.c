#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <sys/time.h>

struct resp_header//保持相应头信息
{
    int status_code;//HTTP/1.1 '200' OK
    char content_type[128];//Content-Type: application/gzip
    long content_length;//Content-Length: 11683079
};

struct part_desc
{
    char url[1024];
    char domain[1024];
    char ip[32];
    int port;
    char file_name[256];
    long start;
    long end;
};

struct resp_header resp;//全剧变量以便在多个进程中使用


void parse_url(const char *url, char *domain, int *port, char *file_name)
{
    /*通过url解析出域名, 端口, 以及文件名*/
    int j = 0;
    int start = 0;
    *port = 80;
    char *patterns[] = {"http://", "https://", NULL};

    for (int i = 0; patterns[i]; i++)
        if (strncmp(url, patterns[i], strlen(patterns[i])) == 0)
            start = strlen(patterns[i]);

    //解析域名, 这里处理时域名后面的端口号会保留
    for (int i = start; url[i] != '/' && url[i] != '\0'; i++, j++)
        domain[j] = url[i];
    domain[j] = '\0';

    //解析端口号, 如果没有, 那么设置端口为80
    char *pos = strstr(domain, ":");
    if (pos)
        sscanf(pos, ":%d", port);

    //删除域名端口号

    for (int i = 0; i < (int)strlen(domain); i++)
    {
        if (domain[i] == ':')
        {
            domain[i] = '\0';
            break;
        }
    }

    //获取下载文件名
    j = 0;
    for (int i = start; url[i] != '\0'; i++)
    {
        if (url[i] == '/')
        {
            if (i !=  strlen(url) - 1)
                j = 0;
            continue;
        }
        else
            file_name[j++] = url[i];
    }
    file_name[j] = '\0';
}

struct resp_header get_resp_header(const char *response)
{
    /*获取响应头的信息*/
    struct resp_header resp;

    char *pos = strstr(response, "HTTP/");
    if (pos)
        sscanf(pos, "%*s %d", &resp.status_code);

    pos = strstr(response, "Content-Type:");
    if (pos)
        sscanf(pos, "%*s %s", resp.content_type);

    pos = strstr(response, "Content-Length:");
    if (pos)
        sscanf(pos, "%*s %ld", &resp.content_length);

    return resp;
}

void get_ip_addr(char *domain, char *ip_addr)
{
    /*通过域名得到相应的ip地址*/
    struct hostent *host = gethostbyname(domain);
    if (!host)
    {
        ip_addr = NULL;
        return;
    }

    for (int i = 0; host->h_addr_list[i]; i++)
    {
        strcpy(ip_addr, inet_ntoa( * (struct in_addr*) host->h_addr_list[i]));
        break;
    }
}


void progressBar(long cur_size, long total_size)
{
    /*用于显示下载进度条*/
    float percent = (float) cur_size / total_size;
    const int numTotal = 50;
    int numShow = (int)(numTotal * percent);

    if (numShow == 0)
        numShow = 1;

    if (numShow > numTotal)
        numShow = numTotal;

    char sign[51] = {0};
    memset(sign, '=', numTotal);
    printf("\r%.2f%%\t[%-*.*s] %.2f/%.2fMB", percent * 100, numTotal, numShow, sign, cur_size / 1024.0 / 1024.0, total_size / 1024.0 / 1024.0);
    fflush(stdout);

    if (numShow == numTotal)
        printf("\n");
}

void split_header(int *socket_p, char **resp)
{
    int socket = *socket_p;
    int mem_size = 4096;
    int length = 0;
    int len;
    char *buf = (char *) malloc(mem_size * sizeof(char));
    char *response = (char *) malloc(mem_size * sizeof(char));

    //每次单个字符读取响应头信息
    while ((len = read(socket, buf, 1)) != 0)
    {
        if (length + len > mem_size)
        {
            //动态内存申请, 因为无法确定响应头内容长度
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

        //找到响应头的头部信息
        int flag = 0;
        for (int i = strlen(response) - 1; response[i] == '\n' || response[i] == '\r'; i--, flag++);
        if (flag == 4)
            break;

        length += len;
    }
    *resp = response;
}


void * download_func(void * desc)
{
    //cnt++;
    struct part_desc *partiton =  (struct part_desc *) desc;

    char header[2048];
    sprintf(header, \
        "GET %s HTTP/1.1\r\n"\
        "Accept:text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\n"\
        "User-Agent:Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537(KHTML, like Gecko) Chrome/47.0.2526Safari/537.36\r\n"\
        "Host:%s\r\n"\
        "Range:bytes=%ld-%ld\r\n"\
        "Connection:close\r\n"\
        "\r\n"\
    ,partiton->url, partiton->domain, partiton->start, partiton->end);

    int client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (client_socket < 0)
    {
        printf("invalid socket descriptor: %d\n", client_socket);
        exit(-1);
    }

    //创建地址结构体
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(partiton->ip);
    addr.sin_port = htons(partiton->port);

    //连接服务器
    //puts("3: Connect server...");
    int res = connect(client_socket, (struct sockaddr *) &addr, sizeof(addr));
    if (res == -1)
    {
        printf("connect failed, return: %d\n", res);
        exit(-1);
    }

    //puts("4: Send request...");
    write(client_socket, header, strlen(header));

    char *response;
    split_header(&client_socket, &response);

    //printf("file_name: %s\n", partiton->file_name);
    //printf("%s\n\n", response);

    struct resp_header resp = get_resp_header(response);

    /*下载文件函数, 放在线程中执行*/
    //创建文件描述符
    int fd = open(partiton->file_name, O_CREAT | O_WRONLY, S_IRWXG | S_IRWXO | S_IRWXU);
    if (fd < 0)
    {
        printf("Create file failed\n");
        exit(0);
    }

    int buf_len = 4096;
    int len;
    char *buf = (char *) malloc(buf_len * sizeof(char));
    int length = 0;
    //从套接字中读取文件流
    if (resp.status_code != 206)
        pthread_exit(NULL);

    while ((len = read(client_socket, buf, buf_len)) != 0 && length < resp.content_length)
    {
        write(fd, buf, len);
        length += len;
        //printf("%s:", partiton->file_name + strlen(partiton->file_name) - 5);
        progressBar(length, resp.content_length);
        //printf("\n");
    }

    pthread_exit(NULL);
}

long get_file_size(char *path)
{
    long filesize = -1;
    struct stat statbuff;
    if(stat(path, &statbuff) < 0){
        return filesize;
    }else{
        filesize = statbuff.st_size;
    }
    return filesize;
}

long merge_file(char *file1, char *file2, char *dest_file)
{

    printf("merge\n%s\n%s\nto%s\n", file1, file2, dest_file);
    int buf_len = 4096;
    char buf[4096];
    int t_len;

    int in_fd = open(file1, O_RDONLY);
    if (in_fd < 0)
    {
        printf("Create file failed\n");
        exit(0);
    }

    int out_fd = open(dest_file, O_CREAT | O_WRONLY, S_IRWXG | S_IRWXO | S_IRWXU);
    if (out_fd < 0)
    {
        printf("Create file failed\n");
        exit(0);
    }

    while ((t_len = read(in_fd, buf, buf_len)) > 0)
        write(out_fd, buf, t_len);
    

    in_fd = open(file2, O_RDONLY);
    if (in_fd < 0)
    {
        printf("Create file failed\n");
        exit(0);
    }

    while ((t_len = read(in_fd, buf, buf_len)) > 0)
        write(out_fd, buf, t_len);

   return get_file_size(dest_file);
}

int main(int argc, char const *argv[])
{
    /*
        test url:
        1. https://nodejs.org/dist/v4.2.3/node-v4.2.3-linux-x64.tar.gz
        2. http://img.ivsky.com/img/tupian/pre/201312/04/nelumbo_nucifera-009.jpg
    */
    char url[2048] = "127.0.0.1";
    char domain[64] = {0};
    char ip_addr[16] = {0};
    int port = 80;
    char file_name[256] = {0};

    if (argc == 1)
    {
        printf("Input a valid URL please\n");
        exit(0);
    }
    else
        strcpy(url, argv[1]);

    //strcpy(url, "http://img.ivsky.com/img/tupian/pre/201312/04/nelumbo_nucifera-009.jpg");
    puts("1: Parsing url...");
    parse_url(url, domain, &port, file_name);

    if (argc == 3)
        strcpy(file_name, argv[2]);

    puts("2: Get ip address...");
    get_ip_addr(domain, ip_addr);
    if (strlen(ip_addr) == 0)
    {
        printf("can not get ip address\n");
        return 0;
    }

    puts("\n>>>>Detail<<<<");
    printf("URL: %s\n", url);
    printf("DOMAIN: %s\n", domain);
    printf("IP: %s\n", ip_addr);
    printf("PORT: %d\n", port);
    printf("FILENAME: %s\n\n", file_name);


    //设置http请求头信息
    char header[2048] = {0};
    sprintf(header, \
            "HEAD %s HTTP/1.1\r\n"\
            "Accept:text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\n"\
            "User-Agent:Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537(KHTML, like Gecko) Chrome/47.0.2526Safari/537.36\r\n"\
            "Host:%s\r\n"\
            "Connection:close\r\n"\
            "\r\n"\
        ,url, domain);

    //printf("%s\n%d", header, (int) strlen(header));

    //创建套接字
    int client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (client_socket < 0)
    {
        printf("invalid socket descriptor: %d\n", client_socket);
        exit(-1);
    }

    //创建地址结构体
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_addr);
    addr.sin_port = htons(port);

    //连接服务器
    puts("3: Connect server...");
    int res = connect(client_socket, (struct sockaddr *) &addr, sizeof(addr));
    if (res == -1)
    {
        printf("connect failed, return: %d\n", res);
        exit(-1);
    }

    puts("4: Send request...");
    write(client_socket, header, strlen(header));

    char *response = (char *)malloc(1 * sizeof(char));
    split_header(&client_socket, &response);

    //printf("\n>>>>Response header:<<<<\n%s", response);


    resp = get_resp_header(response);


    long tri_len = resp.content_length / 2;


    //part1 for thread 1
    struct part_desc partiton1;
    strcpy(partiton1.url, url);
    strcpy(partiton1.domain, domain);
    strcpy(partiton1.ip, ip_addr);
    strcpy(partiton1.file_name, file_name);
    strcat(partiton1.file_name, ".part1");
    partiton1.port = port;
    partiton1.start = 0L;
    partiton1.end = tri_len;//3894360

    //part2 for thread 2
    struct part_desc partiton2 = partiton1;
    strcpy(partiton2.file_name, file_name);
    strcat(partiton2.file_name, ".part2");
    partiton2.start = tri_len + 1;
    partiton2.end = resp.content_length;//3894359

    /*
    //part3 for thread 3
    struct part_desc partiton3 = partiton1;
    strcpy(partiton3.file_name, file_name);
    strcat(partiton3.file_name, ".part3");
    partiton3.start = part1 * 2 + 1;
    partiton3.end = resp.content_length;//3894360
*/
    //11683079
    
//goto MERGE;

    printf("5: Start thread to download...\n");
   // pthread_mutex_init(&mutex, NULL);
    /*开新的线程下载文件*/
    pthread_t download_thread1;
    pthread_t download_thread2;
    //pthread_t download_thread3;

    pthread_create(&download_thread1, NULL, download_func, (void *) &partiton1);
    //pthread_join(download_thread1, NULL);

    pthread_create(&download_thread2, NULL, download_func, (void *) &partiton2);
    //pthread_join(download_thread2, NULL);

    //pthread_create(&download_thread3, NULL, download_func, (void *) &partiton3);
    //pthread_join(download_thread3, NULL);

    pthread_join(download_thread1, NULL);
    pthread_join(download_thread2, NULL);
    //pthread_join(download_thread3, NULL);
    

    printf("%ld\n", resp.content_length);

    int dest_file_len = merge_file(partiton1.file_name, partiton2.file_name, file_name);
    if (dest_file_len == resp.content_length)
    {
        remove(partiton1.file_name);
        remove(partiton2.file_name);
        //remove(partiton3.file_name);
        printf("Download successful ^_^\n");
    }
    else
        printf("Download failed\n");
    return 0;
}
