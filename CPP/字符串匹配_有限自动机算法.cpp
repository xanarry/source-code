#include <iostream>
#include <cstring>
#define DIST_NUM 128
#define MAX_STRLEN 1000000
using namespace std;

int state_table[MAX_STRLEN][DIST_NUM];

int max_matching(char *pattern, int init_state, char cur_ch)
{
    int i, j, k;
    for (i = init_state; i >= 0; i--)//假定一个最大长度
    {
        if (i < strlen(pattern) && cur_ch == pattern[i])//首先额外添加的字符相同才能继续比较
        {
            for (j = i - 1, k = init_state - 1; j >= 0; j--, k--)//基于上面的假定长度进行比较
                if (pattern[j] != pattern[k])
                    break;
            if (j == -1)
                return i + 1;
        }
    }
    return 0;
}   

void gen_state(char *pattern)
{
    for (int is = 0; is <= strlen(pattern); is++)
        for (int ch = 0; ch < DIST_NUM; ch++)
            state_table[is][ch] = max_matching(pattern, is, (char) ch);
}


int pattern_search(char *text, char *pattern)
{
    int len_t = strlen(text);
    int len_p = strlen(pattern);
    int state = 0;
    int res = 0;
    gen_state(pattern);

    for (int i = 0; i < len_t; i++)
        if ((state = state_table[state][text[i]]) == len_p) 
            cout << "find pattern at:" << i - len_p + 1 << endl, res++;
    return res;
}

int main(int argc, char const *argv[])
{
    char text[MAX_STRLEN];
    char pattern[MAX_STRLEN];

    cin >> text >> pattern;
    cout << "pattern count:" << pattern_search(text, pattern) << endl;
    return 0;
}

/*
char text[MAX_STRLEN] = "AABAACAADAABAAABAA";
char pattern[MAX_STRLEN] = "AABA";

AABAACAADAABAAABAA
012342012012342234
123420120123422342

find pattern at:0
find pattern at:9
find pattern at:13
*/