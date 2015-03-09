#include <stdio.h>
#include <math.h>
#include <stdbool.h>
 
int a[9] = {0};
int n = 8, count = 0;
 
//位置冲突算法
bool Chongtu(int a[], int n)//a[]位置数组，n皇后个数
{
    int i = 0, j = 0;
 
    for (i = 2; i <= n; ++i)//i：位置
    {
        for (j = 1; j <= i-1; ++j)//j：位置
        {
            if ((a[i] == a[j]) || (abs(a[i]-a[j]) == i-j))//1：在一行；2：在对角线上
                return false;   //冲突
        }
    }
    return true;//不冲突
}
 
//八皇后问题：回溯算法（递归版）
void Queens8(int k) //参数k：递归摆放第k个皇后
{
    int i = 0;
 
    if (k > n)      //k>n：n = 8. 即k>8表示最后一个皇后摆放完毕
    {
        printf("第%02d种情况：",++count);
        for (i = 1; i <= n; ++i)
            printf("%d ",a[i]);//打印情况
        printf("\n");
    }
    else   //8个皇后未全部摆放完毕       
    {
        for (i = 1; i <= n; ++i)//摆放第k个皇后时（转下一行）
        {       //依次从列顶端开始搜索，一直到列底端，直到找到合适位置,如果未找到，自动返回上层递归(回溯)
            a[k] = i;              
            if (Chongtu(a,k))//不冲突
                Queens8(k+1);//递归摆放下一个皇后
        }
    }
    return;
}
 
//主函数
int main()
{
    Queens8(1);//参数1：表示摆放第1个皇后
 
    return 0;
} 