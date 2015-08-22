// The code is adopted from http://goo.gl/SDH9hH
#include <iostream>
using namespace std;


// An AVL tree Node
struct Node
{
    int key;
    Node *left;
    Node *right;
};

Node* newNode(int key)
{
    Node *node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

Node *rightRotate(Node *x)
{
    Node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

Node *splay(Node *root, int key)
{
    cout << "splaying in: " << root->key << " with: " << key << endl;
    // Base cases: root is NULL or key is present at root
    if (root == NULL || root->key == key)
        return root;
    // Key lies in left subtree
    if (root->key > key)
    {
        cout << "left";
        // Key is not in tree, we are done
        if (root->left == NULL) return root;
        // Zig-Zig (Left Left)
        if (root->left->key > key)
        {
            cout << " left" << endl;
            // First recursively bring the key as root of left-left
            root->left->left = splay(root->left->left, key);
            // Do first rotation for root, second rotation is done after else
            cout << "left left do rightRotate: " << root->key << endl;
            root = rightRotate(root);
        }
        else if (root->left->key < key) // Zig-Zag (Left Right)
        {
            cout << " right" << endl;
            // First recursively bring the key as root of left-right
            root->left->right = splay(root->left->right, key);
            // Do first rotation for root->left
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }
        // Do second rotation for root
        cout << "left second rightRotate: " << root->key << endl;
        return (root->left == NULL)? root: rightRotate(root);
    }

    else // Key lies in right subtree
    {
        cout << "right ";
        // Key is not in tree, we are done
        if (root->right == NULL) return root;
        // Zag-Zig (Right Left)
        if (root->right->key > key)
        {
            cout << "left" << endl;
            // Bring the key as root of right-left
            root->right->left = splay(root->right->left, key);
            // Do first rotation for root->right
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        else if (root->right->key < key)// Zag-Zag (Right Right)
        {
            cout << "right" << endl;
            // Bring the key as root of right-right and do first rotation
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
        // Do second rotation for root
        return (root->right == NULL)? root: leftRotate(root);
    }
}

Node *search(Node *root, int key)
{
    return splay(root, key);
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

Node *insert_without_splay(Node *root, int key)
{
    if (!root)
        root = newNode(key);
    else 
    {
        if (key > root->key)
            root->right = insert_without_splay(root->right, key);
        else if (key < root->key)
            root->left = insert_without_splay(root->left, key);
    }
    return root;
}

Node* insert(Node *root, int key)
{
    root = insert_without_splay(root, key);
    return splay(root, key);
}

Node* delNode(Node *root, int key)
{
    Node *temp;
    if (root)
    {
        root = splay(root, key);
        if (root->key == key)
        {
            if (root->left == NULL)
                temp = root->right;
            else
            {
                temp = root->left;
                temp = splay(temp, key);
                temp->right = root->right;
            }
            delete(root);
            root = temp;
        } 
    }
    return root;
}

#include <windows.h>
/* Drier program to test above function*/
int main()
{
    Node *root = NULL;
    for (int i = 0; i < 10; i++)
    {
        root = insert(root, i);
        preOrder(root); cout << endl;
    }

    root = insert(root, -1);
    preOrder(root); cout << endl;

    root = search(root, 3);
    preOrder(root); cout << endl;

    root = search(root, 7); preOrder(root); cout << endl;
    return 0;
}