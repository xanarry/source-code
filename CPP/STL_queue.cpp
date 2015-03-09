#include <queue>
#include <string>
#include <iostream>

using namespace std;

struct VERTEX
{
    string name;
    int distance;
};


int main(int argc, const char *argv[])
{
    queue<VERTEX *> vertex_queue;
    VERTEX *a = new VERTEX();
    a->name = "a";
    a->distance = 0;

    VERTEX *b = new VERTEX();
    b->name = "b";
    b->distance = 0;

    VERTEX *c = new VERTEX();
    c->name = "c";
    c->distance = 0;

    vertex_queue.push(a);
    vertex_queue.push(b);
    vertex_queue.push(c);

    cout << vertex_queue.front()->name << endl;

    cout << vertex_queue.size() << endl;
    for (int i = 0; i < 3; i++)
        cout << vertex_queue.find() << endl;

    return 0;
}
