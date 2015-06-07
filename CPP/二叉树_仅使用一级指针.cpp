#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *insert(Node *root, int n)
{
    Node *new_node = new Node();
    new_node->data = n;
    new_node->left = new_node->right = NULL;
    if (!root)
        root = new_node;
    else if (n >= root->data)
        root->right = insert(root->right, n);
    else
        root->left = insert(root->left, n);
    return root;
}

void inorder_traverse(Node *root)
{
    if (root)
    {
        inorder_traverse(root->left);
        cout << root->data << " ";
        inorder_traverse(root->right);
    }
}

Node *find_max(Node *root)
{
    return root->right ? find_max(root->right) : root;
}

Node *find_min(Node *root)
{
    return root->left ? find_min(root->left) : root;
}

Node *search(Node *root, int n)
{
    if (root)
    {
        if (n > root->data)
            return search(root->right, n);
        else if (n < root->data)
            return search(root->left, n);
        else
            return root;
    }
    return NULL;
}

Node *delete_node(Node *root, int n)
{
    if (!root || !search(root, n))
        return root;
    if (n > root->data)
        root->right = delete_node(root->right, n);
    else if (n < root->data)
        root->left = delete_node(root->left, n);
    else
    {
        if (root->left && root->right)//both left and right are not NULL
        {
            Node *temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
        else 
        {
            Node *temp = root;
            if (root->right == NULL)//right is NUL
                root = root ->left;
            else if (root->left == NULL)
                root = root->right;
            delete(temp);
        }
    }
    return root;
}

int main()
{
    Node *root = NULL;
    for (int i = 0; i <= 10; i++)
        root = insert(root, i);
    inorder_traverse(root);
    cout << endl;
    return 0;
}