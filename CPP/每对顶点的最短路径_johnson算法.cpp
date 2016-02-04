#include <iostream>
#include <vector>
#include <map>
#define INF 0x7FFFFFF
using namespace std;

struct V
{
    int id;
    int val;
    bool operator< (const V a) const
    {
        return val < a.val;
    }

    V(int x, int y)
    {
        id = x;
        val = y;
    }
};

class Queue
{
private:
    vector<V> queue;
public:
    V extract_min()
    {
        V res = V(0, INF);
        int index = 0;
        for (int i = 0; i < queue.size(); i++)
        {
            if (queue[i] < res)
            {
                res = queue[i];
                index = i;
            }
        }
        queue.erase(queue.begin() + index);
        return res;
    }

    void push(V v)
    {
        queue.push_back(v);
    }

    int size()
    {
        return queue.size();
    }

    void update(V v)
    {
        for (int i = 0; i < queue.size(); i++)
            if (queue[i].id == v.id)
                queue[i].val = v.val;
    }

    V get(int id)
    {
        for (int i = 0; i < queue.size(); i++)
            if (id == queue[i].id)
                return queue[i];
    }
};

int gm[100][100];
int reweight_gm[100][100];
int pathm[100][100];
vector<int> gt[100];
map<pair<int, int>, int> em;
int h[100];
int plen[100];
int vertex, edge;

void init_m(int n)
{
    //set i and j start from 0 is considered the G' add an extra vertex 0
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            reweight_gm[i][j] = gm[i][j] = pathm[i][j] = (i == j ? 0 : INF);
}

void show_matrix(int m[][100], int d)
{  
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            if (m[i][j] == INF)
                cout << "N ";
            else
                cout << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool bellman_ford(int start)
{
    for (int i = 0; i <= vertex; i++)
        h[i] = INF;

    h[start] = 0;//set start point

    for (int n = 1; n < vertex; n++)//n-1 times
        for (map<pair<int, int>, int>::iterator iter = em.begin(); iter != em.end(); ++iter)//each edge
            if (h[iter->first.second] > h[iter->first.first] + iter->second)
                h[iter->first.second] = h[iter->first.first] + iter->second;
    //check negtive
    for (map<pair<int, int>, int>::iterator iter = em.begin(); iter != em.end(); ++iter)
        if (h[iter->first.second] > h[iter->first.first] + iter->second)
            return false;
    return true;
}   

void dijkstra(int start)
{
    //dijkstra algorithm use adjacent table, and a priority queue
    Queue queue;
    for (int i = 1; i <= vertex; i++)
    {
        queue.push(V(i, INF));
        plen[i] = INF;
    }

    plen[start] = 0;
    queue.update(V(start, 0));

    while (queue.size())
    {
        V cur = queue.extract_min();
        int u = cur.id;
        for (int i = 0; i < gt[u].size(); i++)
        {
            int v = gt[u][i];//adjacent vertex
            int w = reweight_gm[u][v];//adjacent vertex weight
            if (plen[v] > plen[u] + w)
            {
                plen[v] = plen[u] + w;
                queue.update(V(v, plen[v]));
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int u, v, w;
    cin >> vertex >> edge;
    init_m(vertex);
    for (int i = 0; i < edge; i++)
    {
        cin >> u >> v >> w;
        //construct G' for bellman_ford
        em[make_pair(u, v)] = w;
        em[make_pair(0, u)] = 0;
        em[make_pair(0, v)] = 0;

        //graph matrix
        gm[u][v] = w;
        //graph adjacent table for dijkstra algorithm
        gt[u].push_back(v);
    }

    bool res = bellman_ford(0);
    if (res)
    {
        cout << "\ngraph" << endl;
        show_matrix(gm, vertex);

        cout << "shortest path from extra point" << endl;
        for (int i = 1; i <= vertex; i++)
            cout << i << ": " << h[i] << endl;

        //reweight graph
        for (int i = 1; i <= vertex; i++)
            for (int j = 1; j <= vertex; j++)
                if (gm[i][j] < INF)
                    reweight_gm[i][j] = gm[i][j] + h[i] - h[j];

        cout << "\nreweight graph" << endl;
        show_matrix(reweight_gm, vertex);

        //run dijkstra on each vertex
        cout << "shortest path in reweight_gm" << endl;
        for (int i = 1; i <= vertex; i++)
        {
            dijkstra(i);
            for (int j = 1; j <= vertex; j++)
            {
                cout << plen[j] << " ";
                pathm[i][j] = plen[j] + h[j] - h[i];
            }
            cout << endl;
        }

        cout << "\npairs shortest path matrix" << endl;
        show_matrix(pathm, vertex);

    }
    else
        cout << "the graph contains a negative weight cycle" << endl;
    return 0;
}

/*
5 9
1 2 3
1 3 8
1 5 -4
2 4 1
2 5 7
3 2 4
4 3 -5
4 1 2
5 4 6
*/