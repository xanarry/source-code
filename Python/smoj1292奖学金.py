#http://www.smartoj.com/p/1292
n = int(input())
score = {}
for i in range(1, n + 1):
    score[i] = list(map(int, input().strip().split()))
    score[i].append(sum(score[i]))

items = sorted(score.items(), key = lambda x : (-x[1][3], x[1][0], x[0]))
for i in range(5):
    print(items[i][0], items[i][1][3])