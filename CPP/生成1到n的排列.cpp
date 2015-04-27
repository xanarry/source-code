#include <iostream>
#include <vector>
using namespace std;

void gen_permutation(vector<int> permutation, int cur, int n)
{
    if (cur == n)
    {
        cout << "[";
        for (int i = 0; i < permutation.size(); ++i)
            cout << permutation[i] << " ";
        cout << "\b]" << endl;
        return;
    }
    else
    {
        
        cur++;
        for (int i = 1; i <= n; ++i)
        {
            int j = 0;
            for (j = 0; j < permutation.size(); ++j)
                if (permutation[j] == i)
                    break;
            if (j == permutation.size())
            {
                vector<int> v = permutation;
                v.push_back(i);
                gen_permutation(v, cur, n);
            }
        }
    }
}


int main(int argc, char const *argv[])
{
    vector<int> permutation;
    int n;
    cin >> n;
    gen_permutation(permutation, 0, n);
    return 0;
}