import random
nums = []

print "original list"
for i in range(0, 20):
	nums.append(random.randint(1, 500))
	print nums[-1],

print "\nafter bobble sort"
for i in range(0, 19):
	for j in range(0, 19 - i):
		if nums[j] < nums[j + 1]:
			tmp = nums[j]
			nums[j] = nums[j + 1]
			nums[j + 1] = tmp
			
for x in range(0,20):
	print nums[x],
