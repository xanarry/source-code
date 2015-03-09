#include <iostream>
using namespace std;

struct Node
{
	int elem;
	Node *next;
};

void Insert(Node *, int);
void TraverseList(Node *);
void show();

int main(int argc, char const *argv[])
{
	Node *head = new Node;//定义头结点
	head->next = NULL;	

	int n;
	for (int i = 0; i < 10; ++i)//输入10个数用于测试
	{
		cin >> n;
		Insert(head, n);//调用插入函数
	}

	TraverseList(head);//遍历链表
	cout << "\npress any key to see detail" << endl;
	getchar();
	getchar();
	show();
	return 0;
}

void Insert(Node *h, int n)//用头结点和数据作为参数
{
	Node *pre = h;//定义pre表示当前节点的上一个节点
	Node *cur = h->next;//定义cur表示当前，只指向NULL或者head节点后的一串链表

	Node *_new = new Node;//创建新节点
	_new->elem = n;//写入数据

	while (cur && cur->elem > n)//如果表示的当前位置不为空，且它说表示的元素比要插入的数字大，
	{
		pre = cur;//找到一个应该插入的点，记录位置
		cur = cur->next;
	}

	_new->next = cur;//插入节点
	pre->next = _new;
}

void TraverseList(Node *h)
{
	Node *p = h->next;	
	while (p)
	{
		cout << p->elem << " ";
		p = p->next;
	}
}
///一个简单的图解，无聊花很多时间写出来的////////////////////
void show()
{
	printf("-----------------------------------------------------------------------------------------\n");
	printf("\n假定输入的数依次是 5 3 7 1  						                                \n");
	printf("       head node                                                                    \n");
	printf("        +-------+                                                                   \n");
	printf("       	|       |  传递head到insert函数，insert函数中创建pre指向head                \n");
	printf("head--->| unkown|  创建cur指向head->next, 如下--+                                   \n");
	printf("       	|-------|                               |                                   \n");
	printf("       	| NULL  |                               |                                   \n");
	printf("       	|_______|                               |                                   \n");
	printf("                                                |                                   \n");
	printf("                            +-------+           |	                                \n");
	printf("                pre-------->|       |           |                                   \n");
	printf("                    head--->| unkown|           |	                                \n");
	printf("                            |-------| <---------+                                   \n");
	printf("                            | NULL  |                                               \n");
	printf("                cur-------->|_______|                                               \n");               					
	printf("  													                                \n");
	printf("													                                \n");
	printf("													                                \n");
	printf("              节点1(不执行while循环,应为cur = h->next == NULL)                      \n");
	printf("        +-------+                         +-------+                                 \n");		
	printf("        |       |           +-----------> |       |                                 \n");
	printf("head--->| head  |           |             |  5    |                                 \n");
	printf("        |-------|           |             |-------|                                 \n");
	printf("        |    ---|-----------+             |   ----|------> NULL                     \n");
	printf("        |_______|                         |_______|                                 \n");
	printf("                                                                                    \n");
	printf("                                                                                    \n");
	printf("                                                                                    \n");
	printf("节点2(执行1次while循环)，pre和cur的位置为                                           \n");
	printf("     +-------+          +-------+               +-------+                           \n");
	printf("     |       |	head--> |       |    +-------->	|       |                           \n");
	printf("     |   3   |          | unkown|    |  +----->	|  5    |                           \n");
	printf("     |-------|          |-------|    |  |       |-------|                           \n");
	printf("     |       |          |   ----|----+  | +--->	|   ----|----->NULL                 \n");
	printf("     |_______|          |_______|       | |     |_______|                           \n");
	printf("                                  pre---+ |                                         \n");
	printf("                                  cur-----+                                         \n");
	printf("																                    \n");
	printf("																                    \n");
	printf("                +-------+           +-------+         +-------+	                    \n");
	printf("      head----> |       |    +----->|       |    +--->|  3    |        	            \n");
	printf("                | unkown|    |      |  5    |	 |    |       |	                    \n");
	printf("                |-------|    |      |-------|    |    |-------|	                    \n");
	printf("                |   ----|----+      |   ----|----+    |   ----|---->NULL            \n");
	printf("                |_______|           |_______|         |_______|		                \n");
	printf("					  												                \n");
	printf("					    									                        \n");
	printf("			 												                        \n");
	printf("	节点3(执行0次while循环,因为7比目前最大的数大)，pre和cur的位置为                 \n");
	printf("    +-------+              +-------+               +-------+                        \n");
	printf("    |       |   head-----> |       |    +--------> |       |                        \n");
	printf("    |    7  |        +---> |unkown |    |          |  5    |                        \n");
	printf("    |-------|        |	   |-------|    |          |-------|                        \n");
	printf("    |       |        | +-->|   ----|----+          |   ----|------->NULL            \n");
	printf("    |_______|        | |   |_______|	           |_______|                        \n");
	printf("                     | |                                                            \n");
	printf("               pre---+ |                                                            \n");
	printf("               cur-----+                                                            \n");
	printf("						                                                            \n");
	printf("																	                \n");
	printf("          +-------+       +-------+       +-------+       +-------+	                \n");
	printf("head----> |       |  +--> |   7   |  +--> |   5   |  +--> |   3   |	                \n");
	printf("          |unkown |  |    |       |  |    |       |  |	  |       |	                \n");
	printf("          |-------|  |    |-------|  |    |-------|  |	  |-------|	                \n");
	printf("          |   ----|--+    |   ----|--+    |   ----|--+    |   ----|---->NULL        \n");
	printf("          |_______|       |_______|       |_______|       |_______|		            \n");
	printf("																		            \n");
	printf("																		            \n");
	printf("																		            \n");
	printf("																		            \n");		
	printf(" 节点4(执行1次while循环)，pre和cur的位置为								            \n");
	printf("+-------+       +-------+      +-------+      +-------+       +-------+	            \n"); 
	printf("|       | head->|       |  +-->|  7    |  +-->|   5   |  +--> |   3   |	            \n");
	printf("|   3   |       | unkown|  |   |       |  |   |       |  |+-> |       |	            \n");
	printf("|-------|       |-------|  |   |-------|  |   |-------|  ||   |-------|		        \n");
	printf("|       |       |   ----|--+   |   ----|--+   |   ----|--+|+->|   ----|-->NULL      \n");
	printf("|_______|       |_______|      |_______|      |_______|   ||  |_______|             \n");
	printf("                                                    pre---+|		                \n");
	printf("                                                    cur----+		                \n");
	printf("																	                \n");
	printf("                                                                                    \n");
	printf("                                                                                    \n");
	printf("           +-------+	  +-------+      +-------+      +-------+      +-------+	    \n");
	printf("    head-->|       |  +-->|  7    |  +-->|   5   |  +-->|   3   |  +-->|   1   |	    \n");
	printf("           | unkown|  |   |       |  |   |       |  |   |       |  |   |       |	    \n");
	printf("           |-------|  |   |-------|  |   |-------|  |   |-------|  |   |-------|	    \n");
	printf("           |   ----|--+   |   ----|--+   |   ----|--+   |   ----|--+   |   ----|-->NULL \n");
	printf("           |_______|      |_______|      |_______|      |_______|      |_______|	    \n");
	printf("								  						                       	    \n");
	printf("-------------------------------------------------------------------------------------\n");
}
