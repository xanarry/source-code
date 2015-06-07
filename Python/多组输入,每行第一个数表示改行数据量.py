counter = 1
while True:
    a = list(map(int, input().strip().split()))
    n, array = a[0], a[1:]
    if n == 0:
        break
    sum = 0
    for i in range(n):
        sum += array[i]
    print("case:" + str(counter) + ": " + str(sum))
    counter += 1
