#include <iostream>

using namespace std;

int main() 
{
    int m, n, i;
    cin >> n >> m;
    int* a = new int[n];

    for (i = 0; i < n; i++) 
        a[i] = i + 1;

    int j = 1; //用于报数
    int k = 0; //遍历数组
    int l = n; //跟踪剩余人数

    while (l > 1) 
    {//剩余人数大于1，继续报数
        if (a[k])//如果当前位置有人
        {
            j++;
            if (j == m) 
            { //报到m出局
                j = 1; ////报到m出局
                a[k] = 0; //记下位置
                l--;//人数减1
            }
        }
        if (++k == n) 
            k = 0; //循环数组
    }

    while (a[--i] == 0); //找到最后一个人，即为答案
        cout << a[i] << endl;

    delete[] a;
    return 0;
}