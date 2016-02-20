#include <iostream>
#include <algorithm>
using namespace std;

int a[100][100];

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> a[i][j];

    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);

    cout << a[0][0] << endl;
    return 0;
}

/*
4
1
3 2
4 10 1
4 3 2 20
24
*/