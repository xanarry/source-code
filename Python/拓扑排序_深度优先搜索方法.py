topo_order = []#保存拓扑顺序
visited = {}#标记是否被访问

def dfs(graph, start):
    for x in graph[start]:
        if visited[x] == False:
            visited[x] = True
            dfs(graph, start)
    topo_order.insert(0, start)#添加排序顶点到列表

def topo_sort(graph):
    for x in graph:
        if visited[x] == False:
            visited[x] = True
            dfs(graph, x)#深度优先搜索入口

def init_graph():
    graph = {}
    n = int(input())#输入顶点数目
    for x in range(n):
        name = input()#输入顶点
        visited[name] = False
        graph[name] = list(map(str, input().strip().split()))#输入邻接顶点, 空格隔开多个顶点
    return graph

graph = init_graph()#输入图
topo_sort(graph)#拓扑排序
print(topo_order)#输出拓扑排序

'''
9
undershorts
pants shoes
pants
shoes belt
belt
jacket
shirt
tie belt
tie
jacket
socks
shoes
watch

jacket

shoes


'''