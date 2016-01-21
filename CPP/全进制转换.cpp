#include <iostream>
#include <string>
using namespace std;

string convert(int p, string n, int q)
{
    const string nums = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    long long decn = 0, t = 1;
    for (int i = n.length() - 1; i >= 0; i--, t *= p)
        decn += t * nums.find(n[i]);

    string destn = "";
    while (decn > 0)
    {
        destn = nums[decn % q] + destn;
        decn /= q;
    }
    return destn;
}

int main(int argc, char const *argv[]) {
    string n;
    int m, q, p;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> p >> n >> q;
        cout << convert(p, n, q) << endl;
    }
    return 0;
}
