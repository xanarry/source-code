#include <iostream>
#include <set>
#include <vector>
using namespace std;

void gen_permutation(vector<int> permutation, set<int> s, int cur, int n)
{
    if (cur == n)
    {
        cout << '[';
        for (int i = 0; i < permutation.size(); ++i)
            cout << permutation[i] << " ";
        cout << "\b]" << endl;
    }
    else
    {
        cur++;
        for (set<int>::iterator iter = s.begin(); iter != s.end(); ++iter)
        {
            int i = 0;
            for (i = 0; i < permutation.size(); ++i)
                if (permutation[i] == *iter)
                    break;
            if (i == permutation.size())
            {
                vector<int> v = permutation;
                v.push_back(*iter);
                gen_permutation(v, s, cur, n);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    set<int> s;
    int n, t;
    cin >> n; 
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        s.insert(t);
    }
    vector<int> v;
    gen_permutation(v, s, 0, s.size());
    return 0;
}