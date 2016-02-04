#include <iostream>
#include <map>
using namespace std;

int val[1000];

bool dc(map<pair<int, int>, int> g, int m)
{
    for (int i = 0; i < m + 10; i++)
        val[i] = 0x7fffffff;
    val[0] = 0;
    for (int i = 0; i < m - 1; i++)
        for (map<pair<int, int>, int>::iterator iter = g.begin(); iter != g.end(); ++iter)
            if (val[iter->first.second] > val[iter->first.first] + iter->second)
                val[iter->first.second] = val[iter->first.first] + iter->second;

    for (map<pair<int, int>, int>::iterator iter = g.begin(); iter != g.end(); ++iter)
        if (val[iter->first.second] > val[iter->first.first] + iter->second)
            return false;
    return true;
}

int main(int argc, char const *argv[])
{
    map<pair<int, int>, int> g;
    int m, n, u, v, w;
    cin >> m >> n;
    while (n--)
    {
        cin >> v >> u >> w;
        g[make_pair(u, v)] = w;
        g[make_pair(0, u)] = 0;
        g[make_pair(0, v)] = 0;
    }
        
    bool res = dc(g, m);
    val[0] = 21;
    if (res)
    {
        cout << "solveable" << endl;
        for (int i = 1; i <= m; i++)
            cout << 'x' << i << "=" << val[i] << endl;
    }
    else
        cout << "unsolveable" << endl;
    return 0;
}

/*
5 8
1 2 0
1 5 -1
2 5 1
3 1 5
4 1 4
4 3 -1
5 3 -3
5 4 -3
*/

