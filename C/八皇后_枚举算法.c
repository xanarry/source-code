#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//位置冲突算法
bool Chongtu(int a[], int n)//a[]位置数组，数组1-8包含的就是1到8行每行的位置坐标，n皇后个数
{
    int i = 0, j = 0;
 
    for (i = 2; i <= n; ++i)//i：位置，皇后只有2个及以上才会出现冲突，即从第二行开始检查
    {
        for (j = 1; j <= i-1; ++j)//在第i行前面查找是否有在同一行或者对角线
        {
            if ((a[i] == a[j]) || (abs(a[i]-a[j]) == i-j))//1：在一行；2：在对角线上
                return false;   //冲突
        }
    }
    return true;//不冲突
}
//八皇后：枚举算法
void Queens8()
{
    int a[9] = {0}; //用于记录皇后位置：(第0行0列我们不用)。如：a[3] = 4;表示第3列第4行位置有皇后
    int i = 0,count = 0;  //用于计数

    for (a[1] = 1; a[1] <= 8; ++a[1])//第一行1-8个位置
    {
        for (a[2] = 1; a[2] <= 8; ++a[2])
        {
            for (a[3] = 1; a[3] <= 8; ++a[3])
            {
                for (a[4] = 1; a[4] <= 8; ++a[4])
                {
                    for (a[5] = 1; a[5] <= 8; ++a[5])
                    {
                        for (a[6] = 1; a[6] <= 8; ++a[6])
                        {
                            for (a[7] = 1; a[7] <= 8; ++a[7])
                            {
                                for (a[8] = 1; a[8] <= 8; ++a[8])//第八行1-8个位置
                                {
                                    if (!Chongtu(a,8))//如果冲突，则继续枚举
                                        continue;
                                    else
                                    {
                                        printf("第%02d情况：",++count);
                                        for (i = 1; i <= 8; ++i)
                                            printf("%d ",a[i]);//打印某种情况
                                        printf("\n");
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

//主函数
int main()
{
    Queens8();
    return 0;
}
