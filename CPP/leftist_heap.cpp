#include <iostream>
using namespace std;

struct HEAP_NODE//最小堆节点定义
{
	int data;//数据
	int npl;//到右节点的路径
	HEAP_NODE *left;//左孩子指针
	HEAP_NODE *right;//右孩子指针
};

void insert(HEAP_NODE **root, int n);//插入元素
HEAP_NODE *merge(HEAP_NODE *root1, HEAP_NODE *root2);//合并两个左倾堆
void swap_children(HEAP_NODE *root);//交换根节点的两个孩子
HEAP_NODE *minimum(HEAP_NODE *root);//返回最小值
int extract_min(HEAP_NODE **root);//删除最小值
void pre_order_traverse(HEAP_NODE *root);//先序遍历堆

int main(int argc, char const *argv[])
{
	const int A_LEN = 10;
	int a[A_LEN] = {21,14,23,10,12,7,18,24,8,37};
//	int a[A_LEN] = {24,8,37,33,17,18,26,6,3,1};

	HEAP_NODE *heap_root = NULL;

	int ele_count = 10;
	for (int i = 0; i < ele_count; i++)
	{
		insert(&heap_root, a[i]);
//		pre_order_traverse(heap_root);	
	}

	cout << "heap is: ";
	pre_order_traverse(heap_root);
	cout << endl;	

	cout << "min = " << minimum(heap_root)->data << endl;

	cout << "extract_min: " << extract_min(&heap_root) << endl;

	cout << "heap is: ";
	pre_order_traverse(heap_root);
	cout << endl;	

	cout << "min = " << minimum(heap_root)->data << endl;
	return 0;
}

void insert(HEAP_NODE **root, int n)
{
	/*
	 *插入节点即把新的节点当成只有一个节点的堆
	 *调用merge函数将原堆与新的节点合并即可实现合并
	 */

	//创建新节点
	HEAP_NODE *new_node = new HEAP_NODE();
	new_node->data = n;
	new_node->left = new_node->right = NULL;
	new_node->npl = 0;

	if (*root == NULL)//如果跟为空则设置新节点
		*root = new_node;
	else//否则将新节点与原堆合并
		*root = merge(*root, new_node);
}

HEAP_NODE *merge(HEAP_NODE *root1, HEAP_NODE *root2)
{
	/*
	 *合并方式
	 *左边始终为根值最小的堆
	 *如果根的左边为NULL的话，将右堆直接连接到根的左边
	 *否则将左堆的右子树与右堆合并，直到找到一个左边为空的节点
	 *如果合并后最左堆的性质被破坏后，交换其左右节点
	 *递归实现
	 */

	//如果其中一个堆为空，则返回非空对
	if (root1 == NULL)
		return root2;
	if (root2 == NULL)
		return root1;

	//交换，保证root1始终为最小值最小的堆
	if (root2->data < root1->data)
	{
		HEAP_NODE *temp = root1;
		root1 = root2;
		root2 = temp;
	}

	//如果根的左边为NULL的话，将右堆直接连接到根的左边
	if (root1->left == NULL)
		root1->left = root2;
	else//否则将左堆的右子树与右堆合并，直到找到一个左边为空的节点
	{
		root1->right = merge(root1->right, root2);//合并操作

		if (root1->left->npl < root1->right->npl)//检查最左堆的性质是否被破坏，如果破坏，那么交换其左右孩子
			swap_children(root1);

		root1->npl = root1->right->npl + 1;//更新npl值
	}
	return root1;
}

void swap_children(HEAP_NODE *root)
{
	HEAP_NODE *temp = root->left;
	root->left = root->right;
	root->right = temp;
}

HEAP_NODE *minimum(HEAP_NODE *root)
{
	return root;
}

int extract_min(HEAP_NODE **root)
{
	/*
	 *获取最小值
	 *设置根为原来跟的左右孩子合并后的新堆
	 */

	//获取最小值
	int min = (*root)->data;
	//获取左右孩子
	HEAP_NODE *left = (*root)->left;
	HEAP_NODE *right = (*root)->right;
	//释放最小节点的内存
	delete(*root);
	//合并新的堆
	*root = merge(left, right);
	return min;
}

void pre_order_traverse(HEAP_NODE *root)
{
	if (root)
	{
		cout << "[" << root->data << "," << root->npl << "] ";
		pre_order_traverse(root->left);
		pre_order_traverse(root->right);
	}
}