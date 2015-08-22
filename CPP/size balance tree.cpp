#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    int size;
};  

Node *newNode(int key)
{
    Node *newOne = new Node();
    newOne->key = key;
    newOne->left = NULL;
    newOne->right = NULL;
    newOne->size = 1;
    return newOne;
}

void preOrder(Node *root)
{
    if (root)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int getSize(Node *x)
{
    return x ? x->size : 0;
}

Node *rightRotate(Node *x)
{
    Node *y = x->left;
    x->left = y->right;
    y->right = x;
    y->size = x->size;
    x->size = getSize(x->left) + getSize(x->right) + 1;
    return y;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    y->size = x->size;
    x->size = getSize(x->left) + getSize(x->right) + 1;
    return y;
}

Node *findMin(Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

Node *findMax(Node *root)
{
    while (root && root->right)
        root = root->right;
    return root;
}

Node *find(Node *root, int key)
{
    while (root && root->key != key)
    {
        if (key >= root->key)
            root = root->right;
        else
            root = root->left;
    }
    return root;
}

int getRank(Node *root, int key)
{
    if (!root)
        return -1;
    Node *curPos = root;
    int curRank = getSize(root->left) + 1;
    while (curPos && curPos->key != key)
    {
        //cout << curPos->key << "'s rank = " << curRank << endl;
        if (key > curPos->key)
        {
            curPos = curPos->right;
            if (curPos)
                curRank = curRank + getSize(curPos->left) + 1;
        }
        else if (key < curPos->key)
        {
            curPos = curPos->left;
            if (curPos)
                curRank = curRank - getSize(curPos->right) - 1;
        }
    }
    if (key < findMin(root)->key)
        return 0;
    else if (key > findMax(root)->key)
        return curRank + 1;
    else
        return curRank;
}

int _getRank(Node *root, int key)//求key排第几  
{  
    if(key < root->key)  
        return _getRank(root->left, key);  
    else if(key > root->key)  
        return _getRank(root->right, key) + getSize(root->left) + 1;  
    return getSize(root->left) + 1;  
}  

Node *select(Node *root, int k)
{
    int r = getSize(root->left) + 1;
    if (r == k)
        return root;
    else if (k > r)
        return select(root->right, k - r);
    else
        return select(root->left, k);
}

Node *previous(Node *root, int key, Node *parent = NULL)
{
    if (root == NULL)
        return parent;
    else if (key > root->key)
        return previous(root->right, key, root);
    else
        return previous(root->left, key, parent);
}

Node *successor(Node *root, int key, Node *parent = NULL)
{
    if (root == NULL)
        return parent;
    else if (key < root->key)
        return successor(root->left, key, root);
    else
        return successor(root->right, key, parent);
}

Node *maitain(Node *x)
{
    /*
    property of a size balance tree
    case 1: T.left.size >= (T.right.left.size and T.right.right.size)
    case 2: T.right.size >= (T.left.left.size and T.left.right.size)
    */

    //cout << "fixing: " << x->key << endl;
    //case 1:  right is bigger
    if (x->right)
    {
        //cout << "sibling in right" << endl;
        if (getSize(x->right->left) > getSize(x->left))
        {
            //cout << "rightRotate: " << x->right->key << endl;
            x->right = rightRotate(x->right);
        }
        if (getSize(x->right->right) > getSize(x->left))
        {
            //cout << "leftRotate: " << x->key << endl;
            x = leftRotate(x);
        }
    }
    //case 2: left is bigger
    if (x->left)
    {
        //cout << "sibling in left" << endl;
        if (getSize(x->left->right) > getSize(x->right))
        {
            //cout << "leftRotate: " << x->left->key << endl;
            x->left = leftRotate(x->left);
        }
        if (getSize(x->left->left) > getSize(x->right))
        {
            //cout << "rightRotate: " << x->key << endl;
            x = rightRotate(x);
        }
    }
    return x;
}

Node *insert(Node *root, int key)
{
    if (!root)
        return root = newNode(key);
    if (key >= root->key)
        root->right = insert(root->right, key);
    else
        root->left = insert(root->left, key);
    root->size = getSize(root->left) + getSize(root->right) + 1;
    root = maitain(root);
}

int deleteNode(Node *(&root), int key)
{
    /*
    Delete(t,v) here is a function that returns the value deleted. 
    It can result in a destroyed SBT. 
    But with the insertion above, 
    a BST is still kept at the height of O(logn*)

    delet in sbt just like delete in bst, besides update the size of
    node on the searching path,
    */

    root->size--;
    //cout << "get: " << root->key << endl;
    if (key == root->key || key > root->key && !root->right || key < root->key && !root->left)
    {   
        //cout << "get right value: " << root->key << endl;
        if (root->left == NULL || root->right == NULL)
        {
            Node *tmp = root;
            if (root->left == NULL)
                root = root->right;
            else if (root->right == NULL)
                root = root->left;
            return tmp->key;
            delete tmp;
        }   
        else
        {
            return root->key = deleteNode(root->left, key + 1);
        }
    }
    else
    {
        //cout << "cur: " << root->key << " dest: " << key << endl;
        if (key >= root->key)
        {
            //cout << "go right" << endl;
            return deleteNode(root->right, key);
        }
        else
        {
            //cout << "go left" << endl;
            return deleteNode(root->left, key);
        }
    }
}
#include <ctime>
#include <cstdlib>
const int len = 10;
int a[len];
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    Node *tree = NULL;
    int a[len] = {3,8,7,0,5,5,2,4,7,9};
    for (int i = 0; i < len; i++)
    {
        //a[i] = rand() % 10;
        cout << "insert " << a[i] << ": ";
        tree = insert(tree, a[i]);
        preOrder(tree);cout << endl;
    }
    cout << "finish insert" << endl;

    for (int i = 0; i < len; i++)
    {
        cout << "rank " << a[i] << ": " << _getRank(tree, a[i]) << endl;
    }
    
    int t = 7;
    cout << t << "'s successor: " << endl;
    Node *suc = successor(tree, t);
    if (suc) cout << suc->key << endl;

    t = 7;
    cout << t << "'s previous: " << endl;
    Node *pre = previous(tree, t);
    if (pre) cout << pre->key << endl;

    t = 100;
    cout << t << "'s precessor: " << endl;
    pre = previous(tree, t);
    if (pre) cout << pre->key << endl;

    /*for (int i = 0; i < len; i++)
    {
        cout << "delete " << deleteNode(tree, a[i]) << ": ";
        preOrder(tree);cout << endl;
    }
    cout << "finish delete" << endl;*/

    return 0;
}


/*
insert 3: 3
insert 8: 3 8
insert 7: 7 3 8
insert 0: 7 3 0 8
insert 5: 7 3 0 5 8
insert 5: 5 3 0 7 5 8
insert 2: 5 2 0 3 7 5 8
insert 4: 5 2 0 3 4 7 5 8
insert 7: 5 2 0 3 4 7 5 8 7
insert 9: 5 2 0 3 4 7 5 8 7 9
finish insert
rank 3: 4
rank 8: 9
rank 7: 7
rank 0: 2
rank 5: 5
rank 5: 5
rank 2: 3
rank 4: 5
rank 7: 7
rank 9: 10
请按任意键继续. . .
*/
