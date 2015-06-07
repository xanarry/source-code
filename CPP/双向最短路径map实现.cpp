#include <iostream>
#include <map>
#include <queue>
#include <climits>
#include <vector>
using namespace std;

struct Adjecent
{
    string vname;
    int dist;
};

struct Point
{
    string name;
    string parent;
    int dist_from_start;
    vector<Adjecent> adjacents;
};

map<string, Point> input_graph();
map<string, Point> initilize(map<string, Point>);
map<string, Point> build_path(string start, const string dest, const map<string, Point> cpoints);
void show_graph(map<string, Point> points);
void show_graph_with_path_info(map<string, Point> points);
void recursive_output_path(string start, string dest, map<string, Point> graph);
void output_path(string start, string dest, map<string, Point> graph);
bool in_queue(queue<string> pqueue, string vertex);

map<string, Point> input_graph()
{
    cout << "input \"over\" to end up input" << endl;
    map<string, Point> mp;
    string u, v;
    int dist;
    while (cin >>u)
    {
        if (u == "over")
            break;

        cin >> v >> dist;

        Adjecent adjacent;
        adjacent.vname = v;
        adjacent.dist = dist;

        if (mp.count(u))
            mp[u].adjacents.push_back(adjacent);
        else
        {
            Point new_p;
            new_p.name = u;
            new_p.adjacents.push_back(adjacent);
            mp[u] = new_p;
        }

        adjacent.vname = u;
        if (mp.count(v))
            mp[v].adjacents.push_back(adjacent);
        else
        {
            Point new_p;
            new_p.name = v;
            new_p.adjacents.push_back(adjacent);
            mp[v] = new_p;
        }
    }
    return mp;
}

map<string, Point> initilize(const map<string, Point> raw_graph)
{
    map<string, Point> graph = raw_graph;
    for (map<string, Point>::iterator iter = graph.begin(); iter != graph.end(); ++iter)
    {
        iter->second.parent = "NULL";
        iter->second.dist_from_start = INT_MAX;
    }
    return graph;
}

bool in_queue(queue<string> pqueue, string vertex)
{
    while (!pqueue.empty())
    {
        if (pqueue.front() == vertex)
            return true;
        pqueue.pop();
    }
    return false;
}

void show_graph(map<string, Point> points)
{
    for (map<string, Point>::iterator iter = points.begin(); iter != points.end(); ++iter)
    {
        cout << iter->first << " adjacent vertexies: ";
        for (int i = 0; i < (iter->second.adjacents).size(); i++)
            cout << "(" << (iter->second.adjacents[i]).vname << "," << (iter->second.adjacents[i]).dist << ") ";
        cout << endl;
    }
}

void show_graph_with_path_info(map<string, Point> points)
{
    for (map<string, Point>::iterator iter = points.begin(); iter != points.end(); ++iter)
        cout << iter->first << " " << iter->second.dist_from_start << " " << iter->second.parent << endl;
}

void recursive_output_path(string start, string dest, map<string, Point> graph)
{
    if (dest != start)
        recursive_output_path(start, graph[dest].parent, graph);
    cout << dest << "->";
}

void output_path(string start, string dest, map<string, Point> graph)
{
    cout << "shorted path is: [";
    recursive_output_path(start, dest, graph);
    cout << "\b\b] and length is about: ";
    cout << graph[dest].dist_from_start << endl;   
}       

map<string, Point> build_path(string start, const string dest, const map<string, Point> raw_graph)
{
    map<string, Point> points = initilize(raw_graph);
    queue<string> pqueue;
    points[start].dist_from_start = 0;
    pqueue.push(start);

    cout << endl;
    while (!pqueue.empty())
    {   
        start = pqueue.front();
        queue<string> tp = pqueue;
        pqueue.pop();

        vector<Adjecent> adjacents = points[start].adjacents;
    //    cout << "start from:" << start << " pre dist=" << points[start].dist_from_start << " adjacent: ";
        for (int i = 0; i < adjacents.size(); i++)
        {
            Adjecent temp = adjacents[i];
      //      cout << "(" << temp.vname << "," << temp.dist << ") ";
            if (temp.vname != start && points[temp.vname].dist_from_start > points[start].dist_from_start + temp.dist)
            {
                points[temp.vname].dist_from_start = points[start].dist_from_start + temp.dist;
                points[temp.vname].parent = start;
                if (!in_queue(pqueue, temp.vname))
                    pqueue.push(temp.vname);
            }
        }
    }
    return points;
}

int main(int argc, char const *argv[])
{
    map<string, Point> graph = input_graph();
    string start, dest;
    while (1)
    {  
        cout << "input start point: ";
        cin >> start;
        cout << "input destination point: ";
        cin >> dest;
        map<string, Point> graph_with_path_info = build_path(start, dest, graph);
        output_path(start, dest, graph_with_path_info);
    }
    return 0;
}

/*
数据结构与算法分析上的图
v1 v4 1
v1 v2 2
v2 v4 3
v2 v5 10
v3 v1 4
v3 v6 5
v4 v3 2
v4 v6 8
v4 v7 4
v4 v5 2
v5 v7 6
v7 v6 1

算法导论p360
1 3 3
3 9 6
1 5 5
3 5 1
9 11 2
5 11 6
5 9 4
*/