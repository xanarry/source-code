#include <stdio.h>
#include <stdlib.h>

typedef struct node NODE;

struct node
{
    int data;
    NODE *left;
    NODE *right;
};

NODE *seach_binary_tree(NODE *root, int key);
void insert_into_binary_tree(int key);
void recursive_insert(NODE *root, int key);
void inorder_traverse_binary_tree(NODE *root);
void preorder_traverse_binary_tree(NODE *root);
void postorder_traverse_binary_tree(NODE *root);

NODE *Root = NULL;

int main()
{
    int i;
    int data;
    for (i = 0; i < 7; i++)
    {
        printf("input %d data:", i + 1);
        scanf("%d", &data);
        insert_into_binary_tree(data);
    }

    printf("\ninorder traverse binary tree\n");
    inorder_traverse_binary_tree(Root);

    printf("\n\npreorder traverse binary tree\n");
    preorder_traverse_binary_tree(Root);

    printf("\n\npostorder traverse binary tree\n");
    postorder_traverse_binary_tree(Root);

    printf("\n\ninput a number to search:");
    int obj;
    scanf("%d", &obj);
    NODE *result = seach_binary_tree(Root, obj);

    if (result == NULL)
        printf("not find %d in this binary tree\n", obj);
    else
    {
        printf("find %d in this tree\n", result->data);

        if (result->left == NULL)
            printf("its left leaf is: NULL\n");
        else
            printf("its left leaf is: %d\n", result->left->data);

        if (result->right == NULL)
            printf("its right leaf is: NULL\n");
        else
            printf("its right leaf is: %d\n", result->right->data);
    }
}

//本函数可以直接访问Root节点，应为是直接访问，并不是使用传参数的形式
//它将处理根节点为空的情况
void insert_into_binary_tree(int key)
{
    if (Root == NULL)
    {
        Root = (NODE *) malloc(sizeof(NODE));
        if (Root == NULL)
        {
            printf("memery malloc error");
            exit(0);
        }

        Root->data = key;
        Root->left = NULL;
        Root->right = NULL;
    }
    else
        recursive_insert(Root, key);
}

//为什么在这个插入二叉树的函数可以不使用指针的指针
void recursive_insert(NODE *root, int key)
{
    if (key >= root->data)
    {
        if (root->right == NULL)
        {
            NODE *new_node = (NODE *) malloc(sizeof(NODE));
            new_node->data = key;
            new_node->left = NULL;
            new_node->right = NULL;

            root->right = new_node;
        }
        else
            recursive_insert(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            NODE *new_node = (NODE *) malloc(sizeof(NODE));
            new_node->data = key;
            new_node->left = NULL;
            new_node->right = NULL;

            root->left = new_node;
        }
        else
            recursive_insert(root->left, key);
    }
}

NODE *seach_binary_tree(NODE *root, int key)
{
    if (root != NULL)
    {
        if (key > root->data)
            return seach_binary_tree(root->right, key);
        else if (key < root->data)
            return seach_binary_tree(root->left, key);
        else
            return root;
    }
    else
        return NULL;
}

void inorder_traverse_binary_tree(NODE *root)
{
    if (root != NULL)
    {
        inorder_traverse_binary_tree(root->left);
        printf("%d ", root->data);
        inorder_traverse_binary_tree(root->right);
    }
}

void preorder_traverse_binary_tree(NODE *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder_traverse_binary_tree(root->left);
        preorder_traverse_binary_tree(root->right);
    }
}

void postorder_traverse_binary_tree(NODE *root)
{
    if (root != NULL)
    {
        postorder_traverse_binary_tree(root->left);
        postorder_traverse_binary_tree(root->right);
        printf("%d ", root->data);
    }
}
/*test data:
10
6
14
5
8
11
18
*/
