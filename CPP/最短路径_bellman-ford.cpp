#include <iostream>
#include <map>
#include <vector>
#define MIN(x,y) ((x)<(y)?(x):(y))

using namespace std;

int vertex, edge, u, v, w;
map<pair<int, int>, int> g;
int path[100];

bool bellman_ford(int s)
{
    for (int i = 0; i < g.size(); i++)
        path[i] = 0x7fffffff;
    path[s] = 0;

    for (int i = 0; i < vertex - 1; i++)//num of vertex
        //relax each edge
        for (map<pair<int, int>, int>::iterator iter = g.begin(); iter != g.end(); ++iter)
            path[iter->first.second] = MIN(path[iter->first.first] + iter->second, path[iter->first.second]);
    //check
    for (map<pair<int, int>, int>::iterator iter = g.begin(); iter != g.end(); ++iter)
        if (path[iter->first.first] + iter->second < path[iter->first.second])
            return false;
    return true;
    
}


int main(int argc, char const *argv[])
{
    cin >> vertex >> edge;
    for (int i = 0; i < edge; i++)
    {
        cin >> u >> v >> w;
        g[make_pair(u, v)] = w;
    }
    for (map<pair<int, int>, int>::iterator iter = g.begin(); iter != g.end(); ++iter)
        cout << iter->first.first << "-" << iter->first.second << " w=" << iter->second << endl;
    int s;
    cin >> s;
    bool res = bellman_ford(s);
    if (res)
    {
        cout << "non negative-weight cycle" << endl;
        cout << "shortest path" << endl;
        for (int i = 0; i < vertex; i++)
            cout << path[i] << " ";
        cout << endl;
    }
    else
        cout << "negative-weight cycle" << endl;
    return 0;
}

/*
5 10
0 1 6
0 4 7
1 2 5
1 4 8
1 3 -4
2 1 -2
3 2 7
3 0 2
4 2 -3
4 3 9
0
shortest path
0 2 4 -2 7

3 4
0 1 4
1 2 -3
2 0 -4
0 2 2
0
no shortes path
*/
