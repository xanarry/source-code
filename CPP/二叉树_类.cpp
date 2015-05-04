#include <iostream>
using namespace std;

typedef int dataType;
struct Node
{
    dataType data;//data
    Node *left;//left sub-tree pointer
    Node *right;//right
};

class BinaryTree
{
private:
    Node *root;
    int height;
    int leaves;

    //all private method are for public method
    Node *new_node(dataType n);//get new node
    void recursive_insert(Node **root, dataType n);//recurisve insert
    void output(Node *root, int order);//recursive output tree,order: 1 preorder, 2 inorder, 3 postorder
    Node *find_max_recursive(Node *root);//find max element
    Node *find_min_recursive(Node *root);//find min element
    Node *recursive_find(Node *root, dataType n);//recursive find whitch will be called by find()
    Node *recursive_delete(Node **root, dataType n);//recursive delete
    void clear_tree(Node *root);
    void depth_first_search(Node *root, int n);//dept first search, to get height and leaves

public:
    BinaryTree();
    void insert(dataType n);//insert
    void pre_order_recursive();//preorder traverse
    void in_order_recurive();//inorder traverse
    void post_order_recursive();//post order travers
    Node *delete_node(dataType n);//delete node
    int get_height();//get height
    Node *find_max();
    Node *find_min();
    bool find(dataType n);
    int get_leaves_count();
    ~BinaryTree();
};

BinaryTree::BinaryTree()//constructor, initialize root, height and leaves
{
    root = NULL;
    height = 0;
    leaves = 0;
}

BinaryTree::~BinaryTree()
{
    clear_tree(root);//free space
}

void BinaryTree::insert(dataType n)
{
    recursive_insert(&root, n);//call recusive function to do the task
}

void BinaryTree::pre_order_recursive()
{
    output(root, 1);
}

void BinaryTree::in_order_recurive()
{
    output(root, 2);
}

void BinaryTree::post_order_recursive()
{
    output(root, 3);
}

Node *BinaryTree::find_min()
{
    if (root)
        return find_min_recursive(root);
    else
        return NULL;
}

Node *BinaryTree::find_max()
{
    if (root)
        return find_max_recursive(root);
    else
        return NULL;
}

Node *BinaryTree::delete_node(dataType n)
{
    root = recursive_delete(&root, n);
}

bool BinaryTree::find(dataType n)
{
    return recursive_find(root, n) != NULL;
}

int BinaryTree::get_leaves_count()
{
    leaves = 0;//reinitialize leaves, in case of increase by 1 from other number
    get_height();//call get_height(), but actually we wanna call dfs to recount the leaves count
    return leaves;
}

Node *BinaryTree::recursive_find(Node *root, dataType n)//查找元素
{
    if (root == NULL)
        return NULL;//if the tree is empty, return the pointer of NULL
    else
    {
        if (n > root->data)//dest greater than current element then go right sub_tree
            recursive_find(root->right, n);
        else if (n < root->data)
            recursive_find(root->left, n);//contrary
        else//find the right element
            return root; //return it's pointer
    }
}

Node *BinaryTree::new_node(dataType n)
{
    Node *new_v = new Node();//get a new node from system
    new_v->data = n;//assignment valve
    new_v->right = NULL;//init right NULL
    new_v->left = NULL;//init left NULL
    return new_v;
}

void BinaryTree::recursive_insert(Node **root, dataType n)
{
    if (!*root)//find right place, insert it
        *root = new_node(n);
    else
    {   
        if (n >= (*root)->data)//new element greater or equal than current to right
            recursive_insert(&(*root)->right, n);
        else//on the other hand go left
            recursive_insert(&(*root)->left, n);
    }
}

void BinaryTree::output(Node *root, int order)
{
    if (root)
    {
        if (order == 1)//preorder 
        {
            cout << root->data << " ";
            output(root->left, order);
            output(root->right, order);
        }
        if (order == 2)//inorder
        {
            output(root->left, order);
            cout << root->data << " ";
            output(root->right, order);
        }
        if (order == 3)//postorder
        {
            output(root->left, order);
            output(root->right, order);
            cout << root->data << " ";
        } 
    }
}

Node *BinaryTree::find_min_recursive(Node *root)
{
    if (!root)
        return NULL;
    else
    {
        if (!root->left)
            return root;
        else
            find_min_recursive(root->left);
    }
}

Node *BinaryTree::find_max_recursive(Node *root)
{
    if (!root)
        return NULL;
    else
    {
        if (!root->right)
            return root;
        else
            find_max_recursive(root->right);
    }
}


Node *BinaryTree::recursive_delete(Node **root, dataType n)//recursive delete
{
    /*
     *deletion is replace the data of destination node with the smallest data of the right sub_tree
     *the delete the smallest node from the tree
     */
    if (!*root)
        return NULL;
    else
    {
        //find destination element
        if (n > (*root)->data)
            (*root)->right = recursive_delete(&(*root)->right, n);
        else if (n < (*root)->data)
            (*root)->left = recursive_delete(&(*root)->left, n);
        else//meet destination element
        {
            if ((*root)->left && (*root)->right)//has both left and right sub_tree
            {
                Node *temp = find_min_recursive((*root)->right);
                (*root)->data = temp->data;
                (*root)->right = recursive_delete(&(*root)->right, (*root)->data);
            }
            else//only left or right sub_tree
            {
                Node *temp = (*root);
                if (!(*root)->left)
                    (*root) = (*root)->right;
                else if (!(*root)->right)
                    (*root) = (*root)->left;
                delete(temp);//free space
            }
        }
    }
    return *root;
}

void BinaryTree::clear_tree(Node *root)
{
    if (root)
    {
        Node *temp = root;
        clear_tree(root->left);
        clear_tree(root->right);
        delete(root);
    }
}

int BinaryTree::get_height()
{
    if (!root)
        return 0;
    else
        depth_first_search(root, 0);
    return height;
}

void BinaryTree::depth_first_search(Node *root, int n)
{
    if (n > height)
        height = n;//each breach has different height on the tree, here find the max height
    if (root)
    {
        leaves++;//count the number of all leaves on the tree
        depth_first_search(root->left, n + 1);
        depth_first_search(root->right, n + 1);
    }
}

int main(int argc, char const *argv[])
{
    BinaryTree bt;
    int a[] = {5,3,4,2,8,6,9};
    for (int i = 0; i < 7; i++)
        bt.insert(a[i]);

    bt.pre_order_recursive();
    cout << endl;
    bt.in_order_recurive();
    cout << endl;
    bt.post_order_recursive();
    cout << endl;

    cout << "leaves: " << bt.get_leaves_count();
    Node *t = bt.find_max();
    if (t)
    cout << "max = " << t->data << endl;
    t = bt.find_min();
    if (t)
    cout << "min = " << t->data << endl;
    
    int height = bt.get_height();
    cout << "height = " << height << endl;

    cout << bt.find(9) << endl;

    bt.delete_node(9);
    bt.post_order_recursive();
    cout << endl;
    cout << "leaves: " << bt.get_leaves_count() << endl;
    return 0;
}