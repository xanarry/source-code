edges = []
p = {}

def find(x):#并查集find函数
    if p[x] == x:
        return x
    else:
        p[x] = find(p[x])
        return p[x]

while True:
    u, v, w = input().strip().split()#输入每一条边
    if v == "0" and u == "0" and w == "0":
        break
    edges.append((u, v, int(w)))#保存所有边
    #设置每个节点自己单独一类
    p[v] = v
    p[u] = u

#对变按权值升序排序
edges.sort(key = lambda x : x[2])
min_w = 0#保存最小权值

for x in edges:
    u = find(x[0])
    v = find(x[1])
    #搜索边
    if u != v:#如果没有添加到生成树中
        p[u] = v#添加进去
        print("add edge:", x[0] + "-" + x[1], "w:", x[2])#输出树中的边
        min_w += x[2]
print("min_w =", min_w)#输出权值
