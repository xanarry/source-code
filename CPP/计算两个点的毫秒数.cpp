#include <stdio.h>   
#include <stdlib.h>   
#include <windows.h>
#include <time.h>   
    
int  main()   
{   
    clock_t start, finish;    
    double elapsed_time;   
    start=clock();  
    Sleep(1000);  
    finish=clock();   
  
    elapsed_time   =   finish-start;   
    printf("%f\n", elapsed_time);
    return 0;
}   