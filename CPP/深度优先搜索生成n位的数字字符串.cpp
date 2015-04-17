#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
using namespace std;

string nums[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
void dfs(string pass, int curlen, int destlen)
{
    if (curlen == destlen)
    {
        cout << pass << endl;
        return;
    }
    else
        for (int i = 0; i <= 9; i++)
            dfs(pass + nums[i], curlen + 1, destlen);
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    dfs("", 0, n);
    cout << "time consume: " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}