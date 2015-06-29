//avl树中的元素一定是唯一的
#include <iostream>
using namespace std;

struct Node
{
    int data;//数据
    Node *left;//左指针
    Node *right;//右指针
    int height;//当前点的树高
};

int height(Node *root)
{
    if (!root)//null分支返回-1
        return -1;
    else
        return root->height;
}

void show_node(Node *root);
Node *single_rotate_with_left(Node *root)//单左旋转
{
    //旋转
    Node *sub_left = root->left;
    root->left = sub_left->right;
    sub_left->right = root;
    //重新计算旋转后的树高, 下面两行代码顺序不能变
    //先计算原来树根的高度, 因为旋转后已经到树的底部
    root->height = max(height(root->left), height(root->right)) + 1;
    //再计算新的根结点的高度
    sub_left->height = max(height(sub_left->left), height(sub_left->right)) + 1;
    return sub_left;
}

Node *single_rotate_with_right(Node *root)//单右旋转
{
    Node *sub_right = root->right;
    root->right = sub_right->left;
    sub_right->left = root;
    root->height = max(height(root->left), height(root->right)) + 1;
    sub_right->height = max(height(sub_right->left), height(sub_right->right)) + 1;
    return sub_right;
}

Node *double_rotate_with_leftRight(Node *root)//双旋转, 先左后右
{
    root->right = single_rotate_with_left(root->right);//左旋
    return single_rotate_with_right(root);//右旋
}

Node *double_rotate_with_rightLeft(Node *root)//双旋转, 先右后左
{
    root->left = single_rotate_with_right(root->left);//右旋
    return single_rotate_with_left(root);//左旋
}

void traverse(Node *root)//中序遍历
{
    if (root)
    {
        traverse(root->left);
        cout << root->data << " ";
        traverse(root->right);
    }
}

Node *find_max(Node *root)
{
    //返回最大值
    return root->right ? find_max(root->right) : root;
}

Node *find_min(Node *root)
{
    //返回最小值
    return root->left ? find_min(root->left) : root;
}  

Node *search(Node *root, int n)
{
    //搜索节点
    if (root)
    {
        if (n > root->data)
            return search(root->right, n);
        else if (n < root->data)
            return search(root->left, n);
        else
            return root;
    }
}

Node *delete_node(Node *root, int n)
{
    //删除树节点, 删除部分和普通二叉树一样, 删除完成后重新调整树高维持平衡态
    if (!root || !search(root, n))
        return root;
    if (n > root->data)
        root->right = delete_node(root->right, n);
    else if (n < root->data)
        root->left = delete_node(root->left, n);
    else
    {
        if (root->left && root->right)
        {
            Node *temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
        else
        {
            Node *temp = root;
            if (root->left == NULL)
                root = root->right;
            else if (root->right == NULL)
                root = root->left;
            delete(temp);
        }
    }
    //重新旋转调整树高
    if (root)
    {
        //重新计算删除节点后的树根的高度
        root->height = max(height(root->left), height(root->right)) + 1;
        //检查树根两端是否平衡
        if (height(root->left) - height(root->right) == 2)//左边深, 右边浅
        {
            //////LL类型
            if (height(root->left->left) - height(root->left->right) >= 0)    
                root = single_rotate_with_left(root);
            else//LR型
                root = double_rotate_with_rightLeft(root);
        }
        if (height(root->right) - height(root->left) == 2)//右边深, 左边浅      
        {
            //////RR型
            if (height(root->right->right) - height(root->right->left) >= 0)
                root = single_rotate_with_right(root);
            else//RL型
                root = double_rotate_with_leftRight(root);
        }
    }
    return root;
}

Node *insert(Node *root, int n)//删除AVL树中的节点
{
    //如果树中已经存在节点, 则不插入
    if (search(root, n) != NULL)
        return root;
    if (!root)
    {
        //遇到空节点直接插入
        Node *new_node = new Node();
        new_node->data = n;
        new_node->height = 0;
        new_node->left = NULL;
        new_node->right = NULL;
        root = new_node;
    }
    else//方法与二叉树一样
    {
        if (n < root->data)
        {
            root->left = insert(root->left, n);
            //旋转并调整高度
            if (height(root->left) - height(root->right) == 2)
            {
                if (n < root->left->data)//偏左直链式结构, LL型
                    root = single_rotate_with_left(root);
                else//先偏左,后偏右, LR型
                    root = double_rotate_with_rightLeft(root);
            }
        }
        else
        {
            root->right = insert(root->right, n);
            //旋转并调整高度
            if (height(root->right) - height(root->left) == 2)
            {
                if (n > root->right->data)//偏右单直链式结构, 单旋转, RR型
                    root = single_rotate_with_right(root);
                else//先偏右, 后偏左, RL型
                    root = double_rotate_with_leftRight(root);
            }
        }
    }
    //设置树高
    root->height = max(height(root->left), height(root->right)) + 1;
    return root;
}

void show_node(Node *root)//输出树根和左右节点, 用于验证树结构
{
    if (!root)
        cout << "null" << endl;
    else
    {
        cout << "root: " << root->data;
        cout << " left: ";
        if (root->left)
            cout << root->left->data;
        else
            cout << "null";
        cout << " & right: ";
        if (root->right)
            cout << root->right->data;
        else
            cout << "null";
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    Node *root = NULL;
    int a[] = {3,2,1,4,5,6,7,16,15,14,13,11,10,12,8,9};
    //int a[] = {50,80,30,90,10,20,60,70};
    int len = 16;
    for (int i = 0; i < len; i++)
        root = insert(root, a[i]);

    traverse(root);
    cout << endl;
/*    show_node(root);
    show_node(root->left);
    show_node(root->right);

    root = delete_node(root, 90);
    traverse(root);
    cout << endl;
    show_node(root);
    show_node(root->right);
    cout << find_max(root)->data << endl;
*/
    for (int i = 0; i < len; i++)
    {
        show_node(root);
        cout << "after delete: " << a[i] << " :[";
        root = delete_node(root, a[i]);
        traverse(root);
        cout << "]" << endl << endl;
    }
    return 0;
}