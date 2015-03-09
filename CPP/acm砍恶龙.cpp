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
�����������һ��n��ͷ�Ķ�������ϣ����һЩ��ʿ����ɱ�������������е�ͷ����������m����ʿ���Թ�Ӷ��һ������ֵΪx����ʿ���Կ���������һ��ֱ��������x��ͷ������Ҫ֧��x����ҡ���ι�Ӷ��ʿ���ܿ����������е�ͷ������Ҫ֧���Ľ�����٣�ע�⣬һ����ʿֻ�ܿ���һ��ͷ���Ҳ��ܱ���Ӷ���Σ�
Input
��һ��Ϊһ��������n��m������n��ÿ��Ϊһ��������������ÿ��ͷ��ֱ��������m��ÿ��Ϊһ������������ʿ��������
Output
������ٻ��ѣ�����޽⣬�������No����
Sample Input
��������1��
2 3
5
4
7
8
4

��������2��
2 1
5
5
10
Sample Output
�������1��
11

�������2��
No
*/
