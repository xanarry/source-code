#include <queue>
#include <string>
#include <iostream>

#define UNPROBE -1//用于标记每个顶点默认的到起点的路径长度，默认-1表示尚未被探索到
#define NOPARENT NULL//用于标记路径中每个顶点的默认父顶点，默认为NULL

using namespace std;

struct LINKNODE;//声明LINKNODE结构体

//图中每个顶点的定义
struct VERTEX
{
	string name;//定点名
	int distance;//从出发点到该定点的距离，默认为-1
	VERTEX *parent;//在路径中该定点的上一个顶点指针
	int outdegree;//出度，手动输入
	int indegree;//入度，由输入时计算得出
	LINKNODE *adjacent_vertices;//邻接顶点的指针链表头结点，(邻接顶点由单独的指针链表储存其指针)
};

//邻接顶点链表的基本结构
struct LINKNODE
{
	VERTEX *pt_vertex;//指向其他顶点的指针
	LINKNODE *next;//指向下一个节点的指针
};

//图的结构表示
struct GRAPH
{
	int vertex_count;//顶点数目
	VERTEX *adjacent_list;//邻接表
};

GRAPH *inintialize();//初始化图，实现图的输入
void display_graph(GRAPH *graph);//以邻接表的形式输出该图
bool unweighted_shortest_path(string start, GRAPH *graph);//以给定的起点计算到没个顶点的最短路径
void display_shortest_path(string start, string end, GRAPH *graph);//给定起点终点，输出路径
void display_all_shortest_pathes(string start, GRAPH *graph);//给定起点，输出到所有顶点的最短路径
void recursive_print_path(VERTEX *distinct_vertex);//辅助函数，递归输出终点到起点路径的顶点名

int main(int argc, char const *argv[])
{
	GRAPH *graph = inintialize();
//	display_graph(graph);
//	unweighted_shortest_path("v3", graph);
//	display_graph(graph);
	cout << "input start vertex: ";

	string start;
	cin >> start;
//	string end = "v5";
//	display_shortest_path(start, end, graph);
	display_all_shortest_pathes(start, graph);
	return 0;
}

GRAPH *inintialize()
{
	/*
	 *初始化图，实现图的输入
	 *要求输入顶点数，每个顶点名，每个顶点的出度
	 *首先输入顶点数与每个顶点的名字，建立空的邻接表
	 *然后输入每个顶点指向的顶点，建立指针链表的邻接顶点列表，同时计算出每个定点的入度
	 */
	GRAPH *graph = new GRAPH();

	//输入顶点数
	cout << "input num of vertices: ";
	cin >> graph->vertex_count;

	//申请内存
	graph->adjacent_list = new VERTEX[graph->vertex_count];

	for (int i = 0; i < graph->vertex_count; i++)
	{
		//输入每个顶点的名字，设定默认参数
		cout << "input " << i + 1 << " vertex's name: ";
		cin >> graph->adjacent_list[i].name;
		cout << "input " << i + 1 << " vertex's outdegree: ";
		cin >> graph->adjacent_list[i].outdegree;
		graph->adjacent_list[i].indegree = 0;
		graph->adjacent_list[i].distance = UNPROBE;
		graph->adjacent_list[i].parent = NULL;

		//开辟新的链表头
		LINKNODE *head = new LINKNODE();
		head->pt_vertex = NULL;
		head->next = NULL;

		//将链表头放到该顶点的属性中
		graph->adjacent_list[i].adjacent_vertices = head;
	}

	//输入每个顶点的邻接顶点
	string name;
	for (int i = 0; i < graph->vertex_count; i++)//遍历每个顶点
	{
		cout << "you're inputing " << graph->adjacent_list[i].name << "s' adjacent_vertices" << endl;
		for (int j = 0; j < graph->adjacent_list[i].outdegree; j++)//输入指定出度个邻接顶点
		{
			cout << "input " << j + 1 << "th adjacent vertex: ";
			cin >> name;//输入邻接顶点名
			for (int k = 0; k < graph->vertex_count; k++)//在邻接表中搜索该顶点
			{
				if (name == graph->adjacent_list[k].name)//如果搜索到目标顶点
				{
					//申请新的邻接顶点链表的节点
					LINKNODE *new_node = new LINKNODE();
					//设置顶点指针指向邻接表中的目标顶点
					new_node->pt_vertex = &graph->adjacent_list[k];
					new_node->next = NULL;

					//连接到链表中
					new_node->next = graph->adjacent_list[i].adjacent_vertices->next;
					graph->adjacent_list[i].adjacent_vertices->next = new_node;

					//目标顶点的入度应自加1，因为有一个顶点指向它
					graph->adjacent_list[k].indegree++;
					continue;
				}
			}
		}
	}
	return graph;
}

void display_graph(GRAPH *graph)
{
	cout << "-------------------------------------" << endl;
	//输出顶点数
	cout << "vertices count: " << graph->vertex_count << endl;
	//遍历每个顶点
	for (int i = 0; i < graph->vertex_count; i++)
	{
		cout << "\n";
		cout << "name: " << graph->adjacent_list[i].name << endl;
		cout << "indegree: " << graph->adjacent_list[i].indegree << endl;
		cout << "outdegree: " << graph->adjacent_list[i].outdegree << endl;
		cout << "distance: " << graph->adjacent_list[i].distance << endl;

		cout << "parent: ";
		if (graph->adjacent_list[i].parent)
			cout << graph->adjacent_list[i].parent->name << endl;
		else
			cout << "nil" << endl;

		//遍历该顶点的邻接顶点
		cout << "adjacent_vertices: ";
		LINKNODE *head = graph->adjacent_list[i].adjacent_vertices;
		head = head->next;
		while (head)
		{
			cout << head->pt_vertex->name << " ";
			head = head->next;
		}
		cout << endl;
	}
	cout << "-------------------------------------" << endl;
}

bool unweighted_shortest_path(string start, GRAPH *graph)
{
	//检查起点的正确性，并获取起点的指针
	VERTEX *start_v = NULL;
	for (int i = 0; i < graph->vertex_count; i++)
	{
		if (start == graph->adjacent_list[i].name)
		{
			start_v = &graph->adjacent_list[i];
			break;
		}
	}
	if (!start_v)//如果起点不合法，将返回false
	{
		cout << "your start vertex is illegal" << endl;
		return false;
	}

	////////////////////开始探索路径///////////////////

	//路径过程中使用的顶点指针队列
	queue<VERTEX *> vertices_queue;

	//设置起点，并首先入队，路径长度为0
	start_v->distance = 0;
	vertices_queue.push(start_v);

	//依次检查每个邻接顶点，直到将所有顶点都探索一遍
	while (!vertices_queue.empty())
	{
		//获取对头顶点
		VERTEX *current_vertex = vertices_queue.front();

		//开始遍历其邻接顶点
		LINKNODE *temp_ad_v = current_vertex->adjacent_vertices;
		temp_ad_v = temp_ad_v->next;
		while (temp_ad_v)
		{
			//检查该邻接顶点是否已经被探索过，尚未被探索的顶点入队
			if (temp_ad_v->pt_vertex->distance == UNPROBE)
			{
				//更新该邻接顶点的路径长度,其长度比父顶点多1
				temp_ad_v->pt_vertex->distance = current_vertex->distance + 1;
				//更新该邻接顶点的父顶点
				temp_ad_v->pt_vertex->parent = current_vertex;
				//该邻接顶点入队
				vertices_queue.push(temp_ad_v->pt_vertex);
			}
			temp_ad_v = temp_ad_v->next;
		}
		//从队列中删除当前顶点
		vertices_queue.pop();
	}
	//成功完成路径过程，返回true
	return true;
}

void display_all_shortest_pathes(string start, GRAPH *graph)
{
	//调用函数，实现排序
	if (!unweighted_shortest_path(start, graph))
		return;

	//输出起点到每个顶点的路径
	for (int i = 0; i < graph->vertex_count; i++)
	{
		cout << "path from " << start << " to " << graph->adjacent_list[i].name << ": length = " << graph->adjacent_list[i].distance << ", ";
		recursive_print_path(&graph->adjacent_list[i]);
		cout << "\b\b   "<< endl;
	}
}

void display_shortest_path(string start, string end, GRAPH *graph)
{
	//调用函数，实现排序
	if (!unweighted_shortest_path(start, graph))
		return;

	/////检查终点的输入合法性
	VERTEX *end_v = NULL;
	for (int i = 0; i < graph->vertex_count; i++)
	{
		if (graph->adjacent_list[i].name == end)
		{
			end_v = &graph->adjacent_list[i];
			break;
		}
	}
	if (!end_v)
	{
		cout << "undefined end vertex" << endl;
		return;
	}

	//输出路径
	cout << "path from " << start << " to " << end << ": length = " << end_v->name << ", ";
	recursive_print_path(end_v);
	cout << "\b\b   "<< endl;
}

void recursive_print_path(VERTEX *distinct_vertex)
{
	//递归到根顶点后，从头到尾输出经过的顶点
	if (distinct_vertex->parent != NULL)
		recursive_print_path(distinct_vertex->parent);
	cout << distinct_vertex->name << "->";
}

/*测试数据：《数据结构与算法分析》 P292 左上角的图
7
v1
2
v2
2
v3
2
v4
4
v5
1
v6
0
v7
1
v2
v4
v4
v5
v1
v6
v3
v5
v6
v7
v7
v6

测速数据 《算法导论》P360左上角的图
5
0
2
3
2
5
3
9
1
11
2
3
5
5
9
3
9
11
11
0
9
*/