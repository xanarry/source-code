#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    const int LEN = 1000;
    string str;
    cin >> str;
    int lis[LEN];
    for (int i = 0; i < LEN; i++)//初始化所有长度字符串的lis长度都为1，即其本身
        lis[i] = 1;

    for (unsigned i = 0; i < str.length(); i++)//动态规划的构建过程
        for (unsigned j = 0; j < i; j++)
            if (str[i] >= str[j])
                lis[i] = max(lis[j] + 1, lis[i]);

    for (unsigned i = 0; i < str.length(); i++)//输出每个长度字符串的lis长度
        cout << lis[i] << endl;
    return 0;
}
/*
215364897
1
1
2
2
3
3
4
5
4
534867
1
1
2
3
3
4
*/
