def init_graph():
    graph = {}
    #input like u-v-w
    while True:
        u, v, w = input().strip().split()
        if u == "-1" and v == "-1" and w == "-1":
            break
        w = int(w)
        if u in graph:
            graph[u].append((v, w))
        else:
            graph[u] = [(v, w)]

        if v in graph:
            graph[v].append((u, w))
        else:
            graph[v] = [(u, w)]
    return graph

def show_graph(graph):
    for x in graph.items():#each vertex
        print(x[0], "=>", x[1])#adjecent

def prim(graph):
    start = input();
    queue = {start : 0}
    visited = []
    min_w = 0
    pre = "_"
    while len(queue) != 0:
        start = min(queue, key = lambda x : queue[x])
        min_w += queue[start];
        visited.append(start)
        print("Meet:", start, "add edge:", str(pre) + "-" + str(start), "w =", queue[start])
        del(queue[start])
        pre = start
        for x in graph[start]:
            if x[0] in queue:
                if x[1] < queue[x[0]]:
                    queue[x[0]] = x[1]
            elif x[0] not in visited:
                queue[x[0]] = x[1]  

    print("Min weight:", min_w)

graph = init_graph()
prim(graph)

'''
a b 4
b c 8
a h 8
b h 11
c i 2
h i 7
g i 6
g h 1
g f 2
c f 4
c d 7
d e 9
d f 14
f e 9
-1 -1 -1
i
'''
