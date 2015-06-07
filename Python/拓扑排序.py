def topo_sort(graph):
    queue = []
    for x in graph:
        if graph[x]["indegree"] == 0:
            queue.append(x)#首先将孤立的点都加入队列中

    order_list = []
    while len(order_list) != len(graph):#如果没有将所有顶点排完序
        cur = queue.pop(0)
        order_list.append(cur)
        #每添加完一个新的顶点,将该顶点的所有邻接顶点入度都减1
        for x in graph[cur]["adjacents"]:
            graph[x]["indegree"] -= 1
            if graph[x]["indegree"] == 0:#如果减一后入度为0, 那么添加到队列中
                queue.append(x)

    return order_list

def init_graph():
    graph = {}
    n = int(input())#输入顶点数目
    for x in range(n):
        name = input()#输入顶点
        adjs = list(map(str, input().strip().split()))#输入该顶点的邻接顶点
        graph[name] = {"indegree" : 0, "adjacents" : adjs}#保存默认入度0, 和邻接点列表

    for x in graph:#计算没个点的入度
        for adj in graph[x]["adjacents"]:
            graph[adj]["indegree"] += 1

    return graph#返回图

graph = init_graph()
for x in graph:
    print(x, graph[x]["indegree"], graph[x]["adjacents"])

order_list = topo_sort(graph)
print(order_list)

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

