#include <iostream>
using namespace std;

struct Node
{
    int data;
    bool ltag, rtag;//0指向孩子, 1为前后趋线索
    Node *left, *right;
};

Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        root = new Node();
        root->data = key;
        root->ltag = 1;
        root->rtag = 1;
        root->left = NULL;
        root->right = NULL;
    }
    else if (key >= root->data)
    {
        root->right = insert(root->right, key);
        root->rtag = 0;
    }
    else
    {
        root->left = insert(root->left, key);
        root->ltag = 0;
    }
    return root;
}

void in_order_traverse(Node *root)
{
    if (root)
    {
        in_order_traverse(root->left);
        cout << "[" << root->ltag << "," <<root->data << "," << root->rtag << "]" << endl;
        in_order_traverse(root->right);
    }
}

void in_order_threading(Node *root, Node *pre, Node *next)
{
    if (root->left)//左子树的后继节点一定是当前作为跟的节点
        in_order_threading(root->left, pre, root);
    else
        root->left = pre;

    if (root->right)//右子树的前驱一定是当前作为跟的节点
        in_order_threading(root->right, root, next);
    else
        root->right = next;
}

Node *find(Node *root, int key)
{
    if (!root)
        return NULL;

    if (root->data == key)
        return root;
    else if (key > root->data)
        return find(root->right, key);
    else 
        return find(root->left, key);
}

int main(int argc, char const *argv[])
{
    int n = 10;
    int num[1000] = {4,5,1,2,7,6,9,8,0,3};

    Node *root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, num[i]);

    in_order_traverse(root);
    cout << endl;

    in_order_threading(root, NULL, NULL);

    Node *res = find(root, 6);
    if (res)
    {
        cout << res->left->data << endl;
        cout << res->data << endl;
        cout << res->right->data << endl;
    }
    return 0;
}