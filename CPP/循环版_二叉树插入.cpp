#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};


void insert(Node **root, int n)
{
    Node *cur_pos = *root;
    Node *parent = *root;
    while (cur_pos)
    {
        parent = cur_pos;
        if (n >= cur_pos->data)
            cur_pos = cur_pos->right;
        else
            cur_pos = cur_pos->left;
    }    

    Node *new_node = new Node();
    new_node->data = n;
    new_node->left = NULL;
    new_node->right = NULL;

    if (!parent)
        *root = new_node;
    else if (n >= parent->data)        
        parent->right = new_node;    
    else
        parent->left = new_node;
}

Node *search(Node *root, int n)
{
    while (root && root->data != n)
    {
        if (n >= root->data)
            root = root->right;
        else
            root = root->left;
    }
    return root;
}

void traverse(Node *root)
{
    if (root)
    {
        traverse(root->left);
        cout << root->data << " ";
        traverse(root->right);
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {8,9,5,4,2,3,6,7,1};
    Node *root = NULL;
    for (auto i : a)
        insert(&root, i);

    traverse(root); cout << endl;

    Node *res = search(root, 1);
    cout << (res ? res->data : -1) << endl;
    return 0;
}