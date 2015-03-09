#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int r[60000];
    int c[60000];
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> r[i];
        sum += r[i];
    }

    for (int i = 0; i < n; i++)
        cin >> c[i];

    sort(r, r + m);
    sort(c, c + n);

    int sum1 = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {

       if (c[i] >= r[j])
       {
           sum1 += c[i];
           j++;
           if (j == m)
            break;
       }
    }
    if (j < m)
        cout << "No" << endl;
    else
        cout << sum1 << endl;
}

/*
3 5
4 7 8
Description
你的王国里有一条n个头的恶龙，你希望雇一些骑士把他杀死（即砍掉所有的头）。村里有m个骑士可以雇佣，一个能力值为x的骑士可以砍掉恶龙的一个直径不超过x的头，且需要支付x个金币。如何雇佣骑士才能砍掉恶龙所有的头，且需要支付的金币最少？注意，一个骑士只能砍掉一个头（且不能被雇佣两次）
Input
第一行为一个正整数n和m，以下n行每行为一个整数，即恶龙每个头的直径；以下m行每行为一个整数，即骑士的能力。
Output
输出最少花费，如果无解，请输出“No”。
Sample Input
输入样例1：
2 3
5
4
7
8
4

输入样例2：
2 1
5
5
10
Sample Output
输出样例1：
11

输出样例2：
No
*/
