#coding=utf-8
import random
count = 10
nums = []

def binary_search(nums, n):#相同的数字会输出靠左的位置
	left, right = 0, len(nums)
	mid = (left + right) / 2
	while n != nums[mid]:
		if n > nums[mid]:
			left = mid + 1
		if n < nums[mid]:
			right = mid - 1
		mid = (left + right) / 2
	return mid + 1

def binary_search1(nums, n):#相同的数字会输出最靠后的位置
	left, right = 0, len(nums) - 1

	while left <= right:
		mid = left + right
		if n == nums[mid]:
			break
		if n > nums[mid]:
			left = mid + 1
		if n < nums[mid]:
			right = mid - 1
	return mid + 1


for i in range(0, count):
	nums.append(random.randint(1, 10))#随机数列表
	#nums.append(i + 1)#随下标递增数

nums.sort()#排序

print ("the random numbers list")
for i in range(0,count):
	print nums[i],

obj = input("\ninput which number's location you wanna find:")
location = binary_search(nums, obj)
print "the location of %d near to right is %d" % (obj, location)
