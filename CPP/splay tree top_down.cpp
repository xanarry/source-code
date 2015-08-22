#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
};

Node *newNode(int key = 0x7fffffff)
{
    Node *newOne = new Node();
    newOne->key = key;
    newOne->left = NULL;
    newOne->right = NULL;
    return newOne;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

Node *rightRotate(Node *x)
{
    Node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

Node *splay(Node *root, int key)
{
    /*
    zigzig选择当前跟节点, 然后移走一层
    zigzag移走最上面一层
    zig移走上面一层
    */
    Node *header = newNode();
    Node *leftMax = header;
    Node *rightMin = header;

    while (key != root->key)
    {
        if (key < root->key)
        {
            if (root->left && key < root->left->key)//LL zigzig also
                root = rightRotate(root);
            if (root->left == NULL)
                break;
            rightMin->left = root;
            rightMin = root;
            root = root->left;
        }
        if (key > root->key)
        {
            if (root->right && key > root->right->key)//RR zigzig also
                root = leftRotate(root);
            if (root->right == NULL)
                break;
            leftMax->right = root;
            leftMax = root;
            root = root->right;
        }
    }
    //final case: meet x as the current root
    leftMax->right = root->left;
    rightMin->left = root->right;
    root->left = header->right;
    root->right = header->left;
    return root;
}

Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        root = newNode(key);
        return root;
    }
    root = splay(root, key);
    if (key > root->key)
    {
        Node *newOne = newNode(key);
        newOne->left = root; 
        newOne->right = root->right;
        root->right = NULL;
        return newOne;
    }
    else if (key < root->key)
    {
        Node *newOne = newNode(key);
        newOne->right = root;
        newOne->left = root->left;
        root->left = NULL;
        return newOne;
    }
    return root;
}

bool search(Node *root, int key)
{
    return splay(root, key)->key == key ? true : false;
}

Node *deleteNode(Node *root, int key)
{
    /*
    for not empty tree, do splay, if the key of root is equal to the destination key, then
    check whether it has left subtree, if not, then the right subtree gonna be the new tree
    else do splay on left subtree and set it as the new tree, after that, set the old tree's
    right subtree as the new tree's right subtree, finally we delete the old root then done
    */
    Node *newTree;
    if (root == NULL)
        return NULL;
    root = splay(root, key);
    if (root->key == key)
    {
        if (root->left == NULL)
            newTree = root->right;
        else
        {
            newTree = splay(root->left, key);
            newTree->right = root->right;
        }
        delete root;
        return newTree;
    }
    return root;
}

void descNode(Node *root)
{
    if (!root) cout << "(root: 0, left: 0, rigt: 0)" << endl;
    else
    {
        cout << "(root: " << root->key << ",";
        if (root->left) cout << " left: " << root->left->key << ",";
        else cout << " left: 0,";
        if (root->right) cout << " rigt: " << root->right->key << ")";
        else cout << " rigt: 0)";
        cout << endl;
    }
}

void preOrder(Node *root)
{
    if (root)
    {
        descNode(root);
        preOrder(root->left);
        preOrder(root->right);
    }
}


int main(int argc, char const *argv[])
{
    const int len = 10;
    Node *tree = NULL;
    for (int i = 1; i <= 10; i++)
    {
        tree = insert(tree, i);
        preOrder(tree); cout << endl;
    }
    tree = insert(tree, -1);
    preOrder(tree); cout << endl;

    tree = splay(tree, 3);
    preOrder(tree);cout << endl;

    tree = splay(tree, 7);
    preOrder(tree); cout << endl;

    tree = deleteNode(tree, 7);
    cout << "del 7" << endl;
    preOrder(tree); cout << endl;

    for (int i = 1; i <= 10; i++)
    {
        cout << "del " << i << endl;
        tree = deleteNode(tree, i); preOrder(tree); cout << endl;
    }

    cout << "del " << -1 << endl;
    tree = deleteNode(tree, -1); preOrder(tree); cout << endl;
    return 0;
}
