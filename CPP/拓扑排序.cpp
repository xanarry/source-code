#include <iostream>
#include <string>

using namespace std;

struct VERTEX//��������Ķ���
{
	string name;//��������
	int indegree;//��������
	int outdegree;//����ĳ���
	string *adjacency_vertices;//������ڽӶ��������б�
};

struct GRAPH//ͼ�Ķ���
{
	int vertices_count;//ͼ�еĶ�����
	VERTEX *vertices;//ͼ�е��ڽӱ�
};

GRAPH *created_graph();//����ͼ����ʵ������
void display_graph(GRAPH *graph);//���ͼ���ڽӱ�
void get_vertices_indegree(GRAPH *graph);//���㶥������
void topologic_sort(GRAPH *graph, string *result_list);//ʵ����������
VERTEX *find_new_vertex_of_indegree_zero(GRAPH *graph);//�������Ϊ0�Ķ���

int main(int argc, char const *argv[])
{
	GRAPH *graph = created_graph();//����
	display_graph(graph);//���

	string result_list[graph->vertices_count];//����������б����ݸ�������
	topologic_sort(graph, result_list);//��������

	cout << "\ntopological sorted:" << endl;
	for (int i = 0; i < graph->vertices_count; i++)//���������
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
	 *��������ͼ���ڽӱ��ʾ
	 *����ÿ����������ݽṹ�����к��ж���������ȣ����ȣ����ڽӶ��������-string����
	 *����������ͼ��Ϣ��ʱ���ֶ����룬���ڽӶ��������Ҳ���ֶ����룬�������ɵ��ú���
	 *����
	 */
	GRAPH *graph = new GRAPH();
	cout << "input number of vertices: ";
	cin >> graph->vertices_count;//�����ͼ�Ķ�����

	graph->vertices = new VERTEX[graph->vertices_count];//�����ڽӱ���ڴ�ռ�
	if (graph->vertices == NULL)
	{
		cout << "graph initialize failed!" << endl;
		return NULL;
	}

	for (int i = 0; i < graph->vertices_count; i++)//���ͼ��ÿ���������Ϣ
	{
		cout << "input " << i + 1 << "th vertex's name: ";
		string vertex_name;
		cin >> graph->vertices[i].name;//���붥�������

		cout << "input its outdegree: ";
		cin >> graph->vertices[i].outdegree;//���붨��ĳ���

		graph->vertices[i].adjacency_vertices = new string[graph->vertices[i].outdegree];
		for (int j = 0; j < graph->vertices[i].outdegree; j++)
		{
			//����ö���������ڽӶ��������
			cout << "input " << j + 1 << "th adjacency vertice's name:";
			cin >> graph->vertices[i].adjacency_vertices[j];
		}
		cout << endl;
	}
	//��ȡÿ����������
	get_vertices_indegree(graph);
	return graph;
}

void get_vertices_indegree(GRAPH *graph)
{
	//ͨ�������������Ϣ����ÿ����������
	for (int i = 0; i < graph->vertices_count; i++)//��Ҫд��ÿ������
	{
		int indegree = 0;//��ʼ�����Ϊ0
		for (int j = 0; j < graph->vertices_count; j++)//����ÿ������
		{
			for (int k = 0; k < graph->vertices[j].outdegree; k++)//�������ڽӶ���
			{
				/*���������������ڽӶ��㷢����Ŀ�궥�㣬
				 *���������Ķ���ָ��������ȣ�
				 */
				if (graph->vertices[i].name == graph->vertices[j].adjacency_vertices[k])
					indegree++;
			}
		}
		//����ö�������
		graph->vertices[i].indegree = indegree;
	}
}

void display_graph(GRAPH *graph)
{
	cout << "the graph is as following: " << endl;
	//����ͼ�е�ÿ������
	for (int i = 0; i < graph->vertices_count; i++)
	{
		//�����������������ȣ�����
		cout << "vertex_name:" << graph->vertices[i].name << " indegree:" << graph->vertices[i].indegree << " outdegree:" << graph->vertices[i].outdegree << "  adjacency_vertices:";
		//����Ķ�����ڽӶ���
		for (int j = 0; j < graph->vertices[i].outdegree; j++)
			cout << graph->vertices[i].adjacency_vertices[j] << " ";
		cout << endl;
	}
}

void topologic_sort(GRAPH *graph, string *result_list)
{
	/*
	 *�����������Ϊ0�Ķ��㣬������ӵ�������б�
	 *Ȼ������ȼ�һ�����б����������޸��ڽӱ��
	 *�����Ϣ��������Ӱ�쵽��������Ϣ������
	 */

	//һ��graph->vertices�����㣬������������б�result_list���
	for (int i = 0; i < graph->vertices_count; i++)
	{
		//��ͼ�в������Ϊ��Ķ��㣬�����䶥���ָ��
		VERTEX *result = find_new_vertex_of_indegree_zero(graph);
		if (result != NULL)
		{
			//����������ӵ��б�
			result_list[i] = result->name;
			result->indegree--;//�����һ

			//�������Ľڵ�����ÿ���ڵ�����
			/*
			 *��������ղ���Ķ���������ڽӶ�������
			 *ӦΪ�ö����Ѿ���ӽ�������б��´β���
			 *�Ѿ�������Ҫ������������ָ��Ķ�����ȶ�
			 *Ҫ��1
			 */

			//�����ڽӶ���
			for (int j = 0; j < result->outdegree; j++)
			{
				//��������ͼ�е����ж���
				for (int k = 0; k < graph->vertices_count; k++)
				{
					//�������ͼ�е�ĳ������������ղ���Ķ�����ڽӶ��㣬��ô�ö������ȼ�һ
					if (graph->vertices[k].name == result->adjacency_vertices[j])
						graph->vertices[k].indegree--;
				}
			}
		}
		else
		{
			//������Ҳ������Ϊ0�Ķ��㣬��ô�ⲻ��һ��DAG
			cout << "the graph is not a DAG!" << endl;
			return;
		}
	}
}

VERTEX *find_new_vertex_of_indegree_zero(GRAPH *graph)
{
	//�������ж��㣬���������Ƿ�Ϊ0�����ظö����ָ��
	for (int i = 0; i < graph->vertices_count; i++)
	{
		if (graph->vertices[i].indegree == 0)
			return &graph->vertices[i];
	}
	return NULL;
}

/*
ͼ1����
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

ͼ2����(�㷨���۵ڶ���p336����������ͼ)
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

ͼ�������������໥��ָ
2
a
1
b
b
1
a
ͼ4:���ݽṹ���㷨����,P287
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

