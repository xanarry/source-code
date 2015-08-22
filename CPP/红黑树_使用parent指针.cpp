#include <iostream>
#include <queue>
#include <ctime>
#include <set>
#include <vector>
#include <cstdlib>
#define RED 1
#define BLACK 0
using namespace std;

struct Node
{
    int key;
    bool color;
    Node *left;
    Node *right;
    Node *parent;
};

Node *getNil();
Node *newNode(Node *parent, int key);
bool isRed(Node *node);
bool isBlack(Node *node);
void inorder(Node *rbt);
void preorder(Node *rbt);
void descNode(Node *root);
Node *search(Node *rbt, int n);
Node *findMin(Node *rbt);
Node *findMax(Node *rbt);
void leftRotate(Node **rbt, Node *key);
void leftRotate(Node **rbt, Node *key);
void insert(Node **rbt, int n);
void insertFixup(Node **rbt, Node *key);
void deleteNode(Node **rbt, int key);
void deleteFixup(Node **rbt, Node *x);

Node *getNil()
{
    Node *nil = new Node();
    nil->left = nil->right = nil->parent = nil;
    nil->color = BLACK;
    nil->key = 0x7FFFFFFF;
}

Node *nil = getNil();

Node *newNode(Node *parent, int key)
{
    Node *node = new Node();
    node->key = key;
    node->color = RED;
    node->parent = parent;
    node->left = nil;
    node->right = nil;
}

bool isRed(Node *node)
{
    return node && node->color == RED;
}

bool isBlack(Node *node)
{
    return !isRed(node);
}

Node *search(Node *root, int n)
{
    while (root != nil && root->key != n)
    {
        if (n > root->key)
            root = root->right;
        if (n < root->key)
            root = root->left;
    }
    return root;
}

Node *findMin(Node *root)
{
    while (root != nil && root->left != nil)
        root = root->left;
    return root;
}

Node *findMax(Node *root)
{
    while (root != nil && root->right != nil)
        root = root->right;
    return root;
}

void descNode(Node *root)
{
    cout << "[root(" << (root != nil ? root->key : -1) << "," << (root->color ? "red)" : "blk)");

    if (root->parent != nil)
        cout << "  pant(" << root->parent->key << "," << (root->parent->color ? "red)" : "blk)");
    else
        cout << "  pant( null )";
        
    if (root->left != nil)
        cout << "  left(" << root->left->key << "," << (root->left->color ? "red)" : "blk)");
    else
        cout << "  left( null )";

    if (root->right != nil)
        cout << "  rigt(" << root->right->key << "," << (root->right->color ? "red)" : "blk)");
    else
        cout << "  rigt( null )";
    cout << "]" << endl;
}


void preorder(Node *root)
{

    if (root != nil)
    {
        descNode(root);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root)
{
    if (root != nil)
    {
        inorder(root->left);
        descNode(root);
        inorder(root->right);
    }
}

void levelOrderTraverse(Node *root)
{
    queue<pair<Node *, int> > nodeps;
    nodeps.push(make_pair(root, 0));
    int preLeveal = 0;
    cout << "\nlevelOrderTraverse" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    while (!nodeps.empty())
    {
        pair<Node *, int> temp = nodeps.front();
        nodeps.pop();
        if (temp.second > preLeveal)
            cout << endl;
        if (temp.first != nil)
        {
            preLeveal = temp.second;
            cout << "(" << temp.first->key << ", " << (temp.first->color ? "r" : "b") << ")  ";
            if (temp.first->left != nil)
                nodeps.push(make_pair(temp.first->left, preLeveal + 1));
            if (temp.first->right != nil)
                nodeps.push(make_pair(temp.first->right, preLeveal + 1));
        }   
    } 
    cout << "\n-----------------------------------------------------------------------------" << endl;
}

void leftRotate(Node **root, Node *x)
{   
    Node *y = x->right;
    x->right = y->left; 
    if (y->left != nil)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == nil)
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

void rightRotate(Node **root, Node *x)
{
    Node *y = x->left;
    x->left = y->right; 

    if (y->right != nil)
        y->right->parent = x;

    y->parent = x->parent;
    
    if (x->parent == nil)
        *root = y;
    else
    {
        if (x->parent->left == x)
            x->parent->left = y;
        else
            x->parent->right = y;
    }
    y->right = x;
    x->parent = y;
}

void insert(Node **root, int n)
{
    //循环插入
    Node *t = *root;
    Node *parent = (*root)->parent;

    while (t != nil)
    {
        parent = t;
        if (n > t->key)
            t = t->right;
        else if (n < t->key)
            t = t->left;
    }

    Node *newKey = newNode(parent, n);
    if (t == nil && parent == nil)
    {
        *root = newKey;
        (*root)->parent = nil;
    }
    else
    {
        if (n > parent->key)
            parent->right = newKey;
        if (n < parent->key)
            parent->left = newKey;
    }
    insertFixup(root, newKey);
}

void insertFixup(Node **root,  Node *node)
{
    while (isRed(node->parent))
    {
        //deal with left
        if (node->parent == node->parent->parent->left)
        {
            Node *aunt = node->parent->parent->right ? node->parent->parent->right : nil;
            //case 1: aunt is red
            if (isRed(aunt))
            {
                node->parent->parent->color = RED;
                node->parent->color = BLACK;
                aunt->color = BLACK;
                node = node->parent->parent;
            }
            //case 2: aunt is black
            else
            {
                if (node == node->parent->right)
                {
                    node = node->parent;
                    leftRotate(root, node);
                }

                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rightRotate(root, node->parent->parent);
            }
        }   
        //deal with right
        else
        {
            Node *aunt = node->parent->parent->left ? node->parent->parent->left : nil;
            if (isRed(aunt))
            {
                node->parent->parent->color = RED;
                node->parent->color = BLACK;
                aunt->color = BLACK;
                node = node->parent->parent;
            }
            else
            {
                if (node == node->parent->left)
                {
                    node = node->parent;
                    rightRotate(root, node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                leftRotate(root, node->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

void deleteNode(Node **root, int key)
{
    Node *z = search(*root, key);
    if (z != nil)
    {
        Node *y = ((z->left == nil) || (z->right == nil)) ? z : findMax(z->left);
        Node *x = (y->left == nil) ? y->right : y->left;

        x->parent = y->parent;
        if(y->parent == nil)
            *root = x;
        else if(y==y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;

        if(y != z)
            z->key = y->key;

        if(y->color == BLACK)
            deleteFixup(root, x);

        delete y;
    }
}

void deleteFixup(Node **root, Node *x)
{
    while (x != *root && isBlack(x))
    {
        if (x == x->parent->left)
        {
            Node *w = x->parent->right;
            if (isRed(w))//case 1
            {
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(root, x->parent);
                w = x->parent->right;
            }  
            if (isBlack(w->left) && isBlack(w->right))//case 2
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if (isBlack(w->right))//case 3
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(root, w);
                    w = x->parent->right;
                }
                //case 4
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(root, x->parent);
                x = *root;//第四种情况是终止条件, 所以直接将x移动到根节点结束修复
            }    
        }
        else
        {
            Node *w = x->parent->left;
            if (isRed(w))//case 1
            {
                x->parent->color = RED;
                w->color = BLACK;
                rightRotate(root, x->parent);
                w = x->parent->left;
            }
            if (isBlack(w->left) && isBlack(w->right))//case 2
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if (isBlack(w->left))
                {
                    w->color = RED;
                    x->right->color = BLACK;
                    leftRotate(root, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(root, x->parent);
                x = *root;
            }
        }
    }
    x->color = BLACK;
}


int main(int argc, char const *argv[])
{
    srand(time(NULL));
    const int len = 10;
    Node *rbt = nil;
    int a[] = {10, 85, 15, 70, 20, 60, 30, 50};
    int b[] =  {23, 2, 14, 20, 29, 11, 21, 27, 25, 9};

    set<int> tset;
    vector<int> v;
    v.assign(b, b + len);

    //while (tset.size() != len)
    //{
    //    int t = rand() % (len + 20);
    //    if (!tset.count(t))
    //        v.push_back(t);
    //    tset.insert(t);
    //}
    
    cout << "\ninsert_______________________________________________" << endl;
    for (int i = 0; i < len; i++)
        insert(&rbt, v[i]);

    cout << "key list: {";
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
        cout << *iter << ", ";
    cout << "}" << endl;

    cout << "preorder---------------------------------------------------" << endl;
    preorder(rbt);
    cout << "-----------------------------------------------------------" << endl;
    

    for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
    {
        deleteNode(&rbt, *iter);
        cout << "deleteNode: " << *iter << endl;
        cout << "------------------------------------------" << endl;
        preorder(rbt);
        cout << "\n------------------------------------------" << endl;
    }
    preorder(rbt); cout << endl;

    return 0;
}
