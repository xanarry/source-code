#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> mem, int reqseq)
{
    int i = 0;
    for ( ; i < mem.size(); i++)
        if (mem[i] == reqseq)
            return i;
    return i;
}

int main(int argc, char const *argv[])
{
    int n, blk, reqseq, exc = 0;
    vector<int> mem;

    cin >> n >> blk;
    for (int i = 0; i < n; i++)
    {
        cin >> reqseq;
        if (find(mem, reqseq) == mem.size() || mem.size() == 0)//not find
        {
            exc++;
            if (mem.size() == blk)//full
                mem.erase(mem.begin());
            mem.push_back(reqseq);
        }
    }
    cout << "remain: ";
    for (auto x : mem)
        cout << x << " ";
    cout << "\nrate: " << exc << "/" << n << endl;
    return 0;
}

/*
测试数据
20 3
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
15/20
*/