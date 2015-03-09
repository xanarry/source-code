len = input("input how many number you wanna input:")
len = int(len)
sum = 0
for i in range(0, len):
	print 'input', i+1, 'th number:',
	sum += input()
print(sum)
