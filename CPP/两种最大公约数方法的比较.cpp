#include <iostream>
using namespace std;

int gcd1(int a, int b)
{
    while (b)
    {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int gcd2(int a, int b)
{
    return !b ? a : gcd2(b, a % b);
}

int main(int argc, char const *argv[])
{
    int a, b;
    while (cin >> a >> b)
        cout << "gcd1: " << gcd1(a, b) << "\ngcd2: " << gcd2(a, b) << endl;
    return 0;
}