#include <stdio.h>
#include <sys/stat.h> 
#include <unistd.h>

unsigned long get_file_size(const char *filename)
{
    struct stat buf;
    if(stat(filename, &buf) < 0)
        return 0;
    return (unsigned long) buf.st_size;
}

int main(int argc, char const *argv[])
{
    char *file = "http_download.c";
    printf("%d\n", get_file_size(file));
    return 0;
}