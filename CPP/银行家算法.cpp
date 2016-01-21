#include <iostream>
using namespace std;

int max_need[100][100];
int cur_alloc[100][100];
int resource[100];
int res_remain[100];
bool has_run[100] = {false};


int main(int argc, char const *argv[])
{
    int processn, resourcen;
    cin >> processn >> resourcen;

    //avialable resource
    for (int i = 0; i < resourcen; i++)
    {
        cin >> resource[i];
        res_remain[i] = resource[i];
    }

    //max need matrix
    for (int i = 0; i < processn; i++)
        for (int j = 0; j < resourcen; j++)
            cin >> max_need[i][j];

    //allocation matrix
    for (int i = 0; i < processn; i++)
    {
        for (int j = 0; j < resourcen; j++)
        {
            cin >> cur_alloc[i][j];
            res_remain[j] -= cur_alloc[i][j];
        }
    }

    //search runable process
    int run_cnt = 0;
    int i = 0;
    while (run_cnt < processn)
    {
        if (!has_run[i])
        {
            int j;
            //check each resource that current process need, 
            //only if each resource in remain more than need that can run
            for (j = 0; j < resourcen; j++)
                if (res_remain[j] < max_need[i][j] - cur_alloc[i][j])
                    break;

            if (j == resourcen)//if all resource that in need are available
            {
                has_run[i] = true;
                for (int k = 0; k < resourcen; k++)
                    res_remain[k] += cur_alloc[i][k];//recycle resource that current process
                cout << "process: " << i + 1 << endl;
                run_cnt++;
            }
            else if (i == processn - 1)//it's a unsafe sequence if no process could run, 
            {
                cout << "unsafe sequence" << endl;
                return 0;
            }
            i = (i + 1) % processn;//cycling the process list
        }
    }
    return 0;
}
/*
5
3
17 5 20
5 5 9
5 3 6
4 0 11
4 2 5
4 2 4
2 1 2
4 0 2
4 0 5
2 0 4
3 1 4
*/