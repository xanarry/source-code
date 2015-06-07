n = int(input().strip())
for t in range(n):
    m = input().strip().split()
    print(m[0] + "+" + m[1] + "=" + repr(int(m[0]) + int(m[1])))