#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string a = "lasesdfklwsdafsafw";
    string b = "asdfwelsafsafewsewa";
    int ary[100][100];
    memset(ary, 0, sizeof(ary));

    int max = -1;
    int x;
    for (int i = 0; i < a.length(); i++)
    {
        for (int j = 0; j < b.length(); j++) 
        {
            if (a[i] == b[j])
            {
                if (i > 0 && j > 0)
                    ary[i][j] = ary[i - 1][j - 1] + 1;
                else
                    ary[i][j] = 1;

                if (ary[i][j] > max)
                {
                    x = j;
                    max = ary[i][j];
                }
            }
        }
    }

    cout << max << endl;
    cout << x << endl;

    for (int i = 0; i < max; i++)
        cout << b[x - max + i + 1];
    cout << endl;
    return 0;
}