#include <iostream>
using namespace std;
int lis[100009];
int main()
{
    int n, in;
    int t = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> in;
        if (t == 0 || in > lis[t - 1])
            lis[t++] = in;
        else
        {
            int l = -1, r = t, mid;
            do
            {
                mid = (r + l) / 2;
                if (in > lis[mid])
                    l = mid;
                else if (in < lis[mid])
                    r = mid;
            } while (lis[mid] <= in);
            lis[mid] = in;
        }
    }
    cout << "len: " << t << endl;
    for (int i = 0; i < t; i++)
        cout << lis[i] << " ";
    return 0;
}
