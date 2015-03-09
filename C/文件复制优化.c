#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#define BUFSIZE 1000  

int main(int argc, char *argv[])  
{  
	int i;  
    FILE *fp,*fpSrc;  
    char file[20];  
    char temp[BUFSIZE+1];   
      
    if(argc<3)  
    {  
         printf("参数不足！");  
        return 0;  
    }  
      
    if((fp=fopen(argv[1],"a"))==NULL)  
    {  
        printf("目标文件打开失败！");  
        return 0;  
    }  
    fprintf(fp, "%s", "/n");  
      
    for(i=2; i<argc; i++)  
    {  
		fpSrc=fopen(argv[i],"r");
        if(fpSrc == NULL)  
        {  
            printf("源文件打开失败！");  
            return 0;  
        }  
        while(fgets(temp,BUFSIZE,fpSrc))  
        {  
            fputs(temp, fp);  
        }  
        fclose(fpSrc);  
    }  
      
    printf("复制成功！");  
    fclose(fp);  
    getchar();  
    return 0;  
}  

