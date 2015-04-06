#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m;
    long long a[100][100];
    for (int i = 1; i <= m; i++)
    {
        a[i][1] = i;
        for (int j = 2; j <= i; j++)
            a[i][j] = a[i][j - 1] * (i - j + 1);
    }

    
    for (int i = 1; i <= m; i++)
    {
        for (int j = 2; j <= i; j++)
            cout << a[i][j] << endl;
    }
    return 0;
}