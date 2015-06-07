#include <iostream>
#include <cstring>
using namespace std;

const int MAX_V = 1000;

void intersection(int *a, int *b, int *res)//交集
{
    memset(res, 0, sizeof(res));
    for (int i = 0; i < MAX_V; i++)
        res[i] = a[i] & b[i];
}

void union_set(int *a, int *b, int *res)//并集
{
    memset(res, 0, sizeof(res));
    for (int i = 0; i < MAX_V; i++)
        res[i] = a[i] | b[i];
}

void complementary_set(int *a, int *res)//补集
{
    for (int i = 0; i < MAX_V; i++)
        res[i] = !a[i];
}

void difference_set(int *a, int *b, int *res)//差集
{
    int temp[MAX_V];
    memset(res, 0, sizeof(temp));
    complementary_set(b, temp);
    for (int i = 0; i < MAX_V; i++)
        res[i] = a[i] & temp[i];
}

void sysmmetric_difference(int *a, int *b, int *res)//对称差集
{
    memset(res, 0, sizeof(res));
    for (int i = 0; i < MAX_V; i++)
        res[i] = a[i] ^ b[i];
}

void display_res(int *res)
{
    cout << "[";
    for (int i = 0; i < MAX_V; i++)
        if (res[i])
            cout << i << ",";
    cout << "\b]" << endl;
}

int main(int argc, char const *argv[])
{   
    int na, nb, n;
    int a[MAX_V], b[MAX_V], res[MAX_V];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    cout << "input size of set a:";
    cin >> na;
    cout << "input set a:";
    for (int i = 0; i < na; i++)
    {
        cin >> n;
        a[n] = 1;
    }

    cout << "input size of set b:";
    cin >> nb;
    cout << "input set b:";
    for (int i = 0; i < nb; i++)
    {
        cin >> n;
        b[n] = 1;
    }
    for (int i = 0; i < MAX_V; i++)
        if (a[i] == 1)
            cout << i << ' ';
    cout << endl;

    for (int i = 0; i < MAX_V; i++)
        if (b[i] == 1)
            cout << i << " ";
    cout << endl;

    cout << "并集:";
    union_set(a, b, res);
    display_res(res);

    cout << "交集:";
    intersection(a, b, res);
    display_res(res);

    cout << "对称差集";
    sysmmetric_difference(a, b, res);
    display_res(res);

    cout << "差集a-b:";
    difference_set(a, b, res);
    display_res(res);

    cout << "差集b-a:";
    difference_set(b, a, res);
    display_res(res);
    return 0;
}