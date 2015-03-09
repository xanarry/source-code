#coding=utf-8
count = input()#要输入的数字的个数
nums = []#定义空列表
for i in range(0, count):
	tmp = int(input())#输入数字，并转换为整型
	nums.append(tmp)#插入列表

nums.sort()#对列表排序

show_time, last_value = 1, nums[0]#初始化出现次数show_time，和转换变量last_value,默认为nums[0]

for i in range(1, count):#遍历列表
	if nums[i] == last_value:
		show_time += 1#如果数字连续切相同，次数加1
	else:#遇到不同数字时
		print last_value, show_time#输出上一个数字的结果
		last_value = nums[i]#重置当前值
		show_time = 1#重置次数
print last_value, show_time#输出最后一个数字的结果