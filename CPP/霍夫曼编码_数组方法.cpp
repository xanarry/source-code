#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <map>
using namespace std;

struct Node
{
    char value;
    int weight;         
    int parent;         
    int left;         
    int right;         

    bool operator< (const Node a) const
    {
        return weight > a.weight;
    }

    Node(char v, int w, int p)
    {
        value = v;
        weight = w;
        parent = p;
        left = -1;
        right = -1;
    }

    Node(){}
}; 

void creatHuffman(Node *data, int len)
{
    priority_queue<Node> q;
    for (int i = 0; i < len; i++)
        q.push(data[i]);

    int offset = 0;//下标偏移量
    while (q.size() > 1)
    {
        //构造的新结点从下标n放到2*n-1
        Node a = q.top(); q.pop();
        Node b = q.top(); q.pop();

        data[len + offset].value = '#';
        data[len + offset].parent = len + offset;
        data[len + offset].weight = a.weight + b.weight;
        data[len + offset].left = a.parent;
        data[len + offset].right = b.parent;

        data[a.parent].parent = len + offset;
        data[b.parent].parent = len + offset;

        q.push(data[len + offset]);
        offset++;
    }
}

//递归构造huffman编码
void getCode(map<char, string> &hcode, Node *data, int len, int curPos, string code = "")
{
    if (data[curPos].value != '#')
        hcode[data[curPos].value] = code;
    if (data[curPos].left != -1)
        getCode(hcode, data, len, data[curPos].left, code + "0");
    if (data[curPos].right != -1)
        getCode(hcode, data, len, data[curPos].right, code + "1");
}

int main()
{
    const int len = 10;
    char ch[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};      //要编码的各字符 
    int w[]= {7, 3, 5, 2, 1, 4, 6, 9, 7, 8}; 

    //对n个数据编码,霍夫曼编码树一共会有2*n-1个结点, 所以数组开2*n-1
    Node data[2 * len - 1];
    for (int i = 0; i < len; i++)
        data[i] = Node(ch[i], w[i], i);
   
    creatHuffman(data, len);

    for (int i = 0; i < 2 * len - 1; i++)
        cout << "v:" << data[i].value << " w:" << data[i].weight << " p:" << data[i].parent << " L:" << data[i].left << " R:" << data[i].right << endl;
    
    map<char, string> hcode;
    getCode(hcode, data, len, 2 * len - 2);

    cout << "\nhuffman code" << endl;
    for (map<char, string>::iterator iter = hcode.begin(); iter != hcode.end(); ++iter)
        cout << iter->first << " : " << iter->second << endl;

    return 0;
}