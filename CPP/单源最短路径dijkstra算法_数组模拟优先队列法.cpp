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

int gm[100][100];//graph matrix
vector<int> gt[100];//graph adjacet table
int plen[100];//shortest path
int vertex, edge;

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
            int v = gt[u][i];
            int w = gm[u][v];
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
    for (int i = 0; i < edge; i++)
    {
        cin >> u >> v >> w;
        //graph matrix
        gm[u][v] = w;
        //graph adjacent table for dijkstra algorithm
        gt[u].push_back(v);
    }

    //run dijkstra on each vertex
    int start = 1;
   // cin >> start;
    dijkstra(start);
    for (int i = 1; i <= vertex; i++)
        cout << "to: " << i << " len:" << plen[i] << endl;
    return 0;
}

/*
introduction to algorithm 2th edition p367
5 10
1 2 10
1 5 5
2 3 1
2 5 2
3 4 4
4 3 6
4 1 7
5 2 3
5 3 9
5 4 2
*/