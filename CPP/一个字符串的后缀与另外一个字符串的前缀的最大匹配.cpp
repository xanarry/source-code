#include <iostream>
#include <cstring>
using namespace std;

int max_matching(char *a, char *b)
{
    int i, j, lena = strlen(a);
    for (i = lena; i >= 1; i--)
    {
        for (j = 0; j < i; j++)
            if (b[j] != a[lena - i + j])
                break;
        if (j == i)
            return j;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    //this program match a's suffix and b's prefix
    char a[100], b[100];
    cin >> a >> b;
    cout << max_matching(a, b) << endl;
    return 0;
}
/*
ababab
ababaca
*/