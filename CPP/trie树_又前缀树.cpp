#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

#define MAX_CH_NUM 26

/*a trie tree for English word searching, 26 characters need 26 nodes*/

struct Node
{
    //不需要有单独的变量保存该结点的字符, 可以通过从上一个结点的suffix数组哪一个下标而来得出这个字母
    int num;//该字母出现的次数
    bool isw;//判断该字母是否为一个单词的结尾
    Node *suffix[MAX_CH_NUM];//该字符的下一个字符, 最多有26个
};

void insert(Node *root, string word)//插入一个单词到数中
{
    for (int i = 0; i < word.length(); i++)
    {
        /*一单词中字母的顺利为路径, 一直先下走, 如果走到了NULL指针, 说明这个字母需开新结点要存储
        ,并且设num为1,如果单词中的每个字母都走完, 但是没有走到NULL指针, 说明这个单词是另外一个单
        词的前缀, 需要给经过路径结点上的num加1, 最后当每个单词走完时, 需要个结束位置做标记, 以方
        便查找, 否则, 加入字典中有个单词为abcde并不含有abc, 查询abc时会输出字典中有这它
        */
        int pos = word[i] - 'a';
        if (root->suffix[pos] == NULL)//走到原尽头, 说明这个单词长
        {
            root->suffix[pos] = new Node();
            root->suffix[pos]->num = 1;
        }
        else
            root->suffix[pos]->num++;

        if (i == word.length() - 1)
            root->suffix[pos]->isw = true;
        root = root->suffix[pos];
    }
}

int search(Node *root, string str)
{
    if (!root) 
        return 0;
    //顺序查找单词中的每个字母, 如果没有走到NULL并且终点字符有isw标记则查找成功
    for (int i = 0; i < str.length(); i++)
    {
        int pos = str[i] - 'a';
        root = root->suffix[pos];
        if (root == NULL)
            break;
    } 
    return root && root->isw ? root->num : 0;
}

void show_words(Node *root, string prefix)
{
    if (!root)
        return;

    //相同前缀, 如果有isw结束标记则是一个完整的单词, 从短到长输出, 放到最后就是从长到短输出
    if (root->isw)
        cout << prefix << endl;

    //dfs,prefix保存每个节点的前缀字符串
    for (int i = 0; i < MAX_CH_NUM; i++)
        if (root->suffix[i])
            show_words(root->suffix[i], prefix + (char)('a' + i));
}


void search_result(Node *root, string str)
{
    if (!root)
        return;
    //找到给定前缀结束节点, 给定空串时, 直接跳过循环, 字典序遍历所有单词
    for (int i = 0; i < str.length(); i++)
    {
        int pos = str[i] - 'a';
        root = root->suffix[pos];
        if (root == NULL)
            break;
    } 

    if (root)//从结束的结点搜索所有后缀结点
        show_words(root, str);
    else
        cout << "no result finded" << endl;
}


void del(Node *root, string word, int i = 0)//删除单词, 删除单词时请先判断单词存在
{
    if (!root)
        return;
    //dfs走到单词的底部, 在反向回溯过程中对每个结点上的num值减1, 如果num减到了0, 直接释放0下标的结点
    int pos = word[i] - 'a';
    if (!root->suffix[pos]->isw && i < word.length())
         del(root->suffix[pos], word, i + 1);

    root->suffix[pos]->num--;
    if (root->suffix[pos]->num == 0)
    {
       delete root->suffix[pos];//释放内存
       root->suffix[pos] = NULL;//一定要置为NULL,防止非法访问
    }
}

int main(int argc, char const *argv[])
{
    int n = 10;
    string words[2000] = {"about", "to", "tea", "boring", "any", "ted", "ten", "i", "in", "inn"};

    goto START;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> words[i];
    
    START:

    Node *root = new Node();

    for (int i = 0; i < n; i++)
        insert(root, words[i]);

    for (int i = 0; i < n; i++)
    {
        if (search(root, words[i]))
            cout << "yes " << words[i] << endl;
        else
            cout << "no  " << words[i] << endl;
    }

    string prefix = "t";
    cout << "\nwords start with \"" << prefix << "\"" << endl;
    search_result(root, prefix);


    cout << "\ntraverse" << endl;//给空串,直接遍历所有单词
    search_result(root, "");
    for (int i = 0; i < n; i++)
        if (search(root, words[i]))
            del(root, words[i]);
    return 0;
}