#include <iostream>
#include <string>

using namespace std;

struct VERTEX//单个顶点的定义
{
	string name;//顶点名字
	int indegree;//顶点的入度
	int outdegree;//顶点的出度
	string *adjacency_vertices;//顶点的邻接顶点名字列表
};

struct GRAPH//图的定义
{
	int vertices_count;//图中的顶点数
	VERTEX *vertices;//图中的邻接表
};

GRAPH *created_graph();//创建图，即实现输入
void display_graph(GRAPH *graph);//输出图，邻接表
void get_vertices_indegree(GRAPH *graph);//计算顶点的入度
void topologic_sort(GRAPH *graph, string *result_list);//实现拓扑排序
VERTEX *find_new_vertex_of_indegree_zero(GRAPH *graph);//查找入度为0的顶点

int main(int argc, char const *argv[])
{
	GRAPH *graph = created_graph();//输入
	display_graph(graph);//输出

	string result_list[graph->vertices_count];//定义排序的列表，传递给排序函数
	topologic_sort(graph, result_list);//拓扑排序

	cout << "\ntopological sorted:" << endl;
	for (int i = 0; i < graph->vertices_count; i++)//输出排序结果
	{
		cout << result_list[i];
		if (i < graph->vertices_count - 1) 
			cout << "-->";
	}
	cout << endl;
	return 0;
}

GRAPH *created_graph()
{
	/*
	 *本程序中图以邻接表表示
	 *其中每个顶点的数据结构定义中含有顶点名，入度，出度，和邻接顶点的名字-string数组
	 *出度在输入图信息的时候手动输入，其邻接顶点的名字也是手动输入，入度最后由调用函数
	 *计算
	 */
	GRAPH *graph = new GRAPH();
	cout << "input number of vertices: ";
	cin >> graph->vertices_count;//输入该图的顶点数

	graph->vertices = new VERTEX[graph->vertices_count];//申请邻接表的内存空间
	if (graph->vertices == NULL)
	{
		cout << "graph initialize failed!" << endl;
		return NULL;
	}

	for (int i = 0; i < graph->vertices_count; i++)//填充图中每个定点的信息
	{
		cout << "input " << i + 1 << "th vertex's name: ";
		string vertex_name;
		cin >> graph->vertices[i].name;//输入顶点的名字

		cout << "input its outdegree: ";
		cin >> graph->vertices[i].outdegree;//输入定点的出度

		graph->vertices[i].adjacency_vertices = new string[graph->vertices[i].outdegree];
		for (int j = 0; j < graph->vertices[i].outdegree; j++)
		{
			//输入该顶点的所有邻接顶点的名字
			cout << "input " << j + 1 << "th adjacency vertice's name:";
			cin >> graph->vertices[i].adjacency_vertices[j];
		}
		cout << endl;
	}
	//获取每个顶点的入度
	get_vertices_indegree(graph);
	return graph;
}

void get_vertices_indegree(GRAPH *graph)
{
	//通过以上输入的信息计算每个顶点的入度
	for (int i = 0; i < graph->vertices_count; i++)//将要写入每个顶点
	{
		int indegree = 0;//初始化入度为0
		for (int j = 0; j < graph->vertices_count; j++)//遍历每个顶点
		{
			for (int k = 0; k < graph->vertices[j].outdegree; k++)//遍历其邻接顶点
			{
				/*如果在其他顶点的邻接顶点发现了目标顶点，
				 *即有其他的顶点指向它（入度）
				 */
				if (graph->vertices[i].name == graph->vertices[j].adjacency_vertices[k])
					indegree++;
			}
		}
		//保存该顶点的入度
		graph->vertices[i].indegree = indegree;
	}
}

void display_graph(GRAPH *graph)
{
	cout << "the graph is as following: " << endl;
	//遍历图中的每个顶点
	for (int i = 0; i < graph->vertices_count; i++)
	{
		//依次输出顶点名，入度，出度
		cout << "vertex_name:" << graph->vertices[i].name << " indegree:" << graph->vertices[i].indegree << " outdegree:" << graph->vertices[i].outdegree << "  adjacency_vertices:";
		//输出改顶点的邻接顶点
		for (int j = 0; j < graph->vertices[i].outdegree; j++)
			cout << graph->vertices[i].adjacency_vertices[j] << " ";
		cout << endl;
	}
}

void topologic_sort(GRAPH *graph, string *result_list)
{
	/*
	 *依次搜索入度为0的顶点，将其添加到排序的列表
	 *然后将其入度减一，所有本函数将会修改邻接表的
	 *入度信息，但不会影响到其他的信息，调用
	 */

	//一共graph->vertices个顶点，依次向有序的列表result_list添加
	for (int i = 0; i < graph->vertices_count; i++)
	{
		//在图中查找入度为零的顶点，返回其顶点的指针
		VERTEX *result = find_new_vertex_of_indegree_zero(graph);
		if (result != NULL)
		{
			//将顶点名添加到列表
			result_list[i] = result->name;
			result->indegree--;//读书减一

			//添加上面的节点后更新每个节点的入度
			/*
			 *遍历上面刚插入的顶点的所有邻接顶点的入度
			 *应为该顶点已经添加进排序的列表，下次查找
			 *已经不再需要它，所以它所指向的顶点入度都
			 *要减1
			 */

			//遍历邻接顶点
			for (int j = 0; j < result->outdegree; j++)
			{
				//遍历所有图中的所有顶点
				for (int k = 0; k < graph->vertices_count; k++)
				{
					//如果发现图中的某个顶点是上面刚插入的顶点的邻接顶点，那么该顶点的入度减一
					if (graph->vertices[k].name == result->adjacency_vertices[j])
						graph->vertices[k].indegree--;
				}
			}
		}
		else
		{
			//如果查找不到入度为0的顶点，那么这不是一个DAG
			cout << "the graph is not a DAG!" << endl;
			return;
		}
	}
}

VERTEX *find_new_vertex_of_indegree_zero(GRAPH *graph)
{
	//遍历所有顶点，检查其入度是否为0，返回该顶点的指针
	for (int i = 0; i < graph->vertices_count; i++)
	{
		if (graph->vertices[i].indegree == 0)
			return &graph->vertices[i];
	}
	return NULL;
}

/*
图1内容
7
v1
3
v2
v3
v4
v2
2
v4
v5
v3
1
v6
v4
2
v6
v7
v5
2
v4
v7
v6
0
v7
1
v6

图2内容(算法导论第二版p336的拓扑排序图)
9
jacket
0
socks
1
shoes
undershorts
2
pants
shoes
pants
2
belt
shoes
shoes
0
watch
0
shirt
2
belt
tie
belt
1
jacked
tie
1
jacket

图三，两个顶点相互对指
2
a
1
b
b
1
a
图4:数据结构与算法分析,P287
17
MAC3311
1
MAD3104
COP3210
3
MAD3104
COP3400
COP3212
CAP3700
0
MAD3104
6
CAP3700
MAD3305
MAD3512
COP3530
CDA4101
CDA4400
COP3400
1
CDA4101
COP3212
3
COP3530
CDA4101
COP4555
COP4555
0
MAD3305
0
MAD3512
1
COP5621
COP3530
3
COP4500
CIS4610
COP4610
CDA4101
1
COP4610
CAD4400
0
COP4540
0
COP5621
0
CIS4610
1
COP5621
COP4610
1
COP4225
COP4225
0
*/

