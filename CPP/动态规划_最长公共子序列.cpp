#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    string a, b;
    cin >> a >> b;
    int len[100][100];
    memset(len, 0, sizeof(len));
    for (int i = 0; i < a.length(); i++)
        for (int j = 0; j < b.length(); j++)
            if (a[i] == b[j])
                len[i + 1][j + 1] = len[i][j] + 1;
            else
                len[i + 1][j + 1] = max(len[i][j + 1], len[i + 1][j]);

    cout << len[a.length()][b.length()] << endl;
    return 0;
}