#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct CHAR
{
    char ch;//字符本身
    int rate;//出现概率
    string huffman_code;//霍夫曼编码
    CHAR *left;//指向坐节点的指针
    CHAR *right;//指向右节点的指针
};

struct cmp//自定义优先级队列的比较函数定义
{
    bool operator() (const CHAR *a, const CHAR *b) const
    {
        return a->rate > b->rate;
    }
};

CHAR *build_huffman_tree(priority_queue<CHAR *, vector<CHAR*>, cmp> pri_queue);
void construct_huffman_code(CHAR *root, string direction = ""); 
void decode_huffman(CHAR *root, int pos, string huffman_code);//为了避免数组中的线性搜索,定义一个解码函数

int main(int argc, char const *argv[])
{
    const int len = 7;
    CHAR chars[len] = {{'a', 10}, {'e', 15}, {'i', 12}, {'s', 3}, {'t', 5}, {'p', 13}, {'n', 1}};//测试数据
    priority_queue<CHAR *, vector<CHAR *>, cmp> pri_queue;//优先级队列中保存的是每个节点的指针,按指针所指向的值比较
    for (int i = 0; i < len; i++) 
        pri_queue.push(&chars[i]);//将指针放入优先级队列

    CHAR *root = build_huffman_tree(pri_queue);//创建霍夫曼树
    construct_huffman_code(root);//生成霍夫曼码

    //从头到尾都是使用的指针,所以在构造霍夫曼编码后,编码已经写入到数组中,直接输出即可
    for (int i = 0; i < len; i++)
        cout << chars[i].ch << "'s huffman_code: " << chars[i].huffman_code << endl;

    cout << "decode" << endl;
    string huffman_code = "111";
    decode_huffman(root, 0, huffman_code);//使用函数避免线性搜索,但输入的查询编码必须是合法的
    return 0;
}

CHAR *build_huffman_tree(priority_queue<CHAR *, vector<CHAR*>, cmp> pri_queue)
{
    while (pri_queue.size() > 1)
    {
        CHAR *min1 = pri_queue.top();
        pri_queue.pop();
        CHAR *min2 = pri_queue.top();
        pri_queue.pop();

        CHAR *root = new CHAR();
        root->ch = '#';
        root->rate = min1->rate + min2->rate;
        root->left = min1;
        root->right = min2;

        pri_queue.push(root);
    }
    return pri_queue.top();
}

void construct_huffman_code(CHAR *root, string direction)
{   
    if (root)
    {
        root->huffman_code = direction;
        construct_huffman_code(root->left, root->huffman_code + "0");
        construct_huffman_code(root->right,root->huffman_code + "1");
    }
} 

void decode_huffman(CHAR *root, int pos, string huffman_code)
{
    if (huffman_code.length() > pos)
    {
        if (huffman_code[pos] == '0')
            decode_huffman(root->left, pos + 1, huffman_code);
        else
            decode_huffman(root->right, pos + 1, huffman_code);
    }
    else
        cout << huffman_code << " map to: " << root->ch << endl;
}