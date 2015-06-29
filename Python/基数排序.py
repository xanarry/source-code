import random

nums = []
for i in range(100):
    nums.append(random.randint(1, 100))

#nums = [12, 34, 35, 75, 57, 19, 62, 95, 30000, 74]

print(nums)

maxLen = max(map(lambda x : len(str(x)), nums))
nums = [str(x).zfill(maxLen) for x in nums]

print(nums)

while maxLen > 0:
    #置0排序中使用的槽
    leval = [None for x in range(10)];

    for x in nums:
        index = int(x[maxLen - 1])
        if not leval[index]:
            leval[index] = [x]
        else:
            leval[index].append(x)

    nums = []#从槽中提取数据到列表, 准备下次筛选
    for i in leval:
        if i:
            for j in i:
                nums.append(j)
    maxLen -= 1

#最后筛选出有序序列
nums = []
for i in leval:
    if i:
        for j in i:
            nums.append(int(j))
#输出结果
print(nums)