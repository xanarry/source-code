import random
N = 20
MIN = 1
MAX = 10
nums = []

def selectsort(nums):
	l = len(nums)
	for i in range(0, l - 1):
		k = i
		for j in range(i + 1, l):
			if nums[k] < nums[j]:
				k = j
		if k != i:
			tmp = nums[k]
			nums[k] = nums[i]
			nums[i] = tmp

print("original list")
for i in range(0,N):
	nums.append(random.randint(MIN, MAX))
	print(nums[-1], end=',')
	
selectsort(nums)

print("\nafter selectsort")
for i in range(0,N):
	print(nums[i], end=',')

