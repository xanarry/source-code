#include <iostream>

using namespace std;

int main()
{
    int h1, m1, s1;
    int h2, m2, s2;

    cin >> h1 >> m1 >> s1;
    cin >> h2 >> h2 >> h2;

    long t_start = h1 * 3600  + m1 * 60 + s1;
    long t_end = h2 * 3600 + m2 * 60 + s2;

    cout << t_end << endl;
    cout << t_start << endl;
    cout << t_end - t_start << endl;
}


/*
12 34 56
23 45 54
*/
