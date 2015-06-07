#http://www.smartoj.com/p/1006
website = ["http://www.acm.org"]
index = 0
while True:
    cmd = list(map(str, input().strip().split()))
    if len(cmd) == 2:#覆盖当前下标的下一个位置
        print(cmd[1])
        index += 1
        if index >= len(website):
            website.append(cmd[1])
        else:
            website[index] = cmd[1]
    elif cmd[0] == "BACK":#不添加的列表
        if index <= 0:
            print("Ignored")
        else:
            index -= 1
            print(website[index])
    elif cmd[0] == "FORWARD":#移动下标
        if index > len(website) - 2:
            print("Ignored")
        else:
            index += 1
            print(website[index])
    elif cmd[0] == "QUIT"
        break
