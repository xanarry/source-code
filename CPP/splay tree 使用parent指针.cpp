#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *parent;
    Node *left;
    Node *right;
};

void preOrder(Node *root)
{
    if (root)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

Node *getNew(Node *parent, int key)
{
    Node *newOne = new Node();
    newOne->parent = parent;
    newOne->key = key;
    return newOne;
}

void rightRotate(Node **root, Node *x)
{
    Node *y = x->left;
    x->left = y->right;

    y->parent = x->parent;

    if (y->parent == NULL)
        *root = y;
    else
    {
        if (x->parent->left == x)
            x->parent->left = y;
        else
            x->parent->right = y;
    }

    if (y->right)
        y->right->parent = x;

    y->right = x;
    x->parent = y;
}

void leftRotate(Node **root, Node *x)
{
    Node *y = x->right;
    x->right = y->left;

    if (y->left)
        y->left->parent = x;

    y->parent = x->parent;

    if (y->parent == NULL)
        *root = y;
    else
    {
        if (x->parent->left == x)
            x->parent->left = y;
        else
            x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void splay(Node **root, Node *dest)//from buttom to top, a down up way
{
    //the way of splay first rotate x's grandparent if which has, and secondly ratate x's parent 
    while (dest && dest != *root)//from buttom to top, a down up way
    {
        if (dest->parent->parent)//three level structure may has zig-zig or zig-zag
        {
            if (dest->parent == dest->parent->parent->left)//L
            {
                if (dest == dest->parent->left)//LL zig-zig, first rotation
                    rightRotate(root, dest->parent->parent);
                else//LR zig-zag first rotation
                    leftRotate(root, dest->parent);
                //second rotaton, both zig-zig and zig-zag of left need right rotation
                rightRotate(root, dest->parent);
            }
            else//R
            {   
                if (dest == dest->parent->right)//RR zig-zig first rotation
                    leftRotate(root, dest->parent->parent);
                else//RL zig-zag first ratation
                    rightRotate(root, dest->parent);
                //second rotaton, both zig-zig and zig-zag of right need left rotation
                leftRotate(root, dest->parent);
            }
        }
        else//only two level, the only situation is zig
        {
            if (dest == dest->parent->left)//L zig
                rightRotate(root, dest->parent);
            else//R zig
                leftRotate(root, dest->parent);
        }
    }
}

void insert(Node **root, int key)
{
    if ((*root) == NULL)
    //if root is null, then make the root pointer point to the new root node
        *root = getNew(NULL, key);
    else
    {
        //like a bst, greater or equal to current node's value then go right, otherwise to left
        //to find the right place to insert
        Node *parent = *root;
        Node *curPos = *root;
        while (curPos)
        {
            parent = curPos;
            if (key >= curPos->key)
                curPos = curPos->right;
            else
                curPos = curPos->left;
        }
        //insert new node
        Node *newOne = getNew(parent, key);
        if (key >= parent->key)
            parent->right = newOne;
        else
            parent->left = newOne;
        //from down to up to splay new inserted node
        splay(root, newOne);
    }
}

Node *search(Node **root, int n)
{
    Node *parent, *temp = *root;
    while (temp && temp->key != n)
    {
        parent = temp;
        if (n >= temp->key)
            temp = temp->right;
        else
            temp = temp->left;
    }

    /*notice that if we find the right node in the tree then splay it
      but if not, we splay the cloest node to the node we want*/

    if (temp)//find the right node
        splay(root, temp);
    else//not find, splay the cloest node
        splay(root, parent);
    return *root;
}

Node *findMax(Node *root)
{
    while (root && root->right)
        root = root->right;
    return root;
}

void deleteNode(Node **root, int key)
{
    /*the way of delete a node is that we only delete node on the top of the tree
        so give a wanted node, we first do a splay to this node to move the related
        node up to tree root, after splay check whether the root's value is the des-
        tination value we want to delete, because someone may give a value not in 
        the tree, if the root's value is the right value, then, check if the root has
        a left subtree, if not, move the root pointer its right subtree's root, and 
        delete done, otherwise, we do a splay to left subtree's max node on left sub-
        tree, to enssure that after the splay, left subtree's root has no right child,
        set the root of left subtree as the root of the whole tree, and connect to the
        right subtree of old tree, after all that done, we delete the old root from 
        from the memory, and all done
        */
    //search the given value
    Node *res = search(root, key);
    if (res->key == key)//if the given value in the tree
    {
        Node *t = *root;
        //left subtree is null
        if ((*root)->left == NULL)
        {
            *root = t->right;
            if (*root)//set the root of right subtree as new tree root directly
                (*root)->parent = NULL;
        }
        else
        {
            Node *leftChild = t->left;
            Node *rightChild = t->right;
            leftChild->parent = NULL;
            //splay left subtree
            splay(&leftChild, findMax(leftChild));

            //connect the old right subtree
            leftChild->right = rightChild;

            if (rightChild)
                rightChild->parent = leftChild;

            *root = leftChild;//set new tree root
        }
        delete t;//free mem
    }
}
#include <windows.h>
#include <cstdlib>
#include <ctime>
const int len = 1000000;
int a[len];

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    Node *root = NULL;
    
    for (int i = 0; i < len; i++)
    {
        a[i] = rand() % 100;
        //cout << "insert: " << a[i] << ": ";
        insert(&root, a[i]);//preOrder(root); cout << endl;
    }
    cout << "finish insert" << endl;
    /*for (int i = 0; i < len; i++)
    {
        cout << "search: " << a[i] << ": ";
        search(&root, a[i]);preOrder(root); cout << endl;
    }
    cout << "finish visiting" << endl;
    cout << "origin:    ";preOrder(root); cout << endl;*/
    for (int i = 0; i < len; i++)
    {
        //cout << "delete: " << a[i] << ": ";
        deleteNode(&root, a[i]);//preOrder(root); cout << endl;
    }
    cout << "finish deletint" << endl;
    cout << "time consume: " << (double) clock() / CLOCKS_PER_SEC << endl;
    return 0;
}
//5 0 4 5 5 5 6 8 8 9