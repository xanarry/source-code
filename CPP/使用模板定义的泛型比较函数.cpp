#include <iostream>
#include <string>
using namespace std;

template<typename T>
bool cmp(T a, T b)
{
    return a < b;
}

template<typename T>
T add(T a, T b)
{
    return a + b;
}

int main(int argc, char const *argv[])
{
    string a = "df";
    string b = "sdf";
    bool res = cmp(a, b);
    cout << res << endl;
    cout << add(a, b) << endl;
    return 0;
}