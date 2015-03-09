#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
 *描述每个字符的结构体
 *同时在优先级队列和霍夫曼树使用
 */
struct CHAR
{
	char ch;//字符本身
	int rate;//出现概率
	string huffman_code;//霍夫曼编码
	CHAR *left;//指向坐节点的指针
	CHAR *right;//指向右节点的指针
};

/*
 *代码中使用的优先级队列为最小优先级，
 *队列的实现则使用的含有头结点的有序链表
 */
struct QUEUE_NODE//优先级队列的每个单元
{
	CHAR char_info;//一个含有字符信息的结构体
	QUEUE_NODE *next;//指向下一个节点的指针
};

void insert(QUEUE_NODE *head, CHAR *charactor);//向队列中插入节点
CHAR* minmum(QUEUE_NODE *head);//获取队列中的权值最小节点的指针
CHAR* extract_minmum(QUEUE_NODE **head);//删除队列中的权值最小单元，并返回其指针
void display_chars_in_queue(QUEUE_NODE *head);//输出队列元素，只用于辅助测试
CHAR* build_huffman_tree(QUEUE_NODE **head);//构建霍夫曼树
void traverse_huffman_tree(CHAR *root);//遍历霍夫曼树
void display_huffman_code(CHAR *root, char ch);//屏幕输出指定字符的霍夫曼编码
void construct_huffman_code(CHAR *root, int direction);//构建每个字符的霍夫曼编码

int main(int argc, char const *argv[])
{
	//////头结点初始化_start////////
	CHAR init_ch;
	init_ch.rate = -1;
	init_ch.ch = '0';
	init_ch.huffman_code = "";
	init_ch.left = NULL;
	init_ch.right = NULL;

	QUEUE_NODE *queue_head = new QUEUE_NODE();
	queue_head->next = NULL;
	queue_head->char_info = init_ch;
	//////头结点初始化_end////////

	//结构体数组，设定将要编码的字符集,其中left,right指针自动赋值为NULL,huffman_code自动赋值为空串
	CHAR chars[6] = {{'a', 45}, {'b', 13}, {'c', 12}, {'d', 16}, {'e', 9}, {'f', 5}};

	//依次插入每个字符构建最小优先级队列
	for (int i = 0; i < 6; i++)
		insert(queue_head, &chars[i]);

	//得到构建的霍夫曼编码树的跟节点指针
	CHAR *root = build_huffman_tree(&queue_head);

	//遍历霍夫曼编码树
	traverse_huffman_tree(root);

	//输出每个字符的霍夫曼编码
	for (int i = 0; i < 6; i++)
	{
		cout << chars[i].ch << "'s ";
		display_huffman_code(root, chars[i].ch);
	}
	return 0;
}


void insert(QUEUE_NODE *head, CHAR *charactor)
{
	/*
	 *图简单，此处的队列使用的数据结构是有序的单链表，
	 *即删除插入任何操作后，链表始终是一个有升序的
	 */

	 //构造新节点
	QUEUE_NODE *new_queue_node = new QUEUE_NODE();
	new_queue_node->char_info = *charactor;
	new_queue_node->next = NULL;

	if (head->next == NULL)//头结点为空的情况
		head->next = new_queue_node;
	else
	{
		QUEUE_NODE *cur = head;
		//保持有序的核心语句，找到应该插入的位置
		while (cur->next && cur->next->char_info.rate < charactor->rate)
			cur = cur->next;
		//插入节点
		new_queue_node->next = cur->next;
		cur->next = new_queue_node;
	}
}

CHAR* minmum(QUEUE_NODE *head)
{
	//排除头结点，返回第一个元素的指针
	return &(head->next->char_info);
}

CHAR* extract_minmum(QUEUE_NODE **head)
{
	/*使用指向指针的指针是因为直接修改了指针指向的地址*/
	//调用minmum(),然后头结点后移一个位置以清除最小元素
	CHAR* temp = minmum(*head);
	*head = (*head)->next;
	return temp;
}

void display_chars_in_queue(QUEUE_NODE *head)
{
	//简单的遍历链表
	head = head->next;
	while (head)
	{
		cout << "[" << head->char_info.ch << "," << head->char_info.rate << "] ";
		head = head->next; 
	}
	cout << endl;
}

CHAR *build_huffman_tree(QUEUE_NODE **head)
{
	/*使用指向指针的指针是因为在构造过程中要修改修改了指针指向的地址*/
	QUEUE_NODE *current = (*head)->next;
	if (current->next == NULL)//判断给定的队列是否为空
		return NULL;

	while ( (*head)->next->next != NULL )//如果队列中的元素大于一个元素
	{
		/*获取最小的两个元素，同时删除*/
		CHAR *left = extract_minmum(head);
		CHAR *right = extract_minmum(head);
		
		CHAR *new_node = new CHAR();//开辟新节点
		new_node->ch = '#';//作为跟节点没有字符内容，将其设为#方便查看
		new_node->rate = left->rate + right->rate;//新跟节点的权值等于前两个节点权值之和
		new_node->left = left;//设置跟节点的左指针指向最小的节点
		construct_huffman_code(new_node->left, 0);//调用函数刷新左子树每个字符的霍夫曼编码内容，左边的编码内容加0
		new_node->right = right;//设置跟节点的右指针指向次小的节点
		construct_huffman_code(new_node->right, 1);//调用函数刷新右子树每个字符的霍夫曼编码内容，右边的编码内容加0

		//插入新的跟节点到队列中
		insert(*head, new_node);
	//	display_chars_in_queue(*head);
	}
	return &(*head)->next->char_info;//返回霍夫曼编码树的根节点，其实就是队列中第一个元素的指针
}

void display_huffman_code(CHAR *root, char ch)
{
	/*递归遍历霍夫曼树，如果找到目标字符，则输出其编码*/
	if (root)
	{
		if (root->ch == ch)
			cout << "huffman code: " << root->huffman_code << endl;
		display_huffman_code(root->left, ch);
		display_huffman_code(root->right, ch);
	}
}	

void traverse_huffman_tree(CHAR *root)
{
	/*递归遍历霍夫曼树*/
	if (root != NULL)
	{	
	//	if (root->ch != '#')//去掉这行注释就只输出每个字符的内容，不会输出根节点的内容
			cout << "[ char: "  << root->ch << "; rate: " << root->rate << "; code: " << root->huffman_code << "]" << endl;
		traverse_huffman_tree(root->left);
		traverse_huffman_tree(root->right);
	}
}

void construct_huffman_code(CHAR *root, int direction)
{
	/*递归遍历霍夫曼树*/
	if (root != NULL)
	{
		if (direction == 0)//如果传递过来的是左子树，那么应该在之前的编码前新加上一个0
			root->huffman_code = "0" + root->huffman_code;
		if (direction == 1)//如果传递过来的是右子树，那么应该在之前的编码前新加上一个1
			root->huffman_code = "1" + root->huffman_code;
		//实现递归
		construct_huffman_code(root->left, direction);
		construct_huffman_code(root->right, direction);
	}
}