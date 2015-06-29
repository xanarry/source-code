#include <iostream>
#include <string>
#include <ctime>
#include <set>
#include <cstdlib>
#include <queue>
#define RED 1
#define BLACK 0
using namespace std;

struct Node
{
    int key;
    bool color;
    Node *left;
    Node *right;
};

void desc_node(Node *root);
void output_tree(Node *root);

Node *newNode(int n)
{
    Node *node = new Node();
    node->color = RED;
    node->right = NULL;
    node->left = NULL;
    node->key = n;
    return node;
}

Node *leftRotate(Node *root)
{
    Node *rightNode = root->right;
    root->right = rightNode->left;
    rightNode->left = root;

    rightNode->color = rightNode->left->color;
    rightNode->left->color = RED;
    return rightNode;
}


Node *rightRotate(Node *root)
{
    Node *leftNode = root->left;
    root->left = leftNode->right;
    leftNode->right = root;

    leftNode->color = leftNode->right->color;
    leftNode->right->color = RED;
    return leftNode;
}

Node *leftRightRotate(Node *root)
{
    root->left = leftRotate(root->left);
    return rightRotate(root);
}

Node *rightLeftRotate(Node *root)
{
    root->right = rightRotate(root->right);
    return leftRotate(root);
}

void desc_node(Node *root)
{
    if (!root)
        cout << "[ null ]" << endl;
    else
    {
        cout << "[root(" << root->key << "," << (root->color ? "red)" : "blk)");
        if (root->left)
            cout << "  left(" << root->left->key << "," << (root->left->color ? "red)" : "blk)");
        else
            cout << "  left( null )";

        if (root->right)
            cout << "  rigt(" << root->right->key << "," << (root->right->color ? "red)" : "blk)");
        else
            cout << "  rigt( null )";
        cout << "]" << endl;
    }
}

bool isRed(Node *root)
{
    return root && root->color == RED;
}

bool isBlack(Node *root)
{
    return !isRed(root);
}

Node* insertFixup(Node *root)
{
//case   1: L
    if (root->left)//如果有左孩子
    {
        if (isRed(root->left))//如果左孩子是红色
        {
//case 1.2: LL
            if (isRed(root->left->left))//并且最左孙子为红色
            {
                //LL,并且右侧叔叔是红色
                if (isRed(root->right))//叔叔为红色
                {
                    root->color = RED;
                    root->left->color = BLACK;
                    root->right->color = BLACK;
                }
                //LL, 右侧叔叔是黑色
                else
                    root = rightRotate(root);
            }
//case 1.2: LR
            else if (isRed(root->left->right))//左边孩子的右边孩子为红色
            {
                //LR, 右侧的叔叔为红色
                if (isRed(root->right))//叔叔为红色
                {
                    root->color = RED;
                    root->left->color = BLACK;
                    root->right->color = BLACK;
                }
                //LR, 右侧的叔叔为黑色
                else
                    root = leftRightRotate(root);
            }
        }
    }   

//case    2: R
    if (root->right != NULL)//如果右边有孩子
    {
        if (isRed(root->right))//右边孩子为红色
        {
//case 2.1: RR 
            if (isRed(root->right->right))//最右边的孙子为红色
            {
                //RR, 左侧的叔叔是红色
                if (isRed(root->left))//插入节点在祖父的左边的左边, 叔叔是红色
                {
                    root->color = RED;
                    root->left->color = BLACK;
                    root->right->color = BLACK;
                }
                //RR, 左侧的叔叔是黑色
                else
                    root = leftRotate(root);
            }
//case 2.2: RL
            else if (isRed(root->right->left))//插入节点在祖父的左边的右边
            {
                //RL, 左侧的叔叔是红色
                if (isRed(root->left))//左边的
                {
                    root->color = RED;
                    root->left->color = BLACK;
                    root->right->color = BLACK;
                }
                //RL, 左侧的叔叔为黑色
                else
                    root = rightLeftRotate(root);
            }
        }
    }
    return root;
}

Node *insertHelper(Node *root, int n)
{
    if (!root)
        root = newNode(n);
    else
    {
        if (n < root->key)
            root->left = insertHelper(root->left, n);
        else
            root->right = insertHelper(root->right, n);
    }
    return insertFixup(root);
}

Node *insert(Node *root, int n)
{
    root = insertHelper(root, n);
    root->color = BLACK;
    return root;
}

void traverse(Node *root)
{
    if (root)
    {
        traverse(root->left);
        cout << root->key << " ";
        traverse(root->right);
    }
}

void output_tree(Node *root)
{
    cout << "inorder: [";
    traverse(root);
    cout << "]\n";
}


void detail_list(Node *root)
{
    if (root)
    {
        desc_node(root);
        detail_list(root->left);
        detail_list(root->right);
    }
}

void levelOrderTraverse(Node *root)
{
    queue<pair<Node *, int> > nodeps;
    nodeps.push(make_pair(root, 0));
    int preLeveal = 0;
    cout << "levelOrderTraverse" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    while (!nodeps.empty())
    {
        pair<Node *, int> temp = nodeps.front();
        nodeps.pop();
        if (temp.second > preLeveal)
            cout << endl;
        if (temp.first)
        {
            preLeveal = temp.second;
            cout << "(" << temp.first->key << ", " << (temp.first->color ? "r" : "b") << ")  ";
            if (temp.first->left)
                nodeps.push(make_pair(temp.first->left, preLeveal + 1));
            if (temp.first->right)
                nodeps.push(make_pair(temp.first->right, preLeveal + 1));
        }   
    } 
    cout << "\n-----------------------------------------------------------------------------" << endl;
}

Node *search(Node *root, int n)
{
    if (!root)
        return NULL;
    else if (n > root->key)
        return search(root->right, n);
    else if (n < root->key)
        return search(root->left, n);
    else
        return root;
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

Node *deleteNode(Node *root, int n)
{
    if (search(root, n))
    {
        if (n > root->key)
            root->right = deleteNode(root->right, n);
        else if (n < root->key)
            root->left = deleteNode(root->left, n);
        else
        {
            if (root->left && root->right)
            {
                cout << "deleteNode " << root->key << endl;
                root->key = findMin(root->right)->key;
                root->right = deleteNode(root->right, root->key);
            }
            else
            {
                Node *temp = root;
                if (!root->left)
                    root = root->right;
                else if (!root->right)
                    root = root->left;
                delete(temp);
            }
        }
    }
    return root;
}

int main(int argc, char const *argv[])
{
    Node *root = NULL;
    const int len = 8;
    int a[] = {10, 85, 15, 70, 20, 60, 30, 50};
    int b[] = {85, 50, 15, 20, 70, 30, 60, 10};
    int c[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int d[] = {8, 7, 6, 5, 4, 3, 2, 1};
    set<int> tset;
    srand(time(NULL));
    cout << "\ninsert_____________" << endl;
    for (int i = 0; i < len; i++)
    {
    //    int t = rand() % 200;
     //   if (!tset.count(t))
            root = insert(root, a[i]);

    //    tset.insert(t);
    }

    cout << "------------------------------------------" << endl;
    detail_list(root);
    cout << "\n------------------------------------------" << endl;

    cout << "\noutput_____________" << endl;
    levelOrderTraverse(root);

    cout << findMin(root)->key << endl;
    cout << findMax(root)->key << endl;
    return 0;
}
