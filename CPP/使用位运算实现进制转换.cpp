#include <iostream>
#include <string>
using namespace std;

string itob(int a)
{
    int bin[65];
    int len = 8 * sizeof(int);
    for (int i = len - 1; i>= 0; i--, a >>= 1)
        bin[i] = (a & 1);
    bin[len] = '\0';

    string res = "";
    for (int i = 0; i < len; i++)
    {
        if (i && i % 4 == 0)
            res += " ";
        res += char(bin[i] + '0');
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string res;
    int n; 
    while (cin >> n)
    {
        res = itob(n);
        cout << res << endl;
    }
    return 0;
}