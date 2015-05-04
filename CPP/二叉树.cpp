/*插入函数使用指向指针的指针的原因是在插入函数中需要修改二叉树的结构
比如赋值和添加新的节点，而在查找和遍历函数中不用使用指针的指针是因为
在这两个函数中只需要访问，并不对其内部结构和节点中的值进行修改。举个
相似的例子就是
#include <stdio.h>
#include <math.h>

void A(int);
void B(int *);

int main()
{
    int a = 10;
    A(a);
    printf("after A, a = %d \n\n", a);
    B(&a);
    printf("after B, a = %d \n\n", a);
}

void A(int a)
{
    printf("value of %d in A\n", a);
    a += 10;
}

void B(int *a)
{
    printf("value of %d in B\n", *a);
    *a += 10;
}
*/

#include <iostream>
using namespace std;

struct NODE
{
	int data;
	NODE *left;
	NODE *right;
};

bool insert_node(NODE **root, int data);
NODE* delete_node(NODE *root, int data);
NODE* search_node(NODE *root, int data);
void pre_order_traverse(NODE *root);
void post_order_traverse(NODE *root);
void in_order_traverse(NODE *root);
NODE* find_max(NODE *root);
NODE* find_min(NODE *root);

int main(int argc, char const *argv[])
{
	NODE *root = NULL;
	const int N = 9;
	int list[N] = {5,3,4,8,2,1,6,9,10};//9
	for (int i = 0; i < N; i++)
	{
		cout << list[i] << " ";
		insert_node(&root, list[i]);
	}
	cout << endl;

	cout << "pre_order_traverse: ";
	pre_order_traverse(root);
	cout << "\nin_order_traverse: ";
	in_order_traverse(root);
	cout << "\npost_order_traverse: ";
	post_order_traverse(root);
	cout << endl;

	int n = 8;
	NODE *obj = search_node(root, n);
	if (!obj)
		cout << "find nothing in the binary search tree" << endl;
	else
		cout << "find " << n << " in this binary tree" << endl;

	cout << "min = " << find_min(root)->data << endl;
	cout << "max = " << find_max(root)->data << endl;


	int del = 9;
	delete_node(root, del);
	cout << "delete " << del << endl;
	cout << "in_order_traverse: ";
	in_order_traverse(root);
	cout << endl;

	return 0;
}

bool insert_node(NODE **root, int data)
{
	NODE *new_node = new NODE();
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;

	if (*root == NULL)
		*root = new_node;
	else 
	{
		if (data >= (*root)->data)
			insert_node(&(*root)->right, data);
		else
			insert_node(&(*root)->left, data);
	}
}

//删除的方法是找到右子树的最小值，然后覆盖目标节点的数据，然后删除最小值的节点
NODE* delete_node(NODE *root, int data)
{
	if (root == NULL)//如果为空或者不存在目标元素
		return NULL;
	else//存在元素
	{
		if (data > root->data)//目标元素大，在右边去删
			root->right = delete_node(root->right, data);
		else if (data < root->data) //目标元素小，在左边去删
			root->left = delete_node(root->left, data);
		else//正好找到目标元素
		{
			if (root->left && root->right)//有两个子树
			{
				NODE *temp_node = find_min(root->right);//找到右子树的最小值
				root->data = temp_node->data;//覆盖目标节点的值
				root->right = delete_node(root->right, root->data);//删除最小值节点
			}
			else//如果有一个或者0个子树
			{
				NODE *temp = root;
				if (root->left == NULL)
					root = root->right;//指向下一级指针，跳过删除的元素
				else if (root->right == NULL)
					root = root->left;
				free(temp);
			}
		}
	}
	return root;
}

NODE* search_node(NODE *root, int data)
{
	if (root == NULL)
		return NULL;
	else 
	{
		if (data > root->data)
			search_node(root->right, data);
		else if (data < root->data)
			search_node(root->left, data);
		else 
			return root;
	}
}

void pre_order_traverse(NODE *root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		in_order_traverse(root->left);
		in_order_traverse(root->right);
	}
}

void post_order_traverse(NODE *root)
{
	if (root != NULL)
	{
		in_order_traverse(root->left);
		in_order_traverse(root->right);
		cout << root->data << " ";
	}
}

void in_order_traverse(NODE *root)
{
	if (root != NULL)
	{
		in_order_traverse(root->left);
		cout << root->data << " ";
		in_order_traverse(root->right);
	}
}

NODE* find_max(NODE *root)
{
	if (root == NULL)
		return NULL;
	else
	{
		if (root->right == NULL)
			return root;
		else
			find_max(root->right);
	}
}

NODE* find_min(NODE *root)
{
	if (root == NULL)
		return NULL;
	else
	{
		if (root->left == NULL)
			return root;
		else
			find_min(root->left);
	}
}
