#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct NODE//链表结构
{
	string value;//元素值
	NODE *next;//指向下一个节点的指针
};

struct HASH_TABLE//哈希表结构
{
	int table_size;//哈希表的大小
	NODE **the_lists;//针对每个哈希值的链表头结点指针的指针数组起点指针
};

int next_prime(int ele_count);//获取给定数的下一个质数
HASH_TABLE *inintialize_hash_table(int table_size);//初始化哈希表
int hash_code(string name, int table_size);//计算哈希值
void hash_insert(HASH_TABLE *hash_table, string key);//插入哈希表
NODE *hash_search(HASH_TABLE  *hash_table, string key);//哈希搜索
void display_hash_table(HASH_TABLE *hash_table);//显示哈希表的内容
void delete_hash(HASH_TABLE *hash_table, string key);//删除相关的哈希映射

int main(int argc, char const *argv[])
{
	const int N = 15;
	HASH_TABLE *hash_table = inintialize_hash_table(next_prime(N));

	const string names[N] = {"temp", "inintialize", "string", "struct", "size", "undershorts", "pants", "belt", "shirt", "tie", "jacket", "socks", "shoes", "watch", "Tshirt"};

	cout << "insert into hash_table" << endl;
	for (string t : names)
		hash_insert(hash_table, t);
	cout << "end_____________\n" << endl;

	cout << "search all string in hash_table" << endl;
	for (int i = 0; i < N; i++)
	{
		NODE *result = hash_search(hash_table, names[i]);
		cout << hash_code(names[i], hash_table->table_size) << ": " << result->value << endl;
	}

	cout << "\ndisplay_hash_table" << endl;
	display_hash_table(hash_table);

	cout << "\ndelete hash value from this hash table" << endl;
	delete_hash(hash_table, "string");

	cout << "\ndisplay_hash_table" << endl;
	display_hash_table(hash_table);

	return 0;
}

int next_prime(int ele_count)
{
	while (ele_count)
	{
		int i;
		bool flag = true;
		for (i = 2; i <= sqrt(ele_count); i++)
		{
			if (ele_count % i == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag)//直到找到一个质数
			return ele_count;
		ele_count++;
	}
}

HASH_TABLE *inintialize_hash_table(int table_size)
{
	HASH_TABLE *hash_table = new HASH_TABLE();
	hash_table->table_size = table_size;//设定哈希表大小
	hash_table->the_lists = new NODE*[table_size];//申请指针数组的内存

	//设置每个哈希值链表的头结点
	for (int i = 0; i < table_size; i++)
	{
		NODE *init_head = new NODE();
		init_head->value = "__HEAD__";
		init_head->next = NULL;
		hash_table->the_lists[i] = init_head;
	}
	return hash_table;//返回哈希表指针
}

int hash_code(string name, int table_size)
{
	unsigned int code = 0;
	for (int i = 0; i < name.length(); i++)
		code = (code << 1) + (int) name[i];//计算哈希值
	return code % table_size;
}


NODE *hash_search(HASH_TABLE *hash_table, string key)
{
	//计算哈希值
	int code = hash_code(key, hash_table->table_size);
	//找到相关哈希值的头结点
	NODE *head = hash_table->the_lists[code];
	//遍历链表
	while (head->next)
	{
		head = head->next;
		//找到目标关键字
		if (head->value == key)
			return head;
	}
	return NULL;
}

void hash_insert(HASH_TABLE *hash_table, string key)
{
	//计算哈希值
	int code = hash_code(key, hash_table->table_size);
	//申请新节点内存
	NODE *new_key = new NODE();
	new_key->value = key;

	//头插法插入到哈希值映射到的链表上
	new_key->next = hash_table->the_lists[code]->next;
	hash_table->the_lists[code]->next = new_key;
}

void delete_hash(HASH_TABLE *hash_table, string key)
{
	//计算哈希值
	int code = hash_code(key, hash_table->table_size);
	NODE *pre, *temp = hash_table->the_lists[code];

	//检查是否存在该哈希值
	if (temp->next == NULL)
	{
		cout << "no hash value finded in this hash table" << endl;
		return;
	}
	//找到目标哈希值的位置
	while (temp && temp->value != key)
	{
		pre = temp;
		temp = temp->next;
	}
	cout << pre->value << endl;
	cout << temp->value << endl;
	//直接连接到下一个节点
	pre->next = temp->next;
	//释放内存
	delete(temp);
}

void display_hash_table(HASH_TABLE *hash_table)
{
	cout << "size of this hash table: " << hash_table->table_size << endl;
	//遍历每个哈希值的链表
	for (int i = 0; i < hash_table->table_size; i++)
	{
		NODE *temp = hash_table->the_lists[i]->next;
	
		cout << i << ": ";
		if (temp == NULL)
			cout << "__NULL__";

		//遍历该哈希值对应的链表内容
		while (temp != NULL)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}