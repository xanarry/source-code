/*
编译:
    程序在linux下通过了gcc 4.8.4编译, 编译时请添加std=c99参数并且在linux的环境下编译, windows中将编译失败
使用:
    使用方法和Linux中的wc完全一致
注意: 
    1:参数中最多接收255个文件, 文件名最大长度为255个ASCII字符, 文件名不能使用"-"开头
    2:统计单词时, 将所有非字母字符作为单词分割符号, 而不是仅视空格为分割点, 程序将视"about;eat"为两个单词, 而不是一个
*/
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUF_SIZE 4096
#define CHARS 0
#define WORDS 1
#define LINES 2

short isChar(char ch)
{
    /* [A-Z]->[65-90], [a-z]->[97-122] */
    return (ch >= 65 && ch <= 90) || (ch >=97 && ch <= 122);
}

void WL_CounterStr(char *str, int *nums)
{
    /* count the lines and words in a given string*/
    int pos = 0, num = 0;
    short inWord = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '\n')
            nums[LINES]++;

        if (isChar(str[i]) == 0) //seperater
        {
            if (inWord)
                inWord = 0;
        }
        else if (inWord == 0) //litter
        {
            nums[WORDS]++;
            inWord = 1;
        }
    }
}

void CWL_CounterFile(char *file, int *nums)
{
    /* read file and count chars, words and lines*/
    int readLen = 0;
    int fd = open(file, O_RDONLY, S_IRWXG | S_IRWXO | S_IRWXU);
    char buf[BUF_SIZE + 2];
    while ((readLen = read(fd, buf, 1024)) > 0)
    {
        buf[readLen] = '\0'; //set ending char
        WL_CounterStr(buf, nums);
        nums[CHARS] += readLen; //one char one byte
    }
    close(fd);
}

void help()
{
    puts("-l count lines");
    puts("-c count chars");
    puts("-w count words");
}

short fileExist(const char *filename)
{
    struct stat buf;
    if (stat(filename, &buf) < 0)
        return 0;
    return 1;
}

short parseCmd(int argc, char const *argv[], short *option, char files[][255])
{
    /*
     *-1 means that user input wrong command
     * 0 means that user wanna use input
     * >0 means user has gave a file list
     */
    int fileCount = 0;
    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-') //options
        {
            option[0] = option[1] = option[2] = 0;
            for (int j = 1; argv[i][j]; j++)
            {
                if (argv[i][j] == 'c')
                    option[CHARS] = 1;
                if (argv[i][j] == 'w')
                    option[WORDS] = 1;
                if (argv[i][j] == 'l')
                    option[LINES] = 1;
                if (argv[i][j] != 'c' && argv[i][j] != 'w' && argv[i][j] != 'l')
                {
                    //input is not c or w or l
                    printf("unrecognized option: %c\n", argv[i][j]);
                    return -1;
                }
            }
        }
        else
        {
            if (fileExist(argv[i]))//check file existence
                strcpy(files[fileCount++], argv[i]);
            else
            {
                printf("file: %s is not exist\n", argv[i]);
                return -1;
            }
        }
    }
    return fileCount;
}

void showResult(short *option, int *nums)
{
    for (int j = 0; j < 3; j++)
    {
        if (option[j] == 1)
        {
            if (j == CHARS)
                printf("c:%d ", nums[CHARS]);
            else if (j == WORDS)
                printf("w:%d ", nums[WORDS]);
            else if (j == LINES)
                printf("l:%d ", nums[LINES]);
        }
    }
}

int main(int argc, char const *argv[])
{       
    short option[3] = {1, 1, 1};//c  w  l
    int nums[3] = {0, 0, 0};//nums[0]->chars; nums[1]->words; nums[2]->lines
    char files[255][255];//file list
    char inputBuf[BUF_SIZE];//

    int fileCount = parseCmd(argc, argv, option, files);
    if (fileCount == -1)
        help();
    else
    {
        if (fileCount == 0)
        {
            int t = 0;
            while ((inputBuf[t++] = getchar()) != EOF);//get user's any input
            nums[CHARS] = t - 1; //apart from the last control char(ctrl+d)
            WL_CounterStr(inputBuf, nums);
            showResult(option, nums);
            printf("\n");
        }    
        else
        {
            for (int i = 0; i < fileCount; i++)
            {
                nums[0] = nums[1] = nums[2] = 0;//initialize for each file
                CWL_CounterFile(files[i], nums);//handle input file
                showResult(option, nums);
                printf("%s\n", files[i]);
            }
        }    
    }
    return 0;
}
