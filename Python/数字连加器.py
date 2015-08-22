import time
filePath = input("input path of file:")
f = open(filePath, "r")#打开文件
nsum = 0#保存结果
count = 0#保存数量
for line in f:#遍历文件所有行
    nsum += int(line)#获取每行数字并求和
    count += 1#数量加1
print("一共:", count, "个数字, 总和为:", nsum)#输出结果
time.sleep(10000)
